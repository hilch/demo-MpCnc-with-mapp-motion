#!/usr/bin/env python3
"""
G-Code Plotter application
Visualizes G-code contours and displays dimensions and radius errors
"""

import re
import math
import numpy as np
from matplotlib import pyplot as plt
from matplotlib.patches import Rectangle
import argparse
from pathlib import Path


class GCodePlotter:
    """Parser and plotter for G-code files."""
    
    def __init__(self, tolerance=0.00001):
        self.tolerance = tolerance
        self.path_x = []
        self.path_y = []
        self.path_colors = []
        self.current_pos = [0.0, 0.0]
        self.errors = []
        self.arc_details = []
        
    def parse(self, gcode_content):
        """Parse a G-code program."""
        lines = gcode_content.strip().split('\n')
        absolute_coordinates = True
        motion_mode = None
        path_active = False
        path_color = 'lightgray'
        
        for line_idx, line in enumerate(lines):
            # Extract parameters
            x_match = re.search(r'X([-\d.]+)', line)
            y_match = re.search(r'Y([-\d.]+)', line)
            n_match = re.search(r'N(\d+)', line)

            for m_code in re.findall(r'\bM(\d+)\b', line.upper()):
                if m_code == '7':
                    next_color = 'red'
                elif m_code == '8':
                    next_color = 'lightgray'
                else:
                    continue
                if next_color != path_color and path_active:
                    self._append_path_point(np.nan, np.nan, None)
                    path_active = False
                path_color = next_color

            for g_code in re.findall(r'\bG(\d+)\b', line.upper()):
                code = int(g_code)
                if code == 90:
                    absolute_coordinates = True
                elif code == 91:
                    absolute_coordinates = False
                elif code in (0, 1, 2, 3):
                    motion_mode = code

            if not (x_match or y_match):
                if motion_mode == 0:
                    if path_active:
                        self._append_path_point(np.nan, np.nan, None)
                    path_active = False
                continue

            x_start, y_start = self.current_pos
            x_value = float(x_match.group(1)) if x_match else 0.0
            y_value = float(y_match.group(1)) if y_match else 0.0
            if absolute_coordinates:
                x_end = x_value if x_match else x_start
                y_end = y_value if y_match else y_start
            else:
                x_end = x_start + x_value
                y_end = y_start + y_value

            if motion_mode == 0:
                if path_active:
                    self._append_path_point(np.nan, np.nan, None)
                path_active = False
            elif motion_mode == 1:
                if not path_active:
                    self._append_path_point(x_start, y_start, path_color)
                self._append_path_point(x_end, y_end, path_color)
                path_active = True
            elif motion_mode in (2, 3):
                i_match = re.search(r'I([-\d.]+)', line)
                j_match = re.search(r'J([-\d.]+)', line)
                if i_match and j_match:
                    if not path_active:
                        self._append_path_point(x_start, y_start, path_color)
                    self._process_arc(
                        x_start, y_start, x_end, y_end,
                        float(i_match.group(1)), float(j_match.group(1)),
                        motion_mode == 3,
                        n_match.group(1) if n_match else f"{line_idx+1}",
                        path_color
                    )
                    path_active = True

            self.current_pos[0] = x_end
            self.current_pos[1] = y_end

    def _append_path_point(self, x, y, color):
        self.path_x.append(x)
        self.path_y.append(y)
        self.path_colors.append(color)
    
    def _process_arc(self, x_start, y_start, x_end, y_end, i_val, j_val, ccw, n_code, color):
        """Process a G02/G03 arc."""
        
        # Center point
        xc = x_start + i_val
        yc = y_start + j_val
        
        # Radii
        r_start = math.sqrt(i_val**2 + j_val**2)
        dx_end = x_end - xc
        dy_end = y_end - yc
        r_end = math.sqrt(dx_end**2 + dy_end**2)
        
        # Radius error
        radius_error = abs(r_start - r_end)
        
        # Store errors
        if radius_error > self.tolerance:
            self.errors.append({
                'n_code': n_code,
                'error': radius_error,
                'r_start': r_start,
                'r_end': r_end
            })
        
        # Store arc details
        self.arc_details.append({
            'xc': xc, 'yc': yc, 'r': r_start,
            'x_start': x_start, 'y_start': y_start,
            'x_end': x_end, 'y_end': y_end,
            'ccw': ccw
        })
        
        # Interpolate the arc
        angle_start = math.atan2(y_start - yc, x_start - xc)
        angle_end = math.atan2(y_end - yc, x_end - xc)
        
        # Direction
        if ccw:  # G03 - counterclockwise
            if angle_end < angle_start:
                angle_end += 2 * math.pi
        else:  # G02 - clockwise
            if angle_end > angle_start:
                angle_end -= 2 * math.pi
        
        # Interpolation points
        num_points = int(abs(angle_end - angle_start) * 100) + 5
        angles = np.linspace(angle_start, angle_end, num_points)
        
        for angle in angles:
            x = xc + r_start * np.cos(angle)
            y = yc + r_start * np.sin(angle)
            self._append_path_point(x, y, color)
    
    def get_stats(self):
        """Calculate statistics."""
        valid_points = [
            (x, y) for x, y in zip(self.path_x, self.path_y)
            if math.isfinite(x) and math.isfinite(y)
        ]
        x_vals = np.array([point[0] for point in valid_points])
        y_vals = np.array([point[1] for point in valid_points])
        
        stats = {
            'x_min': float(np.min(x_vals)),
            'x_max': float(np.max(x_vals)),
            'y_min': float(np.min(y_vals)),
            'y_max': float(np.max(y_vals)),
            'x_range': float(np.max(x_vals) - np.min(x_vals)),
            'y_range': float(np.max(y_vals) - np.min(y_vals)),
            'num_points': len(valid_points),
            'num_errors': len(self.errors),
            'max_error': max([e['error'] for e in self.errors]) if self.errors else 0.0
        }
        return stats
    
    def plot(self, output_file=None, show=True):
        """Plot the contour."""
        fig, ax = plt.subplots(figsize=(14, 12), dpi=100)
        
        # Main contour
        for color in dict.fromkeys(self.path_colors):
            if color is None:
                continue
            color_x = [x if point_color == color else np.nan
                       for x, point_color in zip(self.path_x, self.path_colors)]
            color_y = [y if point_color == color else np.nan
                       for y, point_color in zip(self.path_y, self.path_colors)]
            label = 'M7' if color == 'red' else 'Contour'
            ax.plot(color_x, color_y, color=color, linewidth=1.5, label=label)
        
        # Start and end
        valid_indices = [
            index for index, (x, y) in enumerate(zip(self.path_x, self.path_y))
            if math.isfinite(x) and math.isfinite(y)
        ]
        ax.plot(self.path_x[valid_indices[0]], self.path_y[valid_indices[0]], 'o',
            color='#6764f6', markersize=10, label='Start', zorder=5)
        ax.plot(self.path_x[valid_indices[-1]], self.path_y[valid_indices[-1]], 's',
            color='#FF000F', markersize=10, label='End', zorder=5)
        
        # Arc centers (optional)
        for arc in self.arc_details[::5]:  # Show every fifth arc
            ax.plot(arc['xc'], arc['yc'], 'x', color='#93a1ff', 
                   markersize=4, alpha=0.5, scalex=False, scaley=False)
        
        ax.set_aspect('equal', adjustable='box')
        ax.grid(True, alpha=0.3)
        ax.legend(fontsize=10, loc='upper right')
        ax.set_xlabel('X', fontsize=11)
        ax.set_ylabel('Y', fontsize=11)
        ax.set_title('G-code contour', fontsize=13, fontweight='bold')
        
        # Statistics on the plot
        stats = self.get_stats()
        x_padding = max(stats['x_range'] * 0.02, 0.01)
        y_padding = max(stats['y_range'] * 0.02, 0.01)
        ax.set_xlim(stats['x_min'] - x_padding, stats['x_max'] + x_padding)
        ax.set_ylim(stats['y_min'] - y_padding, stats['y_max'] + y_padding)

        info_text = f"X: {stats['x_min']:.3f}...{stats['x_max']:.3f} ({stats['x_range']:.3f})\n"
        info_text += f"Y: {stats['y_min']:.3f}...{stats['y_max']:.3f} ({stats['y_range']:.3f})\n"
        info_text += f"Points: {stats['num_points']} | Errors: {stats['num_errors']}"
        
        ax.text(0.02, 0.98, info_text, transform=ax.transAxes,
               fontsize=9, verticalalignment='top',
               bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))
        
        plt.tight_layout()
        
        if output_file:
            plt.savefig(output_file, dpi=150, bbox_inches='tight')
            print(f"✓ Plot saved: {output_file}")
        
        if show:
            plt.show()
        
        return fig
    
    def print_report(self):
        """Print a detailed report."""
        stats = self.get_stats()
        
        print("\n" + "="*70)
        print("G-CODE ANALYSE REPORT")
        print("="*70)
        
        print("\n📐 DIMENSIONS:")
        print(f"  X range:   {stats['x_min']:10.4f} ... {stats['x_max']:10.4f} mm")
        print(f"  Y range:   {stats['y_min']:10.4f} ... {stats['y_max']:10.4f} mm")
        print(f"  Width:     {stats['x_range']:10.4f} mm")
        print(f"  Height:    {stats['y_range']:10.4f} mm")
        
        print("\n📊 PROGRAM:")
        print(f"  Contour points:   {stats['num_points']:8d}")
        print(f"  Arcs (G02/G03):   {len(self.arc_details):8d}")
        
        print("\n⚠️  RADIUS ERRORS:")
        print(f"  Errors found:     {stats['num_errors']:8d}")
        
        if self.errors:
            print(f"  Maximum error:    {stats['max_error']:10.8f} mm")
            print("\n  Error details:")
            for err in sorted(self.errors, key=lambda x: x['error'], reverse=True)[:10]:
                print(f"    N{err['n_code']:4s}: {err['error']:10.8f} mm " +
                      f"(r_start={err['r_start']:.6f}, r_end={err['r_end']:.6f})")
            if len(self.errors) > 10:
                print(f"    ... and {len(self.errors)-10} more")
        else:
            print(f"  Maximum error:    0.00000000 mm (No errors)")
        
        print("\n" + "="*70)


def main():
    parser = argparse.ArgumentParser(
        description='G-code plotter - visualize and analyze G-code'
    )
    parser.add_argument('file', help='G-code file (.txt, .cnc)')
    parser.add_argument('-o', '--output', help='Output PNG file')
    parser.add_argument('-t', '--tolerance', type=float, default=0.00001,
                       help='Radius error tolerance (default: 0.00001)')
    parser.add_argument('--no-plot', action='store_true', help='Do not display the plot')
    
    args = parser.parse_args()
    
    # Load the G-code file
    try:
        with open(args.file, 'r') as f:
            gcode = f.read()
    except FileNotFoundError:
        print(f"❌ File not found: {args.file}")
        return
    
    # Parse and plot
    plotter = GCodePlotter(tolerance=args.tolerance)
    plotter.parse(gcode)
    plotter.print_report()
    
    output_file = args.output if args.output else None
    plotter.plot(output_file=output_file, show=not args.no_plot)


if __name__ == '__main__':
    main()
/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _MCPATHGEN_
#define _MCPATHGEN_

#ifndef _MCAXIS_
#include <McAxis.h>
#endif
#ifndef _MCAXGROUP_
#include <McAxGroup.h>
#endif

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#if defined(_WIN32) || defined(__WINDOWS__) || defined(__MINGW32__) || defined(__CYGWIN__)
#if defined(BUILD_GMCPATHGEN)
#define DECLSPEC_GMCPATHGEN __declspec(dllexport)
#else
#define DECLSPEC_GMCPATHGEN __declspec(dllimport)
#endif
#else	/* not Windows */
#define DECLSPEC_GMCPATHGEN _BUR_PUBLIC
#endif

typedef McAxesGroupType PathGenAxesGroup;
typedef PathGenAxesGroup MCAxesGroupType_PathGen;


/* Datatypes and datatypes of function blocks */
typedef struct McPathGenPacketMonitorType
{
	unsigned long InterpreterMPCount;
	unsigned long InitializerMPCount;
	unsigned long FinalizerMPCount;
	unsigned long TrajectoryPlannerMPCount;
	unsigned long MovementMPCount;
	unsigned long NonMovementMPCount;
} McPathGenPacketMonitorType;

typedef struct McPathGenCondStopMonitorType
{
	plcbit StopReached;
	unsigned long StopIdent;
} McPathGenCondStopMonitorType;

typedef struct McPathGenActiveLimitType
{
	double U;
	unsigned long Index;
	unsigned long Type;
	unsigned long MinMax;
	unsigned long BrakingType;
} McPathGenActiveLimitType;

typedef struct McPathGenAxesType
{
	double JointAxis[10];
	double PathAxis[10];
	double NonTrfAxis[10];
} McPathGenAxesType;

typedef struct McPathGenAxesDynType
{
	float JointAxis[10];
	float PathAxis[10];
	float NonTrfAxis[10];
} McPathGenAxesDynType;

typedef struct McPathGenInternalMonitorType
{
	plcbit Enable;
	unsigned long TicksWithNoData;
	float SampleTimeFactor;
	float SpindleOverride;
	unsigned long HaltInfo;
	unsigned long PacketType;
	unsigned long FeedrateType;
	float ProgrammedFeedrate;
	double PathPosition;
	float PathVelocity;
	float PathAcceleration;
	McPathGenAxesDynType Velocity;
	McPathGenAxesDynType Acceleration;
	McPathGenPacketMonitorType MotionPacketMonitor;
	McPathGenCondStopMonitorType ConditionalStopMonitor;
	McPathGenActiveLimitType ActiveLimit;
} McPathGenInternalMonitorType;

typedef struct McPathGenSimulationMonitorType
{
	plcbit IsActive;
	double RunTime;
} McPathGenSimulationMonitorType;

typedef struct McPathGenRestartMonitorType
{
	plcbit Activated;
	McPathGenSimulationMonitorType Simulation;
} McPathGenRestartMonitorType;

typedef struct McPathGenBlockMonitorType
{
	plcbit Enable;
	plcbit InterpreterSyncDisplay;
	plcbit DisplayLineNumbers;
	plcstring BlockLast2[81];
	plcstring BlockLast1[81];
	plcstring BlockActual[81];
	plcstring BlockNext1[81];
	plcstring BlockNext2[81];
} McPathGenBlockMonitorType;

typedef struct McPathGenMonitorType
{
	plcbit Enable;
	plcstring ProgramName[81];
	unsigned long BlockNumber;
	unsigned long LineNumber;
	double ProgramRunTime;
	double MovementRunTime;
	double DwellTime;
	double DwellTimeRemaining;
	McCoordinateSystemEnum PositionMonitorMode;
	McPathGenAxesType Position;
	McPathGenAxesType TargetPosition;
	McPathGenAxesType RemainingDistance;
	float SpindleVelocity[10];
	McPathGenRestartMonitorType Restart;
	McPathGenBlockMonitorType BlockMonitor;
	McPathGenInternalMonitorType InternalMonitor;
} McPathGenMonitorType;

typedef struct McPathGenMonElemPrgType
{
	plcstring FileName[261];
	plcstring FullPath[261];
	unsigned long Number;
} McPathGenMonElemPrgType;

typedef struct McPathGenMonElemCurrentPrgType
{
	plcstring FileName[261];
	plcstring FullPath[261];
	unsigned long Number;
	unsigned long CallLevel;
} McPathGenMonElemCurrentPrgType;

typedef struct McPathGenMonElemBlockMonType
{
	plcstring BlockLast2[261];
	plcstring BlockLast1[261];
	plcstring BlockActual[261];
	plcstring BlockNext1[261];
	plcstring BlockNext2[261];
} McPathGenMonElemBlockMonType;

typedef struct McPathGenMonElemPrgSequenceType
{
	unsigned long CallLevel;
	McPathGenMonElemPrgType Program[32];
} McPathGenMonElemPrgSequenceType;

typedef struct McPathGenMonElemAxPositionsType
{
	double SetPosition[10];
} McPathGenMonElemAxPositionsType;

typedef struct McPathGenMonElemPathSpeedType
{
	float UnitPerMinute;
	float UnitPerRevolution;
	float Inverse;
} McPathGenMonElemPathSpeedType;

typedef struct McPathGenMonElemToolTransType
{
	double X;
	double Y;
	double Z;
} McPathGenMonElemToolTransType;

typedef struct McPathGenMonElemToolOrientType
{
	double Angle1;
	double Angle2;
	double Angle3;
} McPathGenMonElemToolOrientType;

typedef struct McPathGenMonElemToolDescType
{
	McPathGenMonElemToolTransType ToolTranslation;
	McPathGenMonElemToolOrientType ToolOrientation;
	double ToolLength;
	double ToolRadius;
	long ToolVirtualToolTip;
} McPathGenMonElemToolDescType;

typedef struct McPathGenMonElemAxLimitsType
{
	double UpperPositionLimit;
	double LowerPositionLimit;
	float VelocityPositive;
	float VelocityNegative;
	float AccelerationPositive;
	float AccelerationNegative;
	float DecelerationPositive;
	float DecelerationNegative;
	float JerkAccelerationPositive;
	float JerkAccelerationNegative;
	float JerkDecelerationPositive;
	float JerkDecelerationNegative;
} McPathGenMonElemAxLimitsType;

typedef struct McPathGenMonElemAxTorquesType
{
	double Torques[10];
} McPathGenMonElemAxTorquesType;

typedef struct McPathGenMonElemBasicMonType
{
	McPathGenMonElemCurrentPrgType CurrentProgram;
	unsigned long LineNumber;
	unsigned long BlockNumber;
	double Runtime;
	float PathSpeed;
	McPathGenMonElemAxPositionsType Axes;
	McPathGenMonElemAxPositionsType TCPInMCS;
	McPathGenMonElemAxPositionsType SlaveAxes;
} McPathGenMonElemBasicMonType;

//typedef struct MC_GroupHalt
//{
//	/* VAR_INPUT (analog) */
//	MCAxesGroupType_PathGen* AxesGroup;
//	float Deceleration;
//	float Jerk;
//	/* VAR_OUTPUT (analog) */
//	signed long ErrorID;
//	/* VAR (analog) */
//	McInternalType Internal;
//	/* VAR_INPUT (digital) */
//	plcbit Execute;
//	/* VAR_OUTPUT (digital) */
//	plcbit Done;
//	plcbit Busy;
//	plcbit Active;
//	plcbit CommandAborted;
//	plcbit Error;
//} MC_GroupHalt_typ;

typedef unsigned long McKinematicTrfType;

typedef struct MC_SetKinTrans
{
	/* VAR_INPUT (analog) */
	MCAxesGroupType_PathGen* AxesGroup;
	McKinematicTrfType KinematicModel;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_SetKinTrans_typ;

#if 1
typedef struct MC_BR_GrpJogVelocity_15
{
	/* VAR_INPUT (analog) */
	MCAxesGroupType_PathGen* AxesGroup;
	McCoordinateSystemEnum CoordSystem;
	float JogVelocity[15];
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	McJogStatusEnum JogStatus;
	/* VAR (analog) */
	McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Jog;
	/* VAR_OUTPUT (digital) */
	plcbit Ready;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_GrpJogVelocity_15_typ;

typedef struct MC_BR_GrpJogRelative_15
{
	/* VAR_INPUT (analog) */
	MCAxesGroupType_PathGen* AxesGroup;
	McCoordinateSystemEnum CoordSystem;
	float JogDistance[15];
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	McJogStatusEnum JogStatus;
	/* VAR (analog) */
	McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Jog;
	/* VAR_OUTPUT (digital) */
	plcbit Ready;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_GrpJogRelative_15_typ;

typedef struct MC_BR_GrpJogAbsolute_15
{
	/* VAR_INPUT (analog) */
	MCAxesGroupType_PathGen* AxesGroup;
	McCoordinateSystemEnum CoordSystem;
	float JogPosition[15];
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	McJogStatusEnum JogStatus;
	/* VAR (analog) */
	McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Jog;
	/* VAR_OUTPUT (digital) */
	plcbit Ready;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_GrpJogAbsolute_15_typ;
#endif


#endif /* _GMCPATHGEN_ */


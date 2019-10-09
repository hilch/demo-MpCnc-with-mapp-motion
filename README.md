# demo-MpCnc-with-mapp-motion
[B&amp;R](https://www.br-automation.com) Automation Studio 
demo cnc application with [B&amp;R](https://www.br-automation.com) mapp components (MpCNC based on mapp motion)

![Screenshot](https://github.com/hilch/demo-MpCnc-with-mapp-motion-/blob/master/doc/screenshot.PNG)

## Usage
This project can be started in a simulation environment ('ArSim') with a vnc viewer connected to 127.0.0.1 (8-Bit colour mode).
Just press button '1.', '2.' and '3.' one after another to see Mickey.

## CNC programs
### 'CNC program' object
The 'standard' way to run a cnc program is to insert a special data module named "CNC program" in Automation Studio and to edit it with the buildin editor that also supports minimalistic G-Code highlighting.
![cncprogram1](https://github.com/hilch/demo-MpCnc-with-mapp-motion-/blob/master/doc/cncprogram1.png)
### File
The second way is to create it outside and store it as text file on local flash or a network share. Just point a 'File Device' to the partition or directory ("CPU configuration/File devices")
### general data object
sometimes it might be useful to run the program out of a 'normal' data object. So just use Automation Studio and create a data object with unterminated strings followed by a single LF ('\n') character
![cncprogram2](https://github.com/hilch/demo-MpCnc-with-mapp-motion-/blob/master/doc/cncprogram2.png)
### STRING variable
do the same in e.g. a STRING variable and create a general data object from by help of system Library 'DataObj' (DatObjCreate())
![cncprogram3](https://github.com/hilch/demo-MpCnc-with-mapp-motion-/blob/master/doc/cncprogram3.png)




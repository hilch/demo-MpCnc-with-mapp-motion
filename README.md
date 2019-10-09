# demo-MpCnc-with-mapp-motion
[B&amp;R](https://www.br-automation.com) Automation Studio 
demo cnc application with [B&amp;R](https://www.br-automation.com) mapp components (MpCNC based on mapp motion)

![Screenshot](https://github.com/hilch/demo-MpCnc-with-mapp-motion-/blob/master/doc/screenshot.PNG)

# CNC programs
- The 'standard' way to run a cnc program is to insert a special data module named "CNC program" in Automation Studio and to edit it with the buildin editor that also supports minimalistic G-Code highlighting.
![cncprogram1](https://github.com/hilch/demo-MpCnc-with-mapp-motion-/blob/master/doc/cncprogram1.png)
- The second way is to create it outside and store it as text file on local flash or a network share. Just point a 'File Device' to the partition or directory ("CPU configuration/File devices")
- sometimes it might be useful to run the program out of a 'normal' data object. So just use Automation Studio and create a data object with unterminated strings followed by a single LF ('\n') character or do the same in e.g. a STRING variable and convert it to a data object by help of system Library 'DatObj'
![cncprogram2](https://github.com/hilch/demo-MpCnc-with-mapp-motion-/blob/master/doc/cncprogram2.png)



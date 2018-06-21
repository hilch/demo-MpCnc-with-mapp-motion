
PROGRAM _CYCLIC
	MpCnc3Axis_0();

	g_positionX := MpCnc3Axis_0.X;
	g_positionY := MpCnc3Axis_0.Y;
	 
	IF MFunc_CutterUp THEN
		MFunc_CutterUp := FALSE;
	END_IF

	IF MFunc_CutterDown THEN
		MFunc_CutterDown := FALSE;
	END_IF
END_PROGRAM

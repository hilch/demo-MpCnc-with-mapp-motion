

PROGRAM _INIT
	MpCnc3Axis_0.MpLink := ADR(gCncXYZ);
	MpCnc3Axis_0.Enable := TRUE;
	MpCnc3Axis_0.Parameters := ADR(CncParameters);

	MpCnc3Axis_0.Override := 100.0;

	CncParameters.ProgramName := 'Micky';	
	 

END_PROGRAM
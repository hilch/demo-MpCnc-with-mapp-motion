

PROGRAM _INIT
	fbMpCnc.MpLink := ADR(gCncXYZ);
	fbMpCnc.Enable := TRUE;
	fbMpCnc.Parameters := ADR(CncParameters);

	fbMpCnc.Override := 100.0;

	CncParameters.ProgramName := 'World';	

END_PROGRAM
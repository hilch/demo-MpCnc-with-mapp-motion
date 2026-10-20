

PROGRAM _INIT
	fbMpCnc.MpLink := ADR(gCnc);
	fbMpCnc.Enable := TRUE;
	fbMpCnc.Parameters := ADR(CncParameters);

	fbMpCnc.Override := 100.0;

	CncParameters.ProgramName := 'World'; //'Rect';	

END_PROGRAM
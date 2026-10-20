
PROGRAM _CYCLIC
	fbMpCnc();

	g_positionX := fbMpCnc.X;
	g_positionY := fbMpCnc.Y;
	 
	direction := 360 - (LREAL_TO_REAL(fbMpCnc.C) + 90.0); // direction for circular gauge
END_PROGRAM

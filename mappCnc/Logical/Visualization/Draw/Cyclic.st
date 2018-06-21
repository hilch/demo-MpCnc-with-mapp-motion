
PROGRAM _CYCLIC

	CASE step OF
		0:
		vcHandle := VA_Setup( TRUE, 'Visu' );
		IF vcHandle <> 0 THEN
			step := 10;
		END_IF

		10:
		IF currentPage = 1 THEN
			positionXOld := g_positionX;
			positionYOld := g_positionY;
			scale := 100.0;
			offsetX := 0.0;
			offsetY := 0.0;
			step := 100;
		END_IF

		100:
		IF currentPage <> 1 THEN
			step := 10;
		ELSE
			IF VA_Saccess( TRUE, vcHandle ) = 0 THEN
				drawX1 := LREAL_TO_UINT( (positionXOld+offsetX) * scale );
				drawY1 := 480 - 50 - LREAL_TO_UINT( (positionYOld+offsetY) * scale);
				drawX2 := LREAL_TO_UINT( (g_positionX+offsetX) * scale);
				drawY2 := 480 - 50 - LREAL_TO_UINT( (g_positionY+offsetY) * scale);
				VA_Line( TRUE, vcHandle, drawX1, drawY1, drawX2, drawY2, 10 );
				positionXOld := g_positionX;
				positionYOld := g_positionY;
				VA_Srelease( TRUE, vcHandle );
			END_IF
		END_IF

		

	END_CASE	


 
END_PROGRAM

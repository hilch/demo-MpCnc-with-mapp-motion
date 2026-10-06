
PROGRAM _CYCLIC

	(* M-Functions *)
	IF gMFunc_CutterDown THEN
		gMFunc_CutterDown := FALSE;
		color := 45;
	END_IF
	
	IF gMFunc_CutterUp THEN
		gMFunc_CutterUp := FALSE;
		color := 7;
	END_IF
	
	
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

			offsetX := 0.0;
			offsetY := 0.0;
			step := 100;
		END_IF

		100:
		IF currentPage <> 1 THEN
			step := 10;
		ELSE
			IF VA_Saccess( TRUE, vcHandle ) = 0 THEN
				IF VA_Attach( TRUE, vcHandle, 0, ADR('PageCncView/Default/DrawBox_1') ) = 0 THEN
					drawX1 := LREAL_TO_UINT( (positionXOld+offsetX) * scale );
					drawY1 := 380 - LREAL_TO_UINT( (positionYOld+offsetY) * scale);
					drawX2 := LREAL_TO_UINT( (g_positionX+offsetX) * scale);
					drawY2 := 380 - LREAL_TO_UINT( (g_positionY+offsetY) * scale);
					VA_Line( TRUE, vcHandle, drawX1, drawY1, drawX2, drawY2, color );
					positionXOld := g_positionX;
					positionYOld := g_positionY;
					VA_Detach( TRUE, vcHandle );
				END_IF
				VA_Srelease( TRUE, vcHandle );
			END_IF
		END_IF

		

	END_CASE	


 
END_PROGRAM

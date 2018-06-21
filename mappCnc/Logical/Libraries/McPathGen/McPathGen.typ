TYPE
	McPathGenPacketMonitorType : STRUCT (*Motion Packet Monitor*)
		InterpreterMPCount : UDINT; (**)
		InitializerMPCount : UDINT; (**)
		FinalizerMPCount : UDINT; (**)
		TrajectoryPlannerMPCount : UDINT; (**)
		MovementMPCount : UDINT; (**)
		NonMovementMPCount : UDINT; (**)
	END_STRUCT;

	McPathGenCondStopMonitorType : STRUCT (*Conditional Stop Monitor*)
		StopReached : BOOL; (**)
		StopIdent : UDINT; (**)
	END_STRUCT;

	McPathGenActiveLimitType : STRUCT (*Active Limit Monitor*)
		U : LREAL; (**)
		Index : UDINT; (**)
		Type : UDINT; (**)
		MinMax : UDINT; (**)
		BrakingType : UDINT; (**)
	END_STRUCT;

	McPathGenAxesType : STRUCT (*Axes*)
		JointAxis : ARRAY[0..9] OF LREAL; (**)
		PathAxis : ARRAY[0..9] OF LREAL; (**)
		NonTrfAxis : ARRAY[0..9] OF LREAL; (**)
	END_STRUCT;

	McPathGenAxesDynType : STRUCT (*Dynamics*)
		JointAxis : ARRAY[0..9] OF REAL; (**)
		PathAxis : ARRAY[0..9] OF REAL; (**)
		NonTrfAxis : ARRAY[0..9] OF REAL; (**)
	END_STRUCT;

	McPathGenInternalMonitorType : STRUCT (*Internal Monitor*)
		Enable : BOOL; (**)
		TicksWithNoData : UDINT; (**)
		SampleTimeFactor : REAL; (**)
		SpindleOverride : REAL; (**)
		HaltInfo : UDINT; (**)
		PacketType : UDINT; (**)
		FeedrateType : UDINT; (**)
		ProgrammedFeedrate : REAL; (**)
		PathPosition : LREAL; (**)
		PathVelocity : REAL; (**)
		PathAcceleration: REAL; (**)
		Velocity : McPathGenAxesDynType; (**)
		Acceleration : McPathGenAxesDynType; (**)
		MotionPacketMonitor : McPathGenPacketMonitorType; (**)
		ConditionalStopMonitor : McPathGenCondStopMonitorType; (**)
		ActiveLimit : McPathGenActiveLimitType; (**)
	END_STRUCT;

	McPathGenSimulationMonitorType : STRUCT (*Simulation Monitor*)
		IsActive : BOOL; (**)
		RunTime : LREAL; (**)
	END_STRUCT;

	McPathGenRestartMonitorType : STRUCT (*Restart Monitor*)
		Activated : BOOL; (**)
		Simulation : McPathGenSimulationMonitorType; (**)
	END_STRUCT;

	McPathGenBlockMonitorType : STRUCT (*Block Monitor*)
		Enable : BOOL; (**)
		InterpreterSyncDisplay : BOOL; (**)
		DisplayLineNumbers : BOOL; (**)
		BlockLast2 : STRING[80]; (**)
		BlockLast1 : STRING[80]; (**)
		BlockActual : STRING[80]; (**)
		BlockNext1 : STRING[80]; (**)
		BlockNext2 : STRING[80]; (**)
	END_STRUCT;

	McPathGenMonitorType : STRUCT (*Monitor*)
		Enable : BOOL; (**)
		ProgramName : STRING[80]; (**)
		BlockNumber : UDINT; (**)
		LineNumber : UDINT; (**)
		ProgramRunTime : LREAL; (**)
		MovementRunTime : LREAL; (**)
		DwellTime : LREAL; (**)
		DwellTimeRemaining : LREAL; (**)
		PositionMonitorMode : McCoordinateSystemEnum; (**)
		Position : McPathGenAxesType; (**)
		TargetPosition : McPathGenAxesType; (**)
		RemainingDistance : McPathGenAxesType; (**)
		SpindleVelocity : ARRAY[0..9] OF REAL; (**)
		Restart : McPathGenRestartMonitorType; (**)
		BlockMonitor : McPathGenBlockMonitorType; (**)
		InternalMonitor : McPathGenInternalMonitorType; (**)
	END_STRUCT;

	McPathGenMonElemPrgType : STRUCT (*Monitoring Element: Program*)
		FileName : STRING[260]; (**)
		FullPath : STRING[260]; (**)
		Number : UDINT; (**)
	END_STRUCT;

	McPathGenMonElemCurrentPrgType : STRUCT (*Monitoring Element: Current program*)
		FileName : STRING[260]; (**)
		FullPath : STRING[260]; (**)
		Number : UDINT; (**)
		CallLevel : UDINT; (**)
	END_STRUCT;

	McPathGenMonElemBlockMonType : STRUCT (*Monitoring Element: Block monitor*)
		BlockLast2 : STRING[260]; (**)
		BlockLast1 : STRING[260]; (**)
		BlockActual : STRING[260]; (**)
		BlockNext1 : STRING[260]; (**)
		BlockNext2 : STRING[260]; (**)
	END_STRUCT;

	McPathGenMonElemPrgSequenceType : STRUCT (*Monitoring Element: Nested program sequence*)
		CallLevel : UDINT; (**)
		Program : ARRAY [0..31] OF McPathGenMonElemPrgType; (**)
	END_STRUCT;

	McPathGenMonElemAxPositionsType : STRUCT (*Monitoring Element: Axes positions*)
		SetPosition : ARRAY [0..9] OF LREAL; (**)
	END_STRUCT;

	McPathGenMonElemPathSpeedType : STRUCT (*Monitoring Element: Programmed path speed*)
		UnitPerMinute : REAL; (**)
		UnitPerRevolution : REAL; (**)
		Inverse : REAL; (**)
	END_STRUCT;

	McPathGenMonElemToolTransType : STRUCT (*Monitoring Element: Tool description: Translation*)
		X : LREAL; (**)
		Y : LREAL; (**)
		Z : LREAL; (**)
	END_STRUCT;

	McPathGenMonElemToolOrientType : STRUCT (*Monitoring Element: Tool description: Orientation*)
		Angle1 : LREAL; (**)
		Angle2 : LREAL; (**)
		Angle3 : LREAL; (**)
	END_STRUCT;

	McPathGenMonElemToolDescType : STRUCT (*Monitoring Element: Tool description*)
		ToolTranslation : McPathGenMonElemToolTransType; (**)
		ToolOrientation : McPathGenMonElemToolOrientType; (**)
		ToolLength : LREAL; (**)
		ToolRadius : LREAL; (**)
		ToolVirtualToolTip : DINT; (**)
	END_STRUCT;

	McPathGenMonElemAxLimitsType : STRUCT (*Monitoring Element: Axis limits*)
	UpperPositionLimit : LREAL; (**)
	LowerPositionLimit : LREAL; (**)
	VelocityPositive : REAL; (**)
	VelocityNegative : REAL; (**)
	AccelerationPositive : REAL; (**)
	AccelerationNegative : REAL; (**)
	DecelerationPositive : REAL; (**)
	DecelerationNegative : REAL; (**)
	JerkAccelerationPositive : REAL; (**)
	JerkAccelerationNegative : REAL; (**)
	JerkDecelerationPositive : REAL; (**)
	JerkDecelerationNegative : REAL; (**)
	END_STRUCT;

	McPathGenMonElemAxTorquesType : STRUCT (*Monitoring Element: Torques*)
		Torques : ARRAY [0..9] OF LREAL; (**)
	END_STRUCT;

	McPathGenMonElemBasicMonType : STRUCT (*Monitoring Element: Basic monitor*)
		CurrentProgram : McPathGenMonElemCurrentPrgType; (**)
		LineNumber : UDINT; (**)
		BlockNumber : UDINT; (**)
		Runtime : LREAL; (**)
		PathSpeed : REAL; (**)
		Axes : McPathGenMonElemAxPositionsType; (**)
		TCPInMCS : McPathGenMonElemAxPositionsType; (**)
		SlaveAxes : McPathGenMonElemAxPositionsType; (**)
	END_STRUCT;
END_TYPE

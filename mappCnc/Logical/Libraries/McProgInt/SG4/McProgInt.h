/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _MCPROGINT_
#define _MCPROGINT_

#include <McBase.h>
#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#if defined(_WIN32) || defined(__WINDOWS__) || defined(__MINGW32__) || defined(__CYGWIN__)
#if defined(BUILD_MCPROGINT)
#define DECLSPEC_MCPROGINT __declspec(dllexport)
#else
#define DECLSPEC_MCPROGINT __declspec(dllimport)
#endif
#else	/* not Windows */
#define DECLSPEC_MCPROGINT _BUR_PUBLIC
#endif

/* Datatypes and datatypes of function blocks */
#ifdef __cplusplus
extern "C" {
#endif

/* NcIp error-codes */
#define MCPROGINT_ERROR_SUCCESS							0			/* No error */
#define MCPROGINT_ERROR_NOINTERFACE						0x80000004	/* No such interface supported */
#define MCPROGINT_ERROR_FAIL							0x80000008	/* Error */
#define MCPROGINT_ERROR_BUSY							0x9000ffff	/* Device or resource busy (AR 65535) */

/* NcIp command codes */
#define MCPROGINT_CMD_NC_START							1001	/* Start program */
#define MCPROGINT_CMD_NC_END							1002	/* End program - notification after path events completed */
#define MCPROGINT_CMD_NC_ABORT							1003	/* Program abort signal to interpreter */
#define MCPROGINT_CMD_BLOCK_START						1004	/* Start execution of text block */
#define MCPROGINT_CMD_MODAL_START						1006	/* Start program modal - search restart point (required previously IPCMD_RESTART_POINT) */

#define MCPROGINT_CMD_UNLOAD							1012	/* Unload a program*/
#define MCPROGINT_CMD_CNC_RECONFIG						1051	/* Tell interpreter to re-configure following a change of CNC axis setup */

#define MCPROGINT_CMD_RS_ON								1101	/* Activate restart*/
#define MCPROGINT_CMD_RS_OFF							1102	/* Deactivate restart*/
#define MCPROGINT_CMD_RESTART							1105	/* Restart of program*/

#define MCPROGINT_CMD_SYNC_PLC_CONT						1202	/* G170 - PLC synchronization */

#define MCPROGINT_CMD_IP_MODE							1302	/* Set execution mode: continuous/single-step-into/single-step-over */
#define MCPROGINT_CMD_IP_CONTINUE						1303    /* Continue program */

/* Command codes of commands to motion packet consumer  */
#define MCPROGINT_CMD_INTERRUPT_SS  					5000	/* Interpreter has been interrupted due to single step */
#define MCPROGINT_CMD_INTERRUPT_BRK  					5001	/* Interpreter has been interrupted due to breakpoint */

/* Call-backs codes */
#define MCPROGINT_CALLBACK_UNDEFINED					0		/* Undefined callback */
#define MCPROGINT_CALLBACK_ON_WAKEUP_MP_CLIENT			1		/* Wake-up motion packet consumer */
#define MCPROGINT_CALLBACK_ON_CMD_OK					2		/* Command successfully processed */
#define MCPROGINT_CALLBACK_ON_CMD_ERROR					3		/* Command rejected due to error */
#define MCPROGINT_CALLBACK_ON_CMD						4		/* Command to motion packet consumer */
#define MCPROGINT_CALLBACK_ON_DONE						5		/* Program successfully finished */
#define MCPROGINT_CALLBACK_ON_ERROR						6		/* Error message */

/* Standard definitions */
#define MCPROGINT_AX_NUMBER								15		/* Number of axes */

#define MCPROGINT_AXIS_NAME_LEN 						20		/* Max. length of axis name */
#define MCPROGINT_IP_CONFIG_NAME_LEN 					40		/* Max. length of name of main configuration file ('gmcipsys') */
#define MCPROGINT_FILE_MON_VAR_NAME_LEN 				32      /* Max. length of file monitor variable name */
#define MCPROGINT_FILE_NAME_LEN							128		/* Max filename length for loading programs from disk (including subdir path) */
#define MCPROGINT_BLOCK_TEXT_LEN						264		/* Max length of an NC block given on a IPCMD_BLOCK_START command packet */

/* Restarts */
#define MCPROGINT_RESTART_DATA_HEADER_SIZE				432		/* Size [bytes] of header of restart buffer */
#define MCPROGINT_RESTART_DATA_ELEMENT_SIZE				24		/* Size [bytes] of one element of restart buffer */

/* Restart/start position specification */
#define MCPROGINT_FILE_OFFSET							0
#define MCPROGINT_ABORT_LINE							0
#define MCPROGINT_PATH_DISTANCE							0
#define MCPROGINT_BLOCK_NUMBER							1
#define MCPROGINT_TOOL_NUMBER							2
#define MCPROGINT_LINE_NUMBER							4

/* Single step */
#define MCPROGINT_SINGLESTEP_INTO      					1  		/* Step into subprogram */
#define MCPROGINT_SINGLESTEP_OVER		 				2  		/* Step over subprogram */

/* Error message text */
#define MCPROGINT_ERR_MAX_LENGTH  						1000
#define MCPROGINT_SEVERITY_INFO							1
#define MCPROGINT_SEVERITY_WARNING						2
#define MCPROGINT_SEVERITY_ERROR						3

/* File Monitor - StorageType */
#define MCPROGINT_STORAGE_FILE_XL_MON 					9
#define MCPROGINT_STORAGE_DNC_MON 						8
#define MCPROGINT_STORAGE_INI_TMP 						7  		/* internally created, temporary file */
#define MCPROGINT_STORAGE_LCF_XML 						6  		/* internally created file */
#define MCPROGINT_STORAGE_FILE_XL 						5
#define MCPROGINT_STORAGE_DNC     						4
#define MCPROGINT_STORAGE_STRING  						3
#define MCPROGINT_STORAGE_MODULE  						2
#define MCPROGINT_STORAGE_FILE    						1
#define MCPROGINT_STORAGE_UNKNOWN 						0

/* Mode for execution of path-synchronous set of instruction */
#define MCPROGINT_EXEC_MODE_RUN              			0 		/* fully execute path-synchronous instruction */
#define MCPROGINT_EXEC_MODE_SIMULATE_RUN     			1 		/* simulate-only execution - mark job as done */
#define MCPROGINT_EXEC_MODE_RESTART_SIM_RUN  			2 		/* run in simulation of restart mode */

typedef struct
{
	plcstring ncblock_l2[264]; /* last x2 block */
	plcstring ncblock_l1[264]; /* last block */
	plcstring ncblock[264];    /* current block */
	plcstring ncblock_n1[264]; /* next block */
	plcstring ncblock_n2[264]; /* next x2 block */
} McProgIntBlockMonitorType;

typedef struct
{
	plcbit show_ip_synch;           /* show ip-synch instead of path-synch */
	plcbit show_line_nums;          /* show line numbers in monitor line text "num:line" */
	unsigned char show_brkpts;    	/* show breakpoint marks in monitor line text "<BRK[2]>", 0=off, 1=minimal"<BRK>", 2=detailed"<BRK[2]==5>" */
	plcbit unused[5];
} McProgIntBlockMonitorOptType;

typedef struct McProgIntAxisType
{
	plcstring Name[21];
} McProgIntAxisType;

typedef struct McProgIntAxesConfigType
{
	struct McProgIntAxisType Axis[15];
	unsigned long MechanicalSystem;
} McProgIntAxesConfigType;

typedef struct McProgIntIpConfigFileType
{
	plcstring Name[41];
} McProgIntIpConfigFileType;

typedef struct McProgIntFileMonitorConfigType
{
	plcstring VarName[33];
} McProgIntFileMonitorConfigType;

typedef struct McProgIntIpMonitorConfigType
{
	plcstring VarName[33];
} McProgIntIpMonitorConfigType;

typedef struct McProgIntEventLogType
{
	unsigned long EventLogAdr;
} McProgIntEventLogType;

typedef struct McProgIntMPLogType
{
	plcbit Enable;
} McProgIntMPLogType;

typedef struct McProgIntConfigType
{
	struct McProgIntAxesConfigType AxesCfg;
	struct McProgIntIpConfigFileType IpCfgFile;
	struct McProgIntFileMonitorConfigType FileMonitor;
	struct McProgIntIpMonitorConfigType IpMonitor;
	struct McProgIntEventLogType EventLog;
	struct McProgIntMPLogType MPLog;
	unsigned long PathGenIf;
} McProgIntConfigType;

typedef struct McProgIntErrorType
{
	unsigned int Code;
	unsigned int Severity;
	long EventId;
	plcstring Text[1001];
} McProgIntErrorType;

typedef struct McProgIntCmdOkType
{
	unsigned long Command;
} McProgIntCmdOkType;

typedef struct McProgIntCmdErrorType
{
	unsigned long Command;
	McProgIntErrorType Error;
} McProgIntCmdErrorType;

typedef struct McProgIntInterruptDataType
{
	unsigned long InterruptReason;                  /* Reason for Interruption */
	unsigned long LineNr;                          	/* Interrupt location: Line number */
	unsigned long BlockNr;                         	/* Interrupt location: NC Block number (0 if not programmed) */
	unsigned char FileName[128];    				/* Name of file  */
	unsigned char ProgName[128];    				/* Name of start/main program */
	unsigned char SubProgName[128]; 				/* Name of local subprogram */
} McProgIntInterruptDataType;

typedef union McProgIntCommandtDataUnion
{
	McProgIntInterruptDataType McProgIntInterruptData;
} McProgIntCommandtDataUnion;

typedef struct McProgIntCmdType
{
	unsigned long Command;
	McProgIntCommandtDataUnion* pData;
} McProgIntCmdType;

typedef struct McProgIntIpMonitorType
{
	plcbit Handshake;
	plcbit Reserve[3];
	plcstring StatusMsg[264];
	plcstring LastErrorMsg[120];
	unsigned short LastErrorCode;
	unsigned short LoadedProgCount;
	plcstring ProgName[264];
	plcstring NcblockL2[264];
	plcstring NcblockL1[264];
	plcstring Ncblock[264];
	plcstring NcblockN1[264];
	plcstring NcblockN2[264];
	unsigned long CurLineNum;
	unsigned long CurBlockNum;
	unsigned long LoadFreadTime;
	unsigned long LoadPrepTime;
	unsigned long LoadSepLinesTime;
	unsigned long LoadParseTime;
	unsigned long LoadParseLexTime;
	unsigned long BreakpointCount;
	unsigned long IpvarAccessCount;
	unsigned long ExecTime;
	unsigned long IdleTime;
	unsigned long NumParallelEvents;
	unsigned long ParallelCycleCount;
	plcstring ParallelActionText[12][264];
	unsigned long ParallelEvalCount[12];
	unsigned long ParallelExecCount[12];
	unsigned long NumFubsExecIpsynch;
	unsigned long NumFubsExecPpsynch;
	plcstring Callstack[12][264];
	unsigned long SharedMem_size;
	unsigned long IpMemSize;
	unsigned long IpCurFileMemSize;
	unsigned long SysFreeMem;
	unsigned long ReadingLineNum;
	unsigned long TranslatingLineNuM;
	unsigned long GeneratingAilLineNum;
	unsigned long ParsingAilLineNum;
	plcbit ParallelEnabled;
	plcbit ParallelRdisableSet;
	plcbit StopAtM1;
	plcbit Unused;
	plcstring CurProgFileName[264];
	plcstring CurProgName[264];
} McProgIntIpMonitorType;

typedef struct McProgIntFileMonitorEntryType
{
	plcstring *Name;                              	/* Name of loaded file */
	plcstring *PathName;                          	/* Full path file name */
	plcstring *DirName;                           	/* Directory name */
	plcstring *DeviceName;                        	/* File device name */
	unsigned long ProgramNumber;             		/* Program number */
	unsigned long StorageType;               		/* Storage type */
	unsigned long TimeStamp;                 			/* File time stamp */
	plcbit PrecompiledLCF;            				/* Loaded file is language configuration file */
	struct McProgIntFileMonitorEntryType *Next;  	/* Next element in file list */
} McProgIntFileMonitorEntryType;

typedef struct McProgIntFileMonitorAccessType
{
	plcbit Valid;                     				/* Data are valid and can be accessed */
	McProgIntFileMonitorEntryType *First;        	/* First element of file list */
} McProgIntFileMonitorAccessType;

typedef struct McProgIntFileMonitorLineType
{
	plcstring Name[32];       						/* Name of loaded file */
	unsigned long ProgramNumber;             		/* Program number; automatic if allowed, or dafault/user defined */
	unsigned long StorageType;               		/* Storage type */
} McProgIntFileMonitorLineType;

typedef struct McProgIntFileMonitorType
{
	plcbit Handshake;                 				/* Handshake - set to request data refresh, data valid after zero */
	unsigned long SetOffset;                 		/* Set offset */
	unsigned long Offset;                    		/* Offset of currently displayed files */
	McProgIntFileMonitorLineType File[32]; 			/* File monitor */
	McProgIntFileMonitorAccessType DirectAccess; 	/* Access to extended data */
} McProgIntFileMonitorType;

typedef struct McToolType
{
	unsigned long  Index;
	struct McFrameType Frame;
	double Radius;
} McToolType;


typedef double McSlaveAxisType[15];

typedef struct McPointType
{
	struct McPosType Pos;
	struct McOrientType Orient;
	McSlaveAxisType SlaveAxis;
} McPointType;

typedef double McJointAxisType[6];

typedef struct McAxisTargetType
{
	McJointAxisType JointAxis;
	McSlaveAxisType SlaveAxis;
} McAxisTargetType;

typedef double McRotationMatrixType[9];

typedef struct McLatchPositionsType
{
	plcbit TriggerEvent;
	unsigned long CoordSystem;
	double Position[15];
} McLatchPositionsType;

/* Prototyping of functions and function blocks */
DECLSPEC_MCPROGINT signed long McProgIntCreateIpInstance(const plcstring* Name, UDINT ConfigAdr, unsigned long* Ident);
DECLSPEC_MCPROGINT signed long McProgIntSimulateMPConsumer(unsigned long Ident, unsigned long Mode);
DECLSPEC_MCPROGINT signed long McProgIntRegisterCallback(unsigned long Ident, unsigned long CallbackID, unsigned long FunPtr, unsigned long Context);
DECLSPEC_MCPROGINT signed long McProgIntGetVarValue(unsigned long Ident, plcstring* VariableName, plcstring* FileName, unsigned long ValueAdr, unsigned long Size);
DECLSPEC_MCPROGINT signed long McProgIntSetVarValue(unsigned long Ident, plcstring* VariableName, plcstring* FileName, unsigned long ValueAdr, unsigned long Size);
DECLSPEC_MCPROGINT signed long McProgIntRunExternalProgram(unsigned long Ident, plcstring* Name, unsigned long TimeLimit);
DECLSPEC_MCPROGINT signed long McProgIntStartProgram(unsigned long Ident, plcstring* Name,  plcstring* InitProgramName, unsigned short StartPointType, unsigned long StartPointParameter);
DECLSPEC_MCPROGINT signed long McProgIntUnloadProgram(unsigned long Ident, plcstring* Name, plcbit UnloadAll);


#ifdef __cplusplus
} // End of C-Linkage
#endif
#endif /* _MCPROGINT_ */


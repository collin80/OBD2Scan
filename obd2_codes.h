 enum SERVICE_CODES
 {
    OBDII_SHOW_CURRENT = 1,
    OBDII_SHOW_FREEZE = 2,
    OBDII_SHOW_STORED_DTC = 3,
    OBDII_CLEAR_DTC = 4,
    OBDII_TEST_O2 = 5,
    OBDII_TEST_RESULTS = 6,
    OBDII_SHOW_PENDING_DTC = 7,
    OBDII_CONTROL_DEVICES = 8,
    OBDII_VEHICLE_INFO = 9,
    OBDII_PERM_DTC = 0xA,
    UDS_DIAG_CTRL = 0x10,
    UDS_ECU_RESET = 0x11,
    UDS_GMLAN_READ_FAILURE_REC = 0x12,
    UDS_CLEAR_DIAG = 0x14,
    UDS_READ_DTC = 0x19,
    UDS_GMLAN_READ_DIAG_ID = 0x1A,
    UDS_RETURN_TO_NORMAL = 0x20,
    UDS_READ_BY_ID = 0x22,
    UDS_READ_BY_ADDR = 0x23,
    UDS_READ_SCALING_ID = 0x24,
    UDS_SECURITY_ACCESS = 0x27,
    UDS_COMM_CTRL = 0x28,
    UDS_READ_ID_PERIODIC = 0x2A,
    UDS_DYNAMIC_DATA_DEF = 0x2C,
    UDS_DEFINE_PID_BY_ADDR = 0x2D,
    UDS_WRITE_BY_ID = 0x2E,
    UDS_IO_CTRL = 0x2F,
    UDS_ROUTINE_CTRL = 0x31,
    UDS_REQ_DOWNLOAD = 0x34,
    UDS_REQ_UPLOAD = 0x35,
    UDS_TRANSFER_DATA = 0x36,
    UDS_REQ_TRANS_EXIT = 0x37,
    UDS_REQ_FILE_TRANS = 0x38,
    UDS_GMLAN_WRITE_DID = 0x3B,
    UDS_WRITE_BY_ADDR = 0x3D,
    UDS_TESTER_PRESENT = 0x3E,
    UDS_NEG_RESP = 0x7F,
    UDS_ACCESS_TIMING = 0x83,
    UDS_SECURED_DATA_TRANS = 0x84,
    UDS_CTRL_DTC_SETTINGS = 0x85,
    UDS_RESP_ON_EVENT = 0x86,
    UDS_RESP_LINK_CTRL = 0x87,
    UDS_GMLAN_REPORT_PROG_STATE = 0xA2,
    UDS_GMLAN_ENTER_PROG_MODE = 0xA5,
    UDS_GMLAN_CHECK_CODES = 0xA9,
    UDS_GMLAN_READ_DPID = 0xAA,
    UDS_GMLAN_DEVICE_CTRL = 0xAE
 };
 
 enum VEHICLE_INFO_CODES
 {
     VI_SUPPORTED_PIDS = 0,
     VI_VIN_MSG_COUNT = 1,
     VI_VIN = 2,
     VI_CALIB_COUNT = 3,
     VI_CALIB_ID = 4,
     VI_CALIB_VERIFY_COUNT = 5,
     VI_CALIB_VERIFY = 6,
     VI_INUSE_PERF_TRACK_COUNT = 7,
     VI_INUSE_PERF_TRACK_GAS = 8,
     VI_ECU_NAME_COUNT = 9,
     VI_ECU_NAME = 0xA,
     VI_INUSE_PERF_TRACK_DIESEL = 0xB
 };

 enum STANDARD_PID_CODES
 {
    PID_SUPPORTED1 = 0,
    PID_MON_STATUS_SINCE_CLEARED = 1,
    PID_FREEZE_DTC = 2,
    PID_FUEL_SYS_STATUS = 3,
    PID_CALC_ENGINE_LOAD = 4,
    PID_ENGINE_COOLANT_TEMP = 5,
    PID_SHORT_FUEL_TRIM1 = 6,
    PID_LONG_FUEL_TRIM1 = 7,
    PID_SHORT_FUEL_TRIM2 = 8,
    PID_LONG_FUEL_TRIM2 = 9,
    PID_FUEL_PRESSURE = 0xA,
    PID_INTAKE_MAP = 0xB,
    PID_ENGINE_RPM = 0xC,
    PID_VEHICLE_SPEED = 0xD,
    PID_TIMING_ADV = 0xE,
    PID_INTAKE_AIR_TEMP = 0xF,
    PID_MAF_RATE = 0x10,
    PID_THROTTLE_POS = 0x11,
    PID_SEC_AIR_STATUS = 0x12,
    PID_O2_SENSORS = 0x13,
    PID_O2SENSOR_B1S1 = 0x14,
    PID_O2SENSOR_B1S2 = 0x15,
    PID_O2SENSOR_B1S3 = 0x16,
    PID_O2SENSOR_B1S4 = 0x17,
    PID_O2SENSOR_B2S1 = 0x18,
    PID_O2SENSOR_B2S2 = 0x19,
    PID_O2SENSOR_B2S3 = 0x1A,
    PID_O2SENSOR_B2S4 = 0x1B,
    PID_ODB2_VER = 0x1C,
    PID_O2SENSORS_BITFIELD = 0x1D,
    PID_AUX_INPUT = 0x1E,
    PID_TIME_SINCE_START = 0x1F,
    PID_SUPPORTED2 = 0x20,
    PID_MIL_DISTANCE = 0x21,
    PID_FUEL_RAIL_PRESSURE = 0x22,
    PID_FUEL_RAIL_DIESEL = 0x23,
    PID_O2S1_LAMDBA = 0x24,
    PID_O2S2_LAMDBA = 0x25,
    PID_O2S3_LAMDBA = 0x26,
    PID_O2S4_LAMDBA = 0x27,
    PID_O2S5_LAMDBA = 0x28,
    PID_O2S6_LAMDBA = 0x29,
    PID_O2S7_LAMDBA = 0x2A,
    PID_O2S8_LAMDBA = 0x2B,
    PID_CMD_EGR = 0x2C,
    PID_EGR_ERR  = 0x2D,
    PID_CMD_EVAP  = 0x2E,
    PID_FUEL_LEVEL  = 0x2F,
    PID_WARMUPS_SINCE_CLEAR  = 0x30,
    PID_DISTANCE_SINCE_CLEAR  = 0x31,
    PID_EVAP_PRESSURE  = 0x32,
    PID_ATMOS_PRESSURE  = 0x33,
    PID_O2S1_CURRENT  = 0x34,
    PID_O2S2_CURRENT  = 0x35,
    PID_O2S3_CURRENT = 0x36,
    PID_O2S4_CURRENT = 0x37,
    PID_O2S5_CURRENT = 0x38,
    PID_O2S6_CURRENT = 0x39,
    PID_O2S7_CURRENT = 0x3A,
    PID_O2S8_CURRENT = 0x3B,
    PID_CAT_TEMP_B1S1 = 0x3C,
    PID_CAT_TEMP_B1S2 = 0x3D,
    PID_CAT_TEMP_B2S1 = 0x3E,
    PID_CAT_TEMP_B2S2 = 0x3F,
    PID_SUPPORTED3 = 0x40,
    PID_MONITOR_STATUS = 0x41,
    PID_CTRL_VOLTS = 0x42,
    PID_ABS_LOAD = 0x43,
    PID_CMD_EQUIV = 0x44,
    PID_REL_THROTTLE = 0x45,
    PID_AMB_TEMP = 0x46,
    PID_ABS_THROTTLE_B = 0x47,
    PID_ABS_THROTTLE_C = 0x48,
    PID_ABS_THROTTLE_D = 0x49,
    PID_ABS_THROTTLE_E = 0x4A,
    PID_ABS_THROTTLE_F = 0x4B,
    PID_CMD_THROTTLE_ACTUATOR = 0x4C,
    PID_TIME_RUN_MIL = 0x4D,
    PID_TIME_SINCE_DTC_CLEAR = 0x4E,
    PID_FUEL_TYPE = 0x51,
    PID_ETHANOL_FUEL_PERC = 0x52,
    PID_ABS_EVAP_PRESS = 0x53,

 };

/* other PID codes not implemented yet.
54	Evap system vapor pressure	
55	Short term secondary oxygen sensor trim, A: bank 1, B: bank 3	
56	Long term secondary oxygen sensor trim, A: bank 1, B: bank 3
57	Short term secondary oxygen sensor trim, A: bank 2, B: bank 4
58	Long term secondary oxygen sensor trim, A: bank 2, B: bank 4
59	Fuel rail absolute pressure
5A	Relative accelerator pedal position
5B	Hybrid battery pack remaining life
5C	Engine oil temperature	
5D	Fuel injection timing		
5E	Engine fuel rate
5F	Emission requirements to which vehicle is designed
60	PIDs supported [61 - 80]
61	Driver's demand engine - percent torque
62	Actual engine - percent torque
63	Engine reference torque
64	Engine percent torque data
65	Auxiliary input / output supported
66	Mass air flow sensor				
67	Engine coolant temperature				
68	Intake air temperature sensor				
69	Commanded EGR and EGR Error				
6A	Commanded Diesel intake air flow control and relative intake air flow position				
6B	Exhaust gas recirculation temperature				
6C	Commanded throttle actuator control and relative throttle position				
6D	Fuel pressure control system				
6E	Injection pressure control system				
6F	Turbocharger compressor inlet pressure				
70	Boost pressure control				
71	Variable Geometry turbo (VGT) control				
72	Wastegate control				
73	Exhaust pressure				
74	Turbocharger RPM				
75	Turbocharger temperature				
76	Turbocharger temperature				
77	Charge air cooler temperature (CACT)				
78	Exhaust Gas temperature (EGT) Bank 1
79	Exhaust Gas temperature (EGT) Bank 2
7A	Diesel particulate filter (DPF)				
7B	Diesel particulate filter (DPF)				
7C	Diesel Particulate filter (DPF) temperature				
7D	NOx NTE (Not-To-Exceed) control area status				
7E	PM NTE (Not-To-Exceed) control area status				
7F	Engine run time				
80	PIDs supported [81 - A0]
81	Engine run time for Auxiliary Emissions Control Device(AECD)				
82	Engine run time for Auxiliary Emissions Control Device(AECD)				
83	NOx sensor				
84	Manifold surface temperature				
85	NOx reagent system				
86	Particulate matter (PM) sensor				
87	Intake manifold absolute pressure				
A0	PIDs supported [A1 - C0]
C0	PIDs supported [C1 - E0]
*/
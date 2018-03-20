

//
//  MIOCommonType.h
//  
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#ifndef __MIO_COMMON_TYPE_H__
#define __MIO_COMMON_TYPE_H__

#import "ADLDailyData.h"
#import "Alpha2RecordData.h"

#if !defined(LITTLE_ENDIAN)
#define LITTLE_ENDIAN
#endif


//////////////////////////////////////////////////////////////////////////////////
// Public Definitions
//////////////////////////////////////////////////////////////////////////////////

#if !defined(TRUE)
#define TRUE                           1
#endif

#if !defined(FALSE)
#define FALSE                          0
#endif

#if !defined(NULL)
#define NULL                           ((void *) 0)
#endif

#ifndef MAX_UCHAR
#define MAX_UCHAR                      ((UCHAR) 0xFF)
#endif

#ifndef MAX_SCHAR
#define MAX_SCHAR                      0x7F
#endif

#ifndef MIN_SCHAR
#define MIN_SCHAR                      0x80
#endif


#ifndef MAX_SHORT
#define MAX_SHORT                      0x7FFF
#endif

#ifndef MIN_SHORT
#define MIN_SHORT                      0x8000
#endif

#ifndef MAX_USHORT
#define MAX_USHORT                     0xFFFF
#endif

#ifndef MAX_SSHORT
#define MAX_SSHORT                     0x7FFF
#endif

#ifndef MIN_SSHORT
#define MIN_SSHORT                     0x8000
#endif

#ifndef MAX_LONG
#define MAX_LONG                       0x7FFFFFFF
#endif

#ifndef MIN_LONG
#define MIN_LONG                       0x80000000
#endif

#ifndef MAX_ULONG
#define MAX_ULONG                      0xFFFFFFFF
#endif

#ifndef MAX_SLONG
#define MAX_SLONG                      0x7FFFFFFF
#endif

#ifndef MIN_SLONG
#define MIN_SLONG                      0x80000000
#endif


#ifndef OBJC_BOOL_DEFINED
typedef unsigned char                  BOOL;
#endif

#ifndef _UCHAR_T
#define _UCHAR_T
typedef unsigned char                  UCHAR;
#endif /* _UCHAR_T */

#ifndef _BYTE_T
#define _BYTE_T
typedef unsigned char                  BYTE;
#endif /* _BYTE_T */

#ifndef _SCHAR_T
#define _SCHAR_T
typedef signed char                    SCHAR;
#endif /* _SCHAR_T */

#ifndef _SHORT_T
#define _SHORT_T
typedef short                          SHORT;
#endif /* _SHORT_T */

#ifndef _USHORT_T
#define _USHORT_T
typedef unsigned short                 USHORT;
#endif /* _USHORT_T */

#ifndef _SSHORT_T
#define _SSHORT_T
typedef signed short                   SSHORT;
#endif /* _SSHORT_T */

#ifndef _LONG_T
#define _LONG_T
typedef long                           LONG;
#endif /* _LONG_T */

#ifndef _ULONG_T
#define _ULONG_T
typedef unsigned long                  ULONG;
#endif /* _ULONG_T */

#ifndef _SLONG_T
#define _SLONG_T
typedef signed long                    SLONG;
#endif /* _SLONG_T */

#ifndef _UINT64_T
#define _UINT64_T
typedef unsigned long long             UINT64;
#endif /* _UINT64_T */

#ifndef _SINT64_T
#define _SINT64_T
typedef signed long long               SINT64;
#endif /* _SINT64_T */

#ifndef _FLOAT_T
#define _FLOAT_T
typedef float                          FLOAT;
#endif /* _FLOAT_T */

#ifndef _DOUBLE_T
#define _DOUBLE_T
typedef double                         DOUBLE;
#endif /* _DOUBLE_T */


//
//the macro defined: the HR zone type of MIO device.
//
typedef enum {
    FIVE_ZONES=0,
    THREE_ZONES
}HRZoneType_t;

typedef enum {
    TZ1=0,
    TZ2,
    TZ3,
    TZ4,
    TZ5,
    AllTZ
}HRTargetZone_t;

//
//LED Alert cycle.
//
typedef enum {
    LED_ALWAYS_ON = 3,
    LED_ALERT_1S = 2,
    LED_ALERT_2S = 1,
    LED_ALERT_DEFAULT = 0   // 2 S
    
}LEDAlertCycle_t;



//
//the macro defined: the ANT+ state of the MIO ble device.
//
typedef enum {
    ANTPLUS_ENBALE,
    ANTPLUS_DISABLE
}ANTPlusState_t;



//
//RTC for Link, Velo.
//
struct  RTCtime{
    BYTE second;
    BYTE minute;
    BYTE hour;
};
typedef struct RTCtime RTCtime;

/**
 *the struct define:  5 training zone settings, only used for MIO ble device.
 
  1 count = 1BPM, 5 training zones are defined as:
  HRLimit0 <= TZ1 < HRLimit1
  HRLimit1 <= TZ2 < HRLimit2
  HRLimit2 <= TZ3 < HRLimit3
  HRLimit3 <= TZ4 < HRLimit4
  HRLimit4 <= TZ5
*/
struct HR5ZoneSettings{
    HRTargetZone_t TargetZone;
    short int HRLimit0;
    short int HRLimit1;
    short int HRLimit2;
    short int HRLimit3;
    short int HRLimit4;
};
typedef struct HR5ZoneSettings HR5ZoneSettings;

struct HR3ZoneSettings{
    short int HRLowerLimit;
    short int HRUpperLimit;
};
typedef struct HR3ZoneSettings HR3ZoneSettings;



//Heart rate zone setting.
struct HRZone{
    HRZoneType_t    type;
    
    BOOL            ANTPlusTXEnable;
    BOOL            HRAlertAudioEnable;
    BOOL            HRAlertLEDEnable;
    BOOL            HRAlertVibroEnable;
    BOOL            HRHijackEnable;
    
    LEDAlertCycle_t   LEDAlertCycle;
    
    HR5ZoneSettings zone5;
    HR3ZoneSettings zone3;
    
    BYTE            MHR;    //only valid for Velo or LINK(more than v1.16).
};
typedef struct HRZone HRZone;


/** Describes the state of MIO Command execution. */
typedef enum
{
	/** The commond is success. */
	MIO_RESPONSE_CODE_SUCCESS                = 0,
    
	/** The commond is fail. */
	MIO_RESPONSE_CODE_FAIL                   = 0x01,
    
	/** The commond is timeout. */
	MIO_RESPONSE_CODE_TIMEOUT                = 0x02,
    
	/** The connection is interrupted. */
	MIO_RESPONSE_CODE_INTERRUPTED            = 0x04,
    
    
    
} MIOResponseCode_t;


/** Describes the error code of function return. */
typedef enum
{
    
    //no error.
    MIO_ERRCODE_NOERROR                     = 0,
    
	/** The command is fail. */
	MIO_ERRCODE_FAIL                        = 0x01,
    
	/** The commond is timeout. */
	MIO_ERRCODE_TIMEOUT                     = 0x02,
    
	/** The connection is not connected or interrupted. */
	MIO_ERRCODE_NOT_CONNECTED               = 0x03,
    
    /* The parameter is invalid. */
    MIO_ERRCODE_PARAMETER_INVALID           = 0x04,
    
    /* The device don't support the function */
    MIO_ERRCODE_DONOT_SUPPORT               = 0x05,
    
    /* don't config bike's wheel circuference */
    MIO_ERRCODE_DONOT_KNOW_WHEEK_CIRCUFERENCE       = 0x06,
    
    /* don't have any record */
    MIO_ERRCODE_NO_RECORD                   = 0x07,
    
    /* waiting for response of previous command */
    MIO_ERRCODE_WAITING_FOR_RESP            = 0x08,
    
    /* don't any Ant sensor   */
    MIO_ERRCODE_NO_ANT_SENSOR               = 0x09,
    
    /*  don't notification For characteristic  */
    MIO_ERRCODE_NO_NOTIFY_CHARACTERISTIC               = 0x10,
    
    /* don't have valid data    */
    MIO_ERRCODE_NO_VALIDDATA                = 0x11,
    
    /* enter SYNC mode already    */
    MIO_ERRCODE_ENTERED_SYNC_ALREADY        = 0x12,
    
    
    /* don't allow to end SYNC if is syncing record    */
    MIO_ERRCODE_DONOT_ALLOW_END_SYNC        = 0x13,
    
    MIO_ERRCODE_INVALIDDATA                 = 0x14,
    
    /* not in workout mode */
    MIO_ERRCODE_NOTINWORKOUTMODE            = 0x15,
    
    MIO_ERRCODE_BLUETOOTHERR                = 0x16,
    
} MIOErrorCode_t;


/** Describes the state of the ble device. */
typedef enum
{
    // The ble device is initing.
    MIO_DEVICE_STATE_IS_INITING                    = 0x0,
    
	/** The ble device is init completed. */
	MIO_DEVICE_STATE_INIT_COMPLETED                = 0x01,
    
	/** The ble device's infomation is ready. */
	MIO_DEVICE_STATE_DEVINFO_READY                 = 0x02,

} MIODeviceState_t;



/** Describes the state of the ble hardware. */
typedef enum
{
	/** The ble device is not physically connected to the iphone. */
	MIO_HWCONN_STATE_NOT_CONNECTED                = 0,
	/** The ble device is physically connected to the iphone. */
	MIO_HWCONN_STATE_CONNECTED                    = 0x01,
	/** The ble device is connected and communication is established (norml operating mode). */
	MIO_HWCONN_STATE_ACTIVE                       = 0x02,
	/** The ble device is performing a reset operation. */
	MIO_HWCONN_STATE_RESET                        = 0x04,
    /** The BTLE hardware is enabled. */
    MIO_HWCONN_STATE_BT40_ENABLED                 = 0x08,
    /** The BTLE controller is in bonding mode. */
    MIO_HWCONN_STATE_BT_BONDING_MODE              = 0x10,
	
} MIOHardwareState_t;


/** Describes the connection state of an BLE sensor. */
typedef enum
{
    /** No active connection. */
	MIO_SENSOR_CONNECTION_STATUS_IDLE,
    /** The connection is in process of being established. */
	MIO_SENSOR_CONNECTION_STATUS_CONNECTING,
    /** The sensor connection is established and active. */
	MIO_SENSOR_CONNECTION_STATUS_CONNECTED,
    /** The connection was interrupted . */
    MIO_SENSOR_CONNECTION_STATUS_INTERRUPTED,
    /** The connection is in process of being disconnected. */
	MIO_SENSOR_CONNECTION_STATUS_DISCONNECTING,
	
} MIODeviceConnectionStatus_t;

/**
 * Describes a type of hardware sensor device.
 */
typedef enum
{
	/** Specifies non-existent sensor. */
	MIO_SENSORTYPE_NONE                           = 0,
	/** Specifies the bike power sensor. */
	MIO_SENSORTYPE_BIKE_POWER                     = 0x00000001,
	/** Specifies the bike speed sensor. */
	MIO_SENSORTYPE_BIKE_SPEED                     = 0x00000002,
	/** Specifies the bike cadence sensor. */
	MIO_SENSORTYPE_BIKE_CADENCE                   = 0x00000004,
	/** Specifies the combined bike speed and cadence sensor. */
	MIO_SENSORTYPE_BIKE_SPEED_CADENCE             = 0x00000008,
	/** Specifies the FootPod stride and distance sensor. */
	MIO_SENSORTYPE_FOOTPOD                        = 0x00000010,
	/** Specifies the heart rate monitor sensor. */
	MIO_SENSORTYPE_HEARTRATE                      = 0x00000020,
	/** Specifies the Weight Scale monitor sensor */
	MIO_SENSORTYPE_WEIGHT_SCALE                   = 0x00000040,
	/** Specifies a generic ANT FS device. */
	MIO_SENSORTYPE_ANT_FS                         = 0x00000080,
	/** Specifies the GPS location sensor. */
	MIO_SENSORTYPE_LOCATION                       = 0x00000100,
	/** Specifies the calorimeter sensor. */
	MIO_SENSORTYPE_CALORIMETER                    = 0x00000200,
	/** Specifies the GeoCache sensor. */
	MIO_SENSORTYPE_GEO_CACHE                      = 0x00000400,
	/** Specifies the Fitness Equipment sensor. */
	MIO_SENSORTYPE_FITNESS_EQUIPMENT              = 0x00000800,
    /** Specifies the Multi-Sport Speed and Distance sensor. */
    MIO_SENSORTYPE_MULTISPORT_SPEED_DISTANCE      = 0x00001000,
    /** Specifies the BTLE Proximity sensor. */
    MIO_SENSORTYPE_PROXIMITY                      = 0x00002000,
    /** Specifies the BTLE Health Thermometer sensor. */
    MIO_SENSORTYPE_HEALTH_THERMOMETER             = 0x00004000,
    /** Specifies the BTLE Blood Pressure sensor. */
    MIO_SENSORTYPE_BLOOD_PRESSURE                 = 0x00008000,
    /** Specifies the BTLE Blood Glucose Monitor sensor. */
    MIO_SENSORTYPE_BTLE_GLUCOSE                   = 0x00010000,
    /** Specifies the ANT+ Blood Glucose Monitor sensor. */
    MIO_SENSORTYPE_GLUCOSE                        = 0x00020000,
    
    //Add for OTA update device, by 2014-03-22.
    //MIO_OTA_UPDATE_DEVICE                         = 0x00040000,
    

    
    
} MIOSensorType_t;


/**
 * Describes a type of MIO Device
 */
typedef enum
{
    MIO_DEV_TYPE_UNKNOWN                          = 0x0,
    
    MIO_DEV_TYPE_ALPHA                            = 0x00000001,
    
    MIO_DEV_TYPE_LINK                            = 0x00000002,
    
    MIO_DEV_TYPE_VELO                             = 0x00000004,
    
    MIO_DEV_TYPE_FUSE                             = 0x00000008,
    
    MIO_DEV_TYPE_ALPHA2                           = 0x00000010,


} MIODeviceType_t;


//FUSE firmware version.
#define FUSE_FM_INITIAL                 0
#define FUSE_FM_0108_ABOVE              1



/** Describes an error encountered during an attempt to establish a connection. */
typedef enum
{
    /** No error has occured. */
    MIO_SENSOR_CONN_ERROR_NONE  = 0,
    /** Failed to retrieve the specified paired sensor. */
    MIO_SENSOR_CONN_ERROR_PAIRED_DEVICE_NOT_AVAILABLE,
    /**
     * Occurs when an attempt is made to initiate a proximity search while a
     * sensor of the specified type is currently connected to the phone.
     */
    MIO_SENSOR_CONN_ERROR_PROXIMITY_SEARCH_WHILE_CONNECTED,
    /**
     * Occurs on a conditional connection when no new data is available from the
     * device.
     */
    MIO_SENSOR_CONN_ERROR_NO_NEW_DATA,
    /**
     * Occurs when there has been no activity on the connection for the duration
     * of the connection activity timeout.
     *
     * @note The activity timeout is device-type-specific and is not used on devices
     * which require constant data updates.
     */
    MIO_SENSOR_CONN_ERROR_ACTIVITY_TIMEOUT,
    
    //there is error when connect to a peripheral.
    MIO_SENSOR_CONN_ERROR_FAILED_TO_CONNECT,
    
    //there is error when discovery serivces.
    MIO_SENSOR_CONN_ERROR_DISCOVERY_SERVICES,
    
    //there is error when discovery characteristic
    MIO_SENSOR_CONN_ERROR_DISCOVERY_CHARACTERISTICS,
    
    
} MIODeviceConnectionError_t;


//
//OTA state:
//
typedef enum
{
    INIT,
    DISCOVERING,
    IDLE,
    SEND_NOTIFICATION_REQUEST,
    SEND_START_COMMAND,
    SEND_RECEIVE_COMMAND,
    SEND_FIRMWARE_DATA,
    SEND_VALIDATE_COMMAND,
    SEND_RESET,
    WAIT_RECEIPT,
    FINISHED,
    CANCELED,
} MIO_DFUControllerState_t;


typedef enum
{
    CONNETING=1,
    CONNETED,
    SEARCHSERVICE,
    SEARCHSERVICECOMPLETED,
    SEARCHCHARACTERISTIC,
    ENABLECHCHARACTERISTIC,
    ENABLECHCHARACTERISTICCOMPLETED,
    OPENSESSIONSTART,
    OPENSESSIONOK,
    REQUESTWRITEFIRMWARE,
    REQUESTWRITEFIRMWAREOK,
    ERRORINDEXPACKET,
    WRITEFIRMWARECOMPLETED,
    ENABLECHCHARACTERISTICFAIL,
} MIO_OTAState_t;


/** Describes the data type */
typedef enum
{
    
	MIO_DATATYPE_HR                          = 0x01,
    
	MIO_DATATYPE_RSSI                        = 0x02,
    
	MIO_DATATYPE_BIKESENSOR                  = 0x04,
    
    MIO_DATATYPE_RUN_SPEED_CADENCE           = 0x08,
    
    MIO_DATATYPE_RHR                         = 0x10,
    
    MIO_DATATYPE_HRV                         = 0x20,
    
} MIODataType_t;


#if 0
/** Describes the bike sensor type */
typedef enum
{
	MIO_BIKE_SPEED_TYPE                           = 0x01,
    
	MIO_BIKE_CADENCE_TYPE                        = 0x02,
    
	MIO_BIKE_SPEEDCADENCE_TYPE                   = 0x03,
    
    MIO_BIKE_POWER_TYPE                           = 0x04,
    
} MIOBikeSensorType_t;
#endif




/** Describes the bike sensor chanel */
typedef enum
{
    MIO_BIKE_ALL_CHANNEL_OFF             = 0x0,
    
	MIO_BIKE_SPEED_CHANNEL               = 0x01,
    
	MIO_BIKE_CADENCE_CHANNEL             = 0x02,
    
	MIO_BIKE_SPEEDCADENCE_CHANNEL        = 0x04,
    
    MIO_BIKE_POWER_CHANNEL               = 0x08,
    
} MIOBikeSensorChannel_t;


/** Describes the bike sensor data present  */
typedef enum
{
	MIO_BIKE_WHEEL_DATA                        = 0x01,
    
	MIO_BIKE_CRANK_DATA                        = 0x02,
    
} MIOBikeSensorDataFlag_t;


typedef enum
{
    MIO_BIKE_AUTOMATCH                = 0x0,
    
	MIO_BIKE_INDEX1                   = 0x01,
    
	MIO_BIKE_INDEX2                   = 0x02,
    
	MIO_BIKE_INDEX3                   = 0x03,
    
    MIO_BIKE_INDEX4                   = 0x04,
    
} MIOBikeIndex_t;

typedef enum
{
	MIO_VELO_APP_MIO                   = 0x0,
    
    MIO_VELO_APP_WAHOO                 = 0x1,
    
} MIOVeloAppType_t;



#if 0
/** Describes the bike sensor data struct */
struct BikeSensorData{
    
    //data present flag
    MIOBikeSensorDataFlag_t flags;
        
    //speed sensor data.
    uint32_t    WheelRevolutions;//圈数
    uint16_t    LastWheelEvtTime;//数据 1/1024 s
    
    //cadence sensor data.
    uint16_t    CrankRevolutions;
    uint16_t    LastCrankEvtTime;
    
};
typedef struct BikeSensorData BikeSensorData;
#endif

/** Describes the bike sensor data struct */
struct BikeSensorRawData{
    
    //data present flag
    MIOBikeSensorDataFlag_t flags;
    
    //speed sensor data.
    uint32_t    WheelRevolutions;
    uint16_t    LastWheelEvtTime;
    
    //cadence sensor data.
    uint16_t    CrankRevolutions;
    uint16_t    LastCrankEvtTime;
    
};
typedef struct BikeSensorRawData BikeSensorRawData;


/** Describes the bike sensor data struct */
struct BikeSensorData{
    
    //data present flag
    BOOL        isSpeedValid;
    BOOL        isRPMValid;
    BOOL        isDistValid;
    
    //sensor data.
    uint32_t    speedValue;     //KM/H
    uint32_t    RPMValue;
    uint32_t    DistanceValue;
    
};
typedef struct BikeSensorData BikeSensorData;


/** Describes the device status  data struct */
struct MioDeviceStatus{
    
    BOOL        IsStreamModeActive;
    BOOL        IsGPSModeActive;
    BOOL        IsADLModeActive;
    BOOL        IsWOModeActive;
    BOOL        IsSleepModeActive;
    
    BOOL        WORecordMemFull;
    BOOL        WOLogDataMemFull;
    BOOL        WOLogDataMemLow;

    BOOL        FuseHasRecord;
    BOOL        ActDataMemFull;
    
};
typedef struct MioDeviceStatus MioDeviceStatus;

//======================================================================================================//
//       add for Link2 & Alpha 1.5


#define GENDER_TYPE_MALE        0x1
#define GENDER_TYPE_FEMALE      0x0

#define UNIT_TYPE_IMPERIAL      0x0
#define UNIT_TYPE_METRIC        (0x1<<1)

#define HRMDISPLAY_BPM          0x0
#define HRMDISPLAY_PERCENT      (0x1<<2)

#define DISP_LEFT_HAND         0x0
#define DISP_RIGHT_HAND        (0x1<<3)

#define WODISP_TOUCH_ON           0x0
#define WODISP_ALWAYS_ON          (0x1<<4)

#define WORECORDING_DISABLE    0x0
#define WORECORDING_ENABLE     (0x1<<6)

#define MHR_AUTO_ADJ_DISABLE    0x0
#define MHR_AUTO_ADJ_ENABLE     (0x1<<7)

#define TOTAL_CAL_SELECT        0x0
#define ACTIVE_CAL_SELECT       (0x1<<5)

/**
 * User setting
 * Note: the unitType only influence the display item on the device, App should use METRIC
 *           when set the user’s Weight and Height.
 *           MHRAutoAdj should be set to MHR_AUTO_ADJ_ENABLE and the device will auto adjust
 *           the value of MHR whenever the birthday is reached. On the other hand, if MHR is keyed
 *           in by user, MHRAutoAdj should be set to MHR_AUTO_ADJ_DISABLE.
 */
struct UserSettings{
    BYTE		genderType;		//male, female
    BYTE		unitType;		// IMPERIAL, METRIC
    BYTE		HRMDisplayType;	//BPM or Percent.
    BYTE        DispOrien;	           //left hand, or right hand.
    BYTE        WODispMode;             //Workout display mode.
    BYTE        ADLCalorieGoalOpt;      //0: total calorie 1: active calorie
    BYTE        WORecordingEnable;
    BYTE		MHRAutoAdj;	//
    
    BYTE		birthDay;		//1-31
    BYTE		birthMonth;		//1-12
    unsigned short		birthYear;		//1900 - 2099
    BYTE		bodyWeight;            //20 – 200 KG.
    BYTE		bodyHeight;		//69 – 231 CM
    BYTE		RestHR; 		//30 – 140 BPM.
    BYTE		MaxHR;		//80 – 220 BPM
};
typedef struct UserSettings UserSettings;


#define TIMEFORMAT_12H  0x0
#define TIMEFORMAT_24H  0x1

#define DATAFORMAT_MMDD 0x0
#define DATAFORMAT_DDMM (0x1<<1)


/**
 * RTC
 * Note: the timeFormat and dataFormat only influence the display item on the device,
 *           App should use 24Hour when set RTC .
 */
struct RTCSettings{
    BYTE		timeFormat;	 //12H, 24H
    BYTE		dateFormat;  //MMDD,  DDMM
    BYTE		second;      //0-59
    BYTE		minute;	     //0-59
    BYTE		hour;		 //0-23
    BYTE		day;		 //1-31
    BYTE		month;	     //1-12
    unsigned short    year;		 //2014 – 2099.
};
typedef struct RTCSettings RTCSettings;


#define DISABLE_KEY_LOCK    0   //add for Fuse, 2014-09-28.

//ADL display setting, add for Link2.
struct ADLdisplay{
    BOOL		bDataCalorie;
    BOOL		bDataStep;
    BOOL		bDataDistance;
    BOOL		bDataGoal;
};
typedef struct ADLdisplay ADLdisplay;

//WO display setting, add for Link2.
struct WOdisplay{
    BOOL		bDataCalorie;
    BOOL		bDataStep;
    BOOL		bDataDistance;
    BOOL		bDataPace;
    BOOL		bDataSpeed;
    BOOL		bDataTime;
};
typedef struct WOdisplay WOdisplay;


typedef enum
{
	
	MIO_GOAL_TYPE_STEP = 0x01,
	MIO_GOAL_TYPE_DIST,
    MIO_GOAL_TYPE_CALORIE
	
} MIOGoalType_t;

//daily goal setting, add for Link2.
struct GoalSetting{
    BYTE					GoalType;
    unsigned int            GoalValue;
    BYTE					curProgress;
};
typedef struct GoalSetting GoalSetting;


#define EXERCISE_FLAG_INLUCDE_RECOVERY     0
#define EXERCISE_FLAG_NOT_INLUCDE_RECOVERY 1

#define EXERCISE_FLAG_REPEAT           (0x1<<1)
#define EXERCISE_FLAG_NOT_REPEAT        0

//Exercise setting, add for Alpha 1.5
struct ExerciseSetting{
    
    BOOL    bIncludeRecoverTime;      //
    BOOL    bRepeat;                //
    
    BYTE	RecoveryMin;            //0-59
    BYTE	RecoverySec  ;          //0-59
    BYTE	DownCountHour;          //0-23
    BYTE	DownCountMinute;        //0-59
};
typedef struct ExerciseSetting ExerciseSetting;

#define SCREEN_EMPTY            0
#define US1_CLOCK               1
#define US1_RUNNING_STEPS       2
#define US1_RUNNING_PACE        3
#define US1_RUNNING_KCAL        4
#define US1_RUNNING_DISTANCE    5
#define US1_RUNNING_SPEED       6
#define US1_LAP_CYCLE_STEPS           7
#define US1_LAP_CYCLE_KCAL            8
#define US1_LAP_CYCLE_DISTANCE        9
#define US1_LAP_CYCLE_TIME            10
#define US1_TOTAL_LAPS_CYCLE          11
//#define US1_SEC_STEP            12
//#define US1_SEC_KCAL            13
//#define US1_SEC_DIST            14
//#define US1_SEC_TOTAL_TIME      15
//#define US1_SEC_CYCLE           16

#if 0
#define US2_AVG_HR              1
#define US2_AVG_PACE            2
#define US2_TOTAL_TIME          3
#define US2_TOTAL_STEPS         4
#define US2_TOTAL_KCAL          5
#define US2_TOTAL_DISTANCE      6
#define US2_TOTAL_LAP           7
#define US2_BEST_LAP_TIME       8
#define US2_BEST_PACE           9
#define US2_IN_ZONETIME         10
#endif

//for latest Alpha2.
#define US2_AVG_HR              1
#define US2_AVG_PACE            2
#define US2_AVG_SPEED           3
#define US2_TOTAL_TIME          4
#define US2_TOTAL_STEPS         5
#define US2_TOTAL_KCAL          6
#define US2_TOTAL_DISTANCE      7
#define US2_TOTAL_LAP_CYCLE     8
#define US2_BEST_LAP_TIME       9
#define US2_BEST_PACE           10
#define US2_BEST_SPEED          11
#define US2_IN_ZONETIME         12

//User Screen setting.
struct ScreenSetting{
    
    //User screen 1:
    BYTE	US1_Screen[4];            //

    
    //User screen 2:
    BYTE	US2_Screen[6];            //


};
typedef struct ScreenSetting ScreenSetting;



/** Describes the type of record download. */
typedef enum
{
	
	MIO_RECORD_AUTODELETE                = 0,
	MIO_RECORD_KEEP                      = 0x01,
	
} MIORecDownloadType_t;

typedef enum
{
	
	MIO_DATA_TYPE_STEP = 0x01,
	MIO_DATA_TYPE_DIST,
    MIO_DATA_TYPE_CALORIE
	
} MIORecDataType_t;
//======================================================================================================//


typedef enum
{
    Stream_Mode_Disable =                   0x10,
    Stream_Mode_Enable =                    0x11,
    GPS_Mode_Disable =                      0x12,
    GPS_Mode_Enable =                       0x13,
    Stepping_DataNotification_Disable =     0x14,
    Stepping_DataNotification_Enable =      0x15,
    
    Mem_GetRecordCount =                    0x16,
    WOMem_AllClear =                        0x17,
    ADLMem_AllClear =                       0x18,
    ACTMem_AllClear =                       0x19,

    Reset_ADLToday_Data =                   0x20, //add for Fuse.
    Airplane_Mode_Enable =                  0x21,
    User_Data_Backup_Now =                  0X22,
    Start_ANCS_Engine =                     0X23,
    
    ExeTimerSync_DataNotification_Disable =         0x30,
    ExeTimerSync_DataNotification_Enable =          0x31,
    ExeTimerSync_StartTimer =                       0x32,
    ExeTimerSync_StopTimer =                        0x33,
    ExeTimerSync_TakeLap =                          0x34,
    ExeTimerSync_ResendLastLapData =                0x35,
    ExeTimerSync_Finish =                           0x36,
	
    SLEEPMODE_DEACTIVATE =                          0x40,
    SLEEPMODE_ACTIVATE =                            0x41,
    REST_HR_TAKE_MEASUREMENT =                      0x42,
    REST_HR_STOP_MEASUREMENT =                      0x43,
    REST_HR_SEND_MEASUREMENT_RESULTS =              0x44,
} MIORunCMDType_t;


typedef enum
{
	SYNC_state_starting =     0x0,
    SYNC_state_started =      0x1,
    SYNC_state_ending =       0x2,
    SYNC_state_ended  =       0x3,

} MIO_SYNCstate_t;


typedef enum
{
	Workout_Exercise_Record = 0x01,
	ADL_Record,
    ADL_Today_Record,
    UN_Use1,
    Activity_Record,
    Activity_ThisHour_Record,
    Del_ADL_Record,
    Del_Workout_Record,
    Del_Activity_Record,
	
} MIORecordType_t;

typedef enum
{
    Oldest_Record_IX = 0x00,
	Next_Record_IX,
    Record_N_IX
	
} MIORecordIXType_t;

typedef enum
{
    Delete_Oldest_Record = 0x00,
	Delete_All_Records
	
} MIODeleteOptionType_t;

#if 0
//
//data struct of ADL daily record.
//
struct ADLDailyData{
    BYTE	year;			//2014-2099
    BYTE	month;          //1-12
    BYTE	day;			//1-31
    
    unsigned int	step;		//1count = 1step, range: 0-99999
    unsigned int	dist;		//1count  = 0.001km, range: 0-99999
    unsigned short	calorie;	//1count = 1kcal, range: 0-9999
    
    unsigned int	actTimeOfWalk;      //1 count = 1s, range: 0 - 131072
    unsigned int	actTimeOfRun;       //1 count = 1s, range: 0 - 131072
    
    unsigned int	dailyGoalValue;     //
    MIOGoalType_t   dailyGoalType;      //step, distance, cal
};
typedef struct ADLDailyData ADLDailyData;
#endif

//
//data struct of ADL today record.
//
struct ADLTodayData{
    
    unsigned short	rmr;        //Rest HR.
    
    unsigned int	step;       //Total Step.
    unsigned int	dist;       //TTL Dist
    unsigned short	calorie;    //TTL kcal
    
    unsigned int	actTimeOfWalk;  //
    unsigned int	actTimeOfRun;
    
};
typedef struct ADLTodayData ADLTodayData;



//
//record summary of the workout
//
struct WorkoutRecordSummary{
    
    unsigned short index;
    
    //
    //Time stamp:
    unsigned short year;
    BYTE	month;	//1-12
    BYTE	day;		//1-31
    BYTE	hour;		//0-23
    BYTE	minute;	//0-59
    BYTE	second;	//0-59
    
    //TTL WO time.
    BYTE	WOhour;	//0-10
    BYTE	WOminute;	//0-59
    BYTE	WOsecond;	//0-59
    
    //TTL step
    unsigned int	step;	//unit: 1step, 0-99999
    //TTL dist
    unsigned int	dist;	//unit: meter, 0-99999
    //TTL kcal.
    unsigned short	calorie;//unit: kcal, 0-9999
    
    //Max Speed.
    float           maxSpeed;   //unit: KPH
    
    //Avg speed.
    float           AvgSpeed;   //unit: KPH
    
    //Avg Pace
    unsigned short	AvgPace;   //unit: second
    
    //Time in Zone.
    unsigned short	timeInZone; //unit: second
    unsigned short	timeInZone1;
    unsigned short	timeInZone2;
    unsigned short	timeInZone3;
    unsigned short	timeInZone4;
    unsigned short	timeInZone5;
    
    //Avg HR.
    unsigned short	AvrHR;      //unit: BPM, 30-220.
};
typedef struct WorkoutRecordSummary WorkoutRecordSummary;

struct _DATTIME{
    BYTE		second;             // 0-59
    BYTE		minute;             // 0-59
    BYTE		hour;               // 0-23
    BYTE		day;                // 1-31
    BYTE		month;              // 1-12
    unsigned short    year;         // 2014 – 2099.
};
typedef struct _DATTIME DATTIME;

//
// activity data
//
#define ACTDATA_SLEEPMODE          (0X01)
#define ACTDATA_STEPDATAPRESENT    (0x8)
#define ACTDATA_HRDATAPRESENT       (0x10)
#define ACTDATA_CALORIEDATAPRESENT    (0X20)
#define ACTDATA_BLANKMARKER         (0X40)

struct _ActivityData {
    BYTE            flags;
    BYTE            extFlags;
    BYTE            index;
    BYTE            step;           // 0-255 (steps)
    BYTE            heartRate;      // 30-220 (bpm)
    BYTE            calorie;        // 0-255 (kcal)
};
typedef struct _ActivityData ActivityData;

//
// activity data
//
struct _Activity1Hour {
    unsigned short  year;
    BYTE            month;          // 1-12
    BYTE            day;            // 1-31
    BYTE            hour;           // 0-23
    BYTE            minute;         // 0-59
    
    BYTE            nActDataSize;   // 0~60;
    ActivityData    actData[60];    // 60 minutes
};
typedef struct _Activity1Hour Activity1Hour;


//
// sleep tracking
//
#define SLEEPTRACK_MAX      (60*24)
struct _SleepTracking {
    void            *prev;
    void            *next;
    
    DATTIME         dtStart;                // start time
    DATTIME         dtEnd;                  // dtEnd time
    
    DATTIME         dtSleep;                // sleep time
    DATTIME         dtGetup;                // get up time
    
    int             totalTime;              // 1count = 1minute
    int             validCount;
    int             awake;                  // 1count = 1minute
    int             lightSleeping;          // 1count = 1minute
    int             deepSleeping;           // 1count = 1minute
    
    BOOL            isValid[SLEEPTRACK_MAX];
    BOOL            isSleepMode[SLEEPTRACK_MAX];;
    BYTE            activity[SLEEPTRACK_MAX];        // activity
    BYTE            sleeppattern[SLEEPTRACK_MAX];    // sleepstatus: 0 awake
                                                    // 1 light sleeping
                                                    // 2 deep sleeping
    BYTE            HR[SLEEPTRACK_MAX];
    BYTE            step[SLEEPTRACK_MAX];
    BYTE            calorie[SLEEPTRACK_MAX];
};
typedef struct _SleepTracking SleepTracking;

//
// sleep tracking v2
//
struct _SleepTracking2 {
    void            *prev;              // 指向前一个_SleepTracking2，如果不为null
    void            *next;            // 指向下一个_SleepTracking2，如果不为null
    
    unsigned short  year;
    BYTE            month;          // 1-12
    BYTE            day;            // 1-31
    BYTE            hour;           // 0-23
    BYTE            minute;         // 0-59
    
    unsigned int    nItemSize;
    BYTE *          flag;           // flag
    BYTE *          activity;       // activity
    BYTE *          sleeppattern;   // sleepstatus: 0 awake
                                                    // 1 light sleeping
                                                    // 2 deep sleeping
    BYTE *          HR;
    BYTE *          step;
    BYTE *          calorie;
};
typedef struct _SleepTracking2 SleepTracking2;


typedef enum
{
    ACQStutusNormal, //normal searching in progress
    ACQStutusGPS2D, //GPS 2D fix
    ACQStutusGPS3D //GPS 3D fix
	
} ACQStatusType_t;

//
//record summary of the alpha2
//
struct Alpha2RecordSummary
{
    BYTE    type;
    unsigned short recordTotal;
    unsigned short recordIndex;
    unsigned int   dataSize;
    unsigned short packetAmount;
    
};
typedef struct Alpha2RecordSummary Alpha2RecordSummary;


typedef enum
{
    CSS_Unkonw = 0x00,
    CSS_Ready,
    CSS_Begin,
    CSS_CALING,
    CSS_Finish,
    CSS_Timeout,
    CSS_Nostepupdated,
    
} CaliStrideStatus_t;

//
// VELOConfig.
//
struct  _VELOConfig {
    BYTE appType;
    BYTE activeBike;
    BOOL bSaveHR;
    BOOL bSaveHRV;
    BOOL bSaveSpeed;
    BOOL bSaveCadence;
    BOOL bSavePower;
};
typedef struct _VELOConfig VELOConfig;


//
// VELORawdata.
//
#define VELORD_SPEED            0X08
#define VELORD_CADENCE          0X10
#define VELORD_POWER            0X20
#define VELORD_HRV              0X40
#define VELORD_HR               0X80

struct  _VELORawdata {
    BYTE                header;
    BYTE                HR;
    BYTE                cadence;
    BYTE                nHRVSize;
    float               speed;
    unsigned short      power;
    unsigned short      HRV[15];
};
typedef struct _VELORawdata VELORawdata;

//
// VELOSummary.
//
struct  _VELOSummary {
    unsigned short index;
    BYTE startPage;
    BYTE startByte;
    BYTE ctrlinfo;
    unsigned short workoutsecs;
    unsigned short workoutsize;
    
    unsigned short year;
    BYTE month;
    BYTE day;
    BYTE hour;
    BYTE min;
    BYTE sec;
    
    int             rdSize;
    VELORawdata     *arRawdata;
};
typedef struct _VELOSummary VELOSummary;


//
// Misc1.
//
#define MISC1_SwingArmDetection         0x01
#define MISC1_SwingArmSelect_ADL        0X02
#define MISC1_SwingArmSelect_WO         0X04
#define MISC1_RHRMeasCtrl_SLP           0X08
#define MISC1_RHRMeasCtrl_ADL_WO        0X10
#define MISC1_MobileNotification        0X20


#define SAITEM_ADL_TIME                 0X00
#define SAITEM_ADL_CALORIE              0X01
#define SAITEM_ADL_STEP                 0X02
#define SAITEM_ADL_DISTANCE             0X03

#define SAITEM_WO_HEARTRATE             0X00
#define SAITEM_WO_CHRONO                0X01
#define SAITEM_WO_CALORIE               0X02
#define SAITEM_WO_STEP                  0X03
#define SAITEM_WO_DISTANCE              0X04
#define SAITEM_WO_PACE                  0X05
#define SAITEM_WO_SPEED                 0X06
#define SAITEM_WO_TIME                  0X07

struct  _SAItem_ADL {
    BYTE Item;
};
typedef struct _SAItem_ADL SAItem_ADL;

struct  _SAItem_WO {
    BYTE Item;
};
typedef struct _SAItem_WO SAItem_WO;

struct  _Misc1Config {
    unsigned short      flag;
    SAItem_ADL          saItemADL;
    SAItem_WO           saItemWO;
    BYTE                rhrMeasPeriodSLP;
    BYTE                rhrMeasPeriodADLWO;
};
typedef struct _Misc1Config Misc1Config;

/*
 * Run's speed and cadence data
 */
struct  _RSCData {
    int                 wrStatus;           /* 0:work;1:run */
    float               speed;              /* m/s */
    unsigned short      cadence;
    unsigned short      stride;             /* cm */
    unsigned int        totalDistance;     /* 1/10 m */
};
typedef struct _RSCData RSCData;


/*
 * Alarm clock
 */
#define ALM_ID0                 0X01
#define ALM_ID1                 0X02
#define ALM_ID2                 0X04

#define ALMTYPE_MON             0X02
#define ALMTYPE_TUE             0X04
#define ALMTYPE_WED             0X08
#define ALMTYPE_THU             0X10
#define ALMTYPE_FRI             0X20
#define ALMTYPE_SAT             0X40
#define ALMTYPE_SUN             0X80

struct  _AlarmClock {
    BYTE        AlmID;
    BYTE        AlmMin;
    BYTE        AlmHr;
    BYTE        AlmType;
    char        AlmMsg[10];
};
typedef struct _AlarmClock AlarmClock;


/*
 * MEM Type
 */
#define TYPE_WOMEM                  0X17
#define TYPE_ADLMEM                 0X18
#define TYPE_ACTMEM                 0X19




struct  _HRVData {
    unsigned int   timeSize;
    float          time[9];
    
    unsigned int   rawSize;
    BYTE           byteRaw[20];
};
typedef struct _HRVData HRVData;

#endif











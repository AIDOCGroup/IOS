

//
//  MIO_GLOBAL_SDK.h
//  MIO_GLOBAL_SDK
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#ifndef __MIO_SPORTS_PROTOCOL_H__
#define __MIO_SPORTS_PROTOCOL_H__

#import "MIOCommonType.h"


//Max size of MsgBuf {MIO_MSG_STRUCT}.
#define MIO_MSG_BUF_MAX     20

//
//Message structure
//
typedef struct
{
    BYTE    Len;
    BYTE    MsgID;
    BYTE    MsgBuf[18];
    
}MIO_MSG_CMD_STRUCT;


//
//Message response structure
//
typedef struct
{
    BYTE    Len;
    BYTE    MsgID;
    BYTE    MsgIDOfRespFor;
    BYTE    MsgCode;
    BYTE    MsgBuf[16];
    
}MIO_MSG_RESPONSE_STRUCT;
//
//Velo respond structure
//
typedef struct
{
    BYTE    Len;
    BYTE    MsgID;
    BYTE    AntChannel;
    BYTE    Code;
    //unsigned short DevNumber;
    //unsigned short ManuID;
    unsigned short ManuID;
    unsigned short DevNumber;

    BYTE    MsgBuf[12];
    
}MIO_MSG_VELO_STRUCT;

typedef struct
{
    BYTE    Flags;
    //unsigned int MsgID;
    //unsigned short    WheelValue;
    unsigned int      WheelValue;
    unsigned short    WheelTime;
    unsigned short    CrankValue;
    unsigned short    CrankTime;
}MIO_MSG_SPEED_CADENCE_STRUCT;


typedef struct
{
    BYTE    Flags;
    
    //HR5ZoneStruct
    BYTE    TargetZone;
    BYTE    HRLimit0;
    BYTE    HRLimit1;
    BYTE    HRLimit2;
    BYTE    HRLimit3;
    BYTE    HRLimit4;
    
    //HR3ZoneStruct
    BYTE    HRLower;
    BYTE    HRUpper;
    
    BYTE    MHR;    //only for LINK & VELO.
    
}MIO_HRZONE_SETTING;




//
//
//
typedef struct
{
    BYTE    BikeNum;
    
    BYTE    ChannelFlag;    //add for sdk v2.1
    
    //bike speed sensor.
    BYTE             BSManuID;
    unsigned short   BSDevNumber;
    
    //bike candence sensor.
    BYTE             BCManuID;
    unsigned short   BCDevNumber;
    
    //bike speed & candence sensor.
    unsigned short   BSCManuID;
    unsigned short   BSCDevNumber;
    
    //bike power sensor.
    unsigned short   BPWManuID;
    unsigned short   BPWDevNumber;
    
}MIO_BIKE_SETTINGS;

typedef struct
{
    BYTE            Sec;
    BYTE            Min;
    BYTE            Hr;
}EXE_TIME_STRUCT;

typedef struct
{
    BYTE            Heartrate_start;            // 0 or 30-220
                                                // Heart rate in BPM at the start of the recovery session, 0
                                                // means heart rate cannot be detected
    
    BYTE            Heartrate_end;              // 0 or 30-220
                                                // Heart rate in BPM at the end of the recovery session, 0
                                                // means heart rate cannot be detected
}HRRECOVERY_STRUCT;

//
//
//
typedef struct
{
    unsigned int        Flag;
    
    BYTE                TimerStatus;
    
    BYTE                LapNum;
    
    EXE_TIME_STRUCT     SplitTime;
    EXE_TIME_STRUCT     LapTime;
    
    unsigned int        StepData;
    float               DistData;
    unsigned int        CalorieData;
    float               SpeedData;
    
    HRRECOVERY_STRUCT   HRRecovery;
}EXE_TIMERSYNC_INFO;

//
//flag bit field:
//
#define     HRZONE_TYPE_5ZONE       (0x0<<0)
#define     HRZONE_TYPE_3ZONE       (0x1<<0)
#define     ANTPLUS_TX_DISABLE      (0x0<<1)
#define     ANTPLUS_TX_ENABLE       (0x1<<1)



//Message id:
#define     MSG_ID_RESPONSE_FROM_SENSOR         0x80
#define     MSG_ID_GET_ZONE_SETTING             0x01
#define     MSG_ID_SET_ZONE_SETTING             0x02

#define     MSG_ID_LINK_DFU_CMD                 0xfe

#define     MSG_ID_RESET_CMD                    0xe5

#define     MSG_ID_LINK_OTA_START               0x44

#define     LINK_DISP_GET                       0x20
#define     LINK_DISP_SET                       0X21
#define     LINK_DISP_SET2                      0x28

#define     LINK_DAILY_GOAL_GET                 0x22
#define     LINK_DAILY_GOAL_SET                 0x23
#define     LINK_DEVICE_STATUS_GET              0x24
#define     LINK_MEM_RECORD_GET                 0x25
#define     LINK_MEM_SESSION_GET                0x26
#define     LINK_MEM_RECORD_DEL                 0x27

#define     LINK_MISC1_GET                      0x29
#define     LINK_MISC1_SET                      0X2A

#define     LINK_ALARM_GET                      0X2B
#define     LINK_ALARM_SET                      0X2C

#define     LINK_GPS_SD_DATA                    0x10

// for Alpha 2:
#define     LINK_MEM_RECORD_GET_ALPHA           0x50
#define     LINK_MEM_NEXT_PACKET_GET_ALPHA      0x51
#define     LINK_MEM_RECORD_DELETE_ALPHA        0x52

#define     LINK_EXER_SETTINGS_GET              0x40
#define     LINK_EXER_SETTINGS_SET              0x41
#define     LINK_USER_SCREEN_GET                0x42
#define     LINK_USER_SCREEN_SET                0x43

#define     LINK_ALPHA2_CUS_CMD                 0x45
#define     LINK_ALPHA2_DEVICE_OPTION_GET       0x46
#define     LINK_ALPHA2_DEVICE_OPTION_SET       0x47


#define GET_ALPHA2_BATT         0x01

//add for RTC of LINK1 & Velo
#define     MSG_ID_GET_RTC                      0xd0
#define     MSG_ID_SET_RTC                      0xd1

//common cmd for Velo,Fuse, Alpha1.5&2.0
#define     MSG_ID_GET_USERSETTING              0x03
#define     MSG_ID_SET_USERSETTING              0x04

#define     MSG_ID_GET_CUSTOM_DEVNAME           0x05
#define     MSG_ID_SET_CUSTOM_DEVNAME           0x06

#define     MSG_ID_RTC_GET                      0x10
#define     MSG_ID_RTC_SET                      0x11

#define     MSG_ID_RUN_CMD                      0x12
#define     MSG_ID_CALISTRIDE_GET               0x13
#define     MSG_ID_CALISTRIDE_SET               0x14

#define     MSG_ID_SENSOR_DATA                  0xFD



//Response code:
#define     MSG_RESPONSE_NO_ERROR               0x0
#define     MSG_RESPONSE_INVALID_MSG            0x30
#define     MSG_RESPONSE_WRONG_STATE            0x20


//#define     MIO_SENSOR_DEVICE_NAME              @"MIO GLOBAL"
#define     MIO_SENSOR_DEVICE_NAME              @"MIO "             //changed by 2014-07-14.

#define     MIO_ALPHA_DEVICE_NAME               @"ALPHA"

#define     MIO_LINK_DEVICE_NAME                @"MIO GLOBAL LINK"
#define     MIO_LINK_TEST_DEVICE_NAME           @"MIO LINK TEST"    //for OTA update,by 2014-03-26.
#define     MIO_LINK_SUFFIX_NAME                @"-LINK"
#define     MIO_LINK_OTBEAT_NAME                @"Otbeat Mio Link"

#define     MIO_VELO_DEVICE_NAME                @"MIO VELO"
#define     MIO_VELO_SUFFIX_NAME                @"-VELO"

//for FUSE
#define     MIO_FUSE_DEVICE_NAME                @"MIO GLOBAL FUSE"
#define     MIO_FUSE_TEST_DEVICE_NAME           @"MIO FUSE TEST"
#define     MIO_FUSE_SUFFIX_NAME                @"-FUSE"

//Alpha 2
#define     MIO_ALPHA2_DEVICE_NAME              @"MIO ALPHA2"
#define     MIO_ALPHA2_OTA_DEVICE_NAME          @"MIO ALPHA2_OTA"
#define     MIO_ALPHA2_SUFFIX_NAME              @"ALPHA2"
#define     MIO_ALPHA2_PREFIX_NAME              @"ALPHA2"

//command for MIO velo.
#define     LINK_PRO_BIKE_START_PAIR            0x30
#define     LINK_PRO_BIKE_GET                   0x31
#define     LINK_PRO_BIKE_SET                   0x32
#define     LINK_PRO_BIKE_PAIR_DEVICE_FOUND     0x81
#define     LINK_PRO_BIKE_CHANNEL_STATUS        0x82

#define     LINK_VELO_BIKE_INFO_ASYNC           0x83

#define     LINK_VELO_STATUS_GET                0x33
#define     LINK_VELO_STATUS_SET                0x34
#define     LINK_VELO_DEVICE_STATUS_GET         0x35
#define     LINK_VELO_MEM_RECORD_GET            0x36
#define     LINK_VELO_MEM_SESSION_GET           0x37
#define     LINK_VELO_MEM_RECORD_DEL            0x38


/*
#define MIO_MSG_RESPONSE								0X80

#define LINK1_CMD_ZONE_SETTINGS_GET 					0X01
#define LINK1_CMD_ZONE_SETTINGS_SET 					0X02


#define MIO_RESPONSE_NO_ERROR							0

#define MIO_RESPONSE_UNIT_IN_WRONG_STATE				0X20	//RETURNED WHEN UNIT IS IN WRONG STATE TO PERFORM THE ACTION REQUESTED

#define MIO_RESPONSE_INVALID_MSG						0X30	//RETURNED WHEN THE CMD IS UNKNOWN OR THE MESSAGE HAS INVALID PARAMETERS
*/

#endif











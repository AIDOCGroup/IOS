

//
//  MIO_GLOBAL_SDK.h
//  MIO_GLOBAL_SDK
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#ifndef __MIO_SERVICEANDCHARACT_UUID_H__
#define __MIO_SERVICEANDCHARACT_UUID_H__



//Services UUIDs
#define     SERVICES_GENERIC_ACCESS_UUID        @"0x1800"

#define     SERVICES_GENERIC_ATTRIBUTE_UUID     @"0x1801"

#define     SERVICES_HEART_RATE_UUID            @"0x180D"

#define     BATTERY_SERVICE_UUID                @"0x180F"

#define     SERVICES_DEVICE_INFO_UUID           @"0x180A"




// Service: Run's Speed and Cadence
#define     SERVICES_RUN_SPEED_CADENCE          @"0x1814"
#define     CHAR_RSC_MEASUREMENT                @"0x2A53"   // Notify,read.
#define     CHAR_RSC_FEATURE                    @"0x2A54"   // read.

//Characteristic UUIDs

//Service: Generic Access
#define     CHAR_GENERIC_ACCESS_DEVICE_NAME     @"0x2A00"
#define     CHAR_GENERIC_ACCESS_APPERANCE       @"0x2A01"
#define     CHAR_GENERIC_ACCESS_PER_PARM        @"0X2A04"


//Service: Generic Attribute
#define     CHAR_GENERIC_ATTR_SERVICE_CHANGED   @"0x2A05"

//Service: Battery service
#define     CHAR_BATTERY_SERVICE_BATT_LEVEL     @"0x2A19"   //Notify,read.

//Service: Device infomation
#define     CHAR_DEV_INFO_MANUFACTACTY_NAME     @"0x2A29"   //READ.
#define     CHAR_DEV_INFO_MODEL_NUMBER          @"0x2A24"   //READ.
#define     CHAR_DEV_INFO_SERIAL_NUMBER         @"0x2A25"   //READ.
#define     CHAR_DEV_INFO_HARDWARE_REV          @"0x2A27"   //READ.
#define     CHAR_DEV_INFO_FIRMWARE_REV          @"0x2A26"   //READ.
#define     CHAR_DEV_INFO_SOFTWARE_REV          @"0x2A28"   //READ.
#define     CHAR_DEV_INFO_SYSTEM_ID             @"0x2A23"   //READ.


//Service: Heart rate
#define     CHAR_HR_HEART_RATE_MEASUREMENT      @"0x2A37"   //Nofify
#define     CHAR_HR_BODY_SENSOR_LOCATION        @"0x2A38"   //READ.


//
//MIO specific UUIDs
//

// 0x6C721826-5BF14F64-9170381C-08EC57EE
#define MIO_UUID_FACTORY_SERVICE				@"0x1826"
// 0x6C722A0A-5BF14F64-9170381C-08EC57EE
#define 	MIO_UUID_FS_CODE_CHAR1				@"0x2A0A"   //READ,WRITE.
#define 	MIO_UUID_FS_CODE_CHAR2				@"0x2A0B"   //READ,WRITE.
#define 	MIO_UUID_FS_CODE_CHAR3				@"0x2A0C"   //Notify,Read.



// 0x6C721838-5BF14F64-9170381C-08EC57EE
//#define MIO_UUID_SPORTS_SERVICE 				@"0x1838"
#define MIO_UUID_SPORTS_SERVICE 				@"6C721838-5BF1-4F64-9170-381C08EC57EE"

// 0x6C722A80-5BF14F64-9170381C-08EC57EE
//#define 	MIO_UUID_SS_CHAR_MSG				@"0x2A80"   //READ,WRITE.
//#define 	MIO_UUID_SS_CHAR_MSG_EXT			@"0x2A81"   //READ,WRITE.
//#define 	MIO_UUID_SS_CHAR_MSG_RSP			@"0x2A82"   //Notify,Read.
//#define 	MIO_UUID_SS_CHAR_SENSOR_DATA		@"0x2A83"   //Notify,Read.
#define 	MIO_UUID_SS_CHAR_MSG				@"6C722A80-5BF1-4F64-9170-381C08EC57EE"   //READ,WRITE.
#define 	MIO_UUID_SS_CHAR_MSG_EXT			@"6C722A81-5BF1-4F64-9170-381C08EC57EE"   //READ,WRITE.
#define 	MIO_UUID_SS_CHAR_MSG_RSP			@"6C722A82-5BF1-4F64-9170-381C08EC57EE"   //Notify,Read.
#define 	MIO_UUID_SS_CHAR_SENSOR_DATA		@"6C722A83-5BF1-4F64-9170-381C08EC57EE"   //Notify,Read.
#define     MIO_UUID_SS_CHAR_STREAM_DATA        @"6C722A84-5BF1-4F64-9170-381C08EC57EE"   //Notify.

#define     MIO_UUID_SS_CHAR_STREAM_DATA_ALPHA  @"2A84"   //Notify.


//SPEED AND CADENCE SERVICES,
#define     SERVICES_SPEED_AND_CADENCE_UUID     @"0x1816"

//Service: Speed and Cadence.
#define     CHAR_CSC_MEASUREMENT                @"0x2A5B"   //CSC Measurement
#define     CHAR_CSC_FEATURE                    @"0x2A5C"   //CSC FEATURE

#define MIO_RESPONSE_NO_ERROR							0

/*
#define MIO_MSG_RESPONSE								0X80

#define LINK1_CMD_ZONE_SETTINGS_GET 					0X01
#define LINK1_CMD_ZONE_SETTINGS_SET 					0X02



#define MIO_RESPONSE_UNIT_IN_WRONG_STATE				0X20	//RETURNED WHEN UNIT IS IN WRONG STATE TO PERFORM THE ACTION REQUESTED

#define MIO_RESPONSE_INVALID_MSG						0X30	//RETURNED WHEN THE CMD IS UNKNOWN OR THE MESSAGE HAS INVALID PARAMETERS
*/

#endif













//
//  MIODeviceConnection.h
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>


#import "MIOCommonType.h"
#import "MIOServiceAndCharactUUID.h"
#import "MIOSportsProtocol.h"
#import "MIODeviceInfoExtend.h"
#import "MIODeviceConnectionDelegate.h"

#import "MIODeviceSensor.h"
#import "MIODeviceSensorExtend.h"

#import "MIOBikeANTSensor.h"
#import "MIOBikeANTSensorExtend.h"

#import "WorkoutRecordData.h"

@interface MIODeviceConnection : NSObject
{
    
    //id<MIODeviceConnectionDelegate> delegate;
    
}


/**
 * Gets the current connection status.
 */
@property (atomic, readonly) MIODeviceConnectionStatus_t connectionStatus;

/**
 * Specifies the MIODeviceConnectionDelegate instance which will handle callback
 * methods for this MIODeviceConnection.
 */
@property (nonatomic, retain) id<MIODeviceConnectionDelegate> delegate;

/**
 * the sensor used by the connection, add by zb,2013-12-28.
 */
@property (nonatomic, readonly) MIODeviceSensor  *deviceSensor;

/**
 * Specifies the BTLE Device UUID String
 */
@property (nonatomic, readonly) NSString* deviceUUIDString;

/**
 * Gets a boolean value indicating whether a connection timeout occurred.
 */
@property (nonatomic, readonly) BOOL didTimeout;


/** Get the error status for the connection. */
@property (nonatomic, readonly) MIODeviceConnectionError_t error;

/**
 * <c>TRUE</c> if the sensor is currently connected, otherwise <c>FALSE</c>.
 */
@property (nonatomic, readonly) BOOL isConnected;

/**
 * Gets a boolean value indicating whether this MIODeviceConnection instance
 * is valid.
 *
 * The MIODeviceConnection is invalidated when the sensor is disconnected, or
 * when the API is reset.
 *
 */
@property (nonatomic, readonly) BOOL isValid;


/** <c>TRUE</c> if an error has occured, otherwise <c>FALSE</c>. */
@property (nonatomic, readonly) BOOL hasError;


/**
 * Gets the BLE sensor type for this MIODeviceConnection.
 */
@property (nonatomic, readonly) MIOSensorType_t sensorType;

/** 
 * <c>TRUE</c> if this connection is connect to a MIO sensor device.
 */
@property (nonatomic, readonly) BOOL IsMIODevice;

/**
 * <c>TRUE</c> if this MIO Sensor is unlocked.
 */
@property (nonatomic, readonly) BOOL IsUnlocked;

/**
 * <c>TRUE</c> if this MIO device support HRZone setting.
 */
@property (nonatomic, readonly) BOOL IsSupportHRZone;


/**
 * <c>TRUE</c> if this MIO device support ANT+.
 */
@property (nonatomic, readonly) BOOL IsSupportANTPlus;


@property (nonatomic, readonly)    MIODeviceType_t     MioDeviceType;

/**
 * <c>TRUE</c> if HR data is valid.
 */
@property (atomic, readonly) BOOL hasHRdata;


/**
 * <c>TRUE</c> if GPS mode is enable.
 */
@property (atomic, readonly) BOOL IsGPSmode;



/**
 * <c>TRUE</c> if Workout mode is enable.
 */
@property (atomic, readonly) BOOL IsWorkoutMode;


/**
 * Disconnects the sensor.
 */
- (void)DisconnectFromSensor_MIO;

/**
 * Retrieves the most current data available from the sensor.
 *
 *
 * @return  heart rate , in beats per minute.
 */
- (unsigned short)GetDataOfHeartRate_MIO;


/**
 * Returns a boolean value indicating whether new data is available.
 *
 * @return <c>TRUE</c> if new data is available since the last time
 * read data was invoked, otherwise <c>FALSE</c>.
 */
- (BOOL)HasData_MIO;

/**
 * Returns the signal efficiency for the connected sensor.
 *
 * @return 
 * This value should give a good indication of the reception quality for the sensor.
 * For BTLE connections, this property represents the RSSI (in dBm).
 * If the sensor is not currently connected, the return value is <c>-1</c>.
 */
- (int)SignalEfficiency_MIO;



/**
 *  unlock the protection of the MIO device.
 *
 * @return not used.
 * 
 */
-(BOOL) UnlockMIODevice_MIO;


//-(BOOL) IsMIODeviceUnlocked_MIO;

/**
 *  get the device information.
 *
 * @return <c>TRUE</c> if have got the device information, otherwise <c>FALSE</c>.
 *
 */
-(BOOL) GetDeviceInfo_MIO:(MIODeviceInfo*)pInfo;


/**
 *  enable or disable the notification of Heart rate device.
 *
 */
-(BOOL) NotificationOfHeartRate_MIO:(BOOL)on;


/**
 *  get heart rate zone setting of MIO device.
 *
 * @Note: call the function “GetHRZoneSettings_MIO”  to get HR zone setting, App will get delegate function “DidGetHRZoneSetting_MIO” when it read from device.
 *
 *  Devices: LINK, VELO, FUSE, ALPHA2
 *  @return FALSE if device does not have HR Zone function; otherwise TRUE
 */
-(MIOErrorCode_t) GetHRZoneSettings_MIO;


/**
 *  set heart rate zone setting of MIO device.
 *
 *  @Note:  Call the function to write HR zone setting to device, App will get delegate fuction “DidSetHRZoneSetting_MIO” when it writed to device.
 *
 *  Devices: LINK, VELO, FUSE, ALPHA2
 *
 *  @return FALSE if device does not have have HR Zone function; otherwise TRUE
 */
-(MIOErrorCode_t) SetHRZoneSetting_MIO:(HRZone*)zone ;


/**
 *  get ANT+ state of MIO device.
 *
 *  @Note:  Call the function to get Ant state, App will get delegate fuction “Did GetANTPlusStatus_MIO” when it get the state successfully.
 *
 *  Devices: LINK, VELO, FUSE
 *
 *  @return FALSE if device does not have ANT+ function; otherwise TRUE
 */
-(MIOErrorCode_t) GetANTPlusStatus_MIO;


/**
 *  set ANT+ state of MIO device.
 *
 *  @Note:  Call the function to get Ant state, App will get delegate function “Did SetANTPlusStatus_MIO” when it set the state successfully.
 
 *  Devices: LINK, VELO, FUSE
 *
 *  @return FALSE if device does not have ANT+ function; otherwise TRUE
 */
-(MIOErrorCode_t) SetANTPlusStatus_MIO:(ANTPlusState_t)state;


/**
 *  Let the MIO device enter OTA mode, then do upload firmware.
 *  Now, the api is only support by MIO link.
 *
 */
-(MIOErrorCode_t) EnterOTAUpdateMode_MIO;       //Add by toling,2014-03-22.


/*
 * App can check if there is a waiting command.
 *
 *  Devices: LINK, VELO, FUSE
 *
 *  @return TRUE if device is sending a command to device or waiting for a response from device; otherwise FALSE
 *
 */
- (BOOL) IsDeviceBusy_MIO;




//
//Force to reset device.  only for Fuse.
//
-(MIOErrorCode_t) ResetDevice_MIO;


//
//check if the Fuse memory is full.  only for Fuse.
//
-(MIOErrorCode_t) CheckIsMemFull_MIO;

//
//get device status from Fuse device.
//
-(MIOErrorCode_t) GetDeviceStatus_MIO;

//
//change device name
//
-(MIOErrorCode_t) ChangeDeviceName_MIO:(NSString* )deviceName;


//
//Let device switch to airplane mode.
//
-(MIOErrorCode_t) SwitchToAirplaneMode_MIO;


//
//Get battery level from Alpha2 device.
//
-(MIOErrorCode_t) GetBatteryfromAlpha2_MIO;

/**
 *  Get the device battery level
 *
 *  @return   MIO_ERRCODE_NOERROR if the device does not have the function; otherwise error code
 */
-(MIOErrorCode_t) GetBatteryLevel_MIO;


/**
 * Returns the error code of the last calling function.
 *
 */
//-(MIOErrorCode_t) GetLastErrorCode;


//=============================================================================================//
//   Add below functions for MIO Velo

/**
 *  start to search Ant+ Bike sensor
 *
 *  Devices: VELO
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
//- (BOOL)BikeSensorStartPair_MIO:(unsigned short)timeout;

/**
 *  start to search Ant+ Bike sensor
 *
 *  Devices: VELO
 *   Para:  bikeID   the Bike index 1 – 4.
 *  Para:  timeout   30 – 255 seconds.
 *  @return   MIO_ERRCODE_NOERROR if the device does not have the function; otherwise error code
 *  @Note:  App will get delegate function “BikeSensorPairDeviceFound_MIO” when it find a Ant sensor or pair timeout.
 */
- (MIOErrorCode_t)BikeSensorStartPair_MIO:(MIOBikeIndex_t)bikeID timeout:(unsigned short)timeout;


/**
 *  Cancel search Ant+ Bike sensor
 *
 *  Devices: VELO
 *   Para:
 *  @return   MIO_ERRCODE_NOERROR
 *  @Note:  App will get delegate function “BikeSensorPairDeviceFound_MIO”.
 */
- (void)BikeSensorCancelPair_MIO;


/**
 *  config Ant+ Bike sensor array to Velo device
 *
 *  Devices: VELO
 *  Para:  bikeID   the Bike index 1 – 4.
 *   Para:  sensorList  a array include the Ant+ bike sensor.
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
- (BOOL)SetBikeSensorSetting_MIO:(MIOBikeIndex_t)bikeID sensor:(NSArray*)sensorList active:(BOOL)active;
//- (MIOErrorCode_t)SetBikeSensorSetting_MIO:(MIOBikeIndex_t)bikeID  active:(BOOL)active;




/**
 *  get the setting of Ant+ Bike sensor from Velo device
 *
 *  Devices: VELO
 *  Para:     bikeID   the Bike index 1 - 4.
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
- (MIOErrorCode_t)GetBikeSensorSetting_MIO:(MIOBikeIndex_t)bikeID;

/**
 *  Delete all the setting of Ant+ Bike sensor from Velo device
 *
 *  Devices: VELO
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
- (MIOErrorCode_t)ClearBikeSensorSetting_MIO;


/**
 *  clear specific bike profile.
 *
 *  Devices: VELO
 *  Para:  bikeID   the Bike index 1 – 4.
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
- (MIOErrorCode_t)ClearBikeSensorSetting_MIO:(MIOBikeIndex_t)bikeID;

/**
 *  Enable  some  Ant+ Bike sensor channel for Velo device
 *
 *  Devices: VELO
 * @Para  channel to be enable or disable.
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
- (MIOErrorCode_t)SetBikeSensorChannels_MIO:(MIOBikeSensorChannel_t)channel;


/**
 *  Enable  some  Ant+ Bike sensor channel for Velo device
 *
 *  Devices: VELO
 * @Para  channel to be enable or disable.
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
//- (MIOErrorCode_t)EnableBikeSensorChannel_MIO:(MIOBikeSensorChannel_t)channel;

/**
 *  Disable some  Ant+ Bike sensor channel for Velo device
 *
 *  Devices: VELO
 * @Para  channel to be enable or disable.
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
//- (MIOErrorCode_t)DisableBikeSensorChannel_MIO:(MIOBikeSensorChannel_t)channel;

/**
 *  Read the Ant+ sensor data from Velo device.
 *
 *  Devices: VELO
 * @Para  data   include various sensor data for a Bike.
 *  @return FALSE if the device does not have the function; otherwise TRUE
 */
//- (BOOL)ReadBikeSensorData:(BikeSensorData*)data;

/**
 *  Read the Ant+ sensor raw data from Velo device.
 *
 *  Devices: VELO
 * @Para  data   include various sensor raw data for a Bike.
 *  @return   MIO_ERRCODE_NOERROR if the device does not have the function; otherwise error code
 */
- (MIOErrorCode_t)ReadBikeRawSensorData_MIO:(BikeSensorRawData*)data ;



/**
 *  Read the Ant+ sensor data from Velo device.
 *
 *  Devices: VELO
 * @Para  data   include various sensor data for a Bike.
 *  @return   MIO_ERRCODE_NOERROR if the device does not have the function; otherwise error code
 */
- (MIOErrorCode_t)ReadBikeSensorData_MIO:(BikeSensorData*)data;

/**
 *  set the wheel circumference for a bike.
 *
 *  Devices: VELO
 * @Para  bikeID   the Bike index 1 - 4.
 * @Para  wheel    the wheel circuference.
 
 *  @return
 */
- (MIOErrorCode_t)CongfigBikeWheelCircumference_MIO:(MIOBikeIndex_t)bikeID wheel:(float)value;


/**
 *  Set App type and active bike number to Velo device.
 *
 *  Devices: VELO
 * @Para  data   include various sensor data for a Bike.
 *  @return   MIO_ERRCODE_NOERROR if the device does not have the function; otherwise error code
 */
- (MIOErrorCode_t)SetConfigOfVelo_MIO:(MIOVeloAppType_t)AppType activeBike:(MIOBikeIndex_t)bikeID;

- (MIOErrorCode_t)SetConfigOfVelo_MIO:(VELOConfig)config;

/**
 *  Get App type from Velo device.
 *
 *  Devices: VELO
 *
 *  @return   MIO_ERRCODE_NOERROR if the device does not have the function; otherwise error code
 */




/**
 *  get rtc time from MIO LINK1 device.   e.g.: Link, Velo.
 *
 */
-(MIOErrorCode_t) GetRTCtimeInner_MIO;


/**
 *  set rtc time to MIO LINK1 device. e.g.: Link, Velo.
 *
 */
-(MIOErrorCode_t) SetRTCtimeInner_MIO:(RTCtime*)time;


//=============================================================================================//




//=============================================================================================//
//   Add below functions for MIO FUSE, Alpha2

/**
 *  set RTC time to MIO device, e.g.: FUSE, Alpha2
 *
 */
-(MIOErrorCode_t) SetRTCTime_MIO:(RTCSettings*)time;


/**
 *  get current RTC time from MIO device, e.g.: FUSE, Alpha2
 *
 */
-(MIOErrorCode_t) GetRTCTime_MIO;



/**
 *  set user personal info to MIO device, e.g.: Link2, Alpha1.5
 *
 */
-(MIOErrorCode_t) SetUserInfo_MIO:(UserSettings*)user;


/**
 *  get current user info from MIO device, e.g.: Link2, Alpha1.5
 *
 */
-(MIOErrorCode_t) GetUserInfo_MIO;

/**
 *  set display setting to MIO device, e.g.: Link2,
 *
 *  parameter: timeout -> DISABLE_KEY_LOCK, 10 - 120 S.
 */
//-(MIOErrorCode_t) SetDispSetting_MIO:(ADLdisplay*)adl wo:(WOdisplay*)wo lockTimer:(BYTE)timeout;
-(MIOErrorCode_t) SetDispSetting_MIO:(ADLdisplay*)adl wo:(WOdisplay*)wo ADLlockTimer:(BYTE)timeout1 WOlockTimer:(BYTE)timeout2;


/**
 *  get display setting from MIO device, e.g.: Link2,
 *
 */
-(MIOErrorCode_t) GetDispSetting_MIO;


/**
 *  set Daily goal to MIO device, e.g.: Link2,
 *
 */
-(MIOErrorCode_t) SetDailyGoal_MIO:(GoalSetting*)goal updateDaily:(BOOL)isUpdateDaily updateToday:(BOOL)isUpdateToday;


/**
 *  get Daily goal from MIO device, e.g.: Link2,
 *
 */
-(MIOErrorCode_t) GetDailyGoal_MIO;


/**
 *  set exercise setting to MIO device, e.g.: Alpha 1.5,
 *
 */
-(MIOErrorCode_t) SetExerciseSetting_MIO:(ExerciseSetting*)setting;


/**
 *  get exercise setting from MIO device, e.g.: Alpha 1.5,
 *
 */
-(MIOErrorCode_t) GetExerciseSetting_MIO;


/**
 *  set exercise setting to MIO device, e.g.: Alpha 1.5,
 *
 */
-(MIOErrorCode_t) SetScreenSetting_MIO:(ScreenSetting*)setting;


/**
 *  get exercise setting from MIO device, e.g.: Alpha 1.5,
 *
 */
-(MIOErrorCode_t) GetScreenSetting_MIO;




//
// Enable/Disable GPS mode of the MIO device.
//
//-(MIOErrorCode_t)SetDeviceGPSStatus_MIO:(MIORunCMDType_t)type;
-(MIOErrorCode_t)SetDeviceGPSStatus_MIO:(BOOL)bEnable;


//
// Send GPS data to mio device.
//
// parameter:  speed -> 0.1KPH     odometer  -> 0.001 km.
//
//
-(MIOErrorCode_t)SendGPSData_MIO:(ACQStatusType_t)flags speed:(unsigned short)speed odometer:(unsigned short)odometer;



//Enter SYNC mode for download record.
-(MIOErrorCode_t)StartSYNC_MIO;


//Exit SYNC mode .
-(MIOErrorCode_t)EndSYNC_MIO;

//
//Get today ADL data from MIO device, e.g.: Fuse.
//
-(MIOErrorCode_t)GetTodayADLrecord_MIO:(BOOL)delFlag;


//
//Reset today ADL data to MIO device, e.g.: Fuse.
//
-(MIOErrorCode_t)ResetTodayADLrecord_MIO;




//
//Get all records of daily ADL data from MIO device, e.g.: Fuse.
//
-(MIOErrorCode_t)GetAllRecordOfDailyADL_MIO:(BOOL)delFlag;

//
//Delete all records of daily ADL data from MIO device, e.g.: Fuse.
//
-(MIOErrorCode_t)DeleteAllDailyADLrecord_MIO;



//
//Get total number of Workout record ofrom MIO device, e.g.: Fuse.
//
//-(MIOErrorCode_t)GetTotalNumberOfWorkoutRecord_MIO:(BOOL)delFlag;
-(MIOErrorCode_t)GetAllRecordOfWorkout_MIO:(BOOL)delFlag;






//
//Get one of Workout record ofrom MIO device, e.g.: Fuse.
//
//-(MIOErrorCode_t)GetOneOfWorkoutRecord_MIO:(unsigned short)Index;


//
//Stop getting workout record from device, e.g.: Fuse.
//
//-(MIOErrorCode_t)stopWorkoutRecord_MIO;
-(MIOErrorCode_t)StopWorkoutRecord_MIO;

//
//Delete all records of Workout record from MIO device, e.g.: Fuse.
//
-(MIOErrorCode_t)DeleteAllWorkoutrecord_MIO;

//
//Get total number of Activity record ofrom MIO device, e.g.: Fuse.
//
-(MIOErrorCode_t)GetAllRecordOfActivity_MIO:(BOOL)delFlag;

//
//Stop getting activity record from device, e.g.: Fuse.
//
-(MIOErrorCode_t)StopActivityRecord_MIO;

//
//Delete all records of Activity record from MIO device, e.g.: Fuse.
//
-(MIOErrorCode_t)DeleteAllActivityrecord_MIO;

/**
 *  ConvertRawWorkoutData_MIO
 *  @param rawData
 *  @return   MIO_ERRCODE_NOERROR
 *  @note  Change the speed unit from 1kph to 0.01kph.
 */
-(WorkoutRecordData*)ConvertRawWorkoutData_MIO:(NSData*)rawData;


//
//Calc MHR by age, gender, rhr.
//
-(int)CalcMHR:(int)age male:(BOOL)isMale  rhr:(int)rhr;





- (MIOErrorCode_t)GetAllRecordOfAlpha_MIO:(BOOL)DelFlag;

//- (MIOErrorCode_t)DeleteRecordOfAlpha_MIO:(MIODeleteOptionType_t)type;

- (MIOErrorCode_t)StopGetRecordOfAlpha_MIO;


// Delete all records from Alpha2, add by 2014-11-14.
- (MIOErrorCode_t)DeleteAllRecordOfAlpha_MIO;


/**
 *  ExeTimerSyncDataNotificationDisable from MIO device, e.g.: FUSE, Alpha2
 *
 */
-(MIOErrorCode_t) ExeTimerSyncDataNotificationDisable_MIO;

-(MIOErrorCode_t) ExeTimerSyncDataNotificationEnable_MIO;

-(MIOErrorCode_t) ExeTimerSyncStartTimer_MIO;

-(MIOErrorCode_t) ExeTimerSyncStopTimer_MIO;

-(MIOErrorCode_t) ExeTimerSyncTakeLap_MIO;

-(MIOErrorCode_t) ExeTimerSyncResendLastLapData_MIO;

-(MIOErrorCode_t) ExeTimerSyncFinish_MIO;


/**
 *  GetConfigOfVelo_MIO
 *  @param
 *  @return   MIO_ERRCODE_NOERROR
 *  @note
 */
- (MIOErrorCode_t)GetConfigOfVelo_MIO;

/**
 *  MemAllClear_MIO
 *  @param
 *             type:TYPE_WOMEM,TYPE_ADLMEM,TYPE_ACTMEM;
 *  @return   MIO_ERRCODE_NOERROR
 *  @note
 */
-(MIOErrorCode_t) MemAllClear_MIO:(int)type;

/**
 *  SleepModeDeactivate_MIO
 *  @param
 *  @return   MIO_ERRCODE_NOERROR
 *  @note
 */
-(MIOErrorCode_t) SleepModeDeactivate_MIO;

/**
 *  SleepModeActivate_MIO
 *  @param
 *  @return   MIO_ERRCODE_NOERROR
 *  @note
 */

-(MIOErrorCode_t) SleepModeActivate_MIO;

/**
 *  ConvertSleepData_MIO
 *  @param
 *  @return SleepTracking
 *  @note
 */

-(SleepTracking)ConvertSleepData_MIO:(Activity1Hour*)arAct size:(int)size sleepTime:(DATTIME)dtSleep getupTime:(DATTIME)dtGetup;
//-(SleepTracking *)ConvertSleepData2_MIO:(Activity1Hour*)arAct size:(int)size;


/**
 *  RestHRTakeMeasurement_MIO
 *  @param
 *  @return   MIOErrorCode_t
 *  @note
 */
-(MIOErrorCode_t) RestHRTakeMeasurement_MIO;

/**
 *  RestHRStopMeasurement_MIO
 *  @param
 *  @return   MIOErrorCode_t
 *  @note
 */
-(MIOErrorCode_t) RestHRStopMeasurement_MIO;

/**
 *  RestHRSendMeasurementResults_MIO
 *  @param
 *  @return   MIOErrorCode_t
 *  @note
 */
-(MIOErrorCode_t) RestHRSendMeasurementResults_MIO;


-(MIOErrorCode_t) CaliStrideOfTreadmill_MIO:(unsigned short)preStartTime testTime:(unsigned short)times speed:(float)speed gender:(BYTE)gender height:(int)height;
-(MIOErrorCode_t) SetCaliStrideFactor_MIO:(BOOL)bEnable clearFlag:(BOOL)bClear WalkFactor:(float)walkFactor RunFactor:(float)runFactor;
-(MIOErrorCode_t) GetCaliStrideFactor_MIO;

-(MIOErrorCode_t) CaliStrideOfGPS_MIO:(unsigned short)preStartTime testTime:(unsigned short)testTime gender:(BYTE)gender height:(int)height;
-(MIOErrorCode_t) CaliStrideSetCurDis_MIO:(float)dis;

-(MIOErrorCode_t) CaliStrideOfDis_MIO:(unsigned short)preStartTime testTime:(unsigned short)testTime gender:(BYTE)gender height:(int)height dis:(float)fDis;
-(MIOErrorCode_t) CaliStrideStopCalitimer_MIO;
-(MIOErrorCode_t) CaliStrideStopPretimer_MIO;

-(MIOErrorCode_t) GetMisc1_MIO;
-(MIOErrorCode_t) SetMisc1_MIO:(Misc1Config *)pMic1Config;

-(MIOErrorCode_t) GetAlarmClock_MIO:(BYTE)index;
-(MIOErrorCode_t) SetAlarmClock_MIO:(BYTE)almStatus Alm:(AlarmClock *)pAlarmClock;

-(MIOErrorCode_t) GetDeviceOption_MIO;
-(MIOErrorCode_t) SetDeviceOption_MIO:(unsigned char)optCode;

//----------------------------------------------------------------------------------------------------------------//
//   private sdk api

//function: enter shipment mode from normal mode.
- (MIOErrorCode_t)EnterToShipmentModeFromNormal_MIO;


//function: enter shipment mode from factory mode.
- (MIOErrorCode_t)EnterToShipmentModeFromFactory_MIO;

- (BOOL)HasRSCData_MIO;
- (MIOErrorCode_t)GetRSCData_MIO:(RSCData *)pRSCData;

/**
 * Returns a boolean value indicating whether new RHR data is available.
 *
 * @return <c>TRUE</c> if new data is available since the last time
 * read data was invoked, otherwise <c>FALSE</c>.
 */
- (BOOL)HasRHRData_MIO;

/**
 * Retrieves the most current RHR data available from the sensor.
 *
 *
 * @return  Rest Hate rate.
 */
- (unsigned char)GetDataOfRHR_MIO;


-(void) SetHRVDataStreaming_MIO:(BOOL)isEnable;
-(BOOL) GetHRVDataStreaming_MIO;
-(BOOL) HasHRVData_MIO;
-(HRVData *)GetHRVData_MIO;

@end









//
//  MIODeviceConnectionDelegate.h
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//


#import "MIOCommonType.h"


@class MIODeviceConnection;


/**
 * Provides the interface for callback methods used by the MIODeviceConnection.
 */
@protocol MIODeviceConnectionDelegate <NSObject>

@required


/**
 * Invoked when the device is ready for operation, eg: read device information, change device  setting.
 *
 * @param connectionInfo The MIODeviceConnection instance.
 */
- (void)DeviceIsReady:(MIODeviceConnection*)connectionInfo  state:(MIODeviceState_t)state;


/**
 * Invoked when the MIODeviceConnection fails to connect to a device before
 * the specified timeout period ellapses.
 *
 * @param connectionInfo The MIODeviceConnection instance.
 */
- (void)ConnectionDidTimeout_MIO:(MIODeviceConnection*)connectionInfo;

/**
 * Invoked when the MIODeviceConnection has changed connection state.
 *
 * @param connectionInfo The MIODeviceConnection instance.
 *
 * @param connState A ::MIODeviceConnectionStatus_t value indicating the
 * current connection state.
 */
- (void)Connection_MIO:(MIODeviceConnection*)connectionInfo stateChanged:(MIODeviceConnectionStatus_t)connState;

/**
 * Alerts the delegate that data is available.
 *
 * This method may be invoked only when new data is availabe, or on a
 * specified interval.
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DeviceHasData_MIO:(MIODeviceConnection*)connectionInfo;



@optional


/**
 * Alerts the delegate that the device is enter OTA mode.
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)TimeoutForLastCommand_MIO:(MIODeviceConnection*)connectionInfo;


/**
 * Alerts the delegate that the device is enter OTA mode.
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DidEnterOTAmode_MIO:(MIODeviceConnection*)connectionInfo ret:(BOOL)ret;   //Add by zb,2014-03-23.


/**
 * Alerts the delegate that get device memory state.
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DidCheckIsMemFull_MIO:(MIODeviceConnection*)connectionInfo isFull:(BOOL)isFull resp:(unsigned char)respCode;



/**
 * Alerts the delegate that get device  status.
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DidGetDeviceStatus_MIO:(MIODeviceConnection*)connectionInfo status:(MioDeviceStatus*)status resp:(unsigned char)respCode;




/**
 * Alerts the delegate that the device has been unlocked.
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DeviceUnlocked_MIO:(MIODeviceConnection*)connectionInfo;



/**
 * Alerts the delegate that the device has reply to the SetHRZoneSetting_MIO,
 *
 * @param respCode The response code.
 */
-(void)DidSetHRZoneSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode; //<<<< NEW FUNCTION >>>>>


/**
 * Alerts the delegate that the device has read HR zone setting from the ble device.
 *
 * @param respCode The response code.
 */
-(void)DidGetHRZoneSetting_MIO:(MIODeviceConnection*)connectionInfo zone:(HRZone*)zone resp:(unsigned char)respCode;  //<<<< NEW FUNCTION >>>>>


/**
 * Alerts the delegate that the device has reply to the SetHRZoneSetting_MIO,
 *
 * @param respCode The response code.
 */
-(void)DidSetANTPlusStatus_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode; //<<<< NEW FUNCTION >>>>>


/**
 * Alerts the delegate that the device has reply to the GetHRZoneSetting_MIO,
 *
 */
-(void)DidGetANTPlusStatus_MIO:(MIODeviceConnection*)connectionInfo state:(ANTPlusState_t*)pState resp:(unsigned char)respCode;   //<<<< NEW FUNCTION >>>>>

/**
 * Alerts the delegate that got battery level from Alpha2
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DidGetBatteryfromAlpha2_MIO:(MIODeviceConnection*)connectionInfo batt:(BYTE)batt resp:(unsigned char)respCode;


/**
 * Alerts the delegate that got battery level(0-100).
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DidGetBatteryLevel_MIO:(MIODeviceConnection*)connectionInfo batt:(BYTE)batt resp:(unsigned char)respCode;




/**
 * Alerts the delegate that changed the device name.
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DidChangedDeviceName_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


/**
 * Alerts the delegate that changed the device name.
 *
 *
 * @param sensor The MIODeviceSensor instance.
 */
- (void)DidSwitchToAirplaneMode_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


//=============================================================================================//
//   Add below functions for MIO Velo

/**
 * Alerts the delegate that the device have some incoming data.
 *
 *
 * @param connectioninfo: The MIODeviceConnection instance.
 *
 *  @param type:  the incoming data type.
 *
 *  Devices: LINK, VELO, FUSE, ALPHA, ALPHA2
 */
- (void)DeviceHasData_MIO:(MIODeviceConnection*)connectionInfo type:(MIODataType_t)type;

/**
 * Alerts the delegate that the device have find some Ant+ sensor.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param DeviceParams:  a array include the Ant+ sensor object.
 *  @param bCompleted:   the searching is complete, or not complete.
 *
 *  Devices: VELO,
 */
- (void)BikeSensorPairDeviceFound_MIO:(MIODeviceConnection*)connectionInfo didFoundDevices:(NSArray*)DeviceParams searchCompleted:(BOOL)bCompleted;

/**
 * Alerts the delegate that the device have config the bike’s Ant+ sensors.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param respCode:   the respond code.
 *  Devices: VELO,
 */
- (void)DidSetBikeSensorSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/*
* Alerts the delegate that the device have got the bike’s Ant+ sensors.
*
*
*  @param connectioninfo: The MIODeviceConnection instance.
*  @param bikeID:        the bike index 1 - 4
*  @param sensorList:   a array include the Ant+ sensors object.
*  Devices: VELO,
*/
- (void)DidGetBikeSensorSetting_MIO:(MIODeviceConnection*)connectionInfo bike:(UInt8)bikeID sensor:(NSArray*)sensorList;

/**
 * Alerts the delegate that the device have cleared the setting of the bike’s Ant+ sensors.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param respCode:        the respond code
 *  Devices: VELO,
 */
- (void)DidClearBikeSensorSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 * Alerts the delegate that the device have enabled or disabled the Ant+ sensor channel.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param respCode:        the respond code
 *  Devices: VELO,
 */
//- (void)DidEnableBikeSensorChanel_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 * Alerts the delegate that the device have enabled or disabled the Ant+ sensor channel.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param respCode:        the respond code
 *  Devices: VELO,
 */
//- (void)DidDisableBikeSensorChanel_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


/**
 * Alerts the delegate that the device have set the Ant+ sensor channel.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param respCode:        the respond code
 *  Devices: VELO,
 */
- (void)DidSetBikeSensorChannels_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


/**
 * Alerts the delegate that the device have enabled or disabled the Ant+ sensor channel.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param respCode:        the respond code
 *  Devices: VELO,
 */
//- (void)DidUpdateConfigOfVelo_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;
- (void)DidSetConfigOfVelo_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


/**
 * Alerts the delegate that the device have enabled or disabled the Ant+ sensor channel.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param respCode:        the respond code
 *  Devices: VELO,
 */
- (void)DidGetConfigOfVelo_MIO:(MIODeviceConnection*)connectionInfo apptype:(MIOVeloAppType_t)AppType resp:(unsigned char)respCode;

- (void)DidGetConfigOfVelo_MIO:(MIODeviceConnection*)connectionInfo VeloConfig:(VELOConfig)config resp:(unsigned char)respCode;

/**
 * Alerts the delegate that the Velo is use which bike now.
 *
 *
 *  @param connectioninfo: The MIODeviceConnection instance.
 *  @param bikeNum:        the bike number used now, range: 1 - 4.
 *  Devices: VELO,
 */
- (void)UpdateActiveBikeNum_MIO:(MIODeviceConnection*)connectionInfo bikeNum:(MIOBikeIndex_t)bikeNum;


/**
 *  read time from LINK1 DEVICE. e.g.: Link1, Velo.
 *
 */
-(void) DidGetRTCtimeInner_MIO:(MIODeviceConnection*)connectionInfo time:(RTCtime*)curTime ;


/**
 *  set time to LINK1 DEVICE.  e.g.: Link1, Velo.
 *
 */
-(void) DidSetRTCtimeInner_MIO:(MIODeviceConnection*)connectionInfo ;


//=============================================================================================//



//=============================================================================================//
//   Add below functions for MIO Link2, Alpha1.5

/**
 *  Alerts the delegate that the device has changed the RTC time.
 *
 */
-(void) DidSetRTCTime_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 *  Alerts the delegate that has read the RTC time from the device.
 *
 */
-(void) DidGetRTCTime_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode  time:(RTCSettings*)time;


/**
 *  Alerts the delegate that the device has changed the user info.
 *
 */
-(void) DidSetUserInfo_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 *  Alerts the delegate that has read the user info from the device.
 *
 */
-(void) DidGetUserInfo_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode  info:(UserSettings*)info;


/**
 *  Alerts the delegate that the device has changed the display setting.
 *
 */
-(void) DidSetDispSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 *  Alerts the delegate that has read the display setting from the device.
 *
 */
//-(void) DidGetDispSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode  adl:(ADLdisplay*)adl wo:(WOdisplay*)wo lockTimer:(BYTE)timeout;
-(void) DidGetDispSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode  adl:(ADLdisplay*)adl wo:(WOdisplay*)wo ADLlockTimer:(BYTE)timeout1 WOlockTimer:(BYTE)timeout2;


/**
 *  Alerts the delegate that the device has changed the daily goal.
 *
 */
-(void) DidSetDailyGoal_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 *  Alerts the delegate that has read the daily goal from the device.
 *
 */
-(void) DidGetDailyGoal_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode  todayGoal:(GoalSetting*)todayGoal dailyGoal:(GoalSetting*)dailyGoal;


/**
 *  Alerts the delegate that the device has changed the exercise setting.
 *
 */
-(void) DidSetExerciseSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 *  Alerts the delegate that has read the exercise setting from the device.
 *
 */
-(void) DidGetExerciseSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode  setting:(ExerciseSetting*)setting;


/**
 *  Alerts the delegate that the device has changed the exercise setting.
 *
 */
-(void) DidSetScreenSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

/**
 *  Alerts the delegate that has read the exercise setting from the device.
 *
 */
-(void) DidGetScreenSetting_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode  setting:(ScreenSetting*)setting;



-(void)DidSetGPSStatus_MIO:(MIODeviceConnection*)connectionInfo bEnable:(BOOL)bEnable resp:(unsigned char)respCode;




-(void)DidStartSYNC_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


-(void)DidEndSYNC_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

//
//Alerts the delegate that get today ADL record from device.
//
-(void)DidGetTodayADLrecord_MIO:(MIODeviceConnection*)connectionInfo data:(ADLTodayData *)data resp:(unsigned char)respCode;


//
//Alerts the delegate that reset today ADL record to device.
//
-(void)DidResetTodayADLrecord_MIO:(MIODeviceConnection*)connectionInfo  resp:(unsigned char)respCode;

//
//Alerts the delegate that get a Daily ADL record from device.
//
//-(void)DidGetRecordOfDailyADL_MIO:(MIODeviceConnection*)connectionInfo data:(ADLDailyData *)data resp:(unsigned char)respCode;

//
//Alerts the delegate that get all Daily ADL records from device.
//
-(void)DidGetAllRecordOfDailyADL_MIO:(MIODeviceConnection*)connectionInfo records:(NSArray*)records resp:(unsigned char)respCode;


//
//Alerts the delegate that deleted all daily ADL record.
//
-(void)DidDeleteAllDailyADLrecord_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


//
//Alerts the delegate that get total number of Workout record
//
-(void)DidGetTotalNumberOfWorkoutRecord_MIO:(MIODeviceConnection*)connectionInfo num:(unsigned int)number resp:(unsigned char)respCode;


//
//Get one of Workout record ofrom MIO device, e.g.: Fuse.
//
-(void)DidGetOneOfWorkoutRecord_MIO:(MIODeviceConnection*)connectionInfo sum:(WorkoutRecordSummary*)summary LogData:(NSData*)LogData isFinish:(BOOL)isFinish resp:(unsigned char)respCode;

-(void)DidGetOneOfVeloWorkoutRecord_MIO:(MIODeviceConnection*)connectionInfo sum:(VELOSummary*)summary isFinish:(BOOL)isFinish resp:(unsigned char)respCode;

//
//Alerts the delegate that get total number of Workout record
//
//-(void)DidGetAllRecordOfWorkout_MIO:(MIODeviceConnection*)connectionInfo  resp:(unsigned char)respCode;


//
//Alerts the delegate that stopped the download record.
//
-(void)DidStopWorkoutRecord_MIO:(MIODeviceConnection*)connectionInfo  resp:(unsigned char)respCode;


//
//Alerts the delegate that deleted all Workout record.
//
-(void)DidDeleteAllWorkoutrecord_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


//
//Alerts the delegate that get total number of Workout record
//
-(void)DidGetTotalNumberOfActivityRecord_MIO:(MIODeviceConnection*)connectionInfo num:(unsigned int)number resp:(unsigned char)respCode;


//
//Get one of Activity record ofrom MIO device, e.g.: Fuse.
//
-(void)DidGetOneOfActivityRecord_MIO:(MIODeviceConnection*)connectionInfo index:(int)index actHourList:(Activity1Hour*)actHourList size:(int)size RawData:(NSData*)rawData isFinish:(BOOL)isFinish resp:(unsigned char)respCode;

/*
 * 回调函数，同步Activity Data之后，SDK调用此函数回传SleepTracking2
 * connectionInfo -- MIODeviceConnection
 * pListData -- SleepTracking2链表的表头，可以通过SleepTracking2.next或SleepTracking2.prev遍历整个链表
 * rawData -- 睡眠相关的原始数据,一般仅用于调试时使用
 * respCode -- 报告代码
 */
-(void)DidGetSleepTrackList_MIO:(MIODeviceConnection*)connectionInfo DataList:(SleepTracking2 *)pListData RawData:(NSData*)rawData resp:(unsigned char)respCode;


//
// this Progress is changed for Get Activity Record, e.g.: Fuse.
//
-(void)DidGetActivityRecordProgress_MIO:(MIODeviceConnection*)connectionInfo progress:(float)progress resp:(unsigned char)respCode;


//
//Alerts the delegate that get total number of Workout record
//
//-(void)DidGetAllRecordOfWorkout_MIO:(MIODeviceConnection*)connectionInfo  resp:(unsigned char)respCode;


//
//Alerts the delegate that stopped the download record.
//
-(void)DidStopActivityRecord_MIO:(MIODeviceConnection*)connectionInfo  resp:(unsigned char)respCode;


//
//Alerts the delegate that deleted all Workout record.
//
-(void)DidDeleteAllActivityRecord_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


//- (void)DidGetTotalNumberofAlpha2Record_MIO:(MIODeviceConnection*)connectionInfo sum:(Alpha2RecordSummary*)summary resp:(unsigned char)respCode;
- (void)DidGetTotalNumberofAlpha2Record_MIO:(MIODeviceConnection*)connectionInfo num:(unsigned int)number resp:(unsigned char)respCode;

//- (void)DidGetRecordOfAlpha2_MIO:(MIODeviceConnection*)connectionInfo records:(NSArray*)records resp:(unsigned char)respCode;


- (void)DidGetRecordDataOfAlpha2_MIO:(MIODeviceConnection*)connectionInfo recordData:(Alpha2RecordData *)recordData isFinish:(BOOL)isFinish resp:(unsigned char)respCode;


//- (void)DidDeleteRecordOfAlpha2_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;
//- (void)DidGetAllRecordOfAlpha_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


- (void)DidStopGetRecordOfAlpha2_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


- (void)DidDeleteAllRecordOfAlpha2_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;


- (void)DidExeTimerSyncDataNotificationDisable_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidExeTimerSyncDataNotificationEnable_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidExeTimerSyncStartTimer_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidExeTimerSyncStopTimer_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidExeTimerSyncTakeLap_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidExeTimerSyncResendLastLapData_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidUpdateWithExeTimerSync_MIO:(MIODeviceConnection*)connectionInfo info:(EXE_TIMERSYNC_INFO*)eti_data;

- (void)DidExeTimerSyncFinish_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidMemAllClear_MIO:self type:(unsigned int)type resp:(unsigned char)respCode;

- (void)DidSleepModeDeactivate_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidSleepModeActivate_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidRestHRTakeMeasurement_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidRestHRStopMeasurement_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidRestHRSendMeasurementResults_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

- (void)DidCaliStrideOfTreadmill_MIO:(MIODeviceConnection*)connectionInfo status:(unsigned char)statusCode flag:(unsigned char)flag data:(float)data;

- (void)DidCaliStrideOfGPS_MIO:(MIODeviceConnection*)connectionInfo status:(unsigned char)statusCode flag:(unsigned char)flag data:(float)data;

- (void)DidCaliStrideOfDis_MIO:(MIODeviceConnection*)connectionInfo status:(unsigned char)statusCode flag:(unsigned char)flag data:(float)data;

- (void)DidSetCaliStrideFactor_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode enable:(BOOL)bEnable clearFlag:(BOOL)bClearFlag;

- (void)DidGetCaliStrideFactor_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode enable:(BOOL)bEnable walkFactor:(float)fWalkFactor runFactor:(float)fRunFactor;

-(void) DidGetMisc1_MIO:(MIODeviceConnection*)connectionInfo misc1Config:(Misc1Config *)misc1Config resp:(unsigned char)respCode;
-(void) DidSetMisc1_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

-(void) DidGetAlarmClock_MIO:(MIODeviceConnection*)connectionInfo AlmStatus:(BYTE)almStatus alarmClock:(AlarmClock *)alarmClock resp:(unsigned char)respCode;
-(void) DidSetAlarmClock_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

-(void) DidGetDeviceOption_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode opt:(unsigned char)optCode;
-(void) DidSetDeviceOption_MIO:(MIODeviceConnection*)connectionInfo resp:(unsigned char)respCode;

@end





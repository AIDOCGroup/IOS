//
//  LandiReader.h
//  LandiReader
//
//  Created by HudongFang on 16/2/10.
//  Copyright © 2016年 LANDI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "CommonClass.h"

@interface LakalaBand : NSObject

+ (instancetype) shareInstance;

#pragma mark ---------------  工具
/**
 *  NSDATA      ------> hexString
 */
+(NSString *)nsdata2HexString:(NSData *)dataIn;
/**
 *  hexString   ------> NSDATA
 */
+(NSData *)hexString2nsdata:(NSString *)dataIn;

/**
 * 获取运动卡路里
 * @param sex 性别（YES男，NO女）
 * @param height 身高(cm)
 * @param weight 体重（kg）
 * @param age 年龄(year)
 * @param run 跑步步数(step)
 * @param walk 走路步数(step)
 */
+ (int)getCalorie:(bool)sex height:(int)height weight:(int)weight age:(int)age run:(int)run walk:(int)walk;

/**
 *  获取SDK版本号
 */
+ (NSString *)getLibVersion;

/**
 *  结束使用SDK
 */
- (void)closeDevice;

/**
 *  LOG开关
 */
- (void)switchLog:(BOOL)log;
#pragma mark ---------------  设备连接接口
/**
 *  搜索设备，支持同时搜索蓝牙和音频设备
 *
 *  @param timeout      搜索设备的超时时间
 *  @param listener     搜索设备的监听器
 */
- (void)startSearchDev:(NSInteger)timeout searchListener:(id<SearchDeviceListener>)listener;

/**
 *  搜索蓝牙设备
 *
 *  @param timeout      搜索设备的超时时间
 *  @param listener     搜索设备的监听器
 */
- (int)searchBluetoothDev:(NSInteger)timeout searchListener:(id<SearchDeviceListener>)listener;

-(void)setHealthDataChangeListener:(id<HealthDataChangeListener>)listener;

/**
 *  停止搜索设备
 */
- (void)stopSearchDev;

/**
 *  连接音频设备
 *
 *  @param listener     连接设备的监听器
 */
- (void)connectDeviceWithAudio:(id<ConnectDeviceListener>)listener;

/**
 *  连接蓝牙设备
 *
 *  @param deviceUUID   连接的蓝牙设备的UUID
 *  @param listener     连接设备的监听器
 */
- (void)connectDeviceWithBluetooth:(NSString *)deviceUUID withListener:(id<ConnectDeviceListener>)listener;

/**
 *  连接蓝牙设备,同步的方式
 */
-(BOOL)connectDeviceWithBluetoothSyn:(NSString *)deviceUUID withListener:(id<ConnectDeviceListener>)listener;
/**
 *  连接蓝牙设备
 *
 *  @param deviceUUID   连接的蓝牙设备的UUID
 *  @param timeOut      连接最大超时时间
 *  @param listener     连接设备的监听器
 */
-(void)connectDeviceWithBluetooth:(NSString *)deviceUUID timeOut:(int)timeOut withListener:(id<ConnectDeviceListener>)listener;

/**
 *  当前是否有设备连接
 */
- (BOOL)isConnect;

/**
 *  取消操作
 */
- (void)cancelCommand;

/**
 *  获取设备信息
 *
 *  @return 设备信息
 */
-(DeviceInfo *) deviceInfo;

/**
 *  同步设备时间
 *
 *  @return BOOL
 */
-(BOOL) setSysTime:(NSDate *) date;

/**
 *  获取设备时间
 *
 *  @return NSDate
 */
-(NSDate*) getSysTime;

- (NSData*)powerOnWithSlot:(ICCardSlot)slot;

- (void)powerOffWithSlot:(ICCardSlot)slot;

- (NSData*)callWithSlot:(ICCardSlot)slot req:(NSData*)req timeout:(NSTimeInterval)timeout;

/**
 *  获取TLV数据
 *
 *  @param tags tag列表
 *
 *  @return tlv数据 (字典key为NSNumber，字典对应object为NSData)
 */
-(NSDictionary*)valuesForTags:(NSArray*)tags;
/*!
 *  设置TLV数据
 *
 *  @param tlvInfos tlv数据(字典key为NSNumber，字典对应object为NSData/十六进制NSString，如果是实现清空tag则对应value必须为0x00)
 *
 *  @return 设置是否成功
 */
- (BOOL)setTagValues:(NSDictionary*)tlvInfos;

-(void)setBalanceRemind:(NSData *)data;

-(NSData *)balanceRemind;

-(void)setCurrentSportTarget:(NSData *)target;

-(void)setCurrentSleepTarget:(NSData *)target;

-(NSData *)currentSleepTarget;

-(NSData *)currentSportTarget;

-(void)setStepLenght:(LDStepLength *)stepLenght;

-(LDStepLength *)stepLenght;

-(int)currentCalorie;

-(int)currentDistance;

-(void)findBracelet:(NSData *)data;

-(void)setAlarmClock:(int)tag data:(NSData *)data;

-(NSData *)alarmClock:(int)tag;

- (int)heartRate;

-(int)getHeartRateWarningValue;

-(BOOL)setHeartRateWarningValue:(int) value;

-(BOOL)startRealTimeHeartRate;

-(BOOL)stopRealTimeHeartRate;

-(int)batteryPercent;

-(void)setCallRemind:(NSData *)data;

-(void)setShortMsgRemind:(NSData *)data;

-(void)setSocialRemind:(NSData *)data;

-(void)setRemind:(NSData *)data;

-(NSData *)remind;

-(void)setBTSpeedRate:(int)speed;

-(void)setTimeDisplayFormat:(Byte)type;

-(void)setDisplayFlag:(Byte)flag;

-(Byte)displayFlag;

-(void)setrunningDisplayFlag:(Byte)flag;

-(Byte)runningDisplayFlag;

-(LDPersonal *)personalParams;

-(void)setPersonalParams:(LDPersonal *)params;

-(BOOL)bindBand:(NSData *)data;

-(void)setBandBtName:(NSString *)name;

-(NSData *)readFileOrRecord:(FileType)fileType fileName:(NSData *)fileName;

-(BOOL)flushBalance:(NSData *)aid;

-(BOOL)delFileOrRecord:(FileType)fileType;

-(int)currentSteps;

-(void)setSittingRemind:(NSData *)sitRemindData;

-(NSData *)sittingRemind;

-(void)restoreFactory:(NSData *)restoreData;

-(NSData *)currentSportRecord;

-(void)setCurrentSportRecord;

-(NSData *)historySportRecord:(int)day;

-(void)setHistorySportRecord:(int)day;

-(NSData *)currentSleepRecord;

-(void)setCurrentSleepRecord;

-(void)setHistorySleepRecord:(int)day;

-(NSData *)historySleepRecord:(int)day;

-(NSData *)effectiveSprotTaglist;

-(NSData *)effectiveSleepTaglist;

-(void)clearSportRecords;

-(void)clearSleepRecords;

-(void)setHandUpCtrl:(NSData *)data;

-(NSData *)handUpCtrl;

-(void)setNoonBreak:(NSData *)data;

-(NSData *)noonBreak;

-(int)handUpBackLightTime;

-(void)setHandUpBackLightTime:(int)handUpTime;

-(int)touchBackLightTime;

-(void)setTouchBackLightTime:(int)touchTime;

-(void)setSysPowerSaveTime:(int)standbyTime dormantTime:(int)dormantTime shutDownTime:(int)shutdownTime;

-(NSData *)cycleDataTest:(NSData *)sendData;

-(BOOL)writeSEL78:(int)page data:(NSData *)data;

-(NSData *)readSEL78:(int)page;

-(NSData *)sendRawData:(NSData *)sendData;

-(BOOL)setBatchNum:(NSString *)numbers;

-(NSString *)batchNum;

-(void)setMerchantName:(NSString *)name;

-(NSString *)merchantName;

-(void)setAppData:(NSString *)appData;

-(NSString *)appData;

-(BOOL)openAncsFlag:(BOOL)flag;

-(BOOL)isAncsExist;

-(NSString *)getEMVkernelVersion:(unsigned char)type;

-(EMVRet *)EMVkernelInit;

-(EMVRet *)EMVSetAid:(NSData *)aid partSelect:(BOOL)partSlt;

-(EMVRet *)EMVStart:(Byte) transType amout:(int)amount transDate:(NSData *)transDate forceOnline:(BOOL)forceOnline;

-(EMVRet *)EMVContinueTrade:(int) aidNo;

-(EMVRet *)EMVGetDolData:(NSData *)tags;

-(EMVRet *)EMVSecondIssuance:(NSData *)onlineData;

-(EMVRet*)EMVStop;

-(EMVRet*)EMVTradeLog;
@end

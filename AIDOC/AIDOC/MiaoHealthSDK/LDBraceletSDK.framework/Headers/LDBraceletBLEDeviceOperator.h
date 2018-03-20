//
//  LDBraceletBLEOperator.h
//  LDBraceletSDK
//
//  Created by houhm on 16/11/24.
//  Copyright © 2016年 houhm. All rights reserved.
//


#ifndef LDBraceletBLEDeviceOperator_h
#define LDBraceletBLEDeviceOperator_h
#import "CommonClass.h"

@class DeviceBaseInfo;
@class DeviceInfo;
@class LDPersonal;

@protocol LDBraceletBLEDeviceOperator

- (NSString *)sdkVersion;

- (void)searchDevWithTime:(NSInteger)timer
    foundOneDeviceHandler:(void(^)(DeviceBaseInfo *deviceInfo))foundOneDeviceHandler
          completeHandler:(void(^)(NSArray *allDevices))completeHandler;

- (void)stopSearchDev;

- (void)setBTEvenCBFlag:(BOOL)flag;

- (void)connectDevUUID:(NSString *)UUID;

- (BOOL)synReconnectDev;

- (BOOL)isConnect;

- (void)disConnectDev;

- (DeviceInfo *)deviceInfo;

- (void)findBracelet:(NSString *)data;

- (void)setDeviceSysTime:(NSDate *)date;

- (NSDate *)deviceSysTime;

- (NSData *)powerOnSlot:(NSInteger)slot cardType:(NSInteger)cardType;

- (void)powerOffSlot:(NSInteger)slot cardType:(NSInteger)cardType;

- (NSData*)callWithSlot:(ICCardSlot)slot req:(NSData*)req;

- (void)setSysSuspendTime:(NSInteger)suspendTime dormantTime:(NSInteger)dormantTime shutdownTime:(NSInteger)shutdownTime;

- (void)restoreFactory:(NSArray *)types;

- (int)batteryPower;

- (BOOL)bindDevice:(NSData *)data;

- (void)updateFirmware:(NSString *)path progressBlock:(void(^)(float progress))progressBlock successBlock:(void(^)()) successBlock failedeBlock:(void(^)(int failCode,NSString *failInfo))failedBlock;

-(void)changeBTName:(NSString *)name;

- (BOOL)writeProfileWith:(NSString *)fileName
             inputStream:(NSInputStream*)input
                fileType:(FileType )fileType
           progressBlock:(void(^)(float progress))progressBlock
            successBlock:(void(^)()) successBlock
            failedeBlock:(void(^)(int failCode,NSString *failInfo))failedBlock;

-(NSData *)readFileOrRecord:(FileType)fileType fileName:(NSData *)fileName;

- (NSData*)writeSEL78:(NSData*)data;

- (NSData*)readSEL78:(NSData*)data length:(int)len;

- (BOOL)isAncsExist;

- (BOOL)openAncs;

//设置蓝牙速率
- (void)setBTRate:(int)rate;

//设置应用数据
- (void)setAppData:(NSString *)data;

//获取应用数据
- (NSString *)appData;

- (void)setAutoBTspeed:(BOOL)autoBTspeedEnable;

/**
 * 设置久坐提醒
 * @param start 提醒起始时间
 * @param end   提醒中止时间
 * @param flag  1:打开；0：关闭
 * @param time 久坐提醒时间 单位：分钟
 *
 **/
-(void)setSittingRemind:(int)start end:(int)end open:(int)flag time:(int)time;

/*
 *设置界面显示选项
 *显示选项顺序如下：
 *卡包  步数 里程 卡路里  心率 睡眠 电量
 *目前七位（如后续新增显示选项，依次往后排），默认值为：1111111
 *每个标识位 有三种值 0，1，其他
 *0:设置为不显示
 *1：设置为显示
 *其他：不设置 例如：3或着2，或者2-9以内均可
 *例如：1333301   设置卡包，电量显示，睡眠隐藏，其他不设置（维持先前配置）
 */
-(void)setDisplayFlags:(NSString *)flag;

-(NSString *)displayFlags;

/**
 * 抬手亮屏时间设置
 * @param start  起始时间 例如：如设置09：30 则值为  930
 * @param end   中止时间 例如：如设置18：30 则值为  1830
 * @param time     抬手亮屏时间   单位：秒
 **/
-(void) setRaise2WakeOptions:(int)start end:(int)end time:(int)time;

/**
 * 获取抬手亮屏时间设置
 *
 * 返回数据包含以下：
 {
 start: NSString  起始时间 例如：如设置09：30 则值为  930
 end: NSString   中止时间 例如：如设置18：30 则值为  1830
 time:NSString   抬手亮屏时间
 }
 *
 **/
-(NSMutableDictionary *) raise2WakeOptions;

/**
 * 设置亮屏时间
 * 单位：秒
 **/
-(void)setLightScreenTime:(int)time;


/**
 * 获取亮屏时间 单位：秒
 *
 **/
-(int)lightScreenTime;
@end

#endif /* asd_h */

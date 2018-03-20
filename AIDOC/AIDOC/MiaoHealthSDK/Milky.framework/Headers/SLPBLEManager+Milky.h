//
//  SLPBLEManager+Milky.h
//  Sleepace
//
//  Created by Martin on 6/18/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import <BluetoothManager/BluetoothManager.h>
#import "MilkyDeviceInfo.h"
#import "MilkyBatteryInfo.h"
#import "MilkyDeviceVersionInfo.h"
#import "MilkyCollectionStatus.h"
#import "MilkyEnvironmentalData.h"
#import "MilkyUpgradeInfo.h"
#import "Milky_HistoryData.h"
#import "MilkySleepStatus.h"

@interface SLPBLEManager (Milky)

/*deviceName 设备名称 和设备ID区分一下
 deviceCode 设备编码
 userId 用户ID
 timeoutInterval 超时时间，如果为0时则用默认超时时间10秒
 回调值为 MilkyDeviceInfo
 */
- (void)milky:(CBPeripheral *)peripheral loginWithDeviceName:(NSString *)deviceName
    deviceCode:(NSString *)deviceCode
        userId:(NSInteger)userId
      callback:(SLPTransforCallback)handle;

/*获取设备信息
 回调值为 MilkyDeviceInfo
 */
- (void)milky:(CBPeripheral *)peripheral getDeviceInfoTimeout:(CGFloat)timeout callback:(SLPTransforCallback)handle;

/*获取电量
 回调值为MilkyBatteryInfo
 */
- (void)milky:(CBPeripheral *)peripheral getBatteryWithTimeout:(CGFloat)timeout
     callback:(SLPTransforCallback)handle;

/*获取设备版本号
  回调值为MilkyDeviceVersionInfo
 */
- (void)milky:(CBPeripheral *)peripheral getDeviceVersionWithTimeout:(CGFloat)timeout
     callback:(SLPTransforCallback)handle;

/*设置自动采集区间
 hour:时
 minute：分
 timeLength：持续时间 单位：分钟
 timeout：超时
 */
- (void)milky:(CBPeripheral *)peripheral setAutoCollectionWithHour:(UInt8)hour
       minute:(UInt8)minute
   timeLength:(UInt16)timeLength
      timeout:(CGFloat)timeout
     callback:(SLPTransforCallback)handle;

/*结束采集状态
 */
- (void)milky:(CBPeripheral *)peripheral stopCollectionWithTimeout:(CGFloat)timeout
     callback:(SLPTransforCallback)handle;

/*查询采集状态
 回调返回：MilkyCollectionStatus
 */
- (void)milky:(CBPeripheral *)peripheral getCollectionStatusWithTimeout:(CGFloat)timeout
      allback:(SLPTransforCallback)handle;

/*获取设备的环境数据
 回调返回MilkyEnvironmentalData
 */
- (void)milky:(CBPeripheral *)peripheral getEnvironmentalDataTimeout:(CGFloat)timeout completion:(SLPTransforCallback)handle;

/*获取睡眠信息
 回调返回MilkySleepStatus
 */
//- (void)milky:(CBPeripheral *)peripheral getSleepStatusTimeout:(CGFloat)timeout compeltion:(SLPTransforCallback)handle;

/*升级
 crcDes:加密包CRC32
 crcBin:原始包CRC32
 package:升级包
 回调返回 MilkyUpgradeInfo
 */
- (void)milky:(CBPeripheral *)peripheral upgradeDeviceWithCrcDes:(long)crcDes
        crcBin:(long)crcBin
upgradePackage:(NSData *)package
      callback:(SLPTransforCallback)handle;

/*历史数据下载
 type: 样本数据的人群类型
 startTime:开始时间戳
 endTime:结束时间戳 一般传当前时间
 eachhandle:每次获取到一段报告回调一次 回调返回SLPHistoryData
 finishHandle:最终结束的回调
 */
- (void)milky:(CBPeripheral *)peripheral personType:(SLPSleepPersonTypes)type
        historyDownloadWithStartTime:(NSInteger)startTime
       endTime:(NSInteger)endTime
        eachDataCallback:(SLPTransforCallback)eachhandle
        finishCallback:(SLPTransforCallback)finishHandle;
@end

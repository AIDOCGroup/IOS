//
//  ICTBleSDKMain.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/5/25.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ICTBleSDKEnums.h"
#import "ICTBleSDKSportsDataEntity.h"
#import "ICTBleSDKThresholdEntity.h"
#import "ICTBleSDKMonitorEntity.h"
#import "ICTBleSDKUserInfoEntity.h"
#import "ICTBleSDKBandInfoEntity.h"
#import "ICTBleSDKBodyDataEntity.h"

extern NSString *ICTBleSDKSharedVendorKey;

#pragma delegate

@protocol ICTBleSDKMainDelegate <NSObject>

@optional

/**
 *	@brief	是否有权限使用SDK
 */
- (void)couldAccessICTBleSDK:(NSString *)useTips;

/**
 *	@brief	蓝牙状态改变
 *
 *	@param 	BTState 	当前蓝牙状态
 */
- (void)discoveryBluetoothStateChanged:(CBCentralManagerState)BTState;

/**
 *	@brief	发现手环硬件设备
 *
 *	@param 	peripheral 	手环
 *	@param 	deviceName 	手环名称
 *	@param 	serialNumber  手环序列号
 *	@param 	RSSI 	信号强弱
 */
- (void) didDiscoveryICTBand:(CBPeripheral *)peripheral
                  deviceName:(NSString *)deviceName
                serialNumber:(NSString *)serialNumber
                  deviceRSSI:(NSNumber *)RSSI;

/**
 *	@brief	手环已经建立蓝牙连接
 *
 *	@param 	band 	手环
 */
- (void)didConnectedWithICTBand:(CBPeripheral*)band;

/**
 *	@brief	手环连接断开
 *
 *	@param 	band 	手环
 *	@param 	error 	错误信息
 */
- (void)didDisconnectedWithICTBand:(CBPeripheral*)band
                             error:(NSError *)error;

/**
 *	@brief	密码验证成功
 */
- (void)passwordAuthenticationSucceed;

/**
 *	@brief	密码验证失败
 */
- (void)passwordAuthenticationFailed;

/**
 *	@brief	接收设备基本信息
 *
 *	@param 	bandInfo 	设备信息
 */
-(void)didReceiveICTBandInfo:(ICTBleSDKBandInfoEntity*)bandInfo;


/**
 *	@brief	手环电量值更新
 *
 *	@param 	elecCount 	电量值刻度(0-4)
 */
- (void)didReceiveElectronic:(NSInteger)elecCount;

/**
 *	@brief	接收运动数据
 *
 *	@param 	sportsData 	运动数据
 */
- (void)didReceiveSportsData:(ICTBleSDKSportsDataEntity*)sportsData;

/**
 *	@brief	采集异常告警
 */
- (void)didReceiveWarningGatherException;

/**
 *	@brief	接收体征数据值
 *
 *	@param 	bodyDatas 	体征数据数组，元素是：ICTBleBodyDataEntity
 *	@param 	gatehrWay   采集途径
 *
 */
- (void)didReceiveBodyDataValue:(NSArray *)bodyDatas
                      gatherWay:(ICTBleGatherWay)gatherway;

/**
 *	@brief	数据同步进度
 *
 *	@param 	progressValue 	数据同步进度值(0-1)
 */
- (void)didReceiveSyncedDataWithProgressValue:(CGFloat)progressValue;


/**
 *	@brief	体征数据分包数据同步结束
 */
- (void)didFinishedSyncedBodyData;

#pragma mark -固件升级

/**
 *	@brief	有新的固件需要更新
 */
- (void)ICTBandCouldUpdateFirmware;

/**
 *	@brief	固件更新进度提示
 *
 *	@param 	percentValue 	第几步更新的百分比进度
 *	@param 	cStep 	当前更新至第几步
 *	@param 	tStep 	总共有几步
 */
- (void)ICTBandRefreshProgress:(NSInteger)percentValue
                    currentStep:(NSInteger)cStep
                      totalStep:(NSInteger)tStep;

/**
 *	@brief	固件更新失败
 *
 *	@param 	error 	错误信息
 */
- (void)ICTBandfirmwareUpdateFailed:(ICTFWError)error;

/**
 *	@brief	固件更新成功
 */
- (void)ICTBandfirmwareUpdateSucceed;

@end

#pragma interface

@interface ICTBleSDKMain : NSObject

@property (strong, nonatomic) CBPeripheral *currentConnectedICTBand;//当前已连接的手环（经过密码验证之后赋值）
@property (strong, nonatomic) CBPeripheral *currentConnectingICTBand;//当前正在连接的手环(经过密码验证后置空)
@property (assign, nonatomic) CBCentralManagerState centralState;

/**
 *	@brief  初始化
 *
 *	@param 	vendorKey 	厂商关健字
 */
- (id)initWithVendorKey:(NSString*)vendorKey;

/**
 *	@brief  添加委托
 */
- (void)addDelegate:(id <ICTBleSDKMainDelegate>)delegate;

/**
 *	@brief	开始查找周围ICT手环
 *
 *	@param 	bandType 	手环类型
 */
- (void)startScanningWithICTBandType:(ICTBandType)bandType;

/**
 *	@brief	根据设备的identifier查找设备，可用于设备自动重连
 *
 *	@param 	identifiers 	由CBPeripheral的identifier.uuidstring组成的数组
 *
 *	@return	返回所找到的设备
 */
- (NSArray*)retrievePeripheralWithUUID:(NSArray*)identifiers;

/**
 *	@brief	查找已和系统连接的手环
 *
 *	@return	返回和系统连接的手环数组(元素为CBPeripheral类)
 */
- (NSArray *)retrieveConnectedBand;


/**
 *	@brief	停止查找设备
 */
- (void)stopScanning;

/**
 *	@brief	连接手环
 *
 *	@param 	band 	需要连接的手环
 */
- (void) connectICTBand:(CBPeripheral*)band;

/**
 *	@brief	断开已经连接的设备或取消连接正在连接的设备
 */
- (void) disconnectICTBand:(CBPeripheral *)band;

/**
 *	@brief	请求验证密码
 */
- (void)requestAuthenticationPwd;

/**
 *	@brief	发送验证密码至当前正在连接的设备
 *
 *	@param 	password 	密码
 */
- (void)sendWithPasswordToConnectingBand:(NSString *)password;

/**
 *	@brief	获取设备基本信息，包括设备名称、设备支持能力、硬件版本号、设备序列号、设备制造商、当前使用的协议版本、A、B、C、D、E类型的固件版本号
 */
- (void)getICTBandDetailsInfo;

///**
// *	@brief	获取B、C、D、E四种类型的固件版本号，A类型固件版本号通过获取设备基本信息得到
// */
//- (void)getOtherFirmwareVersions;
//
///**
// *	@brief	获取设备基本信息，包括设备名称、设备支持能力、硬件版本号、设备序列号、设备制造商、当前使用的协议版本、A类型固件版本号
// */
//- (void)getICTBandBasisInfo;

/**
 *	@brief	手机时间与手环同步
 */
- (void)syncTimeWithICTBand;

/**
 *	@brief	获取设备电量
 */
- (void)getICTBandElec;

/**
 *	@brief	修改手环名称
 *
 *	@param 	name 	手环名称(仅支持12位长度以内的字母、数字、下划线和横线)
 *  
 *  @return 若名称校验正确，返回YES，反之，返回NO
 */
- (BOOL)changeICTBandName:(NSString *)name;

/**
 *	@brief	读取今日运动数据
 */
- (void)getSportsData;

/**
 *	@brief	开始同步体征数据
 */
- (void)beginSyncData;

/**
 *	@brief	读取需要生成报告的文件
 *
 *	@param 	serialNumber 	设备序列号
 *
 *	@return	返回需要生成报告的文件
 */
- (NSArray *)readReportsFilesWithSerialNumber:(NSString *)serialNumber;

/**
 *	@brief	删除报告文件（必须先把文件上传服务器成功之后，才能执行此方法，否则可能造成数据丢失）
 *
 *  @param  serialNumber 手环序列号
 *
 *	@return	文件删除是否成功  YES：删除成功 NO：删除失败
 */
- (BOOL)deleteReportFilesWithSerialNumber:(NSString *)serialNumber;

/**
 *	@brief	开启实时采集
 *
 *	@param 	bodyParameter 	采集参数(可传多个参数)
 *	@param 	count 	单次采集或持续采集  0：持续采集 1：单次采集
 */
- (void)beginMeasuring:(ICTBleSDKBodyParameterType)bodyParameter
                count:(NSInteger)count;

/**
 *	@brief	实时采集停止
 */
- (void)stopMeasuring;

/**
 *	@brief	开启测试模式
 */
- (void)enableTestMode;

/**
 *	@brief	关闭测试模式
 */
- (void)disableTestMode;

/**
 *	@brief	发送门限值,目前C+手环仅支持心率、血氧门限值设定，不能设置其它参数类型的门限值
 *
 *	@param 	threshold 	门限值
 *
 *	@return	门限值校验正确，返回YES，检验错误，返回NO
 */
- (BOOL)sendThresholdToICTBand:(ICTBleSDKThresholdEntity*)threshold;

/**
 *	@brief	发送监护方案
 *
 *	@param 	monitor 当前监护方案
 *
 *	@return	方案校验正确，返回YES，校验错误，返回NO
 */
- (BOOL)sendMonitorToICTBand:(ICTBleSDKMonitorEntity*)monitor;

/**
 *	@brief	发送用户基本信息
 *
 *	@param 	userInfo 	当前用户基本信息
 *
 *	@return	用户信息校验正确，返回YES，校验错误，返回NO
 */
- (BOOL)sendUserInfoToICTBand:(ICTBleSDKUserInfoEntity*)userInfo;

/**
 *	@brief	设置手环是否具有来电通知功能
 *
 *	@param 	isOpen 	1：来电通知功能开启，0：来电通知功能关闭
 */
- (void)setDialogisOpen:(NSInteger)isOpen;

#pragma mark -固件更新

/**
 *	@brief	使手环进行固件升级
 */
- (void)makeICTBandStartFirmwareUpdate;

/**
 *	@brief	取消更新
 */
- (void) makeICTBandCancelFirmwareUpdate;

@end

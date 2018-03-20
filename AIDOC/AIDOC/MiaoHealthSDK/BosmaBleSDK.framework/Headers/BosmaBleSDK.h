//
//  BosmaBleSDK.h
//  BosmaBleSDK
//
//  Created by Bosma on 2017/4/17.
//  Copyright © 2017年 Bosma. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for BosmaBleSDK.
FOUNDATION_EXPORT double BosmaBleSDKVersionNumber;

//! Project version string for BosmaBleSDK.
FOUNDATION_EXPORT const unsigned char BosmaBleSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <BosmaBleSDK/PublicHeader.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BosmaMeasureRequestModel.h"
#import "BosmaMeasureResultModel.h"
#import "BosmaExportConstantsDefine.h"
#import "TemperatureModel.h"
#import "ElectricModel.h"
@interface BosmaBleSDK : NSObject

@property(nonatomic,copy)NSString * _Nullable deviceCode;//设备代码
@property(nonatomic,assign,readonly)BOOL isLostModelOpen;//体温计-防丢模式 YES-防丢模式 NO-正常测温模式
/*!在请求测量数据之前请先设置，测量请求对象*/
@property(nonatomic,strong)BosmaMeasureRequestModel * _Nonnull reqMeasureModel;

#pragma mark Bosma智能产品前缀
/**
 *  返回Bosma智能产品前缀
*  @param deviceType 设备类型
 *
 */
+(NSString *_Nonnull)bosmaSmartProductNamePrefixWithType:(BosmaDeviceType)deviceType;
#pragma mark - 根据名称选择对应的Bosma智能产品
/**
 *  根据名称选择对应的Bosma智能产品
 *
 *  @param deviceType   设备类型枚举值
 *  @param name 连接的蓝牙设备名称
 */
+(BOOL)chooseBosmaDeviceUsingDeviceType:(BosmaDeviceType)deviceType prefixOfName:(NSString *_Nonnull)name;


#pragma mark - 构建单一实例
/**
 *  创建实例
 */
+ (BosmaBleSDK *_Nonnull)sharedInstance;

#pragma mark - 向设备写数据
/**
 *  向设备写数据
 *
 *  @param peripheral     具有Bosma读写特征的设备
 *  @param data    数据
 */
- (void)peripheral:(CBPeripheral *_Nullable)peripheral writeData:(NSData *_Nullable)data;


#pragma mark - 寻找周边设备
/**
 *  寻找周边具有Bosma读写特征的智能设备
 *  在CBPeripheral实例的delegate代理的peripheral:didDiscoverServices方法中，调用此方法
 *  @param peripheral     具有Bosma读写特征的设备
 *  @param error    错误信息 如果错误不为空，则不搜索设备，为空则搜索设备
 */
-(void)peripheral:(CBPeripheral *_Nonnull)peripheral didDiscoverServices:(NSError *_Nullable)error;

#pragma mark - 找到周报设备
/**
 *  找到周边具有Bosma读写特征的智能设备，并获取该设备的数据
 *  在CBPeripheral实例的delegate代理的peripheral:didDiscoverCharacteristicsForService:error方法中，调用此方法
 *  @param peripheral     具有Bosma读写特征的设备
 *  @param service  服务
 *  @param error    错误信息 如果错误不为空，则不搜索设备，为空则搜索设备
 */
-(void)peripheral:(CBPeripheral *_Nonnull)peripheral didDiscoverCharacteristicsForService:(CBService *_Nullable)service error:(NSError *_Nullable)error;

#pragma mark 读取设备数据，获取秤的体重与生物电阻值后，并请求服务器获取详细的测量报告
/**
 *  获取秤的体重与生物电阻值后，并请求服务器获取详细的测量报告
 *  在CBPeripheral实例的delegate代理的peripheral:didUpdateValueForCharacteristic:error方法中，调用此方法
 *  @param peripheral     具有Bosma读写特征的设备
 *  @param characteristic  特征
 *  @param error    错误信息 如果错误不为空，则不读取数据，否则读取数据
 *  @param completion  处理完成之后的数据回调
 *          - result 取值YES或者NO，YES代表获取详细的测量报告成功,NO代表获取详细的测量报告失败。
 - model 详细的测量报告
 - message 处理完毕的消息
 */
- (void)peripheral:(CBPeripheral *_Nonnull)peripheral scaleCharacteristic:(CBCharacteristic *_Nonnull)characteristic
             error:(NSError *_Nullable)error
        completion:(void (^ __nullable)(BOOL result,BosmaMeasureResultModel * _Nullable model,NSString * _Nullable message))completion;


#pragma mark - 体温计相关 
#pragma mark 测量温度
/**
 *  接收体温计返回的数据
 *  在CBPeripheral实例的delegate代理的peripheral:didUpdateValueForCharacteristic:error方法中，调用此方法.
 *
 *  @param peripheral     具有Bosma读写特征的设备
 *  @param characteristic  特征
 *  @param error    错误信息 如果错误不为空，则不读取数据，否则读取数据
 *  @param callbackBlock  处理完成之后的数据回调,callback可能会被调用多次
            - receiveCmdType 体温计接收命令
 *          - result 取值YES或者NO，YES代表解析数据成功。
 *          - returnData 返回数据
 *          receiveCmdType
 *          - ThmReceiveCmdType_Connect 连接命令 返回数据字典 key字符常量，deviceVersionString-设备代码,deviceIdString:设备Id，electricString:电量百分比（0-100的整数）。
 *          - ThmReceiveCmdType_realtimeTemp 实时数据 返回TemperatureModel对象，具体参见TemperatureModel属性说明。
 *          - ThmReceiveCmdType_historyTemp 历史温度数据 返回NSArray<TemperatureModel *>数组，具体参见TemperatureModel属性说明。
 
                        
 - model 详细的测量报告
 - message 处理完毕的消息
 */
- (void)peripheral:(CBPeripheral *_Nonnull)peripheral ThmCharacteristic:(CBCharacteristic *_Nonnull)characteristic
             error:(NSError *_Nullable)error
          callback:(void (^ __nullable)(int receiveCmdType,BOOL isSuccess,id _Nullable returnData))callbackBlock;

#pragma mark 读取体温计电量
/**
 *  读取体温计电量
 * @param peripheral     具有Bosma读写特征的设备
 */
- (void)readThmElectircWithPeripheral:(CBPeripheral *_Nonnull)peripheral;

#pragma mark 设置体温计历史温度记录频率
/**
 *  设置体温计历史温度记录频率
 * @param peripheral     具有Bosma读写特征的设备
 * @param second 秒数
 */
-(void)settingThmHistoryFrequeWithPeripheral:(CBPeripheral *_Nonnull)peripheral second:(NSUInteger)second;

#pragma mark 设置体温计运行模式
/**
 *  设置体温计运行模式。连接的时候，默认为正常模式。 打开或关闭防丢模式，防丢模式-设备会一直广播，不测温。 正常测温模式-测温
 * @param peripheral     具有Bosma读写特征的设备
 * @param on 防丢开关 YES-防丢模式 NO-正常测温模式
 */
-(void)settingThmModeWithPeripheral:(CBPeripheral *_Nonnull)peripheral on:(BOOL)on;

#pragma mark 同步设备时间与APP系统时间保持一致
/**
 *  同步设备时间与APP系统时间保持一致
 * @param peripheral     具有Bosma读写特征的设备
 */
-(void)syncThmDeviceTimeWithAppTimeWithPeripheral:(CBPeripheral *_Nonnull)peripheral;
@end


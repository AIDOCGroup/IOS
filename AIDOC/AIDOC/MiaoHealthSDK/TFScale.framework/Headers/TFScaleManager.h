//
//  TFScaleManager.h
//  TFScale
//
//  Created by Yalin on 16/4/9.
//  Copyright © 2016年 tongfang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TFScale/TFScaleResult.h>

typedef NS_OPTIONS(NSUInteger, TFDeviceType) {
    TFDeviceTypeAll = 1 << 0,           // 所有秤
    TFDeviceTypeMyBody = 1 << 1,        // 老秤
    TFDeviceTypeMyBodyMini = 1 << 2,    // 新秤
    TFDeviceTypeMyBodyWhite = 1 << 3,
};

@interface TFScaleManager : NSObject

/**
 *  搜索设备, 在超时时间内会一直搜索，搜索到设备会调用findDeviceBlock，知道超时时间到才会停止搜索。
 *
 *  @param timeout           搜索多少时间时间
 *  @param deviceTypeOptions 需要搜索的设备类型
 *  @param findDeviceBlock   devices数组里为字典类型,格式如下: ["name" : device.name , "RSSI" : device.RSSI, "deviceType" : device.type.typeStr, "uuid" : device.uuid]
 */
+ (void)scanDeviceWithTimeut:(NSTimeInterval)timeout deviceTypeOptions:(TFDeviceType)deviceTypeOptions findDevice:(void (^)(NSArray *devices, BOOL isTimeout, NSError *error))findDeviceBlock;

/**
 *  评测
 *
 *  @param age               年龄
 *  @param gender            性别 true 男 false 女
 *  @param height            身高
 *  @param deviceTypeOptions 搜索的设备类型
 *  @param timeOut           超时时间
 *  @param complete          评测完成回调
 */
+ (void)startScaleWithAge:(NSUInteger)age gender:(BOOL)gender height:(NSUInteger)height deviceTypeOptions:(TFDeviceType)deviceTypeOptions timeOut:(NSTimeInterval)timeOut complete:(void (^)(TFScaleResult *result, NSError *error))complete;

/**
 *  取消当前评测或搜索设备
 */
+ (void)stopScaleOrScan;

@end



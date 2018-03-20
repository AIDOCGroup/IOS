//
//  ICTBleSerialNumber.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/18.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface ICTBleSDKSerialNumber : NSObject

+ (instancetype)sharedBleSerialNumber;


//获取序列号
- (NSString *)serialNumberWithBand:(CBPeripheral *)band;
//设置序列号
- (void)setSerialNumberWithBand:(CBPeripheral *)band
                   serialNumber:(NSString *)serialNumber;

@end

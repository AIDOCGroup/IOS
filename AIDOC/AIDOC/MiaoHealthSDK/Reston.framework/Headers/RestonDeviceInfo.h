//
//  RestonDeviceInfo.h
//  SDK
//
//  Created by Martin on 2017/7/28.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RestonDeviceInfo : NSObject
//主硬件版本号
@property (nonatomic,copy) NSString *hardwareVersion;//硬件版本
//设备ID	Char[13]	13	UTF-8字串，不带结束符
@property (nonatomic,copy) NSString *deviceID;
@end

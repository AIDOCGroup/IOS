//
//  ICTBleBodyDataEntity.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/25.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "FMDB.h"
#import "ICTBleSDKEnums.h"

@interface ICTBleSDKBodyDataEntity : NSObject

@property (strong, nonatomic) NSDate                 *gatherTime;
@property (copy, nonatomic)   NSString               *bandSerialNumber;

@property (assign, nonatomic) CGFloat                bodyValue;
@property (assign, nonatomic) ICTBleSDKBodyParameterType   bodyType;
@property (assign, nonatomic) ICTBodyParamGatherType gatherType;
@property (assign, nonatomic) ICTBleGatherWay        gatherWay;

+ (instancetype)ICTBleSDKBodyDataWithResult:(FMResultSet *)rs;
- (NSDictionary *)ICTBleSDKServerFormatter;

@end

//
//  ICTBleThreshold.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/18.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "ICTBleSDKBodyDataEntity.h"

@interface ICTBleSDKThresholdEntity : NSObject

/**
 *	@brief	门限初始化
 *
 *	@param 	bodyType 	参数类型(一次只能传一个参数)
 *	@param 	lowLimit 	严重下限
 *	@param 	smallLimit 	正常上限
 *	@param 	bigLimit 	正常上限
 *	@param 	highLimit 	严重上限
 */
- (instancetype)initWithBodyType:(ICTBleSDKBodyParameterType)bodyType
                     lowestLimit:(CGFloat)lowLimit
                normalSmallLimit:(CGFloat)smallLimit
                  normalBigLimit:(CGFloat)bigLimit
                       highLimit:(CGFloat)highLimit;


@property (assign, nonatomic) ICTBleSDKBodyParameterType bodyType;          //参数类型
@property (assign, nonatomic) CGFloat              lowestLimit;       //严重下限
@property (assign, nonatomic) CGFloat              normalSmallLimit;  //正常下限
@property (assign, nonatomic) CGFloat              normalBigLimit;    //正常上限
@property (assign, nonatomic) CGFloat              highLimit;         //严重上限

@end

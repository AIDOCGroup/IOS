//
//  ICTBleSportsData.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/19.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ICTBleSDKSportsDataEntity : NSObject

/**
 *	@brief	初始化
 *
 *	@param 	steps 	    步数
 *	@param 	disValue 	距离
 *	@param 	calValue 	卡路里
 */
- (instancetype)initWithSteps:(NSInteger)steps
                     distance:(NSInteger)disValue
                      calorie:(NSInteger)calValue;

@property (assign, nonatomic) NSInteger steps;
@property (assign, nonatomic) NSInteger distance;
@property (assign, nonatomic) NSInteger calorie;


@end

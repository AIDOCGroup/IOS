//
//  ICTBleUserInfo.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/18.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICTBleSDKEnums.h"

@interface ICTBleSDKUserInfoEntity : NSObject

/**
 *	@brief	用户信息初始化
 *
 *	@param 	height 	用户身高 以CM为单位
 *	@param 	weight 	体重 以KG为单位
 *	@param 	ageValue 	年龄
 *	@param 	sexValue 	性别
 */
- (instancetype)initWithHeight:(NSInteger)height
                        Weight:(NSInteger)weight
                           age:(NSInteger)ageValue
                           sex:(ICTUserSexEnum)sexValue;

@property (assign, nonatomic) NSInteger height;
@property (assign, nonatomic) NSInteger weight;
@property (assign, nonatomic) NSInteger agevalue;
@property (assign, nonatomic) ICTUserSexEnum sexvalue;

@end

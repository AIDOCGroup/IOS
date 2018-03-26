//
//  StepCountManage.h
//  AIDOC
//
//  Created by app on 2018/3/16.
//  Copyright © 2018年 app. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StepCountManage : NSObject

/*
 * 展示步数
 **/
/**
 stepCount3  有网步数显示  最真实：当前历史+设备差值
 stepCount4  无网步数显示  真实：bao历史+设备差值
 */
//获取设备步数
- (void)getStepCountFromHealthKitSuccess:(void (^)(float))stepCount3 failure:(void (^)(float))stepCount4;

- (void)uploadStepCountToServerSuccess:(void (^)(id))success failure:(void (^)(NSString *))error2;

- (void)getStepCountFromHealthKitSuccess:(void (^)(float))stepCount;

- (void)getStepCountExerciseAndHealthSuccess:(void (^)(float))stepCountSuccessBlock failure:(void (^)(float))stepCountFailBlock;
@end

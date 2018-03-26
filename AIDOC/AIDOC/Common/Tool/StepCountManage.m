//
//  StepCountManage.m
//  AIDOC
//
//  Created by app on 2018/3/16.
//  Copyright © 2018年 app. All rights reserved.
//

#import "StepCountManage.h"
#import "HealthKitManage.h"
#import "HistoryModel.h"
#import <CoreMotion/CoreMotion.h>

@interface StepCountManage()

@property (nonatomic, strong) CMPedometer *pedoMeter;//计步器

@end

@implementation StepCountManage
{
    float historySteps;
    double updateStepCount;
    
}


/*
 * 展示步数
 **/

//获取历史步数
#pragma -mark getStepCountFromHistory
/**
    stepCount1  有网步数显示  最真实：当前历史+设备差值
    stepCount2  无网步数显示  真实：历史+设备差值
 */
- (void)getStepCountFromHistory:(float)uploadStepCount success:(void (^)(float))stepCount1 failure:(void (^)(float))stepCount2{
    
    historySteps = 0;
    
    [YTNetworkRequest loadHistorySuccess:^(id result) {
            NSMutableArray *arr = [result valueForKey:@"list"];
            NSMutableArray *allArray = [NSMutableArray array];
            for (NSDictionary *dic in arr) {

                HistoryModel *model = [[HistoryModel alloc] initContentWithDic:dic];
                [allArray addObject:model];
            }
            if ([allArray count] >= 1) {
                HistoryModel *model1 = allArray[0];

                historySteps = [model1.steps floatValue];
            }
        

        
        stepCount1(historySteps);
        
    } failure:^(NSString *error) {
        
        stepCount2(historySteps);
    }];

    
}

/*
 * 展示步数
 **/
/**
 stepCount3  有网步数显示  最真实：当前历史+设备差值
 stepCount4  无网步数显示  真实：历史+设备差值
 */

//获取设备步数
#pragma -mark getStepCountFromHealthKit
- (void)getStepCountFromHealthKitSuccess:(void (^)(float))stepCount3 failure:(void (^)(float))stepCount4{
   
    [self getStepCountExerciseAndHealthSuccess:^(float value) {

        //获取旧的健康数据
        UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
        //保存今天数据
        userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
        updateStepCount = 0.0;
        if ([CommonFunc oneNSDate:userHealthModel.latestDate isEqualWithTwoNSDate:[NSString DateToStr:[NSDate date]]]) {//同一天
            if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
                if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
                    updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
                }
                userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
            }
            
        }else {
            if (value >= 0) {
                if (userHealthModel.latestDate) {
                    updateStepCount = value;//设备更新的数据
                }
                //                if (userHealthModel.latestDate == datehealth) {//如果设备还是昨天
                //                    userHealthModel.saveCurrentDeviceStepCount = @"0";
                //                    userHealthModel.stepCount = @"0";
                //                    userHealthModel.currentDeviceStepCount = @"0";
                //
                //                }else{
                userHealthModel.saveCurrentDeviceStepCount = @"0";
                userHealthModel.stepCount = @"0";
                userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
                
                //                }
            }
        }

        
        
        [self getStepCountFromHistory:updateStepCount success:^(float stepCount1) {
            userHealthModel.stepCount = [NSString stringWithFormat:@"%.0f",(updateStepCount+stepCount1)];
            [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
            stepCount3((updateStepCount+stepCount1));
            
        } failure:^(float stepCount2) {
            
            float oldStep = [userHealthModel.stepCount floatValue]+updateStepCount;
            userHealthModel.stepCount = [NSString stringWithFormat:@"%f",oldStep];
            [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
            stepCount4(oldStep);
            
        }];
    } failure:^(float value) {
        //获取旧的健康数据
        UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
        //保存今天数据
        userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
        updateStepCount = 0.0;
        if ([CommonFunc oneNSDate:userHealthModel.latestDate isEqualWithTwoNSDate:[NSString DateToStr:[NSDate date]]]) {//同一天
            if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
                if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
                    updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
                }
                userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
            }
            
        }else {
            if (value >= 0) {
                if (userHealthModel.latestDate) {
                    updateStepCount = value;//设备更新的数据
                }
                //                if (userHealthModel.latestDate == datehealth) {//如果设备还是昨天
                //                    userHealthModel.saveCurrentDeviceStepCount = @"0";
                //                    userHealthModel.stepCount = @"0";
                //                    userHealthModel.currentDeviceStepCount = @"0";
                //
                //                }else{
                userHealthModel.saveCurrentDeviceStepCount = @"0";
                userHealthModel.stepCount = @"0";
                userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
                
                //                }
            }
        }

        
        [self getStepCountFromHistory:updateStepCount success:^(float stepCount1) {
            userHealthModel.stepCount = [NSString stringWithFormat:@"%.0f",(updateStepCount+stepCount1)];
            [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
            stepCount3((updateStepCount+stepCount1));
            
        } failure:^(float stepCount2) {
            
            float oldStep = [userHealthModel.stepCount floatValue]+updateStepCount;
            userHealthModel.stepCount = [NSString stringWithFormat:@"%f",oldStep];
            [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
            stepCount4(oldStep);
            
        }];

    }];
    
}
//{
//    //获取新的健康数据上传
//    HealthKitManage *manage = [HealthKitManage shareInstance];
//    [manage authorizeHealthKit:^(BOOL success, NSError *error) {
//        if (success) {
//            NSLog(@"success");
//            [manage fetchHealthDataForUnit:MHMHealthIntervalUnitDay queryResultBlock:^(NSDictionary *queryResultDict) {
//                NSString *dateStr = [queryResultDict valueForKey:@"endDate"];
//                float value = [[queryResultDict valueForKey:@"totalStepCount"] floatValue];
//                NSArray *array = [dateStr componentsSeparatedByString:@" "];
//                NSString *datehealth;
//                if ([array count]==2) {
//                    datehealth = array[0];
//                }
//
//                //获取旧的健康数据
//                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
//                //保存今天数据
//                //                UserHealthModel *userHealthModel = [[UserHealthModel alloc] init];
//                userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
//                updateStepCount = 0.0;
//                if ([CommonFunc oneNSDate:userHealthModel.latestDate isEqualWithTwoNSDate:[NSString DateToStr:[NSDate date]]]) {//同一天
//                    if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
//                        if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
//                            updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
//                        }
//                        userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
//                    }
//                }else {
//                    if (value >= 0) {
//                        if (userHealthModel.latestDate) {
//                            updateStepCount = value;//设备更新的数据
//                        }
//                        if (userHealthModel.latestDate == datehealth) {//如果设备还是昨天
//                            userHealthModel.saveCurrentDeviceStepCount = @"0";
//                            userHealthModel.stepCount = @"0";
//                            userHealthModel.currentDeviceStepCount = @"0";
//
//                        }else{
//                            userHealthModel.saveCurrentDeviceStepCount = @"0";
//                            userHealthModel.stepCount = @"0";
//                            userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
//
//                        }
//                    }
//                }
//
//
//                userHealthModel.latestDate = datehealth;
//                userHealthModel.latestDateWithHMS = dateStr;
//
//                [self getStepCountFromHistory:updateStepCount success:^(float stepCount1) {
//                    userHealthModel.stepCount = [NSString stringWithFormat:@"%.0f",(updateStepCount+stepCount1)];
//                    [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
//                    stepCount3((updateStepCount+stepCount1));
//
//                } failure:^(float stepCount2) {
//
//                    float oldStep = [userHealthModel.stepCount floatValue]+updateStepCount;
//                    userHealthModel.stepCount = [NSString stringWithFormat:@"%f",oldStep];
//                    [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
//                    stepCount4(oldStep);
//
//                }];
//            }];
////            [manage getStepCount:^(double value,NSString *date, NSError *error) {
////
////                NSArray *array = [date componentsSeparatedByString:@" "];
////                NSString *datehealth;
////                if ([array count]==2) {
////                    datehealth = array[0];
////                }
////
////                //获取旧的健康数据
////                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
////                //保存今天数据
//////                UserHealthModel *userHealthModel = [[UserHealthModel alloc] init];
////                userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
////                 updateStepCount = 0.0;
////                if ([CommonFunc oneNSDate:userHealthModel.latestDate isEqualWithTwoNSDate:[NSString DateToStr:[NSDate date]]]) {//同一天
////                    if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
////                        if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
////                            updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
////                        }
////                        userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
////                    }
////                }else {
////                    if (value >= 0) {
////                        if (userHealthModel.latestDate) {
////                            updateStepCount = value;//设备更新的数据
////                        }
////                        if (userHealthModel.latestDate == datehealth) {//如果设备还是昨天
////                            userHealthModel.saveCurrentDeviceStepCount = @"0";
////                            userHealthModel.stepCount = @"0";
////                            userHealthModel.currentDeviceStepCount = @"0";
////
////                        }else{
////                            userHealthModel.saveCurrentDeviceStepCount = @"0";
////                            userHealthModel.stepCount = @"0";
////                            userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
////
////                        }
////                    }
////                }
////
////
////                userHealthModel.latestDate = datehealth;
////                userHealthModel.latestDateWithHMS = date;
////
////                [self getStepCountFromHistory:updateStepCount success:^(float stepCount1) {
////                    userHealthModel.stepCount = [NSString stringWithFormat:@"%.0f",(updateStepCount+stepCount1)];
////                    [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
////                    stepCount3((updateStepCount+stepCount1));
////
////                } failure:^(float stepCount2) {
////
////                    float oldStep = [userHealthModel.stepCount floatValue]+updateStepCount;
////                    userHealthModel.stepCount = [NSString stringWithFormat:@"%f",oldStep];
////                    [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
////                    stepCount4(oldStep);
////
////                }];
////            }];
//        }
//
//    }];
//}

//上传
- (void)uploadStepCountToServerSuccess:(void (^)(id))success failure:(void (^)(NSString *))error2{
    [self getStepCountFromHealthKitSuccess:^(float stepCount3) {
       
        if (updateStepCount > 0) {
            [YTNetworkRequest saveSteps:[NSString stringWithFormat:@"%.0f",stepCount3] success:^(id result) {
                NSLog(@"%@",result);
                success(result);
                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
                userHealthModel.currentDeviceStepCount = userHealthModel.currentDeviceStepCount;
                [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
                
            } failure:^(NSString *error) {
                error2(error);
                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
                userHealthModel.currentDeviceStepCount = userHealthModel.saveCurrentDeviceStepCount;
                [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
                
            }];
        }else{
            NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
            [dic setValue:@"0" forKey:@"errcode"];
            success(dic);
        }
        
    } failure:^(float stepCount4) {
        
        if (updateStepCount > 0) {
            [YTNetworkRequest saveSteps:[NSString stringWithFormat:@"%.0f",stepCount4] success:^(id result) {
                NSLog(@"%@",result);
                success(result);
                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
                userHealthModel.currentDeviceStepCount = userHealthModel.currentDeviceStepCount;
                [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
                
            } failure:^(NSString *error) {
                error2(error);
                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
                userHealthModel.currentDeviceStepCount = userHealthModel.saveCurrentDeviceStepCount;
                [CommonFunc setUserHealthModel:userHealthModel forKey:[CommonFunc getUserHealthModelKey]];
                
            }];
        }else{
            NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
            [dic setValue:@"0" forKey:@"errcode"];
            success(dic);
        }
    }];
}

//获取设备步数
#pragma -mark getStepCountFromHealthKit
- (void)getStepCountFromHealthKitSuccess:(void (^)(float))stepCount{
    [self getStepCountExerciseAndHealthSuccess:^(float value) {
        
        //获取旧的健康数据
        UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
        //保存今天数据
        userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
       updateStepCount = 0.0;
        
        if ([CommonFunc oneNSDate:userHealthModel.latestDate isEqualWithTwoNSDate:[NSString DateToStr:[NSDate date]]]) {//同一天
            if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
                if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
                    updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
                }
                userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
            }
            
        }else {
            if (value >= 0) {
                if (userHealthModel.latestDate) {
                    updateStepCount = value;//设备更新的数据
                }
//                if (userHealthModel.latestDate == datehealth) {//如果设备还是昨天
//                    userHealthModel.saveCurrentDeviceStepCount = @"0";
//                    userHealthModel.stepCount = @"0";
//                    userHealthModel.currentDeviceStepCount = @"0";
//
//                }else{
                    userHealthModel.saveCurrentDeviceStepCount = @"0";
                    userHealthModel.stepCount = @"0";
                    userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
                    
//                }
            }
        }
        
        userHealthModel.latestDate = [NSString DateToStr:[NSDate date]];

    } failure:^(float value) {
        //获取旧的健康数据
        UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
        //保存今天数据
        userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
        updateStepCount = 0.0;
        if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
            if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
                updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
            }
            userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
        }
        
    }];
}
//{
//    //获取新的健康数据上传
//    HealthKitManage *manage = [HealthKitManage shareInstance];
//    [manage authorizeHealthKit:^(BOOL success, NSError *error) {
//        if (success) {
//            NSLog(@"success");
//            [manage fetchHealthDataForUnit:MHMHealthIntervalUnitDay queryResultBlock:^(NSDictionary *queryResultDict) {
//                NSString *dateStr = [queryResultDict valueForKey:@"endDate"];
//                float value = [[queryResultDict valueForKey:@"totalStepCount"] floatValue];
//
//                updateStepCount = 0.0;
//
//                NSArray *array = [dateStr componentsSeparatedByString:@" "];
//                NSString *datehealth;
//                if ([array count]==2) {
//                    datehealth = array[0];
//                }
//
//                //获取旧的健康数据
//                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
//                //保存今天数据
//                //                UserHealthModel *userHealthModel = [[UserHealthModel alloc] init];
//                userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
//                updateStepCount = 0.0;
//                if ([CommonFunc oneNSDate:userHealthModel.latestDate isEqualWithTwoNSDate:[NSString DateToStr:[NSDate date]]]) {//同一天
//                    if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
//                        if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
//                            updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
//                        }
//                        userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
//                    }
//                }else {
//                    if (value >= 0) {
//                        if (userHealthModel.latestDate) {
//                            updateStepCount = value;//设备更新的数据
//                        }
//                        if (userHealthModel.latestDate == datehealth) {//如果设备还是昨天
//                            userHealthModel.saveCurrentDeviceStepCount = @"0";
//                            userHealthModel.stepCount = @"0";
//                            userHealthModel.currentDeviceStepCount = @"0";
//
//                        }else{
//                            userHealthModel.saveCurrentDeviceStepCount = @"0";
//                            userHealthModel.stepCount = @"0";
//                            userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
//
//                        }
//                    }
//                }
//                userHealthModel.latestDate = datehealth;
//                userHealthModel.latestDateWithHMS = dateStr;
//                if (updateStepCount > 0) {
//                    stepCount(updateStepCount);
//                }
//            }];
////            [manage getStepCount:^(double value,NSString *date, NSError *error) {
////                updateStepCount = 0.0;
////
////                NSArray *array = [date componentsSeparatedByString:@" "];
////                NSString *datehealth;
////                if ([array count]==2) {
////                    datehealth = array[0];
////                }
////
////                //获取旧的健康数据
////                UserHealthModel *userHealthModel = [CommonFunc getUserHealthModelForKey:[CommonFunc getUserHealthModelKey]];
////                //保存今天数据
////                //                UserHealthModel *userHealthModel = [[UserHealthModel alloc] init];
////                userHealthModel.saveCurrentDeviceStepCount = userHealthModel.currentDeviceStepCount;
////                updateStepCount = 0.0;
////                if ([CommonFunc oneNSDate:userHealthModel.latestDate isEqualWithTwoNSDate:[NSString DateToStr:[NSDate date]]]) {//同一天
////                    if (value >= [userHealthModel.currentDeviceStepCount doubleValue]) {
////                        if ([userHealthModel.currentDeviceStepCount doubleValue] != 0) {
////                            updateStepCount = value - [userHealthModel.currentDeviceStepCount doubleValue];//设备更新的数据
////                        }
////                        userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
////                    }
////                }else {
////                    if (value >= 0) {
////                        if (userHealthModel.latestDate) {
////                            updateStepCount = value;//设备更新的数据
////                        }
////                        if (userHealthModel.latestDate == datehealth) {//如果设备还是昨天
////                            userHealthModel.saveCurrentDeviceStepCount = @"0";
////                            userHealthModel.stepCount = @"0";
////                            userHealthModel.currentDeviceStepCount = @"0";
////
////                        }else{
////                            userHealthModel.saveCurrentDeviceStepCount = @"0";
////                            userHealthModel.stepCount = @"0";
////                            userHealthModel.currentDeviceStepCount = [NSString stringWithFormat:@"%.0f",value];
////
////                        }
////                    }
////                }
////                userHealthModel.latestDate = datehealth;
////                userHealthModel.latestDateWithHMS = date;
////                if (updateStepCount > 0) {
////                    stepCount(updateStepCount);
////                }
////            }];
//        }
//
//    }];
//}

- (void)getStepCountExerciseAndHealthSuccess:(void (^)(float))stepCountSuccessBlock failure:(void (^)(float))stepCountFailBlock{
    //这个方法用来查询近7天内的任意时间段的CMPedometerData信息。
    //这个方法是当你请求的时候才会触发
    
    //我查询从今天0点到现在我走了多少步[NSDate dateWithTimeIntervalSinceNow:0]
    NSDate *startOfToday = [[NSCalendar currentCalendar] startOfDayForDate:[NSDate date]];
    NSDate *endOfToday = [NSDate dateWithTimeIntervalSinceNow:0];
    
    [self.pedoMeter queryPedometerDataFromDate:startOfToday toDate:endOfToday withHandler:^(CMPedometerData * _Nullable pedometerData, NSError * _Nullable error) {
        if (!error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                
                NSString *stepCount = [NSString stringWithFormat:@"我已经走了%@步，距离%@米",pedometerData.numberOfSteps,pedometerData.distance];
                NSLog(@"stepCount = %@",stepCount);
                NSString *stepStr = [NSString stringWithFormat:@"%@",pedometerData.numberOfSteps];
                stepCountSuccessBlock([stepStr floatValue]);
            });
            
        }else{
            stepCountFailBlock(0);
        }
        
    }];
    
}

- (CMPedometer *)pedoMeter {
    if (!_pedoMeter) {
        _pedoMeter = [[CMPedometer alloc] init];
    }
    return _pedoMeter;
}

@end

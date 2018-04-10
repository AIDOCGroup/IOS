//
//  HealthKitManage.h
//  AIDOC
//
//  Created by app on 18/1/19.
//  Copyright © 2018年 app. All rights reserved.
//

#import <Foundation/Foundation.h>

//导入头文件
#import <HealthKit/HealthKit.h>
#import <UIKit/UIDevice.h>
#define HKVersion [[[UIDevice currentDevice] systemVersion] doubleValue]
#define CustomHealthErrorDomain @"com.sdqt.healthError"
typedef NS_ENUM(NSUInteger, MHMHealthIntervalUnit) {
    MHMHealthIntervalUnitDay,
    MHMHealthIntervalUnitWeek,
    MHMHealthIntervalUnitMonth,
    MHMHealthIntervalUnitYear,
};

@interface HealthKitManage : NSObject
+(id)shareInstance;//单例

//检查是否支持获取健康数据
/*
 *  @brief  检查是否支持获取健康数据
 */
- (void)authorizeHealthKit:(void(^)(BOOL success, NSError *error))compltion;

////读取步行+跑步距离
////获取步数
//- (void)getStepCount:(void(^)(double value,NSString *date, NSError *error))completion;
//
////获取公里数
//- (void)getDistance:(void(^)(double value, NSError *error))completion;
//

/**
 *  获取健康应用步数信息
 *
 *  @param unit             数据段类型
 *  @param queryResultBlock 结果返回block 以字典形式返回数据：resultModels：查询后封装的model数组 ； maxStepCount：最大步数；minStepCount：最小步数；totalStepCount：总步数
 */
- (void)fetchHealthDataForUnit:(MHMHealthIntervalUnit)unit
              queryResultBlock:(void (^)(NSDictionary *queryResultDict))queryResultBlock;

@property (nonatomic, strong) HKHealthStore *healthStore;//声明一个属性

#pragma mark - 判断是否获得了指定类型的权限
+ (void)openHealthServiceWithHKQuantityTypeIdentifier:(HKQuantityTypeIdentifier)identifier Bolck:(void(^)(BOOL value))returnBolck;

@end

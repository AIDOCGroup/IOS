//
//  HealthKitManage.m
//  AIDOC
//
//  Created by app on 18/1/19.
//  Copyright © 2018年 app. All rights reserved.
//

#import "HealthKitManage.h"

@implementation HealthKitManage

//创建单例方法
+(id)shareInstance
{
    static id manager ;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [[[self class] alloc] init];
    });
    return manager;
}


//检查是否支持获取健康数据
/*
 *  @brief  检查是否支持获取健康数据
 */
- (void)authorizeHealthKit:(void(^)(BOOL success, NSError *error))compltion
{
    if(HKVersion >= 8.0)
    {
        if (![HKHealthStore isHealthDataAvailable]) {
            NSError *error = [NSError errorWithDomain: @"com.raywenderlich.tutorials.healthkit" code: 2 userInfo: [NSDictionary dictionaryWithObject:@"HealthKit is not available in th is Device"                                                                      forKey:NSLocalizedDescriptionKey]];
            if (compltion != nil) {
                compltion(false, error);
            }
            return;
        }
        if ([HKHealthStore isHealthDataAvailable]) {
            if(self.healthStore == nil)
                self.healthStore = [[HKHealthStore alloc] init];
            /*
             组装需要读写的数据类型
             */
            NSSet *writeDataTypes = [self dataTypesToWrite];
            NSSet *readDataTypes = [self dataTypesRead];
            
            /*
             注册需要读写的数据类型，也可以在“健康”APP中重新修改
             *///writeDataTypes
            [self.healthStore requestAuthorizationToShareTypes:nil readTypes:readDataTypes completion:^(BOOL success, NSError *error) {
                
                if (compltion != nil) {
                    NSLog(@"error->%@", error.localizedDescription);
                    compltion (success, error);
                }
            }];
        }
    }
    else {
        NSDictionary *userInfo = [NSDictionary dictionaryWithObject:@"iOS 系统低于8.0"                                                                      forKey:NSLocalizedDescriptionKey];
        NSError *aError = [NSError errorWithDomain:CustomHealthErrorDomain code:0 userInfo:userInfo];
        compltion(0,aError);
    }
}

/*!
 *  @brief  写权限
 *  @return 集合
 */
- (NSSet *)dataTypesToWrite
{
    HKQuantityType *heightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierHeight];
    HKQuantityType *weightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyMass];
    HKQuantityType *temperatureType = [HKQuantityType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyTemperature];
    HKQuantityType *activeEnergyType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierActiveEnergyBurned];
    
    return [NSSet setWithObjects:heightType, temperatureType, weightType,activeEnergyType,nil];
}

/*!
 *  @brief  读权限
 *  @return 集合
 */
- (NSSet *)dataTypesRead
{
    HKQuantityType *heightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierHeight];
    HKQuantityType *weightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyMass];
    HKQuantityType *temperatureType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyTemperature];
    HKCharacteristicType *birthdayType = [HKObjectType characteristicTypeForIdentifier:HKCharacteristicTypeIdentifierDateOfBirth];
    HKCharacteristicType *sexType = [HKObjectType characteristicTypeForIdentifier:HKCharacteristicTypeIdentifierBiologicalSex];
    HKQuantityType *stepCountType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierStepCount];
    HKQuantityType *distance = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierDistanceWalkingRunning];
    HKQuantityType *activeEnergyType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierActiveEnergyBurned];
    
    return [NSSet setWithObjects:heightType, temperatureType,birthdayType,sexType,weightType,stepCountType, distance, activeEnergyType,nil];
}

//读取步行+跑步距离
//获取步数
- (void)getStepCount:(void(^)(double value,NSString *date, NSError *error))completion
{
    HKQuantityType *stepType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierStepCount];
    NSSortDescriptor *timeSortDescriptor = [[NSSortDescriptor alloc] initWithKey:HKSampleSortIdentifierEndDate ascending:NO];
    
    // Since we are interested in retrieving the user's latest sample, we sort the samples in descending order, and set the limit to 1. We are not filtering the data, and so the predicate is set to nil.
    HKSampleQuery *query = [[HKSampleQuery alloc] initWithSampleType:stepType predicate:[HealthKitManage predicateForSamplesToday] limit:HKObjectQueryNoLimit sortDescriptors:@[timeSortDescriptor] resultsHandler:^(HKSampleQuery *query, NSArray *results, NSError *error) {
        
        NSString *endDate;
        
        if(error)
        {
            completion(0,endDate,error);
        }
        else{
            NSInteger totleSteps = 0;
            //获取数组
            if ([results count] == 0) {
                completion(totleSteps,endDate,error);
                return;
            }
            
            //获取今天第一次运动的时间
            HKQuantitySample *quantitySample = results[results.count-1];
            NSDateFormatter *fm=[[NSDateFormatter alloc]init];
            fm.dateFormat=@"yyyy-MM-dd HH:mm:ss";
            NSString *strNeedStart = [fm stringFromDate:quantitySample.startDate];
            NSLog(@"startDate %@",strNeedStart);
            NSString *strNeedEnd = [fm stringFromDate:quantitySample.endDate];
            NSLog(@"endDate %@",strNeedEnd);
            endDate = [fm stringFromDate:quantitySample.endDate];
            
            NSArray *array = [self getRealHealthData:results];
            
            
            //一个数组的添加
            for (NSDictionary *dict in array)
            {
                NSInteger stepCount = [dict[@"stepCount"]integerValue];
                totleSteps = totleSteps + stepCount;
                
            }
           
             NSLog(@"当天最后的时间 = %@",endDate);
            NSLog(@"当天行走步数 = %ld",(long)totleSteps);
            
            completion(totleSteps,endDate,error);
        }
        
    }];
    
    [self.healthStore executeQuery:query];
}
- (NSArray *)getRealHealthData:(NSArray *)resultArr
{
    NSMutableArray *returnArr = [[NSMutableArray alloc]init];
//    HKQuantityType *stepType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierStepCount];
    for (HKQuantitySample *model in resultArr)
    {
        //HKQuantity 类存储了给定单位的值,此值和单位就构成了数据。和 HKUnit类一样,在使用它时,需要进行实例化。实例化 HKQuantity需要使用到 init(unit:doubleValue:)方法。它可以用来创建一个 quantity(数量)对象。
        HKQuantity *resultQuantity = model.quantity;
//        HKUnit *unit = [HKHealthKitHelper defaultUnitForQuantityType:stepType];
        HKUnit *unit = [HKUnit countUnit];
    
        double valueDou = [resultQuantity doubleValueForUnit:unit];
        NSString *value = [NSString stringWithFormat:@"%.0f",valueDou];
//
//        //NSString *startDateStr = [RequestHelper getDateStrFromDate:model.startDate];
//        NSString *endDateStr   = [RequestHelper getDateStrFromDate:model.endDate];
//
        NSDictionary *dict = (NSDictionary *)model.metadata;
//        NSLog(@"dict= %@",dict);
        NSInteger wasUserEntered = [dict[@"HKWasUserEntered"]integerValue];

        if(wasUserEntered == 1)
        {
            //这是用户自己手动添加的数据
//            NSLog(@"手动添加的步数 == %@",value);
        }
        else
        {
            //这是苹果HealthKit记录的数据
            NSDictionary *dictReturn = @{@"stepCount":value};
            NSLog(@"%@",value);
            [returnArr addObject:dictReturn];
        }
    }
    return returnArr;
}

//获取公里数
- (void)getDistance:(void(^)(double value, NSError *error))completion
{
    HKQuantityType *distanceType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierDistanceWalkingRunning];
    NSSortDescriptor *timeSortDescriptor = [[NSSortDescriptor alloc] initWithKey:HKSampleSortIdentifierEndDate ascending:NO];
    HKSampleQuery *query = [[HKSampleQuery alloc] initWithSampleType:distanceType predicate:[HealthKitManage predicateForSamplesToday] limit:HKObjectQueryNoLimit sortDescriptors:@[timeSortDescriptor] resultsHandler:^(HKSampleQuery * _Nonnull query, NSArray<__kindof HKSample *> * _Nullable results, NSError * _Nullable error) {
        
        if(error)
        {
            completion(0,error);
        }
        else
        {
            double totleSteps = 0;
            for(HKQuantitySample *quantitySample in results)
            {
                HKQuantity *quantity = quantitySample.quantity;
                HKUnit *distanceUnit = [HKUnit meterUnitWithMetricPrefix:HKMetricPrefixKilo];
                double usersHeight = [quantity doubleValueForUnit:distanceUnit];
                totleSteps += usersHeight;
            }
            NSLog(@"当天行走距离 = %.2f",totleSteps);
            completion(totleSteps,error);
        }
    }];
    [self.healthStore executeQuery:query];
}

//NSPredicate当天时间段的方法实现

/*!
 *  @brief  当天时间段
 *
 *  @return 时间段
 */
+ (NSPredicate *)predicateForSamplesToday {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDate *now = [NSDate date];
    NSDateComponents *components = [calendar components:NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay fromDate:now];
    [components setHour:0];
    [components setMinute:0];
    [components setSecond: 0];
    
    NSDate *startDate = [calendar dateFromComponents:components];
    NSDate *endDate = [calendar dateByAddingUnit:NSCalendarUnitDay value:1 toDate:startDate options:0];
    NSPredicate *predicate = [HKQuery predicateForSamplesWithStartDate:startDate endDate:endDate options:HKQueryOptionNone];
    return predicate;
}

#pragma mark - 判断是否获得了指定类型的权限
/*!
 *  @brief  写权限
 *  @return 集合
 */
+ (NSSet *)healthKitTypesToWrite
{
    HKQuantityType *heightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierHeight];
    HKQuantityType *weightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyMass];
    HKQuantityType *temperatureType = [HKQuantityType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyTemperature];
    HKQuantityType *activeEnergyType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierActiveEnergyBurned];
    
    return [NSSet setWithObjects:heightType, temperatureType, weightType,activeEnergyType,nil];
}

/*!
 *  @brief  读权限
 *  @return 集合
 */
+ (NSSet *)healthKitTypesToRead
{
    HKQuantityType *heightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierHeight];
    HKQuantityType *weightType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyMass];
    HKQuantityType *temperatureType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierBodyTemperature];
    HKCharacteristicType *birthdayType = [HKObjectType characteristicTypeForIdentifier:HKCharacteristicTypeIdentifierDateOfBirth];
    HKCharacteristicType *sexType = [HKObjectType characteristicTypeForIdentifier:HKCharacteristicTypeIdentifierBiologicalSex];
    HKQuantityType *stepCountType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierStepCount];
    HKQuantityType *distance = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierDistanceWalkingRunning];
    HKQuantityType *activeEnergyType = [HKObjectType quantityTypeForIdentifier:HKQuantityTypeIdentifierActiveEnergyBurned];
    
    return [NSSet setWithObjects:heightType, temperatureType,birthdayType,sexType,weightType,stepCountType, distance, activeEnergyType,nil];
}

+ (HKObjectType *)HKQuantityTypeIdentifier:(HKQuantityTypeIdentifier)identifier {
    HKObjectType *tempType = [HKObjectType quantityTypeForIdentifier:identifier];
    return tempType;
}

+ (void)openHealthServiceWithHKQuantityTypeIdentifier:(HKQuantityTypeIdentifier)identifier Bolck:(void(^)(BOOL value))returnBolck
{
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_8_0
    if (![HKHealthStore isHealthDataAvailable]) {
        if (returnBolck) {
            returnBolck(NO);
        }
    } else {
        HKHealthStore *healthStore = [[HKHealthStore alloc] init];
        //HKObjectType *hkObjectType = [HealthKitManage HKQuantityTypeIdentifier:identifier];
        HKSampleType *hkObjectType = [HKSampleType quantityTypeForIdentifier:HKQuantityTypeIdentifierStepCount];
        HKAuthorizationStatus hkAuthStatus = [healthStore authorizationStatusForType:hkObjectType];
        if (hkAuthStatus == HKAuthorizationStatusNotDetermined) {//还未获取权限
            // 1. 你创建了一个NSSet对象，里面存有本篇教程中你将需要用到的从Health Stroe中读取的所有的类型：个人特征（血液类型、性别、出生日期）、数据采样信息（身体质量、身高）以及锻炼与健身的信息。
            NSSet <HKObjectType *> * healthKitTypesToRead = [HealthKitManage healthKitTypesToRead];
            // 2. 你创建了另一个NSSet对象，里面有你需要向Store写入的信息的所有类型（锻炼与健身的信息、BMI、能量消耗、运动距离）
            NSSet <HKSampleType *> * healthKitTypesToWrite = [HealthKitManage healthKitTypesToWrite];
            /*
             组装需要读写的数据类型
             */
            [healthStore requestAuthorizationToShareTypes:nil readTypes:healthKitTypesToRead completion:^(BOOL success, NSError *error) {
                if (returnBolck) {
                    returnBolck(success);
                }
            }];
        } else if (hkAuthStatus == HKAuthorizationStatusSharingDenied) {//已被用户拒绝
            if (returnBolck) {
                returnBolck(NO);
            }
        }else {
            if (returnBolck) {
                returnBolck(YES);
            }
        }
    }
#endif
}


- (void)fetchHealthDataForUnit:(MHMHealthIntervalUnit)unit
              queryResultBlock:(void (^)(NSDictionary *queryResultDict))queryResultBlock {
    NSMutableDictionary *tempDict = @{}.mutableCopy;
    
    HKQuantityType *quantityType = [HKQuantityType quantityTypeForIdentifier:HKQuantityTypeIdentifierStepCount];
    
    NSDateComponents *intervalComponents = [[NSDateComponents alloc] init];
    
    __block NSDate *endDate = [NSDate date];
    __block NSCalendarUnit calendarUnit;
    __block NSCalendar *calendar;
    
#ifdef IOS8
    calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
#else
    calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
#endif
    __block NSInteger value = 0;//根据该值计算查询开始时间
    NSDateComponents *currentComponents = [calendar components:NSCalendarUnitSecond | NSCalendarUnitMinute | NSCalendarUnitHour fromDate:endDate];
    NSTimeInterval currentInterval = currentComponents.hour * 3600 + currentComponents.minute * 60 + currentComponents.second;
    
    switch (unit) {
        case MHMHealthIntervalUnitDay:
            intervalComponents.hour = 1;
            calendarUnit = NSCalendarUnitHour;
            value = currentComponents.hour;
            endDate = [NSDate dateWithTimeIntervalSinceNow: - (currentComponents.minute * 60 + currentComponents.second)];
            break;
        case MHMHealthIntervalUnitWeek:
            value = 6;
            intervalComponents.day = 1;
            endDate = [NSDate dateWithTimeIntervalSinceNow:- (currentInterval + 24 * 3600)];
            calendarUnit = NSCalendarUnitDay;
            break;
        case MHMHealthIntervalUnitMonth:
            value = 29;
            intervalComponents.day = 1;
            endDate = [NSDate dateWithTimeIntervalSinceNow:- (currentInterval + 24 * 3600)];
            calendarUnit = NSCalendarUnitDay;
            break;
        case MHMHealthIntervalUnitYear:
            value = 12;
            intervalComponents.month = 1;
            calendarUnit = NSCalendarUnitMonth;
            break;
    }
    
    NSDateComponents *anchorComponents = [calendar components:NSCalendarUnitSecond | NSCalendarUnitMinute | NSCalendarUnitHour | NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear
                                                     fromDate:endDate];
    
    [self executeQueryForQuantityType:quantityType
                            predicate:nil
                           anchorDate:[calendar dateFromComponents:anchorComponents]
                   intervalComponents:intervalComponents
                       callBackResult:^(HKStatisticsCollection * _Nullable result, NSError *error) {
                           if (error) {
                               NSLog(@"an error occurred while calculating the statistics %@",error.localizedDescription);
                           } else {
                               
                               NSDate *startDate = [calendar dateByAddingUnit:calendarUnit
                                                                        value:-value
                                                                       toDate:endDate
                                                                      options:0];
                               
                               __block NSInteger maxStepCount = 0;//最大步行数
                               __block NSInteger minStepCount = 0;//最小步行数
                               __block double totalStepCount = 0;//总步行数
                               
                               [result enumerateStatisticsFromDate:startDate toDate:endDate withBlock:^(HKStatistics * _Nonnull statistic, BOOL * _Nonnull stop) {
                                   for (HKSource *source in statistic.sources) {
                                       if ([source.name isEqualToString:[UIDevice currentDevice].name]) {//只取设备的步数，过滤其他第三方应用的
                                           double stepCount = [[statistic sumQuantityForSource:source] doubleValueForUnit:[HKUnit countUnit]];
                                           if (stepCount > 0) {//手动从健康应用中获取添加数据，设备步数为0，这里做过滤操作
                                               //初始化最小步数为第一个值，方便之后计算最小步数
                                               if (minStepCount == 0) {
                                                   minStepCount = stepCount;
                                               }
                                               maxStepCount = MAX(maxStepCount, stepCount);
                                               minStepCount = MIN(minStepCount, stepCount);
                                               totalStepCount += stepCount;
             
                                           }
                                       }
                                   }
                                   NSString *totalStr = [NSString stringWithFormat:@"%.0f",totalStepCount];
//                                   tempDict = @{
//                                                @"totalStepCount":totalStr,
//                                                @"startDate":startDate,
//                                                @"endDate":endDate
//                                                }
                                   NSTimeZone *zone = [NSTimeZone systemTimeZone];
                                   NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
                                   [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
                                   [dateFormatter setTimeZone:zone];
//                                   NSString *dateStrStart =[dateFormatter stringFromDate:startDate];
                                   NSString *dateStrEnd =[dateFormatter stringFromDate:endDate];
                                   
                                   [tempDict setValue:totalStr forKey:@"totalStepCount"];
//                                   [tempDict setValue:dateStrStart forKey:@"startDate"];
                                   [tempDict setValue:dateStrEnd forKey:@"endDate"];
                                   
                               }];
                               
                               NSLog(@"当天行走步数%.0f",totalStepCount);
                               if (queryResultBlock) {
                                   queryResultBlock(tempDict);
                               }
                           }
                       }];
}

//查询
- (void)executeQueryForQuantityType:(HKQuantityType *)quantityType
                          predicate:(nullable NSPredicate *)quantitySamplePredicate
                         anchorDate:(NSDate *)anchorDate
                 intervalComponents:(NSDateComponents *)intervalComponents
                     callBackResult:(void (^)(HKStatisticsCollection * __nullable result, NSError *error))queryResult {
    
    HKStatisticsCollectionQuery *collectionQuery =
    [[HKStatisticsCollectionQuery alloc] initWithQuantityType:quantityType
                                      quantitySamplePredicate:quantitySamplePredicate
                                                      options:HKStatisticsOptionCumulativeSum | HKStatisticsOptionSeparateBySource
                                                   anchorDate:anchorDate
                                           intervalComponents:intervalComponents];
    
    collectionQuery.initialResultsHandler = ^(HKStatisticsCollectionQuery *query, HKStatisticsCollection * __nullable result, NSError * __nullable error){
        if (queryResult) {
            queryResult(result, error);
        }
    };
    [self.healthStore executeQuery:collectionQuery];
}

@end

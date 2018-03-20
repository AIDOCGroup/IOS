//
//  ICTBleMonitor.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/18.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICTBleSDKThresholdEntity.h"
#import "NSDate-Utilities.h"
#import "NSDateFormatter+ICT.h"

@interface ICTBleSDKMonitorEntity : NSObject

/**
 *	@brief	未选择监护方案
 *
 *	@return	返回未选择监护方案时，需要发送给手环的默认监护方案
 */
+ (ICTBleSDKMonitorEntity *)notSelectedMonitor;


/**
 *	@brief	监护方案初始化
 *
 *	@param 	interval 	采集频率，即多久采集一次数据
 *	@param 	period 	采集时间段 如：07:00-14:00表示当天的7点至14点这个时间段，14:00-07:00表示当天的14点至24点，0点至7点
 *	@param 	workDay 	工作日,1：有效，0：无效 如：1101111表示周一、二、四、五、六、七有效，周三无效
 *	@param 	conTime 	持续时间(小于时间间隔)
 *	@param 	gatherBodyType 	采集参数(可传多个参数)
 *	@param 	excepGatherBodyType 	异常采集参数(可传多个参数)
 *	@param 	excepGatherTime 	异常采集时间
 *	@param 	excepInterval 	异常采集频率
 *	@param 	isOpen 	监护方案是否启动  1:方案启动  0:方案暂停
 *	@param 	isVibration 	数据异常时，手环是否振动 0:不振动 1：振动
 *	@param 	monitorID 	方案ID
 *	@param 	updateInterval 	运动数据更新频率(建议传值900)
 */
- (instancetype)initWithInterval:(NSInteger)interval
                      timePeriod:(NSString *)period
                         workDay:(NSString *)workDay
                    continueTime:(NSInteger)conTime
                        gatherID:(ICTBleSDKBodyParameterType)gatherBodyType
               exceptionGatherID:(ICTBleSDKBodyParameterType)excepGatherBodyType
             exceptionGatherTime:(NSInteger)excepGatherTime
               exceptionInterval:(NSInteger)excepInterval
                          isOpen:(NSInteger)isOpen
                     isVibration:(NSInteger)isVibration
                       monitorID:(ICTMonitorTemplateIDs)monitorID
            sportsUpdateInterval:(NSInteger)updateInterval;

@property (assign, nonatomic) NSInteger             interval;//采集频率
@property (assign, nonatomic) NSString              *timePeriod;//采集时间段
@property (assign, nonatomic) NSString              *workDay;//工作日
@property (assign, nonatomic) NSInteger             continueTime;//持续时间
@property (assign, nonatomic) ICTBleSDKBodyParameterType  gatherID;//采集参数
@property (assign, nonatomic) ICTBleSDKBodyParameterType  exceptionGatherID;//异常采集参数
@property (assign, nonatomic) NSInteger             exceptionGatherTime;//异常采集时间
@property (assign, nonatomic) NSInteger             exceptionInterval;//异常采集频率
@property (assign, nonatomic) NSInteger             isOpen;//监护方案是否启动
@property (assign, nonatomic) NSInteger             isVibration;//手环是否振动
@property (assign, nonatomic) ICTMonitorTemplateIDs monitorID;//方案ID
@property (assign, nonatomic) NSInteger             sportsUpdateInterval;//运动数据更新频率

- (NSString *)formatNormalMonitorTime;

@end

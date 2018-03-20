//
//  TemperatureModel.h
//  BosmaBleSDK
//
//  Created by TaoLi on 2017/5/16.
//  Copyright © 2017年 Bosma. All rights reserved.
//  测量温度值

#import <Foundation/Foundation.h>

@interface TemperatureModel : NSObject
/*!测量日期*/
@property(nonatomic,strong)NSDate *measureDate;
/*!测量温度值 如果value为0值，代表测温异常，否则正常。*/
@property(nonatomic,strong)NSNumber *value;
-(instancetype)initWithDate:(NSDate *)date value:(NSNumber *)value;
@end

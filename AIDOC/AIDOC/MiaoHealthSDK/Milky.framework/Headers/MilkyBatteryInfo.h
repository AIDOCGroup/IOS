//
//  MilkyBatteryInfo.h
//  SDK
//
//  Created by Martin on 2017/8/4.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MilkyBatteryInfo : NSObject
@property (nonatomic,assign) NSInteger quantity;//电量 0xFF: 无效值 其他: 电量百分比
@end

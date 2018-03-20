//
//  RestonBatteryInfo.h
//  SDK
//
//  Created by Martin on 2017/7/28.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RestonBatteryInfo : NSObject
/*充电状态
 0: 未充电状态
 1: 正在充电状态
 */
@property (nonatomic,assign)UInt8 chargingState;
/*电量
 0xFF: 无效值
 其他: 电量百分比 (充电时, 不建议使用该值)
 */
@property (nonatomic,assign) UInt8 quantity;
@end

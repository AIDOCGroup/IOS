//
//  ElectricModel.h
//  BosmaBleSDK
//
//  Created by TaoLi on 2017/5/17.
//  Copyright © 2017年 Bosma. All rights reserved.
//  电量

#import <Foundation/Foundation.h>

@interface ElectricModel : NSObject
/*!测量日期*/
@property(nonatomic,strong)NSDate *measureDate;
/*!测量电量百分比(取值0-100 100满电)*/
@property(nonatomic,assign)int value;
@end

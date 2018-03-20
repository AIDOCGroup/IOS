//
//  BosmaMeasureRequestModel.h
//  BosmaBleSDK
//
//  Created by Bosma on 2017/4/20.
//  Copyright © 2017年 Bosma. All rights reserved.
//  请求测量对象

#import <Foundation/Foundation.h>
#import "BosmaExportConstantsDefine.h"
@interface BosmaMeasureRequestModel : NSObject
/*!秤重单位*/
@property(nonatomic,assign)BosmaMeasureUnitType unitType;
/*!性别*/
@property(nonatomic,assign)BosmaGenderType genderType;
/*!年龄*/
@property(nonatomic,assign)NSUInteger age;
/*!身高（厘米）*/
@property(nonatomic,assign)NSUInteger height;
/*!是否测脂 默认-测脂 YES-测脂 NO-不测脂*/
@property(nonatomic,assign)BOOL ifMeasureBodyFat;
@end

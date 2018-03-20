//
//  BosmaMeasureResultModel.h
//  BosmaBleSDK
//
//  Created by Bosma on 2017/4/20.
//  Copyright © 2017年 Bosma. All rights reserved.
//  测量结果输出模型

#import <Foundation/Foundation.h>

@interface BosmaMeasureResultModel : NSObject
/*!BMI*/
@property(nonatomic,copy)NSString *bmi;
/*!体脂率*/
@property(nonatomic,copy)NSString *bodyFat;
/*!骨骼率*/
@property(nonatomic,copy)NSString *bone;
/*!肌肉率*/
@property(nonatomic,copy)NSString *boneMuscle;
/*!基础代谢(静息能耗)*/
@property(nonatomic,copy)NSString *kCal;
/*!水分含量*/
@property(nonatomic,copy)NSString *tbw;
/*!内脏脂肪率*/
@property(nonatomic,copy)NSString *vFat;
/*!体重(公斤)*/
@property(nonatomic,copy)NSString *weight;
@end

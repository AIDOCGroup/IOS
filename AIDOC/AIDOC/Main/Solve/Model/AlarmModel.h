//
//  AlarmModel.h
//  AlarmDemo
//
//  Created by apple on 16/7/13.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "BaseModel.h"

@interface AlarmModel : BaseModel

@property(nonatomic, copy) NSString * alarmTime;        //报警时间
@property(nonatomic, copy) NSString * alarm_id;         //报警id
@property(nonatomic, copy) NSString * name;             //报警设备名称
@property(nonatomic, copy) NSString * periodTime;        //
@property(nonatomic, copy) NSString * position;         //报警位置（设备位置）
@property(nonatomic, copy) NSString * statusPerson;     //人工状态 0未消除 1已消除
@property(nonatomic, copy) NSString *typeName;          //报警类型名称
@property(nonatomic, copy) NSString *type;              //报警类型


@end

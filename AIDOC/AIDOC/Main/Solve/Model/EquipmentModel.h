//
//  EquipmentModel.h
//  AlarmDemo
//
//  Created by apple on 16/7/13.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "BaseModel.h"

@interface EquipmentModel : BaseModel

@property(nonatomic, copy) NSString * build_ID;     //设备id
@property(nonatomic, copy) NSString * name;         //设备名称
@property(nonatomic, copy) NSString * flag;         //室内室外标示 0室内（即楼宇） 1室外
@property(nonatomic, copy) NSString * position;     //设备位置详情
@property(nonatomic, copy) NSString * model;        //设备型号
@property(nonatomic, copy) NSString * maker;        //制造商
@property(nonatomic, copy) NSString * phone;        //sim卡号
@property(nonatomic, copy) NSString *typeName;      //设备类型
@property(nonatomic, copy) NSString *sn;            //设备编码
@property(nonatomic, copy) NSString * max;          //上限(室外)
@property(nonatomic, copy) NSString * min;          //下限(室外)
@property(nonatomic, copy) NSString * orgName;      //所属企业
@property(nonatomic, copy) NSString * waterPress;   //




@end

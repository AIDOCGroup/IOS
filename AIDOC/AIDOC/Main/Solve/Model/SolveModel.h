//
//  SolveModel.h
//  AlarmDemo
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "BaseModel.h"

@interface SolveModel : BaseModel
@property(nonatomic, copy) NSString * alarmCount;       //报警数量 楼宇内设备报警数，室外设备可为0
@property(nonatomic, copy) NSString * alarmExpireNum;   //
@property(nonatomic, copy) NSString * dangerCount;      //隐患数量 隐患数量
@property(nonatomic, copy) NSString * dangerExpireNum;  //
@property(nonatomic, copy) NSString * equipmentCount;   //设备数量 楼宇内设备总数，室外设备可为0

@property(nonatomic, copy) NSString * isAlarm;          //是否有报警 0正常 1报警。只针对室外设备，楼宇都为0
@property(nonatomic, copy) NSString *lat;              //纬度
@property(nonatomic, copy) NSString *lng;              //经度
@property(nonatomic, copy) NSString * buildID;       //室外设备id或楼宇id
@property(nonatomic, copy) NSString * flag;        //室内室外标示 0室内（即楼宇） 1室外,2室外隐患


@end

//
//  BindDevice.h
//  MiaoHealthConnect
//
//  Created by 罗志平 on 16/11/25.
//  Copyright © 2016年 Miao Health. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMPeripheralsProvider.h"
#import "MCData.h"


@interface MCDeviceFunctional : NSObject
/// 功能类型ID
@property (nonatomic, assign) NSInteger functional_id;
/// 功能类型说明
@property (nonatomic, strong) NSString  *_Nullable functional_name;

@end

@interface MCDeviceType : NSObject

/// 设备类型ID
@property (nonatomic, strong) NSString *_Nonnull tid;
/// 设备类型名称
@property (nonatomic, strong) NSString *_Nullable type_name;
/// 设备类型描述
@property (nonatomic, strong) NSString *_Nullable type_desc;
/// 设备类型logo
@property (nonatomic, strong) NSString *_Nullable logo;
/// 排序字段
@property (nonatomic, assign) NSInteger sort_no;

@end


@interface MCDevice : NSObject

/// 设备id  device_id = connect_type
@property (nonatomic, strong) NSString *_Nonnull device_id;
/// 设备号
@property (nonatomic, strong) NSString *_Nonnull device_sn;
/// 设备名称
@property (nonatomic, strong) NSString *_Nullable device_name;
/// 设备描述
@property (nonatomic, strong) NSString *_Nullable device_des;
/// 设备描述：h5页面
@property (nonatomic, strong) NSString *_Nullable des_url;
/// 设备连接方式
@property (nonatomic, assign) PeripheralsAttendedMode link_type;

/// 绑定人数
@property (nonatomic, assign) NSInteger bindnum;
/// 是否绑定 1-支持绑定 2-不支持绑定 3-设备即将上线 4-下线
@property (nonatomic, assign) NSInteger isbind;
/// 是否推荐
@property (nonatomic, assign) NSInteger ishot;
/// 同device_id一直
@property (nonatomic, assign) NSInteger connect_type;

/// 设备连接类型描述
@property (nonatomic, strong) NSString *_Nullable connect_name;
/// 绑定详情
@property (nonatomic, strong) NSMutableArray<MCDeviceFunctional *> *_Nullable deviceFunctional;

/// 设备logo
@property (nonatomic, strong) NSString *_Nullable logo;
/// 排序字段
@property (nonatomic, assign) NSInteger sort_no;

/// 是否为条形码
@property (nonatomic, assign) BOOL isBarcode;

@property (nonatomic, assign) NSInteger type_id;

/// 是否已绑定此设备， 1=是 ， 0=否
@property (nonatomic , assign) NSInteger bind_status;

@end

@interface MCUserDevice : NSObject
/// 用户与设备关联ID
@property (nonatomic, strong) NSString *_Nonnull did;
/// 设备id  device_id = connect_type
@property (nonatomic, strong) NSString *_Nonnull device_id;
/// 设备sn
@property (nonatomic, strong) NSString *_Nonnull device_sn;
/// 设备编码
@property (nonatomic, strong) NSString *_Nonnull device_no;
/// 设别名称
@property (nonatomic, strong) NSString *_Nonnull device_name;
/// 设备连接方式
@property (nonatomic, assign) PeripheralsAttendedMode link_type;
/// 设备类型ID
@property (nonatomic, assign) NSInteger type_id;
/// 设备tips
@property (nonatomic, strong) NSString *_Nullable tips;
/// 设备logo
@property (nonatomic, strong) NSString *_Nullable logo;
/// 连接类型
@property (nonatomic, assign) NSInteger connect_type;
/// 康康SIM卡有效期截止时间
@property (nonatomic, assign) NSInteger validity_date_sim;
/// 服务器当前时间（康康SIM卡有效期判断）
@property (nonatomic, assign) NSInteger current_time;
/// 更新时间
@property (nonatomic, assign) NSInteger update_time;
/// 绑定时间
@property (nonatomic, assign) NSInteger create_time;
/// 平台号
@property (nonatomic, assign) NSInteger plat;
/// 绑定详情
@property (nonatomic, strong) NSMutableArray<MCDeviceFunctional *> *_Nullable deviceFunctional;

/// 是否为条形码
@property (nonatomic, assign) BOOL isBarcode;

@end


@interface MCDeviceData : NSObject
/// 设备id
@property (nonatomic, strong) NSString *_Nonnull device_id;
/// 设备sn
@property (nonatomic, strong) NSString *_Nonnull device_sn;
/// 设备no
@property (nonatomic, strong) NSString *_Nonnull device_no;
/// 设备源
@property (nonatomic, strong) NSString *_Nonnull data_source;
/// 设备源的数据
@property (nonatomic, strong) NSMutableArray<MCData *> *_Nonnull device_datas;
/// 设备包含的功能类型
@property (nonatomic, strong) NSMutableArray<MCDeviceFunctional *> *_Nonnull deviceFunctional;

@end



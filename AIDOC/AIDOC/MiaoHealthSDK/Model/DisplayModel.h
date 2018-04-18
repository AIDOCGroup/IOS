//
//  DisplayModel.h
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 2017/6/5.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DisplayModel : NSObject

@property (nonatomic , copy) NSString *name;

@property (nonatomic , copy) NSString *descr;

@property (nonatomic , copy) NSString *imageUrl;

/// 设备连接方式
@property (nonatomic, assign) PeripheralsAttendedMode link_type;

@end

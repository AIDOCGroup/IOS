//
//  MCBLEDeviceModel.h
//  MiaoHealthConnect
//
//  Created by JinZhengxuan on 2016/11/2.
//  Copyright © 2016年 Miao Health. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MCBLEDevice : NSObject
/// UUID
@property (nonatomic, copy) NSString *_Nonnull uuid;
/// 设备名字
@property (nonatomic, copy) NSString *_Nullable name;
/// 描述信息
@property (nonatomic, strong) NSDictionary *_Nullable data;
// 状态
@property (nonatomic, assign) NSInteger  status;

@end

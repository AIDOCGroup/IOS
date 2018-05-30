//
//  DeviceView.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DeviceView : UIView

@property(nonatomic , copy) NSString *name;
@property(nonatomic , copy) NSString *enName;
@property(nonatomic , copy) NSString *desc;
@property(nonatomic , copy) NSString *enDesc;
@property(nonatomic , copy) NSString *url;

+(DeviceView *)deviceView;
@end

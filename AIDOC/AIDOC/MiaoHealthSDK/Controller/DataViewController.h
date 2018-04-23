//
//  DataViewController.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/18.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MiaoHealthConnect/MCDevice.h>
#import <MiaoHealthConnect/MCData.h>

@interface DataViewController : UIViewController
@property (nonatomic, strong) NSMutableArray * _Nullable dataArray;
@property (nonatomic, assign) PeripheralsDataType peripheralsDataType;
@property (nonatomic , weak ) UITableView * _Nullable tableView;

/// 设备id  device_id = connect_type
@property (nonatomic, strong) NSString *_Nonnull device_id;
@end

//
//  DeviceCell.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>
#define DeviceCellIdentifier @"DeviceCell"

@interface DeviceCell : UITableViewCell

@property (nonatomic , copy) NSString *num;
@property (nonatomic , copy) NSString *imageString;
@property (nonatomic , copy) NSString *descString;
@property (nonatomic , copy) NSString *enDescString;

+ (DeviceCell *)deviceCell;
@end

//
//  ScanDeviceCell.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ScanDeviceCell : UITableViewCell

@property (nonatomic , weak) MCBLEDevice *device;

+ (ScanDeviceCell *)scanDeviceCellWithTableView:(UITableView *)tableView indexPath:(NSIndexPath *)indexPath;

@end

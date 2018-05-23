//
//  DeviceSectionCell.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>

#define DeviceSectionCellIdentifier @"DeviceSectionCell"

@interface DeviceSectionCell : UITableViewCell

@property (nonatomic , copy) NSString *title;

+ (DeviceSectionCell *)deviceSectionCellWithTableView:(UITableView *)tableView;
@end

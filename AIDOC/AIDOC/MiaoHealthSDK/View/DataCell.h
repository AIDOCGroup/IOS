//
//  DataCell.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/18.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DataCell : UITableViewCell

+ (DataCell *)dataCell;

@property (nonatomic, assign) PeripheralsDataType peripheralsDataType;

@property (nonatomic , assign) id data;
@end

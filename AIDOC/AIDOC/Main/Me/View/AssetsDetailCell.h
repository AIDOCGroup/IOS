//
//  AssetsDetailCell.h
//  TYToken
//
//  Created by app on 2018/8/21.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AssetsDetailCell : UITableViewCell
@property (strong, nonatomic) UIImageView *imgView;
@property (strong, nonatomic) UILabel *typeLabel;//转入/转出
@property (strong, nonatomic) UILabel *countLabel;//金额
@property (strong, nonatomic) UILabel *timeLabel;//时间

@property (assign, nonatomic)NSInteger typeInt;

@end

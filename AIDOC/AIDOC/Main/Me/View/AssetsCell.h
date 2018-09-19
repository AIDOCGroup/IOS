//
//  AssetsCell.h
//  TYToken
//
//  Created by app on 2018/8/20.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AddAssetsModel.h"
@interface AssetsCell : UITableViewCell
@property (strong, nonatomic) UIImageView *imgView;
@property (strong, nonatomic) UILabel *titleLabel;
@property (strong, nonatomic) UILabel *descLabel;
@property (strong, nonatomic) UISwitch  *switchBtn;
@property (nonatomic, strong)AddAssetsModel *model;
@end

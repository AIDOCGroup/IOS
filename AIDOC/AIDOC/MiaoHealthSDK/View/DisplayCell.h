//
//  DisplayCell.h
//  SDKTest
//
//  Created by 刘云梦 on 16/12/21.
//  Copyright © 2016年 miao.cn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DisplayModel.h"

@interface DisplayCell : UITableViewCell
@property (weak, nonatomic)  UILabel *deviceNameLb;
@property (weak, nonatomic)  UILabel *deviceDescLb;
@property (weak, nonatomic)  UIImageView *displayIv;
@property (weak, nonatomic)  UILabel *bindPlat;
@property (strong , nonatomic) DisplayModel *displayModel;

+ (DisplayCell *)displayCellWithTableView:(UITableView *)tableView;

@end

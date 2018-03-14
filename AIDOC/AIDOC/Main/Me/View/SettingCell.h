//
//  SettingCell.h
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SettingCell : UITableViewCell
@property (nonatomic,strong)UILabel *itemName;
@property (nonatomic,strong)UILabel *detailLabel;
@property (nonatomic,strong)UIImageView *iconImgView;
@property (nonatomic,assign)BOOL isIcon;
@end

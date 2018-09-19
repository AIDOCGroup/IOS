//
//  HomeAssetsCell.m
//  TYToken
//
//  Created by app on 2018/8/20.
//  Copyright © 2018年 app. All rights reserved.
//

#import "HomeAssetsCell.h"

@implementation HomeAssetsCell
{
    UIView *bgView;
    UIImageView *imgView;
    UILabel *nameLabel;
    UILabel *MYLabel;
    UILabel *RMBLabel;
    UIView *lineView;
    UILabel *freezeLabel;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.contentView.backgroundColor = TEXTCOLORWITHEEEEEE;
        [self _initView];
    }
    return self;
}

- (void)_initView{
    
    bgView = [[UIView alloc] initWithFrame:CGRectMake(15, 0, kScreenWidth-30, 110)];
    bgView.backgroundColor = WHITECOLOR;
    bgView.layer.cornerRadius = 2.0f;
    [self.contentView addSubview:bgView];
    //78
    imgView = [[UIImageView alloc] initWithFrame:CGRectMake(10, 25, 40, 40)];
    imgView.image = [UIImage imageNamed:@"logo_aidoc_80"];
    [bgView addSubview:imgView];
    
    nameLabel = [[UILabel alloc] initWithFrame:CGRectMake(imgView.right+5, 0, 70, 19)];
    nameLabel.centerY = imgView.centerY;
    nameLabel.text = @"AIDOC";
    nameLabel.font = [UIFont systemFontOfSize:16];
    nameLabel.textColor = TEXTCOLORWITH333333;
    [bgView addSubview:nameLabel];
    
    MYLabel = [[UILabel alloc] initWithFrame:CGRectMake(bgView.width/2.0, 20, bgView.width/2.0-10, 27)];
    MYLabel.text = @"200.30306098";
    MYLabel.font = [UIFont systemFontOfSize:16];
    MYLabel.textColor = TEXTCOLORWITH333333;
    MYLabel.textAlignment = NSTextAlignmentRight;
    [bgView addSubview:MYLabel];
    
    RMBLabel = [[UILabel alloc] initWithFrame:CGRectMake(bgView.width/2.0, MYLabel.bottom+4, bgView.width/2.0-10, 20)];
    RMBLabel.text = @"≈ ¥ 3866.92";
    RMBLabel.font = [UIFont systemFontOfSize:14];
    RMBLabel.textColor = TEXTCOLORWITH9196A9;
    RMBLabel.textAlignment = NSTextAlignmentRight;
    [bgView addSubview:RMBLabel];
    
    lineView = [[UIView alloc] initWithFrame:CGRectMake(10, imgView.bottom+15, bgView.width-10, 1)];
    lineView.backgroundColor = [UIColor colorWithRed:234/255.0 green:236/255.0 blue:243/255.0 alpha:1];
    [bgView addSubview:lineView];
    
    freezeLabel = [[UILabel alloc] initWithFrame:CGRectMake(bgView.width/2.0, lineView.bottom+7, bgView.width/2.0-10, 17)];
    freezeLabel.text = @"冻结金额：20";
    freezeLabel.font = [UIFont systemFontOfSize:12];
    freezeLabel.textColor = TEXTCOLORWITH9196A9;
    freezeLabel.textAlignment = NSTextAlignmentRight;
    [bgView addSubview:freezeLabel];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}
- (void)setIsFreezeCount:(BOOL)isFreezeCount{
    _isFreezeCount = isFreezeCount;
    if (!_isFreezeCount) {
        bgView.frame = CGRectMake(15, 0, kScreenWidth-30, 90);
        lineView.hidden = YES;
        freezeLabel.hidden = YES;
    }
}

- (void)setModel:(AddAssetsModel *)model{
    _model = model;
}
@end

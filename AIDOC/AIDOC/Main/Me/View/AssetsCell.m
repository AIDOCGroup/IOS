//
//  AssetsCell.m
//  TYToken
//
//  Created by app on 2018/8/20.
//  Copyright © 2018年 app. All rights reserved.
//

#import "AssetsCell.h"

@implementation AssetsCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.layer.cornerRadius = 2.0f;
        [self _initView];
    }
    return self;
}

- (void)_initView{
    //78
    UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(15, 27, 40, 40)];
    [self.contentView addSubview:imgView];
    self.imgView = imgView;
    
    UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(imgView.right+8, 27, 100, 23)];
    titleLabel.font = [UIFont systemFontOfSize:16];
    titleLabel.textColor = TEXTCOLORWITH333333;
    [self.contentView addSubview:titleLabel];
    self.titleLabel = titleLabel;

    UILabel *descLabel = [[UILabel alloc] initWithFrame:CGRectMake(imgView.right+8, titleLabel.bottom+3, 100, 19)];
    descLabel.font = [UIFont systemFontOfSize:16];
    descLabel.textColor = TEXTCOLORWITH333333;
    [self.contentView addSubview:descLabel];
    self.descLabel = descLabel;
    
    UISwitch  *switchBtn = [[UISwitch alloc] initWithFrame:CGRectMake(kScreenWidth-70, 30, 51, 30)];
    [self.contentView addSubview:switchBtn];
    self.switchBtn = switchBtn;

    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(15, 89, kScreenWidth-15, 1)];
    lineView.backgroundColor = TEXTCOLORWITHEAECF3;
    [self.contentView addSubview:lineView];

}

- (void)setModel:(AddAssetsModel *)model{
    _model = model;
    self.titleLabel.text = model.name_short;
    self.descLabel.text  = model.name_long;
//    imgView.image = ;
    [self.imgView sd_setImageWithURL:[NSURL URLWithString:_model.logo] placeholderImage:[UIImage imageNamed:@"logo_aidoc_80"] options:SDWebImageRetryFailed];
    if ([model.addType boolValue]) {
        [self.switchBtn setOn:YES animated:NO];  // 设置开关状态(默认是 关)
    }else{
        [self.switchBtn setOn:NO animated:NO];  // 设置开关状态(默认是 关)
    }
    
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end

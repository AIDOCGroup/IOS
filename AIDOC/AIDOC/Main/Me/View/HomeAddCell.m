//
//  HomeAddCell.m
//  TYToken
//
//  Created by app on 2018/8/20.
//  Copyright © 2018年 app. All rights reserved.
//

#import "HomeAddCell.h"

@implementation HomeAddCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
//        self.contentView.backgroundColor = [UIColor clearColor];
        [self _initView];
    }
    return self;
}

- (void)_initView{
    
    UIView *bgView = [[UIView alloc] initWithFrame:CGRectMake(15, 0, kScreenWidth-30, 45)];
    bgView.backgroundColor = WHITECOLOR;
    bgView.layer.cornerRadius = 2.0f;
    [self.contentView addSubview:bgView];
    //78
    UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake((bgView.width-80)/2.0, 15, 15, 15)];
    imgView.image = [UIImage imageNamed:@"icon_+"];
    [bgView addSubview:imgView];
    
    UILabel *addLabel = [[UILabel alloc] initWithFrame:CGRectMake(imgView.right+10, 0, 55, 19)];
    addLabel.centerY = imgView.centerY;
    addLabel.text = @"添加资产";
    addLabel.font = [UIFont systemFontOfSize:13];
    addLabel.textColor = TEXTCOLORWITH4A4564;
    [bgView addSubview:addLabel];
    
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end

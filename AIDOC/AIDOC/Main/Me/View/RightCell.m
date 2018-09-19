//
//  RightCell.m
//  TYToken
//
//  Created by app on 2018/8/20.
//  Copyright © 2018年 app. All rights reserved.
//

#import "RightCell.h"

@implementation RightCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.contentView.backgroundColor = [UIColor clearColor];
        [self _initView];
    }
    return self;
}

- (void)_initView{
    _iconImgView = [[UIImageView alloc] initWithFrame:CGRectMake(20, 20, 40, 40)];
    _iconImgView.image = [UIImage imageNamed:@"img_tx_80"];
    [self.contentView addSubview:_iconImgView];
    
    _nameLabel = [[UILabel alloc] initWithFrame:CGRectMake(_iconImgView.right+10, 30, kScreenWidth*0.55-_iconImgView.right-10, 20)];
    _nameLabel.font = [UIFont systemFontOfSize:14.0f];
    _nameLabel.textColor = TEXTCOLORWITH333333;
    [self.contentView addSubview:_nameLabel];
    
    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(20, 79, kScreenWidth*0.55-20, 1)];
    lineView.backgroundColor = TEXTCOLORWITHEAECF3;
    [self.contentView addSubview:lineView];
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end

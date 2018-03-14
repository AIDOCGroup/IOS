//
//  SettingCell.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "SettingCell.h"

@implementation SettingCell
{
    UIImageView *rirhtImgView;
}


- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // 点击cell的时候不要变色
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        
        [self initViews];
    }
    return self;
}

-(void)initViews{
    _iconImgView = [[UIImageView alloc] init];
    [self.contentView addSubview:_iconImgView];
    
    _itemName = [[UILabel alloc] initWithFrame:CGRectMake(20, 10, 100, 20)];
    _itemName.font = [UIFont systemFontOfSize:12.0f];
    _itemName.textColor = rgbColor(0x999999);
    _itemName.textAlignment = NSTextAlignmentLeft;
    [self.contentView addSubview:_itemName];
    
    
    _detailLabel = [[UILabel alloc] initWithFrame:CGRectMake(kScreenWidth - 200, 10, 170, 20)];
    _detailLabel.font = [UIFont systemFontOfSize:10.0f];
    _detailLabel.textColor = rgbColor(0x999999);

    _detailLabel.textAlignment = NSTextAlignmentRight;
    [self.contentView addSubview:_detailLabel];
    
    //向右的箭头
    UIImage *rightImage = [UIImage imageNamed:@"my_rightjd"];
    rirhtImgView = [[UIImageView alloc] initWithFrame:CGRectMake(kScreenWidth - 28, 12, 16, 16)];
    rirhtImgView.image = rightImage;
    [self.contentView addSubview:rirhtImgView];

    
}

-(void)setIsIcon:(BOOL)isIcon
{
    _isIcon = isIcon;
    if (_isIcon) {
        _iconImgView.frame = CGRectMake(10, 15, 20, 20);
        _itemName.frame = CGRectMake(_iconImgView.right+5, 15, 100, 20);
        rirhtImgView.frame =CGRectMake(kScreenWidth - 20 - 28, 17, 16, 16);
    }
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end

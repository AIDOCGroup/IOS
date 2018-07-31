//
//  SolveMapCell.m
//  AlarmDemo
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "SolveMapCell.h"

@implementation SolveMapCell

{
    UIImageView *_iconImageView;
    UIImageView *rirhtImgView;
}

- (void)awakeFromNib {
    // Initialization code
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // 点击cell的时候不要变色
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.backgroundColor = [UIColor clearColor];
        [self initViews];
    }
    return self;
}

-(void)initViews{
    
    _iconImageView = [[UIImageView alloc] initWithFrame:CGRectMake(5, 5, 20, 20)];
    [self.contentView addSubview:_iconImageView];
    
    _itemName = [[UILabel alloc] initWithFrame:CGRectMake(_iconImageView.right + 5, 5, 30, 20)];
    _itemName.font = [UIFont systemFontOfSize:12.0f];
    _itemName.textAlignment = NSTextAlignmentLeft;
    [self.contentView addSubview:_itemName];
    
    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(0, self.frame.size.height - 0.3, self.frame.size.width, 0.3)];
    lineView.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"map_equip_line"]];
    [self.contentView addSubview:lineView];
}

- (void)setImgStr:(NSString *)imgStr
{
    _iconImageView.image = [UIImage imageNamed:imgStr];
}

- (void)setIsWhiteColor:(BOOL)isWhiteColor
{
    _isWhiteColor = isWhiteColor;
    
    if (_isWhiteColor) {
        
      _itemName.textColor = [UIColor whiteColor];
        
    }else
    {
        _itemName.textColor = [UIColor orangeColor];
    }
    
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}

@end

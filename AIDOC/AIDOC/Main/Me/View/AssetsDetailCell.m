//
//  AssetsDetailCell.m
//  TYToken
//
//  Created by app on 2018/8/21.
//  Copyright © 2018年 app. All rights reserved.
//

#import "AssetsDetailCell.h"

@implementation AssetsDetailCell

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
    //78
    UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(15, 20, 15, 15)];
    [self.contentView addSubview:imgView];
    self.imgView = imgView;
    
    UILabel *typeLabel = [[UILabel alloc] initWithFrame:CGRectMake(imgView.right+5, 18, 100, 20)];
    typeLabel.font = [UIFont systemFontOfSize:14];
    typeLabel.textColor = TEXTCOLORWITH4A4564;
    [self.contentView addSubview:typeLabel];
    self.typeLabel = typeLabel;
    
    UILabel *countLabel = [[UILabel alloc] initWithFrame:CGRectMake(imgView.left, typeLabel.bottom+7, kScreenWidth-30-100, 19)];
    countLabel.font = [UIFont systemFontOfSize:20];
    [self.contentView addSubview:countLabel];
    self.countLabel = countLabel;
    
    UILabel *timeLabel = [[UILabel alloc] initWithFrame:CGRectMake(countLabel.right+10, 50, 90, 19)];
    timeLabel.font = [UIFont systemFontOfSize:13];
    timeLabel.textColor = TEXTCOLORWITHBBBBBB;
    timeLabel.textAlignment = NSTextAlignmentRight;
    [self.contentView addSubview:timeLabel];
    self.timeLabel = timeLabel;
    

    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(15, 89, kScreenWidth-15, 1)];
    lineView.backgroundColor = rgbColor(0xEAECF3);
    [self.contentView addSubview:lineView];
    
}

-(void)setTypeInt:(NSInteger)typeInt{
    _typeInt = typeInt;
    self.timeLabel.text = @"07/05 13:30";
    if (_typeInt==1) {//转入
        self.imgView.image = [UIImage imageNamed:@"icon_zr"];
        self.typeLabel.text = @"转入";
        self.countLabel.textColor = TEXTCOLORWITH50C65F;
    }else{//转出
        self.imgView.image = [UIImage imageNamed:@"icon_zc"];
        self.typeLabel.text = @"转出";
        self.countLabel.textColor = rgbColor(0xEF5B5B);
    }
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}

@end

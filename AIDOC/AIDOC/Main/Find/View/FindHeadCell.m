//
//  FindHeadCell.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "FindHeadCell.h"

@implementation FindHeadCell
{
    UIButton *btn;
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
        //        [self initViews];
    }
    return self;
}

-(void)initViews{
    
    float width = kScreenWidth/self.imgArr.count;
    NSLog(@"%f %f",self.bounds.size.height,self.bounds.size.width);
    for (int i = 0; i<[self.imgArr count]; i++) {//数组是图片集合
        btn = [[UIButton alloc] initWithFrame:CGRectMake(width*i, 0, width, 74)];
        [btn setImage:[UIImage imageNamed:self.imgArr[i]] forState:UIControlStateNormal];
        [btn setTitle:self.titleArr[i] forState:UIControlStateNormal];
        
        [btn setTitleColor:rgbColor(0x666666) forState:UIControlStateNormal];
        btn.titleLabel.font = [UIFont systemFontOfSize:12];
        btn.titleLabel.textAlignment = NSTextAlignmentCenter;
        btn.titleEdgeInsets = UIEdgeInsetsMake(-8,  -width/2.0-25, - 70,  -width/2.0+25);
        btn.imageEdgeInsets = UIEdgeInsetsMake( -12, width/2.0-25, 0, width/2.0-25);
        btn.tag = i+1;
        [btn addTarget:self action:@selector(buttonClickAtIndex:) forControlEvents:UIControlEventTouchUpInside];
        [self.contentView addSubview:btn];
    }
    
}

- (void)buttonClickAtIndex:(UIButton *)sender{
    
    if ([self.delegate respondsToSelector:@selector(clickCellBtn:)]) {
        [self.delegate clickCellBtn:sender.tag];
    }
    
}

-(void)setImgArr:(NSArray *)imgArr{
    _imgArr = imgArr;
    
}

- (void)setTitleArr:(NSArray *)titleArr{
    _titleArr = titleArr;
    [self initViews];
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}

@end

//
//  ZKLoginTextField.m
//  demo
//
//  Created by 中组智库 on 15/7/16.
//  Copyright (c) 2015年 中组智库. All rights reserved.
//

#import "ZKLoginTextField.h"

@interface ZKLoginTextField ()

@property (nonatomic, weak) UIImageView *iconView;
@property (nonatomic, weak) UIView *lineView;

@end

@implementation ZKLoginTextField

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
    
        //左边icon
        UIImageView *iconView = [[UIImageView alloc] init];
        self.iconView = iconView;
        
        CGFloat iconH = 18;
        CGFloat iconViewY = (48 - iconH) / 2;
        
        iconView.frame = CGRectMake(10, iconViewY, 17, iconH);
        [self addSubview:iconView];
        
    
//        //线条
//        UIView *lineView = [[UIView alloc] init];
//        lineView.backgroundColor = rgbColor(0xe7e7e7);
//        self.lineView = lineView;
//        [self addSubview:lineView];
       
        
    }
    return self;
}

/**
 *  TextField光标缩进
 */
- (CGRect)editingRectForBounds:(CGRect)bounds {
    return CGRectInset(bounds, 37, 0);
}
/**
 *  文字缩进
 */
- (CGRect)textRectForBounds:(CGRect)bounds {
    return CGRectInset(bounds, 37, 0);
}

- (void)layoutSubviews {
    [super layoutSubviews];
    self.iconView.image = [UIImage imageNamed:self.iconNmae];
    self.lineView.frame = CGRectMake(0, 37, self.frame.size.width - 2, 1);
    if (self.hideBorder) {
        self.lineView.frame = CGRectZero;
    }
}

@end

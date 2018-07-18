//
//  UILabel+StringSize.h
//  RedCross
//
//  Created by  董剑 on 16/12/29.
//  Copyright © 2016年 董剑. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (StringSize)

+ (CGSize)LabelSizeWithString:(NSString *)str withWidth:(CGFloat)width withFont:(CGFloat)fontSize;
+ (CGSize)LabelSizeWithString:(NSString *)str withHeight:(CGFloat)height withFont:(CGFloat)fontSize;
@end

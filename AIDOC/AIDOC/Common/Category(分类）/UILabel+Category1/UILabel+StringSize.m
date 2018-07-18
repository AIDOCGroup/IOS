//
//  UILabel+StringSize.m
//  RedCross
//
//  Created by  董剑 on 16/12/29.
//  Copyright © 2016年 董剑. All rights reserved.
//

#import "UILabel+StringSize.h"

@implementation UILabel (StringSize)

+ (CGSize)LabelSizeWithString:(NSString *)str withWidth:(CGFloat)width withFont:(CGFloat)fontSize
{
    UILabel *label = [[UILabel alloc] init];
    label.frame = CGRectMake(0, 0, 0, 0);
    label.numberOfLines = 0;
    CGSize size = CGSizeMake(width, 4000);
    UIFont *font = [UIFont systemFontOfSize:fontSize];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    paragraphStyle.lineBreakMode = NSLineBreakByCharWrapping;
    paragraphStyle.alignment = label.textAlignment;
    NSDictionary *attributes = @{NSFontAttributeName:font,
                                  NSParagraphStyleAttributeName:paragraphStyle};
    CGSize labelSize = [str boundingRectWithSize:size
                                         options:(NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingUsesFontLeading)
                                      attributes:attributes
                                         context:nil].size;
    return labelSize;
}

+ (CGSize)LabelSizeWithString:(NSString *)str withHeight:(CGFloat)height withFont:(CGFloat)fontSize
{
    UILabel *label = [[UILabel alloc] init];
    label.frame = CGRectMake(0, 0, 0, 0);
    label.numberOfLines = 0;
    CGSize size = CGSizeMake(kScreenWidth, height);
    UIFont *font = [UIFont systemFontOfSize:fontSize];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    paragraphStyle.lineBreakMode = NSLineBreakByCharWrapping;
    paragraphStyle.alignment = label.textAlignment;
    NSDictionary *attributes = @{NSFontAttributeName:font,
                                 NSParagraphStyleAttributeName:paragraphStyle};
    CGSize labelSize = [str boundingRectWithSize:size
                                         options:(NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingUsesFontLeading)
                                      attributes:attributes
                                         context:nil].size;
    return labelSize;
}

@end

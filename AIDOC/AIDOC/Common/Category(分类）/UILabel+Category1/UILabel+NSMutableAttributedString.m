//
//  UILabel+NSMutableAttributedString.m
//  RedCross
//
//  Created by  董剑 on 16/11/19.
//  Copyright © 2016年 董剑. All rights reserved.
//

#import "UILabel+NSMutableAttributedString.h"

@implementation UILabel (NSMutableAttributedString)

//中划线
+ (NSMutableAttributedString *)strikethroughStyleAttributeName:(NSString *)string
{
    NSDictionary *attribtDic = @{NSStrikethroughStyleAttributeName: [NSNumber numberWithInteger:NSUnderlineStyleSingle]};
    NSMutableAttributedString *attribtStr = [[NSMutableAttributedString alloc]initWithString:string attributes:attribtDic];
    return attribtStr;
}

//下划线
+ (NSMutableAttributedString *)underlineStyleAttributeName:(NSString *)string
{
    NSDictionary *attribtDic = @{NSUnderlineStyleAttributeName: [NSNumber numberWithInteger:NSUnderlineStyleSingle]};
    NSMutableAttributedString *attribtStr = [[NSMutableAttributedString alloc]initWithString:string attributes:attribtDic];
    return attribtStr;
}

@end

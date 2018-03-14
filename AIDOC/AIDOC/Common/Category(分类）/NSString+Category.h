//
//  NSString+Category.h

//  AIDOC
//
//  Created by tangjin on 18/1/8.
//  Copyright (c) 2018年 张百群. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface NSString (Category)

/**
 *  计算文字高度
 *
 *  @param string 需要计算的文字
 *  @param size   字体大小
 *
 *  @return 返回行高
 */
- (float )sizeWithAttributes:(NSString *)string andFontSize:(CGFloat)size maxWidth:(CGFloat)width;

/**
 *  计算文字高度
 *
 *  @param string 需要计算的文字
 *  @param size   字体大小
 *
 *  @return 返回行高Size
 */
- (CGSize )sizeWithAttributesFontSize:(CGFloat)size lineSpacing:(CGFloat)linespacing maxWidth:(CGFloat)width;



/**
 *  格式化时间
 *
 *  @param lodDate     date
 *  @param adateFormat @"yyyy/M/dd"
 *
 *  @return 日期字符串
 */
+ (NSString *)dateFormatter:(ino64_t)lodDate dateFormat:(NSString *)adateFormat;
/**
 *  删除两端空格
 */
- (NSString *)stringByTrimmingNbsp;

/**
 *  计算文字长度
 */
- (int)stringCount:(NSString *)string;

@end

//
//  NSString+Extension.h
//  AIDOC
//
//  Created by tangjin on 18/1/8.
//  Copyright (c) 2018年 张百群. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface NSString (Extension)
/**
 *  根据UILabel的字体大小和宽度或者高度返回label的size大小
 *
 *  @param font 字体大小
 *  @param maxW 宽或高的最大值
 *
 *  @return  返回一个CGSize
 */
- (CGSize)sizeWithFont:(UIFont *)font maxW:(CGFloat)maxW;
- (CGSize)sizeWithFont:(UIFont *)font;
/**
 *  进行MD5加密
 *
 *  @return 加密后的密文
 */
- (NSString *)md5String;
- (BOOL) empty;
-(NSString *)md5AfterString;
-(NSString *)md5AfterString1;
-(NSMutableString *)getHtmlString;
-(id)JSONValue;
@end

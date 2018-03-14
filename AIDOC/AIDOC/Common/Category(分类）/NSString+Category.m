//
//  NSString+Category.m
//  AIDOC
//
//  Created by tangjin on 18/1/8.
//  Copyright (c) 2018年 张百群. All rights reserved.
//
#import "NSString+Category.h"

@implementation NSString (Category)


- (CGSize)sizeWithAttributesFontSize:(CGFloat)size lineSpacing:(CGFloat)linespacing maxWidth:(CGFloat)width {
    
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    paragraphStyle.lineSpacing = linespacing;//调整行间距

    
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:size],NSParagraphStyleAttributeName:paragraphStyle};
    return [self boundingRectWithSize:CGSizeMake(width, 1000.0f) options:NSStringDrawingUsesLineFragmentOrigin attributes:attributes context:nil].size;

}

- (float )sizeWithAttributes:(NSString *)string andFontSize:(CGFloat)size maxWidth:(CGFloat)width {
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:size]};
    CGRect rect = [string boundingRectWithSize:CGSizeMake(width, 1000.0f) options:NSStringDrawingUsesLineFragmentOrigin attributes:attributes context:nil];
    return rect.size.height+8;
}

/**
 *  格式化时间 2015/8/15
 */
+ (NSString *)dateFormatter:(ino64_t)lodDate dateFormat:(NSString *)adateFormat {
    NSDate *date = [[NSDate alloc] initWithTimeIntervalSince1970:lodDate / 1000];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    formatter.dateFormat = adateFormat;
    return [formatter stringFromDate:date];
}
- (NSString *)stringByTrimmingNbsp {
    return [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
}

- (int)stringCount:(NSString *)string {

    int strlength = 0;
    char* p = (char*)[string cStringUsingEncoding:NSUnicodeStringEncoding];
    for (int i=0 ; i<[string lengthOfBytesUsingEncoding:NSUnicodeStringEncoding] ;i++) {
        if (*p) {
            p++;
            strlength++;
        }
        else {
            p++;
        }
    }

    return (strlength+1) / 2;
}


@end

//
//  NSString+Extension.m
//  AIDOC
//
//  Created by tangjin on 18/1/8.
//  Copyright (c) 2018年 张百群. All rights reserved.
//
#import "NSString+Extension.h"
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonHMAC.h>

@implementation NSString (Extension)
- (NSString *)md5String
{
    const char *string = self.UTF8String;
    int length = (int)strlen(string);
    unsigned char bytes[CC_MD5_DIGEST_LENGTH];
    CC_MD5(string, length, bytes);
    return [self stringFromBytes:bytes length:CC_MD5_DIGEST_LENGTH];
}
-(id)JSONValue;
{
    NSData* data = [self dataUsingEncoding:NSUTF8StringEncoding];
    __autoreleasing NSError* error = nil;
    id result = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    if (error != nil) return nil;
    return result;
}


- (NSString *)sha1String
{
    const char *string = self.UTF8String;
    int length = (int)strlen(string);
    unsigned char bytes[CC_SHA1_DIGEST_LENGTH];
    CC_SHA1(string, length, bytes);
    return [self stringFromBytes:bytes length:CC_SHA1_DIGEST_LENGTH];
}

- (NSString *)sha256String
{
    const char *string = self.UTF8String;
    int length = (int)strlen(string);
    unsigned char bytes[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(string, length, bytes);
    return [self stringFromBytes:bytes length:CC_SHA256_DIGEST_LENGTH];
}

- (NSString *)sha512String
{
    const char *string = self.UTF8String;
    int length = (int)strlen(string);
    unsigned char bytes[CC_SHA512_DIGEST_LENGTH];
    CC_SHA512(string, length, bytes);
    return [self stringFromBytes:bytes length:CC_SHA512_DIGEST_LENGTH];
}

- (NSString *)hmacSHA1StringWithKey:(NSString *)key
{
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    NSData *messageData = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableData *mutableData = [NSMutableData dataWithLength:CC_SHA1_DIGEST_LENGTH];
    CCHmac(kCCHmacAlgSHA1, keyData.bytes, keyData.length, messageData.bytes, messageData.length, mutableData.mutableBytes);
    return [self stringFromBytes:(unsigned char *)mutableData.bytes length:mutableData.length];
}

- (NSString *)hmacSHA256StringWithKey:(NSString *)key
{
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    NSData *messageData = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableData *mutableData = [NSMutableData dataWithLength:CC_SHA256_DIGEST_LENGTH];
    CCHmac(kCCHmacAlgSHA256, keyData.bytes, keyData.length, messageData.bytes, messageData.length, mutableData.mutableBytes);
    return [self stringFromBytes:(unsigned char *)mutableData.bytes length:mutableData.length];
}

- (BOOL) empty{
    return ([[self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]length] == 0);
}
- (NSString *)hmacSHA512StringWithKey:(NSString *)key
{
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    NSData *messageData = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableData *mutableData = [NSMutableData dataWithLength:CC_SHA512_DIGEST_LENGTH];
    CCHmac(kCCHmacAlgSHA512, keyData.bytes, keyData.length, messageData.bytes, messageData.length, mutableData.mutableBytes);
    return [self stringFromBytes:(unsigned char *)mutableData.bytes length:mutableData.length];
}

#pragma mark - Helpers

- (NSString *)stringFromBytes:(unsigned char *)bytes length:(int)length
{
    NSMutableString *mutableString = @"".mutableCopy;
    for (int i = 0; i < length; i++)
        [mutableString appendFormat:@"%02x", bytes[i]];
    return [NSString stringWithString:mutableString];
}
- (CGSize)sizeWithFont:(UIFont *)font maxW:(CGFloat)maxW
{
    NSMutableDictionary *attrs = [NSMutableDictionary dictionary];
    attrs[NSFontAttributeName] = font;
    CGSize maxSize = CGSizeMake(maxW, MAXFLOAT);
    return [self boundingRectWithSize:maxSize options:NSStringDrawingUsesLineFragmentOrigin attributes:attrs context:nil].size;
}

- (CGSize)sizeWithFont:(UIFont *)font
{
    return [self sizeWithFont:font maxW:MAXFLOAT];
}

/**
 *  先加密，后乱序
 *
 *  @param text 明文
 *
 *  @return 加密后的密文
 */
-(NSString *)md5AfterString{
    NSString *pwd = [self md5String];
    
    // 加密后pwd == 3f853778a951fd2cdf34dfd16504c5d8
    NSString *prefix = [pwd substringFromIndex:3];
    NSString *subfix = [pwd substringToIndex:3];
    
    // 乱序后 result == 853778a951fd2cdf34dfd16504c5d83f
    NSString *sortResult = [prefix stringByAppendingString:subfix];
    NSString *saltReslt=[NSString stringWithFormat:@"%@%@%@",@"#$%@AF37",sortResult,@"DS1!#$^$"];
    return [saltReslt md5String];
}

-(NSString *)md5AfterString1{
    NSString *pwd = [self md5String];
    
    // 加密后pwd == 3f853778a951fd2cdf34dfd16504c5d8
    NSString *prefix = [pwd substringFromIndex:3];
    NSString *subfix = [pwd substringToIndex:3];
    
    // 乱序后 result == 853778a951fd2cdf34dfd16504c5d83f
    NSString *sortResult = [prefix stringByAppendingString:subfix];
    
    NSString *saltReslt=[NSString stringWithFormat:@"%@%@%@",@"#!f$A33^",sortResult,@"D31!4$8$"];
    
    return [saltReslt md5String];
}


#pragma mark 获取html格式字符串
-(NSMutableString *)getHtmlString{
    NSMutableString *html=[NSMutableString stringWithString:@""];
    [html appendString:@"<!DOCTYPE html><html><head><meta charset='utf-8' /><meta content='telephone=no' name='format-detection' /><meta name='viewport' content='initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no' /><title></title> <link rel='stylesheet' href='bootstrap.min.css'/></head><script  type='text/javascript'  src='bootstrap.min.js' ></script><script  type='text/javascript'  src='jquery.min.js'></script><meta charset='utf-8'>"];
//    if ([CommonFunc isLogin]) {
//        [html appendFormat:@"<script type='text/javascript'>var user=new Object();user.id='%@';user.token='%@';</script>",[CommonFunc getUserInformation].u_id,[CommonFunc getUserInformation].token];
//    }
//    else{
        [html appendString:@"<script type='text/javascript'>var user=null;</script>"];
//    }
    
    if (self) {
        [html appendString:@"<body>"];
        [html appendString:self];
        [html appendString:@"</body>"];
    }
    [html appendString:@"</html>"];
    return html;
}

@end

//
//  NSDictionary+category.m
//  AIDOC
//
//  Created by tangjin on 18/1/8.
//  Copyright (c) 2018年 张百群. All rights reserved.
//
#import "NSDictionary+category.h"

@implementation NSDictionary (category)
#pragma mark 用来转换json返回的字典
-(NSDictionary *)dictionaryWithKey:(NSString *)key{
    NSDictionary *user_infoDic = [self objectForKey:key];
    if (![user_infoDic isKindOfClass:[NSDictionary class]]) {
        return [NSDictionary dictionary];
    }
    return user_infoDic;
}
-(NSArray *)arrayWithKey:(NSString *)key{
    NSArray *user_infoDic = [self objectForKey:key];
    if (![user_infoDic isKindOfClass:[NSArray class]]) {
        return [NSArray array];
    }
    return user_infoDic;
}

@end

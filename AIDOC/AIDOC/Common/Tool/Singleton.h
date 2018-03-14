//
//  Singleton.h
//  Accounting
//
//  Created by ccg on 13-8-20.
//  Copyright (c) 2013年 ccg. All rights reserved.
//  单例宏定义代码

// @interface
#define singleton_interface(className) \
+ (className *)shared##className;\

// @implementation
#define singleton_implementation(className) \
static className *_instance; \
+ (className *)shared##className \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
}

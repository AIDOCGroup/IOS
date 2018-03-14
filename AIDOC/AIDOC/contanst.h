//
//  contanst.h
//  AlarmDemo
//
//  Created by apple on 16/7/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#ifndef contanst_h
#define contanst_h

#define KNOTIFICATION_LOGINCHANGE @"loginStateChange" //登录

//整体色调
#define TotolColor  [UIColor colorWithRed:255/255.0 green:205/255.0 blue:206/255.0 alpha:1]
//颜色
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]

/**
 *  获取16进制 color
 */
#define rgbColor(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


#define KFont @"YouYuan"
#define KBFont @"YouYuan-Bold"


//屏幕的宽、高
#define kScreenHeight ([UIScreen mainScreen].bounds.size.height) - 64 - 49
#define kScreenWidth ([UIScreen mainScreen].bounds.size.width)


#define IOS7_STATUS_BAR_HEGHT (IAIOS7 ||IAIOS8? 20.0f : 0.0f)

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)



#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 667.0)
#define IS_IPHONE_6P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

/**
 *  初始化进度
 *
 *  @return 数值
 */
#define PM_CHAT_INITIAL  1

#endif /* contanst_h */

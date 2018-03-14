//
//  CommonFunc.h
//  AIDOC
//
//  Created by tangjin on  18/1/8.
//  Copyright (c) 2018年 张百群.. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Singleton.h"
#import "UserInfoModel.h"
@interface CommonFunc : NSObject
singleton_interface(CommonFunc)
+ (NSString *)stringFromHexString:(NSString *)hexString;
+ (NSString *)hexStringFromString:(NSString *)string;

+ (CommonFunc *)instanceFile ;
+(UserInfoModel *)getUserInformation;

@property(nonatomic ,copy) NSString *apiKey;

//个人信息本地保存
+(void)saveUserInfomation:(UserInfoModel *)user;
//删除本地存储的用户信息
+(void)removeUserInfomation;
//弹出登陆界面
+(void)presentToLoginPageFrom:(UIViewController *)currentViewController :(void (^)())confirm;

//判读用户是否登录
+(BOOL)isLogin;
//1.附件女生 2.自己主页 3.个人主页  
@property(nonatomic, retain) NSMutableArray *isLoginChanged;

@property(nonatomic, strong) NSMutableDictionary *downloadItems;

@property(nonatomic, assign)BOOL isNewNotification;

@property (nonatomic, strong) NSURLSession *session;

@property(nonatomic, assign)BOOL isNewTicker;//用来提示贴纸便利店是否有心贴纸
@property(nonatomic, assign)int isTempNewTicker;


//是否为第一次打开
- (void)setInitial:(NSInteger)tag;
- (BOOL)initial;


@end

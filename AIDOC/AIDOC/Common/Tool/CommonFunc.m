//
//  CommonFunc.m
//  AIDOC
//
//  Created by tangjin on  18/1/8.
//  Copyright (c) 2018年 张百群.. All rights reserved.
//

#import "CommonFunc.h"
#import "LoginViewController.h"
#import "BaseNavigationController.h"
#import "AppDelegate.h"
#import "UIViewController+HUD.h"

// 账号的存储路径
#define HWAccountPath [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"account.archive"]

@implementation CommonFunc

singleton_implementation(CommonFunc)
// 十六进制转换为普通字符串的。
+ (NSString *)stringFromHexString:(NSString *)hexString { //
    if (hexString.length <= 0) {
        return 0;
    }
    if (hexString == nil || hexString == NULL) {
        return 0;
    }
    if ([hexString isKindOfClass:[NSNull class]]) {
        return 0;
    }
    if ([[hexString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0) {
        return 0;
    }
    if (hexString.length > 0 || hexString != nil) {
        
        char *myBuffer = (char *)malloc((int)[hexString length] / 2 + 1);
        bzero(myBuffer, [hexString length] / 2 + 1);
        for (int i = 0; i < [hexString length] - 1; i += 2) {
            unsigned int anInt;
            NSString * hexCharStr = [hexString substringWithRange:NSMakeRange(i, 2)];
            NSScanner * scanner = [[NSScanner alloc] initWithString:hexCharStr];
            [scanner scanHexInt:&anInt];
            myBuffer[i / 2] = (char)anInt;
        }
        NSString *unicodeString = [NSString stringWithCString:myBuffer encoding:4];
        //    HWLog(@"------字符串=======%@",unicodeString);
        return unicodeString;
    }else
    {
        HWLog(@"字符串为空");
        return 0;
    }
    
    
    
}

//普通字符串转换为十六进制的。

+ (NSString *)hexStringFromString:(NSString *)string{
    if (string.length <= 0) {
        return 0;
    }
    if (string == nil || string == NULL) {
        return 0;
    }
    if ([string isKindOfClass:[NSNull class]]) {
        return 0;
    }
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0) {
        return 0;
    }

    if (string.length > 0 || string != nil) {
        
        NSData *myD = [string dataUsingEncoding:NSUTF8StringEncoding];
        Byte *bytes = (Byte *)[myD bytes];
        //下面是Byte 转换为16进制。
        NSString *hexStr=@"";
        for(int i=0;i<[myD length];i++)
            
        {
            NSString *newHexStr = [NSString stringWithFormat:@"%x",bytes[i]&0xff];///16进制数
            
            if([newHexStr length]==1)
                
                hexStr = [NSString stringWithFormat:@"%@0%@",hexStr,newHexStr];
            
            else
                
                hexStr = [NSString stringWithFormat:@"%@%@",hexStr,newHexStr];
        }
        return hexStr;
    }else
    {
        HWLog(@"字符串为空");
        return 0;
    }
}

+ (CommonFunc *)instanceFile {
    
    static CommonFunc *_sharedInstance = nil;
    static dispatch_once_t oncePredicate;
    
    dispatch_once(&oncePredicate, ^{
        
        _sharedInstance = [[CommonFunc alloc] init];
        
    });
    
    return _sharedInstance;
    
}

+(UserInfoModel *)getUserInformation{
    UserInfoModel *model = [NSKeyedUnarchiver unarchiveObjectWithFile:HWAccountPath];
    return model;
}

-(NSString *)apiKey{
    return @"";
}


//个人信息本地保存
+(void)saveUserInfomation:(UserInfoModel *)user{
    [NSKeyedArchiver archiveRootObject:user toFile:HWAccountPath];
    
}

+(void)removeUserInfomation
{
    UserInfoModel *model=[CommonFunc getUserInformation];
    model.u_id=@"";
    model.token = @"";
    model.username = @"";
    model.isLoginout=YES;
    [self saveUserInfomation:model];
    
    
    
}

+(void)presentToLoginPageFrom:(UIViewController *)currentViewController :(void (^)())confirm
{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        [CommonFunc removeUserInfomation];
        [[NSNotificationCenter defaultCenter] postNotificationName:KNOTIFICATION_LOGINCHANGE object:nil];
        [currentViewController showHint:@"登录信息已过期，请重新登录"];
    });

}
//判读用户是否登录
+(BOOL)isLogin
{
    UserInfoModel *userModel = [self getUserInformation];
    if ((!userModel.u_id||!userModel.token||!userModel.username)) {
        return NO;
    }
    else if(userModel&&userModel.isLoginout){
        return NO;
    }
    else
        return YES;
}

//保存对方信息
+(void)saveChatterInfomation:(UserInfoModel *)chatterUser
{
    [NSKeyedArchiver archiveRootObject:chatterUser toFile:HWAccountPath];
    
}
//获取对方信息
+(UserInfoModel *)getChatterInfomation
{
    UserInfoModel *model = [NSKeyedUnarchiver unarchiveObjectWithFile:HWAccountPath];
    return model;

}

//是否为第一次打开
- (void)setInitial:(NSInteger)tag{
    
    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
    [ud setObject:@(tag) forKey:@"initial"];
    
}

- (BOOL)initial{
    
    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
    return [[ud objectForKey:@"initial" ] boolValue];
    
}



@end

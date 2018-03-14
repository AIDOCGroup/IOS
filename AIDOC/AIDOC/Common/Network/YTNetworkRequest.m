//
//  YTNetworkRequest.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "YTNetworkRequest.h"
#import "BQDataService.h"

@implementation YTNetworkRequest

#pragma mark 获取验证码
+(void)getVerifyCodeWithPhone:(NSString *)phone withType:(NSString *)type  success:(void (^)(id))success failure:(void (^)(NSString *))failure
{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,VerifyCode];
    // 3.设置请求体
    NSDictionary *json = @{
                           @"phone" : phone,
                           @"type" : type
                           };
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypePost success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}
#pragma mark 注册
+(void)registerWithPhone:(NSString *)phone withPassword:(NSString *)u_passwd withPhoneVerify:(NSString *)phone_verify success:(void (^)(id))success failure:(void (^)(NSString *))failure
{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,Register];
    // 3.设置请求体
    NSDictionary *json = @{
                           @"phone" : phone,
                           @"password" : u_passwd,
                           @"phone_verify":phone_verify
                           };
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypePost success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}
#pragma mark 重置密码
+(void)resetPasswordWithPhone:(NSString *)phone withPassword:(NSString *)password  withPhoneVerify:(NSString *)phone_verify_code success:(void (^)(id))success failure:(void (^)(NSString *))failure
{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,ResetPassword];
    // 3.设置请求体
    NSDictionary *json = @{
                           @"phone" : phone,
                           @"password" : password,
                           @"phone_verify_code":phone_verify_code
                           };
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypePost success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}

#pragma mark 修改密码
+(void)changePassword:(NSString *)oldPassword withNewPassword:(NSString *)newPassword  success:(void (^)(id))success failure:(void (^)(NSString *))failure
{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,ChangePassword];
    // 3.设置请求体
    NSDictionary *json = @{
                           @"old_password" : oldPassword,
                           @"new_password":newPassword
                           };
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypePut success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}



#pragma mark 登录
+(void)loginWithPhone:(NSString *)phone withPassword:(NSString *)u_passwd success:(void (^)(id))success failure:(void (^)(NSString *))failure
{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,LogIn];
    // 3.设置请求体
    NSDictionary *json = @{
                           @"username" : phone,
                           @"password" : u_passwd,
                           };
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypePost success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}

#pragma mark 退出
+(void)louOutWithPhone:(NSString *)phone success:(void (^)(id))success failure:(void (^)(NSString *))failure{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,Logout];
    // 3.设置请求体
    NSDictionary *json = @{};
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypePost success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}


#pragma mark 运动目标
+(void)setSportsGoalWithTarget:(NSString *)targetNum success:(void (^)(id))success failure:(void (^)(NSString *))failure
{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,Target];
    // 3.设置请求体
    NSDictionary *json = @{
                           @"target" : targetNum
                           };
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypePut success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}


#pragma mark 加载新闻列表
+(void)loadNewsListWithCategory_id:(NSString *)category_id  success:(void (^)(id))success failure:(void (^)(NSString *))failure{
    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,Categories];
    // 3.设置请求体
    NSDictionary *json = @{
                           @"category_id" : category_id
                           };
    
    // NSDictionary --> NSData
    NSData *data = [NSJSONSerialization dataWithJSONObject:json options:NSJSONWritingPrettyPrinted error:nil];
    
    [[BQDataService shareBQDataService] request:urlStr parameters:data requestType:RequestTypeGet success:^(id responseObject) {
        
        NSDictionary *dic =  [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
        success(dic);
        
    } failure:^(NSString *error) {
        
        failure(error);
        
    }];
    
}





@end

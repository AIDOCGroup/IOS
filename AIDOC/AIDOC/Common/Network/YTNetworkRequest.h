//
//  YTNetworkRequest.h
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YTNetworkRequest : NSObject

#pragma mark 获取验证码
+(void)getVerifyCodeWithPhone:(NSString *)phone withType:(NSString *)type  success:(void (^)(id))success failure:(void (^)(NSString *))failure;


#pragma mark 注册
+(void)registerWithPhone:(NSString *)phone withPassword:(NSString *)u_passwd withPhoneVerify:(NSString *)phone_verify success:(void (^)(id))success failure:(void (^)(NSString *))failure;

#pragma mark 重置密码
+(void)resetPasswordWithPhone:(NSString *)phone withPassword:(NSString *)password  withPhoneVerify:(NSString *)phone_verify_code success:(void (^)(id))success failure:(void (^)(NSString *))failure;

#pragma mark 修改密码
+(void)changePassword:(NSString *)oldPassword withNewPassword:(NSString *)newPassword  success:(void (^)(id))success failure:(void (^)(NSString *))failure;


#pragma mark 登录
+(void)loginWithPhone:(NSString *)phone withPassword:(NSString *)u_passwd success:(void (^)(id))success failure:(void (^)(NSString *))failure;

#pragma mark 退出
+(void)louOutWithPhone:(NSString *)phone success:(void (^)(id))success failure:(void (^)(NSString *))failure;

#pragma mark 运动目标
+(void)setSportsGoalWithTarget:(NSString *)targetNum success:(void (^)(id))success failure:(void (^)(NSString *))failure;



#pragma mark 加载新闻列表
+(void)loadNewsListWithCategory_id:(NSString *)category_id  success:(void (^)(id))success failure:(void (^)(NSString *))failure;





@end

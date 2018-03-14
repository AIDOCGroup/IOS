//
//  UserInfoModel.h
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseModel.h"

@interface UserInfoModel : BaseModel<NSCoding>
@property(nonatomic, copy) NSString *u_id;        //用户id
@property(nonatomic, copy) NSString *username;      //用户账号
@property(nonatomic, copy) NSString *nickname;      //用户昵称
@property(nonatomic, copy) NSString *token;         //用户token
@property(nonatomic, copy) NSString *type;      //用户类型
@property(nonatomic, copy) NSString *msg_count;      //消息为读数
@property(nonatomic, copy) NSString *avatar;       //用户头像


@property(nonatomic, copy) NSString *isSign;       //
@property(nonatomic, copy) NSString *address;      //用户地址
@property(nonatomic, copy) NSString *city_id;      //用户city_id
@property(nonatomic, copy) NSString *city_name;            //用户city_name








@property(nonatomic ,assign) BOOL isLoginout;


@end

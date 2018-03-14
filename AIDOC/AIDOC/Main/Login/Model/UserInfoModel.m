//
//  UserInfoModel.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "UserInfoModel.h"

@implementation UserInfoModel
@synthesize  u_id,username,nickname,token,type,msg_count,avatar;

- (void)encodeWithCoder:(NSCoder *)aCoder{
    [aCoder encodeObject:u_id forKey:@"u_id"];
    [aCoder encodeObject:username forKey:@"username"];
    [aCoder encodeObject:nickname forKey:@"nickname"];
    [aCoder encodeObject:token forKey:@"token"];
    [aCoder encodeObject:type forKey:@"type"];
    [aCoder encodeObject:msg_count forKey:@"msg_count"];
    [aCoder encodeObject:avatar forKey:@"avatar"];
    
}
- (id)initWithCoder:(NSCoder *)aDecoder{
    u_id = [aDecoder decodeObjectForKey:@"u_id"];
    username = [aDecoder decodeObjectForKey:@"username"];
    nickname= [aDecoder decodeObjectForKey:@"nickname"];
    token = [aDecoder decodeObjectForKey:@"token"];
    type = [aDecoder decodeObjectForKey:@"type"];
    msg_count = [aDecoder decodeObjectForKey:@"msg_count"];
    avatar = [aDecoder decodeObjectForKey:@"avatar"];
    
    return self;
}

- (void)setAttributes:(NSDictionary *)jsonDic
{
    [super setAttributes:jsonDic];
}



@end

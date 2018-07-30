//
//  YZMessageModel.h
//  FlashIMiOSDemo
//
//  Created by Broccoli on 16/5/17.
//  Copyright © 2016年 宫城. All rights reserved.
//

#import <YZSDKCore/YZSDKCore.h>

@interface YZMessageModel : YZSJSONModel <NSCopying>

// 用户ID
@property (nonatomic, strong) NSString<YZSOptional> *userID;
// 消息类型
@property (nonatomic, strong) NSString *msgType;
// 消息 ID
@property (nonatomic, assign) long long msgID;
// 消息内容 当 voice 和 image 时 存放的是 七牛 URL
@property (nonatomic, strong) NSString *content;
// 消息时间戳
@property (nonatomic, assign) long long timestamp;
// 会话ID
@property (nonatomic, strong) NSString<YZSOptional> *conversationID;
// 自发消息与否
@property (nonatomic, assign) BOOL isSelf;
// 是否是自动回复
@property (nonatomic, assign) BOOL automate;
// 用户操作消息
@property (nonatomic, assign) BOOL isEvent;
/**
 消息来源
 
 hosting,               //消息托管
 auto_reply,            //微信自动回复
 welcome_reply,         //欢迎语
 waiting_reply,         //排队提醒
 off_work_reply,        //下班后提醒
 consultation_timeout,  //会话超时提示
 realtime_reply,        //微信实时消息回复
 wechat_template_push,  //微信模板消息
 wechat_push,           //微信粉丝消息
 */
@property (nonatomic, strong) NSString<YZSOptional> *source;
// 用户名称
@property (nonatomic, strong) NSString<YZSOptional> *userNickname;
// 用户头像
@property (nonatomic, strong) NSString<YZSOptional> *userAvatar;

@end

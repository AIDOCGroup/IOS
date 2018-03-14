//
//  path.h
//  XueLi
//
//  Created by tangjin on 15/6/9.
//  Copyright (c) 2015年 xuelihudong. All rights reserved.
#ifndef XueLi_path_h
#define XueLi_path_h
//接口
#ifdef DEBUG // 处于开发阶段
#define HWLog(...) NSLog(__VA_ARGS__)
#define IABaseURL @"/" //接口前缀 发布


#else // 处于发布阶段
#define HWLog(...)
#define IABaseURL @"/" //接口前缀 发布
#endif

#define Register @"/"   //用户注册
#define LogIn @"/"   //用户登录
#define Logout @"/"   //用户退出
#define ChangePassword @"/"   //用户修改密码
#define ResetPassword @"/"                           //重置密码
#define Avatar @@"/"    //设置头像
#define NickName @@"/"                                   //保存昵称
#define SaveArea @@"/"          //保存用户所在地区
#define Signature @@"/"            //保存签名
#define Current_Data @"/"   //加载当前用户数据
#define Administrators @@"/"   // 1.管理员列表   //2.增加管理员
#define Administrators_Detail @"/"   //1.管理员用户详情  //2.修改管理员 //3.删除管理员
#define SignIn @"/"   //用户签到
#define GetSigns @"/"   // 加载签到列表
#define StepsNum @"/"   //存储用户步数
#define GetSteps @"/"   //加载我的步数列表
#define Target @"/"   //1.用户运动期望 2.加载我的期望值
#define UserArchives @"/"   //1.加载我的档案 2.存储我的档案
#define Sports @"/"   //加载运动数据
#define SportsState @"/"   //存储用户运动状态
#define SportsGoal @"/"   //运动目标
#define SportsLiked @"/"                           //喜欢的运动
#define SportsFieild @"/"    //喜欢的领域
#define SportDay @"/"                                   //运动的天数
#define SportsHour @"/"          // 运动小时
#define WeightInfo @"/"            //体重信息
#define Shape @"/"   //提醒状态
#define WristLength @"/"   // 手腕长度
#define UsersList @"/"   //1.获取用过户列表  //2.获取用户信息  //3.修改用户信息 //4.删除用户



#define VerifyCode @"/"   //发送验证码
#define Cities @"/"   // 加载全部地区
#define UploadImages @"/"   //上传图片


#define Categories @"/"   //1.加载新闻列表 //2.修改新闻  //3.新增新闻
#define Archives @"/"   //1.加载新闻详情 2.删除新闻
#define ShareArchives @"/"   //新闻分享调用接口





                                                                









   
#endif

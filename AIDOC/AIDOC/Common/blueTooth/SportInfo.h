//
//  SportInfo.h
//  TestTxt
//
//  Created by zhuoting on 15-4-11.
//  Copyright (c) 2015年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SportInfo : NSObject{
    NSDate *begindate;                   //日期
    NSDate *enddate;
    NSInteger step;//步数
    NSInteger des;//距离
    NSInteger cakl;//卡路里
    
    NSInteger hour;//小时//
    NSString *timeFormet;
    
    NSString *beginhhmm;
    NSString *endhhmm;
    
    
}

@property(nonatomic,strong) NSString *beginhhmm;
@property(nonatomic,strong) NSString *endhhmm;


@property(nonatomic,strong) NSString *timeFormet;
@property(nonatomic,strong) NSDate *begindate;                   //日期
@property(nonatomic,strong) NSDate *enddate;
@property(nonatomic,assign) NSInteger step;//步数
@property(nonatomic,assign) NSInteger des;//距离
@property(nonatomic,assign) NSInteger cakl;//卡路里
@property(nonatomic,assign) NSInteger hour;//小时//

-(SportInfo *)initWithData:(NSData*)data;


-(void)fameDate;


@end

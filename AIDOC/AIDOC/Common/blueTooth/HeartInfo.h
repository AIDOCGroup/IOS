//
//  HeartInfo.h
//  TestTxt
//
//  Created by zhuoting on 15-4-12.
//  Copyright (c) 2015年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface HeartInfo : NSObject{
    NSDate *rtime;
    NSInteger heartTimes;
    NSInteger hour;
    NSString *rtimeFormat;
    NSString *timeStr;
}
@property(nonatomic,strong) NSString *timeStr;
@property(nonatomic,strong) NSString *rtimeFormat;
@property(nonatomic,strong) NSDate *rtime;
@property(nonatomic,assign) NSInteger heartTimes;
@property(nonatomic,assign) NSInteger hour;

-(HeartInfo*)initWithData:(NSData*)data;


-(void)fameDate;

@end

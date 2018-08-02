//
//  SleepMegInfo.h
//  health
//
//  Created by cowork16 on 2017/6/30.
//  Copyright © 2017年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SleepMegInfo : NSObject{
    NSInteger sleepType;//1深睡,2浅睡
    NSDate *stime;
    NSInteger sleepLong;
}

@property(nonatomic,assign) NSInteger sleepType;
@property(nonatomic,strong) NSDate *stime;
@property(nonatomic,assign) NSInteger sleepLong;

-(SleepMegInfo*)initWithData:(NSData*)data;


-(NSMutableDictionary *)objectToDictionary;
-(void)setValue:(NSDictionary *)dlist;
@end

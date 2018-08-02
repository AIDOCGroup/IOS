//
//  Timing.h
//  kettle
//
//  Created by zhuoting on 14-8-7.
//  Copyright (c) 2014年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface Timing : NSObject{

    
    BOOL t_open;
    int c_hour;
    int c_min;
    //0:起床1:睡觉 2:锻炼 3:吃药 4:约会 5:聚会 6:会议 7:自定义
    NSInteger type;
    NSMutableArray *_valueArray;
}
@property(nonatomic,strong) NSMutableArray *_valueArray;//Week，1，2，3，4，5，6，7
@property(nonatomic,assign) NSInteger type;
@property(nonatomic,assign) BOOL t_open;
@property(nonatomic,assign) int c_hour;
@property(nonatomic,assign) int c_min;


//-(Timing *)newinfo;

-(char)createInfo;

- (Timing*)initWithData:(NSData*)data;

-(NSString*)repeatDetailString;
-(NSString*)timeDetailString;


//-(NSMutableDictionary *)objToDictionary;
//-(void)dictionaryToObj:(NSDictionary *)ddlist;
@end

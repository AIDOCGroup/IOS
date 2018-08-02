//
//  BloodInfo.h
//  TestTxt
//
//  Created by cowork16 on 2016/11/15.
//  Copyright © 2016年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BloodInfo : NSObject{
    NSInteger SBP;
    NSInteger DBP;
    
    NSDate *rtime;
    NSString *rtimeFormat;
    NSString *timeStr;
}
@property(nonatomic,strong) NSString *timeStr;
@property(nonatomic,strong) NSString *rtimeFormat;
@property(nonatomic,assign) NSInteger SBP;
@property(nonatomic,assign) NSInteger DBP;

@property(nonatomic,strong) NSDate *rtime;


-(BloodInfo*)initWithData:(NSData*)data;


@end

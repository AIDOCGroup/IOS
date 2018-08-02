//
//  NotDisturbInfo.h
//  health
//
//  Created by cowork16 on 2018/1/14.
//  Copyright © 2018年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotDisturbInfo : NSObject{
    int s_hour1;
    int s_min1;
    int e_hour1;
    int e_min1;
}

@property(nonatomic,assign) int s_hour1;
@property(nonatomic,assign) int s_min1;
@property(nonatomic,assign) int e_hour1;
@property(nonatomic,assign) int e_min1;

-(NSString*)timeDetailString1;

@end

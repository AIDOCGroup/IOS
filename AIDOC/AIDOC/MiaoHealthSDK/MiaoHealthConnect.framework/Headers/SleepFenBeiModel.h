//
//  SleepFenBeiModel.h
//  SleepTest
//
//  Created by 123 on 2017/8/30.
//  Copyright © 2017年 jinzhao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SleepFenBeiModel : NSObject
@property (nonatomic,copy) NSString *timeDateStr;

@property (nonatomic,assign) float fenBeiZhi;

@property (nonatomic,assign) float fenBeiZhiCha;


@property (nonatomic,assign) float x;
@property (nonatomic,assign) float y;
@property (nonatomic,assign) float z;

@property (nonatomic,assign) float xCha;
@property (nonatomic,assign) float yCha;
@property (nonatomic,assign) float zCha;


@property (nonatomic,assign) int hasSleepCount;


@property (nonatomic,assign) BOOL isSomeThingComingOrLeft;
@property (nonatomic,assign) BOOL isPlayPhone;
@property (nonatomic,assign) BOOL isBodyMovement;

@property (nonatomic,assign) BOOL isUpToSever;
@end

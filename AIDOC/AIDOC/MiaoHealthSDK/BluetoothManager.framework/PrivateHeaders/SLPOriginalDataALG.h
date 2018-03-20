//
//  SLPOriginalDataALG.h
//  SDK
//
//  Created by Martin on 2017/8/10.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SLPOriginalData;
@interface SLPOriginalDataALG : NSObject
+ (void)initAlgorithm;
+ (void)releaseAlgorithm;
+ (SLPOriginalData *)ALGOriginalData:(NSInteger)data;
@end

@interface SLPOriginalData : NSObject
@property (nonatomic,assign) CGFloat breath;
@property (nonatomic,assign) CGFloat heart;

@end

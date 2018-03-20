//
//  MilkyCollectionStatus.h
//  SDK
//
//  Created by Martin on 2017/8/4.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MilkyCollectionStatus : NSObject
@property (nonatomic,assign) BOOL isInCollecting;
@property (nonatomic,assign) NSInteger startTime;//起始时间戳 本次采集的开始时间(未采集时，该值为0)
@property (nonatomic,assign) NSInteger timeLength;//采集时长 本次采集的时长(分钟为单位，未采集时，该值为0) 单位：分钟
@end

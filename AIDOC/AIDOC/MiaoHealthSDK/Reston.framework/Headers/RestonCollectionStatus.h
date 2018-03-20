//
//  RestonCollectionStatus.h
//  SDK
//
//  Created by Martin on 2017/7/28.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RestonCollectionStatus : NSObject
@property (nonatomic,assign) UInt8 collectionStatus;
@property (nonatomic,readonly) BOOL isCollecting;
@end

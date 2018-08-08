//
//  ColumnPropertyMappingDelegate.h
//  FMDB
//
//  Created by gcf on 16/7/26.
//  Copyright © 2016年 CBayel. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ColumnPropertyMappingDelegate <NSObject>

@required
- (NSDictionary *)columnPropertyMapping;

@end

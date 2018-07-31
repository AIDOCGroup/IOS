//
//  SolVeMapVIew.h
//  AlarmDemo
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>
@class SolVeMapVIew;
@protocol  SolVeMapVIewDelegate <NSObject>

- (void)toSloveCall:(NSString *)build_ID;//跳转至报警界面

@end
@interface SolVeMapVIew : UIView
@property (nonatomic, strong)NSMutableArray *arr;

@property (nonatomic, assign)id <SolVeMapVIewDelegate> delegate;
@end

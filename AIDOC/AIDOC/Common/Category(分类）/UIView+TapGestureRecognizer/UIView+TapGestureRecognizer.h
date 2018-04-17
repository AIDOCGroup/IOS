//
//  UIView+TapGestureRecognizer.h
//  AIDOC
//
//  Created by 董剑 on 2018/3/27.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^TapActionBlock)(id sender);

@interface UIView (TapGestureRecognizer)

/**
 按下按钮手抬起的时候触发block,代替指定@select()方法
 @param  action 触发执行的block
 */
- (void)block:(TapActionBlock)block;

@end

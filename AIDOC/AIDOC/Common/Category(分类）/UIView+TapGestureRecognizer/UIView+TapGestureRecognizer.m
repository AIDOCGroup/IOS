//
//  UIView+TapGestureRecognizer.m
//  AIDOC
//
//  Created by 董剑 on 2018/3/27.
//  Copyright © 2018年 app. All rights reserved.
//

#import "UIView+TapGestureRecognizer.h"

static const char *overviewkey = "TapGestureRecognizerKey";

@implementation UIView (TapGestureRecognizer)

//这个方法的是意思是为UIButton这个类添加一个属性叫block,overviewKey是键值
/**
 按下按钮手抬起的时候触发block,代替指定@select()方法
 @param  action 触发执行的block
 */
- (void)block:(TapActionBlock)block {
    /*
     第一个参数：给哪个对象添加关联
     第二个参数：关联的key，通过这个key获取
     第三个参数：关联的value
     第四个参数：关联的策略
     */
    self.userInteractionEnabled = YES;
    objc_setAssociatedObject(self, overviewkey, block, OBJC_ASSOCIATION_COPY_NONATOMIC);
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(callActionBlock:)];
    [self addGestureRecognizer:tap];
}

- (void)callActionBlock:(UITapGestureRecognizer *)sender {
    TapActionBlock block = (TapActionBlock)objc_getAssociatedObject(self, overviewkey);
    if (block) {
        block(sender);
    }
}

@end

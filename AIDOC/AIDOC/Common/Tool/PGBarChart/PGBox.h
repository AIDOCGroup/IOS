//
//  PGBox.h
//
//  Created by piggybear on 2016/11/29.
//  Copyright © 2016年 piggybear. All rights reserved.
// GitHub Address: https://github.com/xiaozhuxiong121/PGBarChart

#import <UIKit/UIKit.h>

@interface PGBox : UILabel
@property (nonatomic, assign) NSInteger value;
@property (nonatomic, copy) NSString *unit;
@property (nonatomic, copy) NSString *title;

- (instancetype)initWithPosition:(CGPoint)point value:(NSInteger)value unit:(NSString *)unit title:(NSString *)title;
@end

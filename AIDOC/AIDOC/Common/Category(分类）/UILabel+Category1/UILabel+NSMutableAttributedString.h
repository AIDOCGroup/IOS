//
//  UILabel+NSMutableAttributedString.h
//  RedCross
//
//  Created by  董剑 on 16/11/19.
//  Copyright © 2016年 董剑. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (NSMutableAttributedString)

//中划线
+ (NSMutableAttributedString *)strikethroughStyleAttributeName:(NSString *)string;

//下划线
+ (NSMutableAttributedString *)underlineStyleAttributeName:(NSString *)string;

@end

//
//  CodeTextField.m
//  AIDOC
//
//  Created by tangjin on  18/1/8.
//  Copyright (c) 2018年 张百群.. All rights reserved.
//

#import "CodeTextField.h"

@implementation CodeTextField
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
- (CGRect)textRectForBounds:(CGRect)bounds{
        return CGRectInset(bounds, 30, 0);
}

 - (CGRect)editingRectForBounds:(CGRect)bounds{
     if(self.text.length==0){
         return CGRectInset(bounds, 10, 0);
     }
     if (self.text.length==1) {
         return CGRectInset(bounds, 30, 0);
     }
        return CGRectInset(bounds, 5, 0);
}
#pragma mark 根据颜色值转换成图像
- (UIImage*) createImageWithColor: (UIColor*) color
{
    CGRect rect=CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context1 = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context1, [color CGColor]);
    CGContextFillRect(context1, rect);
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return theImage;
}

-(UIImage *)createEllipseImageWithColor:(UIColor *)color
{
    CGRect rect = CGRectMake(0.0f, 0.0f, 15.0f, 15.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextAddEllipseInRect(context, rect);
    CGContextDrawPath(context, kCGPathEOFill);
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return theImage;
    
}

 - (void)drawRect:(CGRect)rect{
     UIImage *bg =[self createImageWithColor:RGBACOLOR(240, 240, 240, .7)];
     UIImage *ellipseImg=[self createEllipseImageWithColor:RGBACOLOR(51, 51, 51, 1)];
     for (int i=0; i<6; i++) {
         [bg drawInRect:CGRectMake(i*rect.size.width/6, 0, 1, rect.size.height)];
     }
     
     for (int i=0; i<self.text.length; i++) {
         CGFloat x = i*rect.size.width/6+10;
         CGFloat w = 15;
         CGFloat y = 10;
         CGFloat h = 15;
         CGRect placeholderRect = CGRectMake(x, y, w, h);
         [ellipseImg drawInRect:placeholderRect];
     }
     
     // 画文字
     //    if (!isShow) {
     //        [self.placeholder drawAtPoint:CGPointMake(5, 6) withAttributes:attrs];
     //    }
     //    else{
     //        [self.placeholder drawAtPoint:CGPointMake(5, 6) withAttributes:attrs];
     //    }

 }

@end

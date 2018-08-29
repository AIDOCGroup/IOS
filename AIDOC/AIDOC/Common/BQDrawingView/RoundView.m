//
//  RoundView.m
//  Circular_ DottedCircular
//
//  Created by app on 2018/8/28.
//  Copyright © 2018年 app. All rights reserved.
//

#import "RoundView.h"
#define PI 3.14159265358979323846
@implementation RoundView

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]){
        self.backgroundColor = [UIColor clearColor];
    }
    return self;
}

-(void)drawRect:(CGRect)rect{
    [super drawRect:rect];
     int selfPercent=(int)([self.percent floatValue]*100);
    //运动图标
    UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(self.bounds.size.width/2.0-7, 8, 14, 14)];
    imgView.image = [UIImage imageNamed:@"icon_yd"];
    [self addSubview:imgView];
    //百分比
    UILabel *percentLabel = [[UILabel alloc] initWithFrame:CGRectMake(15, self.bounds.size.width/2.0-15, self.bounds.size.width-30, 30)];
    percentLabel.text = [NSString stringWithFormat:@"%d%%",selfPercent];
    percentLabel.textColor = [UIColor whiteColor];
    percentLabel.textAlignment = NSTextAlignmentCenter;
    percentLabel.font  = [UIFont systemFontOfSize:24.0f];
    [self addSubview:percentLabel];

     //实线圆
     CGContextRef context =UIGraphicsGetCurrentContext();
     
     CGContextSetLineWidth(context, 3);
     
     CGContextAddArc(context, self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2, (self.bounds.size.width-30)/2, 0, 2*PI, 0);
     
     CGContextSetStrokeColorWithColor(context, [UIColor colorWithRed:1 green:1 blue:1 alpha:0.3].CGColor);
     
     CGContextDrawPath(context, kCGPathStroke);
     
     CGContextSetLineWidth(context, 3);
     
     CGContextAddArc(context, self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2, (self.bounds.size.width-30)/2, -PI/2, (selfPercent*2*PI)/100-PI/2, 0);
     
     CGContextSetStrokeColorWithColor(context, [UIColor whiteColor].CGColor);
     
     CGContextDrawPath(context, kCGPathStroke);
    

     //虚线
     CGContextRef context2 = UIGraphicsGetCurrentContext();
     CGFloat lengths2[] = {3,9,3,9};
     CGContextSetLineDash(context2, 0, lengths2, 2);//设置线条为 虚线
     CGContextAddArc(context2, self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2, (self.bounds.size.width-10)/2, -PI/2, (100*2*PI)/100-PI/2, 0);
     CGContextSetStrokeColorWithColor(context2, [UIColor colorWithWhite:1 alpha:0.3].CGColor);
     CGContextDrawPath(context2, kCGPathStroke);
     CGContextClosePath(context2);
     
     if ([self.percent floatValue]==0.0) {
     
     }else if ([self.percent floatValue]>=1.0f) {
     CGContextSetRGBStrokeColor(context2, 1.0, 1.0, 1.0, 1);//设置图形线的颜色
     }else{
     
     CGContextAddArc(context2, self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2, (self.bounds.size.width-10)/2, -PI/2, (selfPercent*2*PI)/100-PI/2, 0);
     CGContextSetStrokeColorWithColor(context2, [UIColor whiteColor].CGColor);
     CGContextDrawPath(context2, kCGPathStroke);
     CGContextClosePath(context2);
     }
 
}
@end

//
//  DrawingView.m
//  AIDOC
//
//  Created by app on 2018/8/9.
//  Copyright © 2018年 app. All rights reserved.
//

#import "DrawingView.h"
#define PI 3.14159265358979323846
@implementation DrawingView

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]){
        self.backgroundColor = [UIColor clearColor];
    }
    return self;
}

-(void)drawRect:(CGRect)rect
{

    if (!_circle) {

        self.backgroundColor=[UIColor clearColor];

        CGContextRef context =UIGraphicsGetCurrentContext();

        CGContextBeginPath(context);

        CGContextSetLineWidth(context, 1.0);

        CGContextSetStrokeColorWithColor(context, [UIColor grayColor].CGColor);

        CGFloat lengths[] = {3,1};//此值可以确定所花虚线的点数

        CGContextSetLineDash(context, 0, lengths,2);
        CGContextSetLineDash(context, 0,lengths,2);

        CGContextMoveToPoint(context, 0.0, 1.0);

        CGContextAddLineToPoint(context, 300.0,1.0);

        CGContextStrokePath(context);

    }else

    {

        int selfPercent=(int)([self.percent floatValue]*100);

        CGContextRef context =UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(context, 3);

        CGContextAddArc(context, self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2, (self.bounds.size.width-30)/2, 0, 2*PI, 0);

        CGContextSetStrokeColorWithColor(context, [UIColor colorWithRed:1 green:1 blue:1 alpha:0.3].CGColor);

        CGContextDrawPath(context, kCGPathStroke);

        CGContextSetLineWidth(context, 3);

        CGContextAddArc(context, self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2, (self.bounds.size.width-30)/2, -PI/2, (selfPercent*2*PI)/100-PI/2, 0);

        CGContextSetStrokeColorWithColor(context, [UIColor whiteColor].CGColor);

        CGContextDrawPath(context, kCGPathStroke);

//        UILabel *percentLabel=[[UILabel alloc]initWithFrame:CGRectMake(self.bounds.origin.x, 30, self.bounds.size.width, self.bounds.size.height/2.0-30)];
//
//        percentLabel.text=[NSString stringWithFormat:@"%d%%",(int)(selfPercent)];
//
//        percentLabel.backgroundColor=[UIColor clearColor];
//
//        percentLabel.textColor=WHITECOLOR;
//
//        percentLabel.font=[UIFont systemFontOfSize:24];
//
//        percentLabel.textAlignment=NSTextAlignmentCenter;
//
//        [self addSubview:percentLabel];
       
        //运动图标
        UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(self.bounds.size.width/2.0-7, 30-7, 14, 14)];
        imgView.image = [UIImage imageNamed:@"icon_yd"];
        [self addSubview:imgView];
        
        //虚线
        CGContextRef context2 = UIGraphicsGetCurrentContext();
        CGFloat lengths2[] = {3,11};
        CGRect aRect2= CGRectMake(5, 5,self.bounds.size.width-10,self.bounds.size.height-10);
        CGContextSetRGBStrokeColor(context2, 1.0, 1.0, 1.0, 0.3);//设置图形线的颜色
        CGContextSetLineDash(context2, 0, lengths2, 4);//设置线条为 虚线
        CGContextSetLineWidth(context2, 3);//设置线宽；
        CGContextAddEllipseInRect(context2, aRect2); //画圆
        CGContextDrawPath(context2, kCGPathStroke);
        if ([self.percent floatValue]==0.0) {
           
        }else if ([self.percent floatValue]>=1.0f) {
           CGContextSetRGBStrokeColor(context2, 1.0, 1.0, 1.0, 1);//设置图形线的颜色
        }else{
            
            CGContextAddArc(context, self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2, (self.bounds.size.width-10)/2, -PI/2, (selfPercent*2*PI)/100-PI/2, 0);
            CGContextSetStrokeColorWithColor(context2, WHITECOLOR.CGColor);
            CGContextDrawPath(context2, kCGPathStroke);

        }
    }

}


@end

//
//  BQDrawingView.m
//  AIDOC
//
//  Created by 张百群 on 2018/8/9.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BQDrawingView.h"

#define PI 3.14159265358979323846
@implementation BQDrawingView

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]){
        self.backgroundColor = [UIColor clearColor];
    }
    return self;
}

-(void)drawRect:(CGRect)rect{
    [super drawRect:rect];
    
    int selfPercent2=(int)([self.percent floatValue]*100);
    //运动图标
    UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(self.bounds.size.width/2.0-7, 8, 14, 14)];
    imgView.image = [UIImage imageNamed:@"icon_yd"];
    [self addSubview:imgView];
    //百分比
    UILabel *percentLabel = [[UILabel alloc] initWithFrame:CGRectMake(15, self.bounds.size.width/2.0-15, self.bounds.size.width-30, 30)];
    percentLabel.text = [NSString stringWithFormat:@"%d%%",selfPercent2];
    percentLabel.textColor = [UIColor whiteColor];
    percentLabel.textAlignment = NSTextAlignmentCenter;
    percentLabel.font  = [UIFont systemFontOfSize:24.0f];
    [self addSubview:percentLabel];
    

    float startAngle = -M_PI/2;
    float endAngle = M_PI * 2;
    
    //初始圆
    [self drawRoundView:CGPointMake(self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2) withStartAngle:startAngle withEndAngle:endAngle  withRadius:(self.bounds.size.width-30)/2];
    //初始虚线圆
    [self drawRoundView3:CGPointMake(self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2) withStartAngle:startAngle withEndAngle:endAngle  withRadius:(self.bounds.size.width-10)/2];

    //动画圆弧
    if ([self.percent floatValue]==0.0f) {
        endAngle = -M_PI/2;
    }else{
        endAngle = selfPercent2*M_PI*2/100 - PI/2;
    }
    [self drawRoundView2:CGPointMake(self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2) withStartAngle:startAngle withEndAngle:endAngle  withRadius:(self.bounds.size.width-30)/2];
    //动态虚线圆
    [self drawRoundView4:CGPointMake(self.bounds.origin.x+(self.bounds.size.width)/2, self.bounds.origin.y+(self.bounds.size.height)/2) withStartAngle:startAngle withEndAngle:endAngle  withRadius:(self.bounds.size.width-10)/2];

}

//初始圆
- (void)drawRoundView:(CGPoint)centerPoint withStartAngle:(CGFloat)startAngle withEndAngle:(CGFloat)endAngle withRadius:(CGFloat)radius {
    
    UIBezierPath *path = [UIBezierPath bezierPath];
    [path addArcWithCenter:centerPoint radius:radius startAngle:startAngle endAngle:endAngle  clockwise:YES];
    CAShapeLayer *arcLayer = [CAShapeLayer layer];
    arcLayer.path = path.CGPath;
    arcLayer.lineWidth = 3;
    //arcLayer.strokeColor可设置画笔颜色
    arcLayer.strokeColor = [UIColor colorWithWhite:1 alpha:0.3].CGColor;
    arcLayer.frame = self.bounds;
    arcLayer.fillColor = [UIColor clearColor].CGColor;
    [self.layer addSublayer:arcLayer];
}

//动画圆弧
- (void)drawRoundView2:(CGPoint)centerPoint withStartAngle:(CGFloat)startAngle withEndAngle:(CGFloat)endAngle withRadius:(CGFloat)radius {
    
    UIBezierPath *path = [UIBezierPath bezierPath];
    [path addArcWithCenter:centerPoint radius:radius startAngle:startAngle endAngle:endAngle  clockwise:YES];
    CAShapeLayer *arcLayer = [CAShapeLayer layer];
    arcLayer.path = path.CGPath;
    arcLayer.lineWidth = 3;
    //arcLayer.strokeColor可设置画笔颜色
    arcLayer.strokeColor = [UIColor whiteColor].CGColor;
    arcLayer.frame = self.bounds;
    arcLayer.fillColor = [UIColor clearColor].CGColor;
    [self.layer addSublayer:arcLayer];
    
    //    动画显示圆则调用
        [self drawLineAnimation:arcLayer];
}

//初始虚线圆
- (void)drawRoundView3:(CGPoint)centerPoint withStartAngle:(CGFloat)startAngle withEndAngle:(CGFloat)endAngle withRadius:(CGFloat)radius {
    
    CAShapeLayer *line =  [CAShapeLayer layer];
    CGMutablePathRef   path =  CGPathCreateMutable();
    
    line.lineWidth = 3;
    //arcLayer.strokeColor可设置画笔颜色
    line.strokeColor = [UIColor colorWithWhite:1 alpha:0.3].CGColor;
    line.fillColor = [UIColor clearColor].CGColor;
    
    line.lineDashPhase = 0;
    line.lineDashPattern = @[@3, @9];
    CGPathAddArc(path, nil, centerPoint.x, centerPoint.y, (self.bounds.size.width-10)/2.0, startAngle, endAngle, nil);
    line.path = path;
    CGPathRelease(path);
    [self.layer addSublayer:line];
}
//动态虚线圆
- (void)drawRoundView4:(CGPoint)centerPoint withStartAngle:(CGFloat)startAngle withEndAngle:(CGFloat)endAngle withRadius:(CGFloat)radius {
    CAShapeLayer *line =  [CAShapeLayer layer];
    CGMutablePathRef   path =  CGPathCreateMutable();
    line.lineWidth = 3; ;
    //arcLayer.strokeColor可设置画笔颜色
    line.strokeColor = [UIColor whiteColor].CGColor;
    line.fillColor = [UIColor clearColor].CGColor;
    line.lineDashPhase = 0;
    line.lineDashPattern = @[@3, @9];
    CGPathAddArc(path, nil, centerPoint.x, centerPoint.y, (self.bounds.size.width-10)/2.0, startAngle, endAngle, nil);
    line.path = path;
    CGPathRelease(path);
    [self.layer addSublayer:line];  
    //    动画显示圆则调用
    [self drawLineAnimation:line];

}

- (void)drawLineAnimation:(CALayer*)layer {
    CABasicAnimation *bas = [CABasicAnimation animationWithKeyPath:@"strokeEnd"];
    bas.duration = 1;
    bas.delegate = self;
    bas.fromValue = [NSNumber numberWithInteger:0];
    bas.toValue = [NSNumber numberWithInteger:1];
    [layer addAnimation:bas forKey:@"key"];
}




@end

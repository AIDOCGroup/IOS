//
//  ColumnarView.m
//  ecmc
//
//  Created by 王文杰 on 16/9/29.
//  Copyright © 2016年 cp9. All rights reserved.
//

#import "ColumnarView.h"

@implementation ColumnarView{

    CGFloat titleHeight;

}


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.

- (void)drawRect:(CGRect)rect {

    //画x轴
    //获取数据最大值
    
    float max = [[_valueArray valueForKeyPath:@"@max.intValue"] floatValue];
    if (max<_tagetNum) {
        max = _tagetNum*1.2;
    }
    //计算目标坐标比
    float value1 = max/_tagetNum;
   
    //画虚线
    //要显示虚线的view
    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(22, rect.size.height-25-((rect.size.height-25)/value1), kScreenWidth-64, 1)];
    lineView.backgroundColor = [UIColor clearColor];
    [self addSubview:lineView];
    
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    [shapeLayer setBounds:lineView.bounds];
    [shapeLayer setPosition:CGPointMake(CGRectGetWidth(lineView.frame) / 2, CGRectGetHeight(lineView.frame))];
    [shapeLayer setFillColor:[UIColor clearColor].CGColor];
    //  设置虚线颜色为lightGrayColor
    [shapeLayer setStrokeColor:BOTTOMColor.CGColor];
    //  设置虚线宽度
    [shapeLayer setLineWidth:CGRectGetHeight(lineView.frame)];
    [shapeLayer setLineJoin:kCALineJoinRound];
    //  设置线宽，线间距
    [shapeLayer setLineDashPattern:[NSArray arrayWithObjects:[NSNumber numberWithInt:4], [NSNumber numberWithInt:4], nil]];
    //  设置路径
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathMoveToPoint(path, NULL, 0, 0);
    CGPathAddLineToPoint(path, NULL, CGRectGetWidth(lineView.frame), 0);
    [shapeLayer setPath:path];
    CGPathRelease(path);
    //  把绘制好的虚线添加上来
    [lineView.layer addSublayer:shapeLayer];


    UILabel *goalLabel = [[UILabel alloc] init];
    goalLabel.text = [CommonFunc currentLanguageWithKey:@"label.Target"];
    goalLabel.textAlignment = NSTextAlignmentCenter;
    goalLabel.textColor = BOTTOMColor;
    goalLabel.backgroundColor = [UIColor clearColor];
    goalLabel.font = [UIFont systemFontOfSize:10];
    goalLabel.clipsToBounds = YES;
     if ([[CommonFunc userLanguage] isEqualToString:@"zh-Hans"]) {
        goalLabel.frame = CGRectMake(lineView.right, lineView.bottom-15, 15, 30);
        goalLabel.numberOfLines = 2;
        goalLabel.layer.cornerRadius = goalLabel.width/2.0;
    }else{
    
        goalLabel.frame = CGRectMake(kScreenWidth-75, lineView.bottom-10, 50, 20);
        goalLabel.layer.cornerRadius = goalLabel.height/2.0;
    }
    [self addSubview:goalLabel];
    
    //计算坐标比例
    float value = (rect.size.height-30-(rect.size.height/10))/max;
    
    //x坐标线
    UIView *lineView1 = [[UIView alloc] initWithFrame:CGRectMake(22, rect.size.height-25, kScreenWidth-64, 1)];
    lineView1.backgroundColor = [UIColor whiteColor];
    [self addSubview:lineView1];

    //循环创建柱状图
    for (int i = 0; i<_valueArray.count; i++) {
        //x轴坐标
        float width = lineView1.width/7.0;
//        UILabel * label1 = [[UILabel alloc]initWithFrame:CGRectMake((((kScreenWidth-(5*20+5*(kScreenWidth == 320 ? 25:40)))/2)+(i*10)+(i*(kScreenWidth == 320 ? 25:40)))-20, rect.size.height-24, 40, 20)];
        UILabel * label1 = [[UILabel alloc]initWithFrame:CGRectMake(lineView1.left+width*i, rect.size.height-24, width, 20)];
        label1.text = self.monthArray[_valueArray.count - 1- i];
        label1.textAlignment = NSTextAlignmentCenter;
        label1.textColor = [UIColor whiteColor];
        label1.backgroundColor = [UIColor clearColor];
        label1.font = [UIFont systemFontOfSize:11];
        [self addSubview:label1];
      
        
        UILabel *label2 = [[UILabel alloc] initWithFrame:CGRectMake(label1.centerX-4,rect.size.height-30-[[_valueArray objectAtIndex:(_valueArray.count - 1 - i)] floatValue]*value, 8, [[_valueArray objectAtIndex:(_valueArray.count - 1 - i)] floatValue]*value)];
        label2.backgroundColor = BOTTOMColor;
        label2.clipsToBounds = YES;
        label2.layer.cornerRadius = 4;
        if (i == _valueArray.count-1) {
            
            label2.backgroundColor = [UIColor whiteColor];
        }

        [self addSubview:label2];
        
    }

        /*
        UIBezierPath *Polyline = [UIBezierPath bezierPath];
        
//        //设置起点
//        [Polyline moveToPoint:CGPointMake(((kScreenWidth-(5*20+5*(kScreenWidth == 320 ? 25:40)))/2)+(i*10)+(i*(kScreenWidth == 320 ? 25:40)), rect.size.height-30)];
//        //设置终点
//        [Polyline addLineToPoint:CGPointMake(((kScreenWidth-(5*20+5*(kScreenWidth == 320 ? 25:40)))/2)+(i*10)+(i*(kScreenWidth == 320 ? 25:40)),rect.size.height-30-[[_valueArray objectAtIndex:(_valueArray.count - 1 - i)] floatValue]*value)];
        CGPoint startPointPath =CGPointMake(label1.centerX-4, rect.size.height-30);
        CGPoint endPointPath=CGPointMake(label1.centerX-4,rect.size.height-30-[[_valueArray objectAtIndex:(_valueArray.count - 1 - i)] floatValue]*value);

        //设置起点
        [Polyline moveToPoint:startPointPath];
        //设置终点
        [Polyline addLineToPoint:endPointPath];

        //设置颜色
        [[UIColor clearColor] set];
        //设置宽度
        Polyline.lineWidth = 8;
        //添加到画布
        [Polyline stroke];
        
        //添加CAShapeLayer
        CAShapeLayer *shapeLine = [[CAShapeLayer alloc]init];
        //设置颜色
        shapeLine.strokeColor = BOTTOMColor.CGColor;
        
        if (i == _valueArray.count-1) {
        
            shapeLine.strokeColor = [UIColor whiteColor].CGColor;
        }
        
        //设置宽度
        shapeLine.lineWidth = 8;
        // 添加圆到path

        //把CAShapeLayer添加到当前视图CAShapeLayer
        [self.layer addSublayer:shapeLine];
        //把Polyline的路径赋予shapeLine
        shapeLine.path = Polyline.CGPath;
        
        
        //开始添加动画
        [CATransaction begin];
        //创建一个strokeEnd路径的动画
        CABasicAnimation *pathAnimation = [CABasicAnimation animationWithKeyPath:@"strokeEnd"];
        //动画时间
        pathAnimation.duration = 2.0;
        //添加动画样式
        pathAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
        //动画起点
        pathAnimation.fromValue = @0.0f;
        //动画停止位置
        pathAnimation.toValue   = @1.0f;
        //把动画添加到CAShapeLayer
        [shapeLine addAnimation:pathAnimation forKey:@"strokeEndAnimation"];
        //动画终点
        shapeLine.strokeEnd = 1.0;
        
        //结束动画
        [CATransaction commit];
    
    }
 
 */
}


@end

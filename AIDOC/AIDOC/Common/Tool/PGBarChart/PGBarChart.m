//
//  PGBarChart.m
//
//  Created by piggybear on 2016/11/29.
//  Copyright © 2016年 piggybear. All rights reserved.
// GitHub Address: https://github.com/xiaozhuxiong121/PGBarChart

#import "PGBarChart.h"

#define VerticalLabelGapLine 5
#define VerticalLineGap 15

@interface PGBarChart()

@property (strong, nonatomic) NSMutableDictionary<NSNumber *, PGBar *> *bars;
@property (strong, nonatomic) NSMutableDictionary<NSNumber *, PGBarChartLabel *> *barChartLabels;
@property (nonatomic, strong) NSMutableArray<UIView *> *horizontalLines;
@property (nonatomic, weak) UIView *bottomLine;

@end

#define PGColor(r,g,b) [UIColor colorWithRed:r / 255.0f green:g / 255.0f blue:b / 255.0f alpha:1.0f]

@implementation PGBarChart

- (instancetype)initWithFrame:(CGRect)frame {
    if ([super initWithFrame:frame]) {
        _barChartLabels = [NSMutableDictionary dictionary];
        _bars = [NSMutableDictionary dictionary];
        _horizontalLines = [NSMutableArray array];
        self.barWidth = 8;
        self.barNormalColor = PGColor(58, 137, 217);
        self.bottomLabelFontSize = 11;
        self.bottomLineColor = PGColor(150, 150, 150);
        self.bottomLineHeight = 1;
        self.bottomLineColor = PGColor(225, 225, 225);
        self.horizontalLineHeight = 1;
        self.animationType = PGBarAnimationEaseInEaseOut;
        self.lineCap = PGBarLineCapRound;
    }
    return self;
}


#pragma mark Setter and Getter

- (void)setLineCap:(PGBarLineCap)lineCap {
    _lineCap = lineCap;
    [self.bars enumerateKeysAndObjectsUsingBlock:^(NSNumber * _Nonnull key, PGBar * _Nonnull obj, BOOL * _Nonnull stop) {
        obj.lineCap = lineCap;
    }];
}

- (void)setAnimationType:(PGBarAnimationType)animationType {
    _animationType = animationType;
    
    NSArray *datas = [self.dataSource charDataModels];
    if (datas.count != 0) {
        float maxValue = [self maxValueForCharDataModels].value * 1.1;
        [datas enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            PGBarChartDataModel *dataModel = [self valueForIndex:idx];
            PGBar *bar = self.bars[[NSNumber numberWithInteger:idx]];
            bar.barColor = self.barNormalColor;
            [bar grade:dataModel.value / maxValue animationType:animationType];
            bar.barChartDataModel = dataModel;
        }];
    }
}

- (void)setDataSource:(id<PGBarChartDataSource>)dataSource {
    _dataSource = dataSource;
    [self logic];
}

- (void)setHorizontalLineHeight:(CGFloat)horizontalLineHeight {
    _horizontalLineHeight = horizontalLineHeight;
    [self.horizontalLines enumerateObjectsUsingBlock:^(UIView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        CGFloat x = obj.frame.origin.x;
        CGFloat y = obj.frame.origin.y;
        CGFloat width = obj.frame.size.width;
        obj.frame = CGRectMake(x, y, width, horizontalLineHeight);
    }];
}

- (void)setBarWidth:(CGFloat)barWidth {
    _barWidth = barWidth;
    [_bars enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PGBar * obj, BOOL * _Nonnull stop) {
        CGFloat x = obj.frame.origin.x;
        CGFloat y = obj.frame.origin.y;
        CGFloat height = obj.frame.size.height;
        obj.frame = CGRectMake(x, y, barWidth, height);
    }];
    
    [_barChartLabels enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PGBarChartLabel * obj, BOOL * _Nonnull stop) {
        CGFloat y = obj.frame.origin.y;
        CGSize size = obj.frame.size;
        CGSize fontSize = [obj.text sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:self.bottomLabelFontSize]}];
        PGBar *bar = _bars[key];
        obj.frame = CGRectMake(bar.frame.origin.x + barWidth/2 - fontSize.width/2, y, size.width, size.height);
    }];
}

- (void)setBottomLabelFontSize:(NSUInteger)bottomLabelFontSize {
    _bottomLabelFontSize = bottomLabelFontSize;
    [_barChartLabels enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PGBarChartLabel * _Nonnull obj, BOOL * _Nonnull stop) {
        obj.fontSize = bottomLabelFontSize;
        CGSize originalSize = [obj.text sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:bottomLabelFontSize]}];
        CGFloat x = obj.frame.origin.x + originalSize.width/2;
        CGFloat y = obj.frame.origin.y;
        CGFloat width = obj.frame.size.width;
        CGSize size = [obj.text sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:bottomLabelFontSize]}];
        obj.frame = CGRectMake(x - size.width/2, y, width, size.height);
    }];
}

- (void)setBottomLabelFontColor:(UIColor *)bottomLabelFontColor {
    _bottomLabelFontColor = bottomLabelFontColor;
    [_barChartLabels enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PGBarChartLabel * _Nonnull obj, BOOL * _Nonnull stop) {
        obj.fontColor = bottomLabelFontColor;
    }];
}

- (void)setBottomLineColor:(UIColor *)bottomLineColor {
    _bottomLineColor = bottomLineColor;
    self.bottomLine.backgroundColor = bottomLineColor;
}

- (void)setBottomLineHeight:(CGFloat)bottomLineHeight {
    _bottomLineHeight = bottomLineHeight;
    CGFloat x = self.bottomLine.frame.origin.x;
    CGFloat y = self.bottomLine.frame.origin.y;
    CGFloat width = self.bottomLine.frame.size.width;
    self.bottomLine.frame = CGRectMake(x, y, width, bottomLineHeight);
}

- (void)setBarNormalColor:(UIColor *)barNormalColor {
    _barNormalColor = barNormalColor;
    [self.bars enumerateKeysAndObjectsUsingBlock:^(NSNumber * _Nonnull key, PGBar * _Nonnull obj, BOOL * _Nonnull stop) {
        obj.barColor = barNormalColor;
    }];
}

- (void)setTagetValue:(CGFloat)tagetValue{
    _tagetValue = tagetValue;
}
/**
 *  上周/上月按钮
 */
- (UIButton *)leftBtn{
    if (!_leftBtn) {
        _leftBtn  = [[UIButton alloc] initWithFrame:CGRectMake(5, self.centerY-10, 20, 20)];
        [_leftBtn setImage:[UIImage imageNamed:@"more-left"] forState:UIControlStateNormal];
    }
    return _leftBtn;
}

/**
 *  下周/下月
 */
- (UIButton *)rightBtn{
    if (!_rightBtn) {
        _rightBtn  = [[UIButton alloc] initWithFrame:CGRectMake(self.frame.size.width-25, self.centerY-10, 20, 20)];
        [_rightBtn setImage:[UIImage imageNamed:@"more-right"] forState:UIControlStateNormal];
    }
    return _rightBtn;
}


#pragma -mark- Custom Methed

- (PGBarChartDataModel *)maxValueForCharDataModels {
    NSArray *data = [_dataSource charDataModels];
    CGFloat maxValue = [[data valueForKeyPath:@"@max.value.floatValue"] floatValue];
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF.value = %f", maxValue];
    NSArray *array = [data filteredArrayUsingPredicate:predicate];
    return array[0];
}

- (PGBarChartDataModel *)valueForIndex:(NSInteger)index {
    NSArray *data = [_dataSource charDataModels];
    if (index >= [data count] || index < 0) return nil;
    return [data objectAtIndex:index];
}

-(void)rollBackAnimation {
    [self.bars enumerateKeysAndObjectsUsingBlock:^(NSNumber * _Nonnull key, PGBar * _Nonnull obj, BOOL * _Nonnull stop) {
        [obj rollBack];
    }];
}

- (void)reloadData {
    NSArray *datas = [self.dataSource charDataModels];
    float maxValue = [self maxValueForCharDataModels].value * 1.1;
    [datas enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        PGBarChartDataModel *dataModel = [self valueForIndex:idx];
        PGBar *bar = self.bars[[NSNumber numberWithInteger:idx]];
        bar.barColor = self.barNormalColor;
        [bar grade:dataModel.value / maxValue animationType:self.animationType];
        bar.barChartDataModel = dataModel;
    }];
}


- (CGFloat)dataModelsMaxHeight {
    NSMutableArray *array = [NSMutableArray array];
    [[_dataSource charDataModels] enumerateObjectsUsingBlock:^(PGBarChartDataModel * dataModel, NSUInteger idx, BOOL * _Nonnull stop) {
        CGSize dataModelSize = [dataModel.label sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:self.bottomLabelFontSize]}];
        [array addObject:[NSNumber numberWithFloat:dataModelSize.height]];
    }];
    
    CGFloat maxHeight = [[array valueForKeyPath:@"@max.self.floatValue"] floatValue];
    return maxHeight;
}

- (void)logic {
    CGFloat verticalLinePoX = VerticalLabelGapLine;
    NSInteger totalCount = [self.dataSource charDataModels].count;
    float maxValue = [self maxValueForCharDataModels].value * 1.1;
    CGFloat gap = (self.frame.size.width - verticalLinePoX - totalCount * self.barWidth) / (totalCount + 1);
    CGFloat maxHeight = [self dataModelsMaxHeight];
    UIView *bottomLine = [[UIView alloc] initWithFrame:CGRectMake(22, self.frame.size.height - maxHeight - VerticalLineGap, self.frame.size.width-44, self.bottomLineHeight)];

    bottomLine.backgroundColor = self.bottomLineColor;
    [self addSubview:bottomLine];
    self.bottomLine = bottomLine;
    
    //目标线条
    float heightGap = self.frame.size.height-self.tagetValue/[self maxValueForCharDataModels].value*self.frame.size.height;
    
    //画虚线
    //要显示虚线的view
    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(22, heightGap , self.frame.size.width-44, self.horizontalLineHeight)];
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
    
    [self.horizontalLines addObject:lineView];
    
    //目标label
    UILabel *goalLabel = [[UILabel alloc] init];
    goalLabel.text = [CommonFunc currentLanguageWithKey:@"label.Target"];
    goalLabel.textAlignment = NSTextAlignmentCenter;
    goalLabel.textColor = BOTTOMColor;
    goalLabel.backgroundColor = [UIColor clearColor];
    goalLabel.font = [UIFont systemFontOfSize:10];
    goalLabel.clipsToBounds = YES;
    if ([[CommonFunc userLanguage] isEqualToString:@"zh-Hans"]) {
        goalLabel.frame = CGRectMake(kScreenWidth-45, lineView.bottom-15, 15, 30);
        goalLabel.numberOfLines = 2;
        goalLabel.layer.cornerRadius = goalLabel.width/2.0;
    }else{
        goalLabel.frame = CGRectMake(kScreenWidth-75, lineView.bottom-10, 50, 20);
        goalLabel.layer.cornerRadius = goalLabel.height/2.0;
    }
    [self addSubview:goalLabel];


    for (int i = 0; i < totalCount; i++) {
        NSInteger currentIndex = i;
        PGBarChartDataModel *dataModel = [self valueForIndex:currentIndex];
        CGSize dataModelSize = [dataModel.label sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:self.bottomLabelFontSize]}];
        CGFloat barPosX = verticalLinePoX + gap + i * (gap + self.barWidth);
        
        PGBar *bar = [[PGBar alloc] initWithFrame:CGRectMake(barPosX, 3, self.barWidth, self.frame.size.height-3 - maxHeight - VerticalLineGap)];
        bar.lineCap = self.lineCap;
        bar.barColor = self.barNormalColor;
        bar.backgroundColor = [UIColor clearColor];
        [bar grade:dataModel.value / maxValue animationType:self.animationType];
        bar.barChartDataModel = dataModel;
        bar.barColor = self.barNormalColor;
        if (i==totalCount-1) {
            bar.barColor = WHITECOLOR;
        }
        [bar setDelegate:self];
        [self addSubview:bar];
        [self.bars setObject:bar forKey:[NSNumber numberWithInteger:currentIndex]];
        
        CGRect frame = CGRectMake(barPosX + self.barWidth/2 - dataModelSize.width/2,
                                  bottomLine.bottom+4,
                                  dataModelSize.width,
                                  dataModelSize.height);
        PGBarChartLabel *barChartLabel = [[PGBarChartLabel alloc]initWithFrame:frame];
        barChartLabel.fontSize = self.bottomLabelFontSize;
        barChartLabel.fontColor = self.bottomLabelFontColor;
        [barChartLabel setTextAlignment:NSTextAlignmentCenter];
        barChartLabel.text = dataModel.label;
        [self addSubview:barChartLabel];
        [self.barChartLabels setObject:barChartLabel forKey:[NSNumber numberWithInteger:(currentIndex)]];
    }
    
    
    //上周/上月按钮
    [self addSubview:self.leftBtn];
    //下周/下月月按钮
    [self addSubview:self.rightBtn];
}

#pragma -mark- EColumnDelegate

- (void)barTaped:(PGBar *)bar {
    [_delegate barChart:self didSelectBar:bar];
}

@end

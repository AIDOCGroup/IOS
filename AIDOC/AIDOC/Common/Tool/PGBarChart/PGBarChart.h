//
//  PGBarChart.h
//
//  Created by piggybear on 2016/11/29.
//  Copyright © 2016年 piggybear. All rights reserved.
// GitHub Address: https://github.com/xiaozhuxiong121/PGBarChart

#import <UIKit/UIKit.h>
#import "PGBar.h"
#import "PGBarChartLabel.h"
#import "PGBarChartDataModel.h"
#import "PGBox.h"

@class PGBarChart;
@class PGBarChartDataModel;

@protocol PGBarChartDataSource <NSObject>

@required
- (NSArray *)charDataModels;

@end

@protocol PGBarChartDelegate <NSObject>

@optional
- (void) barChart:(PGBarChart *)barChart didSelectBar:(PGBar *)bar;

@end

@interface PGBarChart : UIView <PGBarDelegate>
/**
 *  线帽
 */
@property(nonatomic, assign) PGBarLineCap lineCap;
/**
 *  动画类型
 */
@property(nonatomic, assign) PGBarAnimationType animationType;
/**
 *  设置圆柱的颜色
 */
@property (nonatomic, strong) UIColor *barNormalColor;
/**
 *  每一个圆柱的宽度
 */
@property (nonatomic, assign) CGFloat barWidth;
/**
 *  底线的高度
 */
@property (nonatomic, assign) CGFloat bottomLineHeight;
/**
 *  底线的颜色
 */
@property (nonatomic, strong) UIColor *bottomLineColor;
/**
 *  水平线的高度
 */
@property (nonatomic, assign) CGFloat horizontalLineHeight;

/**
 *  底下的字体颜色
 */
@property (nonatomic, strong) UIColor *bottomLabelFontColor;
/**
 *  底下的字体大小
 */
@property (nonatomic, assign) NSUInteger bottomLabelFontSize;


/**
 *  运动目标
 */
@property (nonatomic, assign) CGFloat tagetValue;

/**
 *  上周/上月按钮
 */
@property (nonatomic, strong) UIButton *leftBtn;

/**
 *  下周/下月
 */
@property (nonatomic, strong) UIButton *rightBtn;


@property (nonatomic, weak) id <PGBarChartDataSource> dataSource;
@property (nonatomic, weak) id <PGBarChartDelegate> delegate;



- (void)reloadData;
-(void)rollBackAnimation;
@end

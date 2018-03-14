//
//  VRGCalendarView.h
//  Vurig
//
//  Created by in 't Veen Tjeerd on 5/8/12.
//  Copyright (c) 2012 Vurig Media. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "UIColor+expanded.h"
#import "NSDate+Category.h"

/**
 *  获取16进制 color
 */
#define rgbColor(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//设备高度
#define kScreenHeight ([UIScreen mainScreen].bounds.size.height)
//设备宽度
#define kScreenWidth ([UIScreen mainScreen].bounds.size.width)

//导航高
#define kNavH self.navigationController.navigationBar.frame.size.height
//状态栏高
#define kStatusH [UIApplication sharedApplication].statusBarFrame.size.height


#define kVRGCalendarViewTopBarHeight 88
#define kVRGCalendarViewTopBarBgHeight 50
#define kVRGCalendarViewWidth kScreenHeight

#define kVRGCalendarViewDayMargin 2
#define kVRGCalendarViewDayWidth (kScreenWidth - 7 * kVRGCalendarViewDayMargin) / 7
#define kVRGCalendarViewDayHeight 44

@protocol VRGCalendarViewDelegate;
@interface VRGCalendarView : UIView {
    id <VRGCalendarViewDelegate> delegate;
    
    NSDate *currentMonth;
    
    UILabel *labelCurrentMonth;
    
    BOOL isAnimating;
    BOOL prepAnimationPreviousMonth;
    BOOL prepAnimationNextMonth;
    
    UIImageView *animationView_A;
    UIImageView *animationView_B;
    
    NSArray *markedDates;
    NSArray *markedColors;
}

@property (nonatomic, retain) id <VRGCalendarViewDelegate> delegate;
/**
 *   当前月
 */
@property (nonatomic, retain) NSDate *currentMonth;
/**
 *  当前月Label
 */
@property (nonatomic, retain) UILabel *labelCurrentMonth;
@property (nonatomic, retain) UIImageView *animationView_A;
@property (nonatomic, retain) UIImageView *animationView_B;
@property (nonatomic, retain) NSArray *markedDates;
@property (nonatomic, retain) NSArray *markedColors;
@property (nonatomic, getter = calendarHeight) float calendarHeight;
@property (nonatomic, retain, getter = selectedDate) NSDate *selectedDate;

-(void)selectDate:(int)date;
-(void)reset;

-(void)markDates:(NSArray *)dates;
-(void)markDates:(NSArray *)dates withColors:(NSArray *)colors;

-(void)showNextMonth;
-(void)showPreviousMonth;

-(int)numRows;
-(void)updateSize;
-(UIImage *)drawCurrentState;

@end

@protocol VRGCalendarViewDelegate <NSObject>

@optional
-(void)calendarView:(VRGCalendarView *)calendarView switchedToMonth:(int)month targetHeight:(float)targetHeight animated:(BOOL)animated;

-(void)calendarView:(VRGCalendarView *)calendarView dateSelected:(NSDate *)date;
/**
 *  左右切换时间
 *
 *  @param calendarView calendarView
 *  @param currentTime  当前时间
 *  @param nextTime     即将转到的时间
 */
-(void)calendarView:(VRGCalendarView *)calendarView currentDay:(NSString *)currentDay nextTime:(NSString *)nextTime;


@end

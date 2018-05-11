//
//  DisplayPickerView.h
//  MiaoHealthConnectDemo
//
//  Created by 罗志平 on 2017/7/6.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DataElderViewController.h"

typedef NS_ENUM(NSUInteger, RemindType) {
    RemindTypeWithType,
    RemindTypeWithRepeatType,
    RemindTypeWithSexType,
    RemindTypeWithHeightType,
    RemindTypeWithWeightType
};

typedef void (^SelectedBlock)(NSInteger number,NSString *title,RemindType remindType);

@interface DisplayPickerView : UIView<UIPickerViewDelegate,UIPickerViewDataSource>

@property (copy , nonatomic) SelectedBlock selectedBlock;

@property (weak, nonatomic) IBOutlet UIPickerView *pickerView;

@property (assign , nonatomic) RemindType remindType;

@property (weak, nonatomic) DataElderViewController *vc;

+ (DisplayPickerView *)displayPickerViewWithSelectedBlock:(SelectedBlock)selectedBlock;
@end

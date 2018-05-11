//
//  DisplayPickerView.m
//  MiaoHealthConnectDemo
//
//  Created by 罗志平 on 2017/7/6.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "DisplayPickerView.h"

@interface DisplayPickerView ()

@property (nonatomic , strong) NSDictionary *dictonary;

@property (weak, nonatomic) IBOutlet UIButton *finishedButton;
@end

@implementation DisplayPickerView

- (void)awakeFromNib{
    [super awakeFromNib];
    self.pickerView.mj_origin = CGPointMake(0, 40);
    self.mj_w = kMainScreenWidth;
    self.pickerView.mj_w = kMainScreenWidth;
    self.finishedButton.mj_x = kMainScreenWidth - self.finishedButton.mj_w - 30;
}

+ (DisplayPickerView *)displayPickerViewWithSelectedBlock:(SelectedBlock)selectedBlock{
    DisplayPickerView *displayPickerView = (DisplayPickerView *)[[[NSBundle mainBundle] loadNibNamed:@"DisplayPickerView" owner:nil options:nil] lastObject];
    displayPickerView.mj_origin = CGPointMake(0, kMainScreenHeight);
    displayPickerView.selectedBlock = selectedBlock;
    return displayPickerView;
    
}
- (void)setRemindType:(RemindType)remindType{
    _remindType = remindType;
    switch (remindType) {
        case RemindTypeWithType:
            self.dictonary = @{@"0":@"无",@"1":@"摔跤",@"2":@"起床",@"3":@"活动",@"4":@"休息",@"5":@"吃药"};
            break;
        case RemindTypeWithRepeatType:
            self.dictonary = @{@"0":@"不重复",@"1":@"按天",@"2":@"按周",@"3":@"按月",@"4":@"按年"};
            break;
        case RemindTypeWithSexType:
            self.dictonary = @{@"0":@"男",@"1":@"女"};
            break;
        case RemindTypeWithHeightType:
            self.dictonary = @{@"0":@"155",@"1":@"156",@"2":@"157",@"3":@"158",@"4":@"159",@"5":@"160",@"6":@"161",@"7":@"162",@"8":@"163",@"9":@"164",@"10":@"165",@"11":@"166",@"12":@"167",@"13":@"168",@"14":@"169",@"15":@"170",@"16":@"171",@"17":@"172",@"18":@"173",@"19":@"174",@"20":@"175",@"21":@"176",@"22":@"177",@"23":@"178",@"24":@"179",@"25":@"180",@"26":@"181",@"27":@"182",@"28":@"183",@"29":@"184",@"30":@"185",@"31":@"186",@"32":@"187",@"33":@"188",@"34":@"189",@"35":@"190",@"36":@"191",@"37":@"192",@"38":@"193",@"39":@"194",@"40":@"195",@"41":@"196",@"42":@"197",@"43":@"198",@"44":@"199",@"45":@"200"};
            break;
        case RemindTypeWithWeightType:
            self.dictonary = @{@"0":@"40",@"1":@"41",@"2":@"42",@"3":@"43",@"4":@"44",@"5":@"45",@"6":@"46",@"7":@"147",@"8":@"48",@"9":@"49",@"10":@"50",@"11":@"51",@"12":@"52",@"13":@"53",@"14":@"54",@"15":@"55",@"16":@"56",@"17":@"57",@"18":@"58",@"19":@"59",@"20":@"60",@"21":@"65",@"22":@"70",@"23":@"75",@"24":@"80"};
            break;
        default:
            break;
    }
    [self.pickerView reloadAllComponents];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView{
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component{
    return self.dictonary.allKeys.count;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component{
    return [self.dictonary objectForKey:[@(row) stringValue]];
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component{
//    NSString *title = [self.dictonary objectForKey:[@(row) stringValue]];
//    self.selectedBlock(row,title,self.remindType);
}

- (IBAction)finishAction:(id)sender {
    NSInteger row = [self.pickerView selectedRowInComponent:0];
     NSString *title = [self.dictonary objectForKey:[@(row) stringValue]];
    self.selectedBlock(row,title,self.remindType);
    [UIView animateWithDuration:0.3 animations:^{
        self.mj_origin = CGPointMake(0, kMainScreenHeight);
    } completion:^(BOOL finished) {
    }];
}


- (IBAction)cancelAction:(id)sender {
    [UIView animateWithDuration:0.3 animations:^{
        self.mj_origin = CGPointMake(0, kMainScreenHeight);
    } completion:^(BOOL finished) {
    }];
}

@end

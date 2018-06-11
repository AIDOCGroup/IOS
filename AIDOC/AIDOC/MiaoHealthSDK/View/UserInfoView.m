//
//  UserInfoView.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 2017/5/26.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "UserInfoView.h"
#import "UICustomDatePicker.h"

@implementation UserInfoView

+ (UserInfoView *)userInfoView{
    UserInfoView *userInfoView = (UserInfoView *)[[[NSBundle mainBundle] loadNibNamed:@"UserInfoView" owner:nil options:nil] lastObject];
    return userInfoView;
}

- (void)awakeFromNib{
    [super awakeFromNib];
    UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(showDataPicker)];
    self.birthdayLabel.userInteractionEnabled = YES;
    [self.birthdayLabel addGestureRecognizer:gesture];
}

- (DisplayPickerView *)pickerView{
    if (!_pickerView) {
        DisplayPickerView *pickerView = [DisplayPickerView displayPickerViewWithSelectedBlock:^(NSInteger number,NSString *title,RemindType remindType) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (remindType == RemindTypeWithSexType){
                    [self.genderButton setTitle:title forState:UIControlStateNormal];
                }else if(remindType == RemindTypeWithHeightType){
                    [self.heightButton setTitle:title forState:UIControlStateNormal];
                }else if(remindType == RemindTypeWithWeightType){
                    [self.weightButton setTitle:title forState:UIControlStateNormal];
                }
            });
        }];
        [self.superview.superview addSubview:pickerView];
        self.pickerView = pickerView;
    }
    return _pickerView;
}
- (IBAction)confirm:(id)sender {
    MCUserInfo *userInfo = [[MCUserInfo alloc] init];
    userInfo.userName = self.userNameTF.text;
    userInfo.age = [self getAgeWithBirthday:self.birthdayLabel.text];
    userInfo.sex = [self.genderButton.titleLabel.text isEqualToString:@"男"] ? 0 : 1;
    userInfo.height = self.heightButton.titleLabel.text.integerValue;
    userInfo.weight = self.weightButton.titleLabel.text.integerValue;
    userInfo.birthDay = self.birthdayLabel.text;
    [self.delegate userInfoViewConfirmCallBack:self userInfo:userInfo];
}

- (IBAction)cancel:(id)sender {
    [self.delegate cancelCallBack];
}

- (IBAction)buttonAction:(id)sender {
    UIButton *button = (UIButton *)sender;
    switch (button.tag) {
        case 101:
            self.pickerView.remindType = RemindTypeWithSexType;
            break;
        case 102:
            self.pickerView.remindType = RemindTypeWithHeightType;
            break;
        case 103:
            self.pickerView.remindType = RemindTypeWithWeightType;
            break;
        default:
            break;
    }
    [self.superview.superview bringSubviewToFront:self.pickerView];

    [UIView animateWithDuration:0.3 animations:^{
        self.pickerView.mj_origin = CGPointMake(0, kMainScreenHeight - self.pickerView.mj_h);
    }];
}


#pragma mark - 根据出生日期计算年龄
- (NSInteger)getAgeWithBirthday:(NSString *)birthday{
    if (!birthday.length) {
        return 18; // 默认18
    }
    //计算年龄
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc]init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    //生日
    NSDate *birthDay = [dateFormatter dateFromString:birthday];
    //当前时间
    NSString *currentDateStr = [dateFormatter stringFromDate:[NSDate date]];
    NSDate *currentDate = [dateFormatter dateFromString:currentDateStr];
    NSTimeInterval time=[currentDate timeIntervalSinceDate:birthDay];
    int age = ((int)time)/(3600*24*365);
    NSLog(@"year %d",age);
    return age;
}

- (void)showDataPicker {
    [UICustomDatePicker showCustomDatePickerAtView:self.superview.superview choosedDateBlock:^(NSDate *date) {
        self.birthdayLabel.text = [self.dateFormater stringFromDate:date];
        NSLog(@"current Date:%@",self.birthdayLabel.text);
    } cancelBlock:^{
        
    }];
}



- (NSDateFormatter *)dateFormater{
    if (!_dateFormater) {
        _dateFormater = [[NSDateFormatter alloc] init];
        _dateFormater.dateFormat = @"yyyy-MM-dd";
    }
    return _dateFormater;
}

@end

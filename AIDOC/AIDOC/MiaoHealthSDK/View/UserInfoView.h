//
//  UserInfoView.h
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 2017/5/26.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MiaoHealthConnect/MCData.h>
#import "DisplayPickerView.h"

@class UserInfoView;

@protocol UserInfoViewDelegate <NSObject>

- (UserInfoView *)userInfoViewConfirmCallBack:(UserInfoView *)userInfoView userInfo:(MCUserInfo *)userInfo;

- (void)cancelCallBack;

@end

@interface UserInfoView : UIView
@property (nonatomic , strong) NSDateFormatter *dateFormater;

@property (weak, nonatomic) IBOutlet UITextField *userNameTF;

@property (weak, nonatomic) IBOutlet UILabel *birthdayLabel;

@property (weak, nonatomic) IBOutlet UIButton *genderButton;

@property (weak, nonatomic) IBOutlet UIButton *heightButton;

@property (weak, nonatomic) IBOutlet UIButton *weightButton;

@property (strong , nonatomic) MCUserInfo *userInfo;

@property (weak , nonatomic) id<UserInfoViewDelegate> delegate;

@property (nonatomic , weak) DisplayPickerView *pickerView;

+ (UserInfoView *)userInfoView;
@end

//
//  ChangePassViewController.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "ChangePassViewController.h"
#import "ZKLoginTextField.h"
@interface ChangePassViewController ()
{
    ZKLoginTextField *oldPassword;
    ZKLoginTextField *newPassword;
    ZKLoginTextField *reNewPassword;
}
@end

@implementation ChangePassViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"修改密码";
    CGFloat textFieldH = 40;
    //1旧密码
    oldPassword = [[ZKLoginTextField alloc] init];
    oldPassword.placeholder = @"输入原密码";
    oldPassword.clearButtonMode = UITextFieldViewModeAlways;
    oldPassword.textColor = rgbColor(0x999999);
    oldPassword.frame = CGRectMake(35, 32, kScreenWidth-70, textFieldH);
    oldPassword.font = [UIFont systemFontOfSize:12];
    oldPassword.secureTextEntry = YES;
    //设置圆角
    [oldPassword setClipsToBounds:YES];
    oldPassword.layer.cornerRadius = oldPassword.height/2.0;//设置矩形四个圆角半径
    oldPassword.layer.borderWidth = 0.7;//边框宽度
    oldPassword.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:oldPassword];
    
    //2.新密码
    newPassword = [[ZKLoginTextField alloc] init];
    newPassword.placeholder = @"输入新秘密";
    newPassword.clearButtonMode = UITextFieldViewModeAlways;
    newPassword.textColor = rgbColor(0x999999);
    newPassword.frame = CGRectMake(35, oldPassword.bottom  + 20, kScreenWidth-70, textFieldH);
    newPassword.font = [UIFont systemFontOfSize:12];
    newPassword.secureTextEntry = YES;
    //设置圆角
    [newPassword setClipsToBounds:YES];
    newPassword.layer.cornerRadius = newPassword.height/2.0;//设置矩形四个圆角半径
    newPassword.layer.borderWidth = 0.7;//边框宽度
    newPassword.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:newPassword];
    
    //3.确认新密码
    reNewPassword = [[ZKLoginTextField alloc] init];
    reNewPassword.placeholder = @"确认新秘密";
    reNewPassword.clearButtonMode = UITextFieldViewModeAlways;
    reNewPassword.textColor = rgbColor(0x999999);
    reNewPassword.frame = CGRectMake(35, newPassword.bottom + 20, kScreenWidth-70, textFieldH);
    reNewPassword.font = [UIFont systemFontOfSize:12];
    reNewPassword.secureTextEntry = YES;
    //设置圆角
    [reNewPassword setClipsToBounds:YES];
    reNewPassword.layer.cornerRadius = reNewPassword.height/2.0;//设置矩形四个圆角半径
    reNewPassword.layer.borderWidth = 0.7;//边框宽度
    reNewPassword.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:reNewPassword];

    
    //确认修改
    UIButton *alterBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [alterBtn setTitle:@"确认修改" forState:UIControlStateNormal];
    [alterBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    alterBtn.titleLabel.font = [UIFont systemFontOfSize:14];
    [alterBtn addTarget:self action:@selector(alterBtnClick) forControlEvents:UIControlEventTouchUpInside];
    alterBtn.frame = CGRectMake(35, reNewPassword.bottom + 100,kScreenWidth - 70, 40);
    alterBtn.backgroundColor = rgbColor(0x0db2f6);
    
    //设置圆角
    [alterBtn setClipsToBounds:YES];
    alterBtn.layer.cornerRadius = alterBtn.height/2.0;//设置矩形四个圆角半径
    alterBtn.layer.borderWidth = 1.0;//边框宽度
    alterBtn.layer.borderColor = [UIColor whiteColor].CGColor;
    
    [self.view addSubview:alterBtn];
    
    
}


/**
 *  确认修改
 */
- (void)alterBtnClick{
    if(![newPassword.text isEqualToString:reNewPassword.text]) {
        [ProgressHUD showError:@"两次密码不一致"];
    }else{
    
        [YTNetworkRequest changePassword:oldPassword.text withNewPassword:newPassword.text success:^(id result) {
            
            [ProgressHUD showSuccess:@"密码修改成功"];
            
        } failure:^(NSString *error) {
            
             [ProgressHUD showError:error];
        }];

    }
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

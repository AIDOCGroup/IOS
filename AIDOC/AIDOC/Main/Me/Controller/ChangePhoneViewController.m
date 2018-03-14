//
//  ChangePhoneViewController.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "ChangePhoneViewController.h"
#import "ZKLoginTextField.h"
@interface ChangePhoneViewController ()
{
    ZKLoginTextField *oldPhoneNum;//手机号
    ZKLoginTextField *codeNum1;//验证码
    UIButton *verifyCodeBtn1;//获取验证码
    
    ZKLoginTextField *newhoneNum;//手机号
    ZKLoginTextField *codeNum2;//验证码
    UIButton *verifyCodeBtn2;//获取验证码

}

//是否点击验证码
@property (nonatomic,assign) BOOL iSverify;

@end

@implementation ChangePhoneViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"修改绑定手机";
    CGFloat textFieldH = 40;
    
    //1.1旧手机号
    oldPhoneNum = [[ZKLoginTextField alloc] init];
    oldPhoneNum.placeholder = @"请输入手机号";
    oldPhoneNum.clearButtonMode = UITextFieldViewModeAlways;
    oldPhoneNum.textColor = rgbColor(0x999999);
    oldPhoneNum.frame = CGRectMake(35, 40, kScreenWidth-70, textFieldH);
    oldPhoneNum.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [oldPhoneNum setClipsToBounds:YES];
    oldPhoneNum.layer.cornerRadius = oldPhoneNum.height/2.0;//设置矩形四个圆角半径
    oldPhoneNum.layer.borderWidth = 0.7;//边框宽度
    oldPhoneNum.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:oldPhoneNum];
    
    //1.2验证码
    codeNum1 = [[ZKLoginTextField alloc] init];
    codeNum1.placeholder = @"请输入验证码";
    codeNum1.clearButtonMode = UITextFieldViewModeAlways;
    codeNum1.textColor = rgbColor(0x999999);
    codeNum1.frame = CGRectMake(35, oldPhoneNum.bottom+20, kScreenWidth-70, textFieldH);
    codeNum1.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [codeNum1 setClipsToBounds:YES];
    codeNum1.layer.cornerRadius = codeNum1.height/2.0;//设置矩形四个圆角半径
    codeNum1.layer.borderWidth = 0.7;//边框宽度
    codeNum1.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:codeNum1];

    //2.2获取验证码
    verifyCodeBtn1 = [UIButton buttonWithType:UIButtonTypeCustom];
    verifyCodeBtn1.frame = CGRectMake(codeNum1.right-100, codeNum1.top+5, 95, codeNum1.height-10);
    [verifyCodeBtn1 setTitle:@"获取验证码(60s)" forState:UIControlStateNormal];
    [verifyCodeBtn1.titleLabel setFont:[UIFont systemFontOfSize:11]];
    
    //设置圆角
    [verifyCodeBtn1 setClipsToBounds:YES];
    verifyCodeBtn1.layer.cornerRadius = verifyCodeBtn1.height/2.0;//设置矩形四个圆角半径
    verifyCodeBtn1.layer.borderWidth = 0.7;//边框宽度
    verifyCodeBtn1.layer.borderColor = [UIColor clearColor].CGColor;
    verifyCodeBtn1.tag = 1;
    [verifyCodeBtn1 setBackgroundImage:[UIImage createImageWithColor:rgbColor(0x38ace5)] forState:UIControlStateNormal];
    [verifyCodeBtn1 setBackgroundImage:[UIImage createImageWithColor:[UIColor grayColor]] forState:UIControlStateDisabled];
    [verifyCodeBtn1 setBackgroundImage:[UIImage createImageWithColor:rgbColor(0x38ace5)] forState:UIControlStateHighlighted];
    
    [verifyCodeBtn1 addTarget:self action:@selector(getVerifyCodeClick:) forControlEvents:UIControlEventTouchUpInside];
    
    
    [self.view addSubview:verifyCodeBtn1];
    

    //2.1新手机号
    newhoneNum = [[ZKLoginTextField alloc] init];
    newhoneNum.placeholder = @"请输入手机号";
    newhoneNum.clearButtonMode = UITextFieldViewModeAlways;
    newhoneNum.textColor = rgbColor(0x999999);
    newhoneNum.frame = CGRectMake(35, codeNum1.bottom + 20, kScreenWidth-70, textFieldH);
    newhoneNum.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [newhoneNum setClipsToBounds:YES];
    newhoneNum.layer.cornerRadius = newhoneNum.height/2.0;//设置矩形四个圆角半径
    newhoneNum.layer.borderWidth = 0.7;//边框宽度
    newhoneNum.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:newhoneNum];
    
    //2.1验证码
    codeNum2 = [[ZKLoginTextField alloc] init];
    codeNum2.placeholder = @"请输入验证码";
    codeNum2.clearButtonMode = UITextFieldViewModeAlways;
    codeNum2.textColor = rgbColor(0x999999);
    codeNum2.frame = CGRectMake(35, newhoneNum.bottom+20, kScreenWidth-70, textFieldH);
    codeNum2.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [codeNum2 setClipsToBounds:YES];
    codeNum2.layer.cornerRadius = codeNum2.height/2.0;//设置矩形四个圆角半径
    codeNum2.layer.borderWidth = 0.7;//边框宽度
    codeNum2.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:codeNum2];
    
    //2.2获取验证码
    verifyCodeBtn2 = [UIButton buttonWithType:UIButtonTypeCustom];
    verifyCodeBtn2.frame = CGRectMake(codeNum2.right-100, codeNum2.top+5, 95, codeNum2.height-10);
    [verifyCodeBtn2 setTitle:@"获取验证码(60s)" forState:UIControlStateNormal];
    [verifyCodeBtn2.titleLabel setFont:[UIFont systemFontOfSize:11]];
    
    //设置圆角
    [verifyCodeBtn2 setClipsToBounds:YES];
    verifyCodeBtn2.layer.cornerRadius = verifyCodeBtn2.height/2.0;//设置矩形四个圆角半径
    verifyCodeBtn2.layer.borderWidth = 0.7;//边框宽度
    verifyCodeBtn2.layer.borderColor = [UIColor clearColor].CGColor;
    verifyCodeBtn2.tag = 2;
    [verifyCodeBtn2 setBackgroundImage:[UIImage createImageWithColor:rgbColor(0x38ace5)] forState:UIControlStateNormal];
    [verifyCodeBtn2 setBackgroundImage:[UIImage createImageWithColor:[UIColor grayColor]] forState:UIControlStateDisabled];
    [verifyCodeBtn2 setBackgroundImage:[UIImage createImageWithColor:rgbColor(0x38ace5)] forState:UIControlStateHighlighted];
    
    [verifyCodeBtn2 addTarget:self action:@selector(getVerifyCodeClick:) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:verifyCodeBtn2];

    
    //确认修改
    UIButton *alterBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [alterBtn setTitle:@"确认修改" forState:UIControlStateNormal];
    [alterBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    alterBtn.titleLabel.font = [UIFont systemFontOfSize:14];
    [alterBtn addTarget:self action:@selector(alterBtnClick) forControlEvents:UIControlEventTouchUpInside];
    alterBtn.frame = CGRectMake(35, codeNum2.bottom + 100,kScreenWidth - 70, 40);
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
}

/**
 *  获取验证码
 */
-(void)getVerifyCodeClick:(UIButton *)btn{

    //去除空格
    NSString *phoneNumStr;
    if (btn.tag==1) {//获取旧手机的验证码
        phoneNumStr = [oldPhoneNum.text stringByTrimmingNbsp];
    }else{//获取新手机的验证码
        phoneNumStr = [newhoneNum.text stringByTrimmingNbsp];
        if ([[newhoneNum.text stringByTrimmingNbsp] isEqualToString:[oldPhoneNum.text stringByTrimmingNbsp]]) {
            [ProgressHUD showError:@"请输入新手机号码."];
            return ;
        }
    }
    
    
    if([phoneNumStr isValidPhoneNum]){
        if (btn.tag==1) {//获取旧手机的验证码
            verifyCodeBtn1.enabled = NO;
            [self startTime:btn.tag];
        }else{//获取新手机的验证码
            verifyCodeBtn2.enabled = NO;
            [self startTime:btn.tag];

        }

        if (self.iSverify) {
//            [YTNetworkRequest getVerifyCodeWithPhone:phoneNumStr withType:typeStr success:^(id result) {
//                NSDictionary *resultDic = (NSDictionary *)result;
//                NSLog(@"result=%@",resultDic);
//                
//            } failure:^(NSString *error) {
//                
//                NSLog(@"error=%@",error);
//            }];
        }
    }else {
        [ProgressHUD showError:@"请输入正确的手机号码."];
    }
    
}
/**
 *  倒计时
 */
-(void)startTime:(NSInteger) tagS{
    
    self.iSverify = YES;
    
    __block int timeout= 60; //倒计时时间
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_source_t _timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0,queue);
    dispatch_source_set_timer(_timer,dispatch_walltime(NULL, 0),1.0*NSEC_PER_SEC, 0); //每秒执行
    dispatch_source_set_event_handler(_timer, ^{
        if(timeout<=0){ //倒计时结束，关闭
            dispatch_source_cancel(_timer);
            dispatch_async(dispatch_get_main_queue(), ^{
                //设置界面的按钮显示 根据自己需求设置
                if (tagS == 1) {
                    [verifyCodeBtn1  setTitle:@"获取验证码" forState:UIControlStateNormal];
                    verifyCodeBtn1 .userInteractionEnabled = YES;
                    verifyCodeBtn1.enabled = YES;
                    self.iSverify = NO;
 
                }else if (tagS == 2){
                    [verifyCodeBtn2  setTitle:@"获取验证码" forState:UIControlStateNormal];
                    verifyCodeBtn2 .userInteractionEnabled = YES;
                    verifyCodeBtn2.enabled = YES;
                    self.iSverify = NO;
                    
                }
            });
        }else{
            int seconds = timeout % 120;
            NSString *strTime = [NSString stringWithFormat:@"%.2d", seconds];
            dispatch_async(dispatch_get_main_queue(), ^{
                //设置界面的按钮显示 根据自己需求设置
                if (tagS == 1) {
                    [verifyCodeBtn1 setTitle:[NSString stringWithFormat:@"%@秒",strTime] forState:UIControlStateNormal];
                    verifyCodeBtn1 .userInteractionEnabled = NO;

                }else if(tagS == 2){
                    [verifyCodeBtn2 setTitle:[NSString stringWithFormat:@"%@秒",strTime] forState:UIControlStateNormal];
                    verifyCodeBtn2 .userInteractionEnabled = NO;
                    
                }

                
            });
            timeout--;
            
        }
    });
    dispatch_resume(_timer);
    
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

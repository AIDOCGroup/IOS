//
//  RegOrForgotViewController.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "RegOrForgotViewController.h"
#import "ZKLoginTextField.h"
#import "UIImage+Category.h"
#import "ServiceProViewController.h"
@interface RegOrForgotViewController ()
{
    ZKLoginTextField *phoneNum;//手机号
    ZKLoginTextField *codeNum;//验证码
    UIButton *verifyCodeBtn;//获取验证码
    ZKLoginTextField *passWord;//密码
    ZKLoginTextField *rePassWord;//确认密码
    UIButton *regOrForgetBtn;
}
//是否点击验证码
@property (nonatomic,assign) BOOL iSverify;

@end

@implementation RegOrForgotViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    
    
    if (self.tag == 1) {
        //注册
        self.title = @"用户注册";
    }else if(self.tag == 2){
        //找回密码
        self.title = @"找回密码";
    
    }
    
    [self _initView];
    
}

-(void)_initView{
    
    CGFloat textFieldH = 40;

    //1.手机号
    phoneNum = [[ZKLoginTextField alloc] init];
    phoneNum.placeholder = @"请输入手机号";
    phoneNum.clearButtonMode = UITextFieldViewModeAlways;
    phoneNum.textColor = rgbColor(0x999999);
    phoneNum.frame = CGRectMake(35, 20, kScreenWidth-70, textFieldH);
    phoneNum.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [phoneNum setClipsToBounds:YES];
    phoneNum.layer.cornerRadius = phoneNum.height/2.0;//设置矩形四个圆角半径
    phoneNum.layer.borderWidth = 0.7;//边框宽度
    phoneNum.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:phoneNum];

    //2.1验证码
    codeNum = [[ZKLoginTextField alloc] init];
    codeNum.placeholder = @"请输入验证码";
    codeNum.clearButtonMode = UITextFieldViewModeAlways;
    codeNum.textColor = rgbColor(0x999999);
    codeNum.frame = CGRectMake(35, phoneNum.bottom+20, kScreenWidth-70, textFieldH);
    codeNum.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [codeNum setClipsToBounds:YES];
    codeNum.layer.cornerRadius = codeNum.height/2.0;//设置矩形四个圆角半径
    codeNum.layer.borderWidth = 0.7;//边框宽度
    codeNum.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [self.view addSubview:codeNum];
    
    //2.2获取验证码
    verifyCodeBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    verifyCodeBtn.frame = CGRectMake(codeNum.right-100, codeNum.top+5, 95, codeNum.height-10);
    [verifyCodeBtn setTitle:@"获取验证码(60s)" forState:UIControlStateNormal];
    [verifyCodeBtn.titleLabel setFont:[UIFont systemFontOfSize:11]];
    
    //设置圆角
    [verifyCodeBtn setClipsToBounds:YES];
    verifyCodeBtn.layer.cornerRadius = verifyCodeBtn.height/2.0;//设置矩形四个圆角半径
    verifyCodeBtn.layer.borderWidth = 0.7;//边框宽度
    verifyCodeBtn.layer.borderColor = [UIColor clearColor].CGColor;
    
    [verifyCodeBtn setBackgroundImage:[UIImage createImageWithColor:rgbColor(0x38ace5)] forState:UIControlStateNormal];
    [verifyCodeBtn setBackgroundImage:[UIImage createImageWithColor:[UIColor grayColor]] forState:UIControlStateDisabled];
    [verifyCodeBtn setBackgroundImage:[UIImage createImageWithColor:rgbColor(0x38ace5)] forState:UIControlStateHighlighted];
    
//    UIImage *loginImg = [UIImage imageName:@"getVerifyCode_icon" stretchableImageWithLeftCapWidth:5 topCapHeight:5];
//    [verifyCodeBtn setBackgroundImage:loginImg forState:UIControlStateNormal];
//    UIImage *highlightImg = [UIImage imageName:@"getVerifyCode_icon_highlight" stretchableImageWithLeftCapWidth:5 topCapHeight:5];
//    //禁用图片
//    UIImage *disabledImg = [UIImage imageName:@"getVerifyCode_icon_disabled" stretchableImageWithLeftCapWidth:5 topCapHeight:5];
//   
//    [verifyCodeBtn setBackgroundImage:disabledImg forState:UIControlStateDisabled];
//    [verifyCodeBtn setBackgroundImage:highlightImg forState:UIControlStateHighlighted];
    
    [verifyCodeBtn addTarget:self action:@selector(getVerifyCodeClick) forControlEvents:UIControlEventTouchUpInside];
    

    [self.view addSubview:verifyCodeBtn];


    //3密码
    passWord = [[ZKLoginTextField alloc] init];
    passWord.placeholder = @"请输入密码";
    passWord.clearButtonMode = UITextFieldViewModeAlways;
    passWord.textColor = rgbColor(0x999999);
    passWord.frame = CGRectMake(35, codeNum.bottom+20, kScreenWidth-70, textFieldH);
    passWord.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [passWord setClipsToBounds:YES];
    passWord.layer.cornerRadius = passWord.height/2.0;//设置矩形四个圆角半径
    passWord.layer.borderWidth = 0.7;//边框宽度
    passWord.layer.borderColor = [UIColor lightGrayColor].CGColor;
    
    [self.view addSubview:passWord];

    //4确认密码
    rePassWord = [[ZKLoginTextField alloc] init];
    rePassWord.placeholder = @"请确认密码";
    rePassWord.clearButtonMode = UITextFieldViewModeAlways;
    rePassWord.textColor = rgbColor(0x999999);
    rePassWord.frame = CGRectMake(35, passWord.bottom+20, kScreenWidth-70, textFieldH);
    rePassWord.font = [UIFont systemFontOfSize:12];
    //设置圆角
    [rePassWord setClipsToBounds:YES];
    rePassWord.layer.cornerRadius = rePassWord.height/2.0;//设置矩形四个圆角半径
    rePassWord.layer.borderWidth = 0.7;//边框宽度
    rePassWord.layer.borderColor = [UIColor lightGrayColor].CGColor;
   
    [self.view addSubview:rePassWord];
    
    
    //注册或找回密码按钮
    regOrForgetBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    
    if (self.tag==1) {
        //服务协议
        UIButton *serviceProBtn = [[UIButton alloc] initWithFrame:CGRectMake(20, rePassWord.bottom+20, kScreenWidth-20, 30)];
        [serviceProBtn setTitleColor:rgbColor(0x333333) forState:UIControlStateNormal];
        [serviceProBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
        [serviceProBtn addTarget:self action:@selector(serviceProBtnClick) forControlEvents:UIControlEventTouchUpInside];
        
        NSMutableAttributedString* regString = [[NSMutableAttributedString alloc] initWithString:@"注册表示用户阅读并同意《天医服务协议》"];
        
        //设置下划线...
        [regString addAttribute:NSUnderlineStyleAttributeName
                          value:@(NSUnderlineStyleSingle)
                          range:(NSRange){11,[regString length]-11}];
        //此时如果设置字体颜色要这样
        [regString addAttribute:NSForegroundColorAttributeName value:rgbColor(0x0699de)  range:NSMakeRange(11,[regString length]-11)];
        
        //设置下划线颜色...
        [regString addAttribute:NSUnderlineColorAttributeName value:rgbColor(0x0699de) range:(NSRange){11,[regString length]-11}];
        [serviceProBtn setAttributedTitle:regString forState:UIControlStateNormal];
        [self.view addSubview:serviceProBtn];

        
        regOrForgetBtn.frame = CGRectMake(20, serviceProBtn.bottom + 25,kScreenWidth - 40, 40);
        [regOrForgetBtn setTitle:@"确认注册" forState:UIControlStateNormal];
        
        //已有账号，去登录
        UIButton *goLoginBtn = [[UIButton alloc] initWithFrame:CGRectMake(kScreenWidth-180, regOrForgetBtn.bottom+20, 160, 30)];
        [goLoginBtn setTitleColor:rgbColor(0x333333) forState:UIControlStateNormal];
        [goLoginBtn.titleLabel setFont:[UIFont systemFontOfSize:14]];
        [goLoginBtn addTarget:self action:@selector(goLogin) forControlEvents:UIControlEventTouchUpInside];
        
        NSMutableAttributedString* goLogString = [[NSMutableAttributedString alloc] initWithString:@"已有账号，去登录>"];
        
        //设置下划线...
        [goLogString addAttribute:NSUnderlineStyleAttributeName
                          value:@(NSUnderlineStyleSingle)
                          range:(NSRange){6,[goLogString length]-6}];
        //此时如果设置字体颜色要这样
        [goLogString addAttribute:NSForegroundColorAttributeName value:rgbColor(0x0699de)  range:NSMakeRange(6,[goLogString length]-6)];
        
        //设置下划线颜色...
        [regString addAttribute:NSUnderlineColorAttributeName value:rgbColor(0x0699de) range:(NSRange){6,[goLogString length]-6}];
        [goLoginBtn setAttributedTitle:goLogString forState:UIControlStateNormal];
        [self.view addSubview:goLoginBtn];

        
    }else if (self.tag == 2){
    
        regOrForgetBtn.frame = CGRectMake(35, rePassWord.bottom + 50,kScreenWidth - 70, 40);
        [regOrForgetBtn setTitle:@"确认找回密码" forState:UIControlStateNormal];
    }
    regOrForgetBtn.tag = self.tag;
    [regOrForgetBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    regOrForgetBtn.titleLabel.font = [UIFont systemFontOfSize:14];
    [regOrForgetBtn addTarget:self action:@selector(btnClick) forControlEvents:UIControlEventTouchUpInside];
    regOrForgetBtn.backgroundColor = rgbColor(0x08a4d8);
    //设置圆角
    [regOrForgetBtn setClipsToBounds:YES];
    regOrForgetBtn.layer.cornerRadius = regOrForgetBtn.height/2.0;//设置矩形四个圆角半径
    regOrForgetBtn.layer.borderWidth = 0.7;//边框宽度
    regOrForgetBtn.layer.borderColor = [UIColor whiteColor].CGColor;
    [self.view addSubview:regOrForgetBtn];

    

}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/**
 *  获取验证码
 */
-(void)getVerifyCodeClick{
    NSString *typeStr = nil;
    if (self.tag==1) {//注册
        typeStr = @"0";
    }else{//忘记密码
        typeStr = @"1";
    }
    //去除空格
    NSString *phoneNumStr = [phoneNum.text stringByTrimmingNbsp];
    
    if([phoneNumStr isValidPhoneNum]){
        verifyCodeBtn.enabled = NO;
        [self startTime];
        if (self.iSverify) {
            [YTNetworkRequest getVerifyCodeWithPhone:phoneNumStr withType:typeStr success:^(id result) {
                NSDictionary *resultDic = (NSDictionary *)result;
                NSLog(@"result=%@",resultDic);
                
            } failure:^(NSString *error) {
                
                NSLog(@"error=%@",error);
            }];
        }
    }else {
        [ProgressHUD showError:@"请输入正确的手机号码."];
    }
    
}
/**
 *  倒计时
 */
-(void)startTime{
    
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
                [verifyCodeBtn  setTitle:@"获取验证码" forState:UIControlStateNormal];
                verifyCodeBtn .userInteractionEnabled = YES;
                verifyCodeBtn.enabled = YES;
                self.iSverify = NO;
            });
        }else{
            int seconds = timeout % 120;
            NSString *strTime = [NSString stringWithFormat:@"%.2d", seconds];
            dispatch_async(dispatch_get_main_queue(), ^{
                //设置界面的按钮显示 根据自己需求设置
                [verifyCodeBtn setTitle:[NSString stringWithFormat:@"%@秒",strTime] forState:UIControlStateNormal];
                verifyCodeBtn .userInteractionEnabled = NO;
            });
            timeout--;
            
        }
    });
    dispatch_resume(_timer);
    
}


/**
 *  天医服务协议
 */

- (void)serviceProBtnClick{
    ServiceProViewController *serviceVC = [[ServiceProViewController alloc] init];
    [self.navigationController pushViewController:serviceVC animated:YES];
}

- (void)btnClick{
    //去除空格
    NSString *phoneNumStr = [phoneNum.text stringByTrimmingNbsp];
    if (![passWord.text isEqualToString:rePassWord.text]) {
        [ProgressHUD showError:@"两次密码不一致"];
    }else if([codeNum.text isEqualToString:@""]){
        [ProgressHUD showError:@"未输入验证码"];
    }else{
        if (self.tag==1) {
            //注册
            
            [YTNetworkRequest registerWithPhone:phoneNumStr withPassword:passWord.text withPhoneVerify:codeNum.text success:^(id result) {
                
                [ProgressHUD showSuccess:@"注册成功"];
                
            } failure:^(NSString *error) {
                
                [ProgressHUD showError:error];
                
            }];
            
            
            
            
            
        }else if(self.tag ==2){
            //重置／找回密码，
            [YTNetworkRequest resetPasswordWithPhone:phoneNumStr withPassword:passWord.text withPhoneVerify:codeNum.text success:^(id result) {
                
                 [ProgressHUD showSuccess:@"密码修改成功成功"];
                
            } failure:^(NSString *error) {
                [ProgressHUD showError:error];
            }];
        }
    }
}

//已有账号，去登录
- (void)goLogin{
   [self.navigationController popViewControllerAnimated:YES];
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

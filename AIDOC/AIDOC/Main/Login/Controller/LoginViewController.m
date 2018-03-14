//
//  LoginViewController.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "LoginViewController.h"
#import "UIAlertTool.h"
#import "ZKLoginTextField.h"
#import "MBProgressHUD.h"
#import "RegOrForgotViewController.h"
#define LOGIN_BOX_H 350
@interface LoginViewController()
{
    UIScrollView *_scroView;
    UIAlertTool *alertTool;
    CAGradientLayer *_gradientLayer;
    RegOrForgotViewController *_regOrForgot;//注册或找回密码
}
/**
 *  用户名
 */
@property (nonatomic, weak) UITextField *userTextField;
/**
 *  密码
 */
@property (nonatomic, weak) UITextField *pwdTextField;
/**
 *  登陆按钮
 */
@property (nonatomic, weak) UIButton *loginBtn;
/**
 *  键盘是否弹出
 */
@property (nonatomic, assign) BOOL isTop;
/**
 *  loginBox
 */
@property (nonatomic, weak) UIView *loginBox;

@property (nonatomic, assign) float move;

@property (nonatomic, weak) UIImageView *logoView;

@property (nonatomic, assign) CGFloat loginBoxY;

@end


@implementation LoginViewController

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.navigationController.navigationBarHidden = YES;
    
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    _scroView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight+64+49)];
    [_scroView setContentSize:CGSizeMake(kScreenWidth, kScreenHeight+64+110)];
    [self.view addSubview:_scroView];
    _scroView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;

    
    [self _initView1];
    [self _initView2];
    [self _initView3];
    //读取账号
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSString *loginUser = [defaults valueForKey:@"loginUser"];
    
    self.userTextField.text = loginUser;
}

/**
 *  初始化_initView1
 */

- (void)_initView1{

    UIView *bgVIew = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth,400)];
    bgVIew.backgroundColor = rgbColor(0x0db2f6);
    [_scroView addSubview:bgVIew];
    
    //标题
    UILabel *titleLbl = [[UILabel alloc] initWithFrame:CGRectMake(0, 30, kScreenWidth, 30)];
    titleLbl.textAlignment = NSTextAlignmentCenter;
    titleLbl.text = @"天医 AIDOC 用户登录";
    titleLbl.textColor = [UIColor whiteColor];
    titleLbl.font = [UIFont boldSystemFontOfSize:18];
    [_scroView addSubview:titleLbl];
    
    //Logo
    UIImage *logoImg = [UIImage imageNamed:@"logo_@x2"];
    UIImageView *logoimgView = [[UIImageView alloc] initWithFrame:CGRectMake((kScreenWidth - logoImg.size.width)/2.0, titleLbl.bottom + 20, logoImg.size.width, logoImg.size.height)];
    logoimgView.image = logoImg;
    
    [_scroView addSubview:logoimgView];
    
    if (alertTool == nil) {
        alertTool = [[UIAlertTool alloc]init];
    }

}

/**
 *  初始化_initView2
 */
- (void)_initView2 {
    
    [self addNotifications];
    
    CGFloat textFieldH = 50;
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapClick)];
    [_scroView addGestureRecognizer:tap];
    
    UIImageView *logoView = [[UIImageView alloc] init];
    logoView.image = [UIImage imageNamed:@"wrsr"];
    
    CGFloat logoViewW = 120;
    CGFloat logoViewH = 120;
    CGFloat logoViewX = (kScreenWidth - logoViewW) / 2;
    CGFloat logoViewY = 70;
    logoView.frame = CGRectMake(logoViewX, logoViewY, logoViewW, logoViewH);
    self.logoView = logoView;
    [_scroView addSubview:logoView];
    
    //loginBox
    UIView *loginBox = [[UIView alloc] init];
    //登陆整个视图
    CGFloat boxMargin = 20;
    CGFloat loginBoxW = kScreenWidth - boxMargin * 2;
    CGFloat loginBoxH = LOGIN_BOX_H;
    CGFloat loginBoxX = boxMargin;
    CGFloat loginBoxY = self.logoView.bottom + 20 ;
    loginBox.frame = CGRectMake(loginBoxX, loginBoxY, loginBoxW, loginBoxH);
    loginBox.backgroundColor = [UIColor whiteColor];
    
    //设置圆角
    [loginBox setClipsToBounds:YES];
    loginBox.layer.cornerRadius = 8.0;//设置矩形四个圆角半径
    loginBox.layer.borderWidth = 1;//边框宽度
    loginBox.layer.borderColor = rgbColor(0xcccccc).CGColor;

    
    //登陆框背景
//    CGFloat inputH = 200;
//    UIImageView *loginImgBgView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, loginBoxW, inputH)];
//    UIImage *loginBoxImg = [UIImage imageNamed:@"login_edit_bg"];
//    loginImgBgView.image = loginBoxImg;
//    [loginBox addSubview:loginImgBgView];
    self.loginBox = loginBox;
    [_scroView addSubview:loginBox];
    
    //用户名
    ZKLoginTextField *userTextField = [[ZKLoginTextField alloc] init];
    userTextField.iconNmae = @"phone_icon_@x2";
    userTextField.placeholder = @"请输入用户名/手机号";
    userTextField.clearButtonMode = UITextFieldViewModeAlways;
    userTextField.textColor = rgbColor(0x999999);
    userTextField.font = [UIFont systemFontOfSize:12];
    userTextField.frame = CGRectMake(20, 20, loginBoxW - 40, textFieldH);
    
    //设置圆角
    [userTextField setClipsToBounds:YES];
    userTextField.layer.cornerRadius = userTextField.height/2.0;//设置矩形四个圆角半径
    userTextField.layer.borderWidth = 0.7;//边框宽度
    userTextField.layer.borderColor = [UIColor lightGrayColor].CGColor;
    self.userTextField = userTextField;
    [loginBox addSubview:userTextField];
    
    //密码
    ZKLoginTextField *pwdTextField = [[ZKLoginTextField alloc] init];
    pwdTextField.iconNmae = @"pw_icon_@x2";
    pwdTextField.placeholder = @"请输入密码";
    pwdTextField.secureTextEntry = YES;
    
    pwdTextField.clearButtonMode = UITextFieldViewModeAlways;
    pwdTextField.textColor = rgbColor(0x999999);
    pwdTextField.hideBorder = YES;
    pwdTextField.font = [UIFont systemFontOfSize:12];
    pwdTextField.frame = CGRectMake(20, CGRectGetMaxY(userTextField.frame) + 22, loginBoxW - 40, textFieldH);
    
    //设置圆角
    [pwdTextField setClipsToBounds:YES];
    pwdTextField.layer.cornerRadius = userTextField.height/2.0;//设置矩形四个圆角半径
    pwdTextField.layer.borderWidth = 0.7;//边框宽度
    pwdTextField.layer.borderColor = [UIColor lightGrayColor].CGColor;
    
    self.pwdTextField = pwdTextField;
    [loginBox addSubview:pwdTextField];
    
    //忘记密码按钮
    UIButton *forgotBtn = [[UIButton alloc] init];
    forgotBtn.tag = 2;
    [forgotBtn setTitleColor:rgbColor(0x666) forState:UIControlStateNormal];
    [forgotBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
    [forgotBtn addTarget:self action:@selector(regOrForgotClick:) forControlEvents:UIControlEventTouchUpInside];
    forgotBtn.frame = CGRectMake(loginBox.width - 100, CGRectGetMaxY(pwdTextField.frame) + 16,  80, 30);
    forgotBtn.titleLabel.textAlignment = NSTextAlignmentRight;
    
    
    NSMutableAttributedString* tncString = [[NSMutableAttributedString alloc] initWithString:@"忘记密码 ?"];
    //设置下划线...
    /*
     NSUnderlineStyleNone                                    = 0x00, 无下划线
     NSUnderlineStyleSingle                                  = 0x01, 单行下划线
     NSUnderlineStyleThick NS_ENUM_AVAILABLE(10_0, 7_0)      = 0x02, 粗的下划线
     NSUnderlineStyleDouble NS_ENUM_AVAILABLE(10_0, 7_0)     = 0x09, 双下划线
     */
    [tncString addAttribute:NSUnderlineStyleAttributeName
                      value:@(NSUnderlineStyleSingle)
                      range:(NSRange){0,[tncString length]-2}];
    //此时如果设置字体颜色要这样
    [tncString addAttribute:NSForegroundColorAttributeName value:[UIColor grayColor]  range:NSMakeRange(0,[tncString length]-2)];
    
    //设置下划线颜色...
    [tncString addAttribute:NSUnderlineColorAttributeName value:[UIColor grayColor] range:(NSRange){0,[tncString length]-2}];
    [forgotBtn setAttributedTitle:tncString forState:UIControlStateNormal];
    [loginBox addSubview:forgotBtn];

    
    //登陆按钮
    UIButton *loginBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [loginBtn setTitle:@"账号登录" forState:UIControlStateNormal];
    [loginBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    loginBtn.titleLabel.font = [UIFont systemFontOfSize:14];
    [loginBtn addTarget:self action:@selector(loginClick) forControlEvents:UIControlEventTouchUpInside];
    loginBtn.frame = CGRectMake(20, CGRectGetMaxY(forgotBtn.frame) + 22,loginBoxW - 40, 40);
    loginBtn.backgroundColor = rgbColor(0x08a4d8);

    //设置圆角
    [loginBtn setClipsToBounds:YES];
    loginBtn.layer.cornerRadius = loginBtn.height/2.0;//设置矩形四个圆角半径
    loginBtn.layer.borderWidth = 1.0;//边框宽度
    loginBtn.layer.borderColor = [UIColor whiteColor].CGColor;
    self.loginBtn = loginBtn;
    
    [loginBox addSubview:loginBtn];
    
    //或
    UILabel *huolabel = [[UILabel alloc] initWithFrame:CGRectMake(0,  CGRectGetMaxY(loginBtn.frame) + 10, loginBoxW, 20)];
    huolabel.text = @"或";
    huolabel.textAlignment = NSTextAlignmentCenter;
    huolabel.textColor = rgbColor(0x666);
    huolabel.font = [UIFont systemFontOfSize:14];
    
    [loginBox addSubview:huolabel];
    
    
    //验证码按钮
    UIButton *codeBtn = [[UIButton alloc] init];
    [codeBtn setTintColor:[UIColor whiteColor]];
    [codeBtn setTitle:@"验证码登录" forState:UIControlStateNormal];
    [codeBtn setTitleColor:rgbColor(0x08a4d8) forState:UIControlStateNormal];
    [codeBtn.titleLabel setFont:[UIFont systemFontOfSize:14]];
    [codeBtn addTarget:self action:@selector(codeBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    codeBtn.frame = CGRectMake(20, CGRectGetMaxY(huolabel.frame) + 10, loginBoxW - 40, 40);
    
    //设置圆角
    codeBtn.backgroundColor = [UIColor whiteColor];
    [codeBtn setClipsToBounds:YES];
    codeBtn.layer.cornerRadius = loginBtn.height/2.0;//设置矩形四个圆角半径
    codeBtn.layer.borderWidth = 1.0;//边框宽度
    codeBtn.layer.borderColor = rgbColor(0x08a4d8).CGColor;

    [loginBox addSubview:codeBtn];

    
    
}


/**
 *  初始化_initView3
 */

- (void)_initView3{
    UILabel *otherLbl = [[UILabel alloc] initWithFrame:CGRectMake(0, self.loginBox.bottom + 20, kScreenWidth, 30)];
    otherLbl.textAlignment = NSTextAlignmentCenter;
    otherLbl.text = @"其他方式快捷登录";
    otherLbl.textColor = rgbColor(0x999999);
    otherLbl.font = [UIFont systemFontOfSize:12];
    [_scroView addSubview:otherLbl];
    
    //QQ 新浪微博 微信 淘宝 支付宝
    
    UIView *bgView = [[UIView alloc] initWithFrame:CGRectMake(20, otherLbl.bottom + 20, kScreenWidth - 40, 40)];
    bgView.backgroundColor = [UIColor redColor];
    [_scroView addSubview:bgView];
    
    
    
    
    //注册按钮
    UIButton *regBtn = [[UIButton alloc] init];
    regBtn.tag = 1;
    [regBtn setTintColor:[UIColor whiteColor]];
    
    [regBtn.titleLabel setFont:[UIFont systemFontOfSize:18]];
    [regBtn addTarget:self action:@selector(regOrForgotClick:) forControlEvents:UIControlEventTouchUpInside];
    regBtn.frame = CGRectMake(0, bgView.bottom + 20, kScreenWidth, 30);
    
    NSMutableAttributedString* regString = [[NSMutableAttributedString alloc] initWithString:@"没有账号？立刻免费注册天医账号"];
    
    //设置下划线...
    /*
     NSUnderlineStyleNone                                    = 0x00, 无下划线
     NSUnderlineStyleSingle                                  = 0x01, 单行下划线
     NSUnderlineStyleThick NS_ENUM_AVAILABLE(10_0, 7_0)      = 0x02, 粗的下划线
     NSUnderlineStyleDouble NS_ENUM_AVAILABLE(10_0, 7_0)     = 0x09, 双下划线
     */
    [regString addAttribute:NSUnderlineStyleAttributeName
                      value:@(NSUnderlineStyleSingle)
                      range:(NSRange){7,[regString length]-7}];
    //此时如果设置字体颜色要这样
    [regString addAttribute:NSForegroundColorAttributeName value:rgbColor(0x08a4d8) range:NSMakeRange(7,[regString length]-7)];
    
    //设置下划线颜色...
    [regString addAttribute:NSUnderlineColorAttributeName value:rgbColor(0x08a4d8) range:(NSRange){7,[regString length]-7}];
    [regBtn setAttributedTitle:regString forState:UIControlStateNormal];
    [_scroView addSubview:regBtn];

}

//监听键盘
- (void)addNotifications
{
    /// 监听键盘事件
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onKeyboardWillShowNotification:) name:UIKeyboardWillChangeFrameNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onKeyboardWillHideNotification:) name:UIKeyboardWillHideNotification object:nil];
}

/**
 *  登陆事件
 */
- (void)loginClick
{
    [[NSNotificationCenter defaultCenter] postNotificationName:KNOTIFICATION_LOGINCHANGE object:@"YES"];
    
}


/**
 * 注册 Or 忘记密码?
 */
- (void)regOrForgotClick:(UIButton *)sender {
    
    _regOrForgot = [[RegOrForgotViewController alloc] init];
    _regOrForgot.tag = sender.tag;
    [self.navigationController pushViewController:_regOrForgot animated:NO];
}



/**
 *  验证码登录
 */
- (void)codeBtnClick:(UIButton *)sender {
    
    
}



- (void)tapClick {
    [self.userTextField resignFirstResponder];
    [self.pwdTextField resignFirstResponder];
}


#pragma mark - notifications
static NSValue *sOldCenter = nil;

- (void)onKeyboardWillShowNotification:(NSNotification *)aNote
{
    
    if (sOldCenter == nil) {
        sOldCenter = [NSValue valueWithCGPoint:self.loginBox.center];
    }
    
    CGRect keyboardFrame = [aNote.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    
    CGFloat y = self.view.frame.size.height - keyboardFrame.size.height;
    
    CGPoint toPoint = CGPointMake(self.view.center.x, y - self.loginBox.size.height/2.0);
    
    [UIView animateWithDuration:.25 delay:.25 options:UIViewAnimationOptionOverrideInheritedOptions animations:^{
        
        if (IS_IPHONE_6_OR_LESS) {
            self.logoView.hidden = YES;
            [self.loginBox setCenter:toPoint];
            
        }
        
    } completion:^(BOOL finished) {
        
    }];
    
}

- (void)onKeyboardWillHideNotification:(NSNotification *)aNote
{
    if (sOldCenter) {
        if (IS_IPHONE_6_OR_LESS) {
            [UIView animateWithDuration:0.25f animations:^{
                self.logoView.hidden = NO;
                [self.loginBox setCenter:sOldCenter.CGPointValue];
            }];
        }
        
    }
}

#pragma mark - UITextFieldDelegate
- (BOOL)textViewShouldBeginEditing:(UITextView *)textView
{
    return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}


-(void)dealloc
{
    
    [[NSNotificationCenter defaultCenter]  removeObserver:self name:UIKeyboardWillChangeFrameNotification object:nil];
    [[NSNotificationCenter defaultCenter]  removeObserver:self name:UIKeyboardWillHideNotification object:nil];
}

//- (NSString *)md5:(NSString *)str{
//    const char *cStr = [str UTF8String];
//    unsigned char result[16];
//    CC_MD5(cStr, strlen(cStr), result); // This is the md5 call
//    return [NSString stringWithFormat:
//            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
//            result[0], result[1], result[2], result[3],
//            result[4], result[5], result[6], result[7],
//            result[8], result[9], result[10], result[11],
//            result[12], result[13], result[14], result[15]
//            ];
//    //    return [hash lowercaseString];
//
//}



@end

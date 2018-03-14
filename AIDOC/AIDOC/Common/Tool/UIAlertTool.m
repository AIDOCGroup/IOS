//
//  UIAlertTool.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#define IAIOS8 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define SMSTIMEOUT 119
#import "UIAlertTool.h"
#import "CodeTextField.h"
#import "NSString+Extension.h"
#import "AppDelegate.h"
typedef void (^confirm)();
typedef void (^cancle)();
@interface UIAlertTool(){
    confirm confirmParam;
    cancle  cancleParam;
    int seconds;
    NSString *hintTxt;
    CodeTextField *codeTextField;
    UIView *parentView; //自定义框主容器
    
    UIView *parentViewOne;
    
    NSTimer *timer;
    
    UIButton *shareButton; //自定义框确定按钮
    
    UIButton *closeButton;  //自定义框取消按钮
    
    UILabel *hintLable;
    
}
@property(nonatomic ,strong)void (^codeConfirm)(NSString *code) ;
@end
@implementation UIAlertTool



//singleton_implementation(UIAlertTool);

+(instancetype)allocWithZone:(NSZone *)zone{
    return [super allocWithZone:zone];
}


#pragma mark 隐藏对话框
-(void)hideDialog:(UITapGestureRecognizer *)tapGestureRecognizer{
    CGPoint location= [tapGestureRecognizer locationInView:[parentView viewWithTag:111]];
    if(location.y<0||location.y>[parentView viewWithTag:111].height){
        [self closeAlertView];
        
    }
}


#pragma mark 显示地图弹出框
-(void)showMapAlertView:(NSString *)title :(NSString *)desc :(NSString *)buttonLeftTitle :(NSString *)buttonRightTitle :(void (^)())confirm :(void (^)())cancle{
    
    CGSize descSize= [desc sizeWithFont:[UIFont fontWithName:KFont size:15] maxW:kScreenWidth-25-30];
    
    if(parentView){
        [self closeAlertView];
    }
    
    confirmParam=confirm;
    cancleParam=cancle;
    UIWindow *keyWindow = [[UIApplication sharedApplication] keyWindow];
    parentView=[[UIView alloc] initWithFrame:keyWindow.bounds];
    parentView.backgroundColor=[UIColor clearColor];
    parentView.userInteractionEnabled=YES;
    [parentView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hideDialog:)]];
    [keyWindow addSubview:parentView];
    
    
    //主容器
    UIView *alertView=[[UIView alloc] init];
    alertView.tag=111;
    alertView.bounds=CGRectMake(0, 0, kScreenWidth-25,  descSize.height+45+20+40+40+30+5);
    alertView.center=parentView.center;
    alertView.backgroundColor=RGBACOLOR(255, 255, 255, .8);
    //    alertView.layer.shadowColor = [UIColor blackColor].CGColor;//阴影颜色
    //    alertView.layer.shadowOpacity = 0.4;
    //    alertView.layer.shadowOffset = CGSizeMake(-5, 3);//偏移距离
    [parentView addSubview:alertView];
    
    UIView *squareLine=[[UIView alloc] initWithFrame:CGRectMake(5, 5, alertView.width-10, alertView.height-10)];
    squareLine.layer.borderColor=[RGBACOLOR(180, 180, 180, .9) CGColor];
    squareLine.layer.borderWidth=.5;
    [alertView addSubview:squareLine];
    
    //标题
    UILabel *titleLabel=[[UILabel alloc] initWithFrame:CGRectMake(0, 45, alertView.width, 20)];
    titleLabel.font=[UIFont fontWithName:KFont size:22];
    titleLabel.textColor=RGBACOLOR(142, 120, 122, 1);
    titleLabel.numberOfLines=0;
    titleLabel.textAlignment=NSTextAlignmentCenter;
    titleLabel.text=[NSString stringWithFormat:@"%@%@",@"",title];
    [alertView addSubview:titleLabel];
    
    //标题分割线
    UIView *titleLineView=[[UIView alloc] initWithFrame:CGRectMake(0, titleLabel.bottom,alertView.width , 0)];
    titleLineView.backgroundColor=RGBACOLOR(255, 255, 255, 1);
    [alertView addSubview:titleLineView];
    
    
    //描述
    
    
    UIView *descView=[[UIView alloc] initWithFrame:CGRectMake(0, titleLineView.bottom+40, alertView.width, descSize.height)];
    [alertView addSubview:descView];
    
    
    UILabel *descLabel=[[UILabel alloc] initWithFrame:CGRectMake(15, 0, alertView.width-30,descView.height)];
    descLabel.font=[UIFont fontWithName:KFont size:15];
    descLabel.numberOfLines=0;
    descLabel.textColor=RGBACOLOR(142, 120, 122, 1);
    descLabel.textAlignment=NSTextAlignmentCenter;
    descLabel.text=desc;
    [descView addSubview:descLabel];
    
    //分割线
    UIView *lineView=[[UIView alloc] initWithFrame:CGRectMake(0, descView.bottom,alertView.width , 0)];
    lineView.backgroundColor=RGBACOLOR(255, 255, 255, 1);
    [alertView addSubview:lineView];
    if (buttonLeftTitle&&buttonRightTitle) {
        //取消
        // UIImage *closeIMG=[UIImage imageNamed:@"bg_close_share"];
        closeButton=[[UIButton alloc] initWithFrame:CGRectMake(0, alertView.height-40, alertView.width/2, 40)];
        //    [closeButton setImage:closeIMG forState:UIControlStateNormal];
        closeButton.titleLabel.font = [UIFont fontWithName:KFont size:16];
        if ([title rangeOfString:@"未解锁"].location!=NSNotFound) {
            [closeButton setTitleColor:RGBACOLOR(220, 220, 220, 1) forState:UIControlStateNormal];
        }
        else{
            [closeButton setTitleColor:RGBACOLOR(142, 120, 122, 1) forState:UIControlStateNormal];
            [closeButton addTarget:self action:@selector(doStay) forControlEvents:UIControlEventTouchUpInside];
        }
        closeButton.contentVerticalAlignment=UIControlContentVerticalAlignmentTop;
        [closeButton setTitle:buttonLeftTitle forState:UIControlStateNormal];
        closeButton.userInteractionEnabled=YES;
        [alertView addSubview:closeButton];
        
        //确定按钮
        shareButton=[[UIButton alloc] initWithFrame:CGRectMake(closeButton.right, alertView.height-40, alertView.width/2, 40)];
        shareButton.titleLabel.font = [UIFont fontWithName:KFont size:16];
        shareButton.contentVerticalAlignment=UIControlContentVerticalAlignmentTop;
        [shareButton setTitleColor:RGBACOLOR(142, 120, 122, 1) forState:UIControlStateNormal];
        [shareButton setTitle:buttonRightTitle forState:UIControlStateNormal];
        shareButton.userInteractionEnabled=YES;
        [alertView addSubview:shareButton];
        
        [shareButton addTarget:self action:@selector(doView) forControlEvents:UIControlEventTouchUpInside];
        
    }
    
}

-(void)doStay{
    [self closeAlertView];
    confirmParam();
}

-(void)doView{
    [self closeAlertView];
    cancleParam();
}

#pragma mark 初始化自定义框
-(void)initCustomerAlertView:(NSString *)title :(NSString *)desc :(void (^)())confirm{
    confirmParam=confirm;
    UIWindow *keyWindow = [[UIApplication sharedApplication] keyWindow];
    parentView=[[UIView alloc] initWithFrame:keyWindow.bounds];
    parentView.backgroundColor=RGBACOLOR(30, 30, 30, .4);
    parentView.userInteractionEnabled=YES;
    [keyWindow addSubview:parentView];
    
    //主容器
    UIView *alertView=[[UIView alloc] init];
    alertView.bounds=CGRectMake(0, 0, 255, 160);
    alertView.center=parentView.center;
    alertView.layer.masksToBounds=YES;
    alertView.layer.cornerRadius=10;
    alertView.backgroundColor=[UIColor whiteColor];
    [parentView addSubview:alertView];
    
    //标题
    UILabel *titleLabel=[[UILabel alloc] initWithFrame:CGRectMake(0, 15, 255, 20)];
    titleLabel.font=[UIFont fontWithName:KFont size:17];
    titleLabel.textColor=[UIColor blackColor];
    titleLabel.textAlignment=NSTextAlignmentCenter;
    titleLabel.text=title;
    [alertView addSubview:titleLabel];
    //描述
    UILabel *descLabel=[[UILabel alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(titleLabel.frame)+5, 255, 30)];
    descLabel.font=[UIFont fontWithName:KFont size:15];
    descLabel.textColor=RGBACOLOR(51, 51, 51, 1);
    descLabel.textAlignment=NSTextAlignmentCenter;
    descLabel.text=desc;
    [alertView addSubview:descLabel];
    
    
    //分割线
    UIView *lineView=[[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(descLabel.frame)+20,255 , .8)];
    lineView.backgroundColor=RGBACOLOR(200, 200, 200, .7);
    [alertView addSubview:lineView];
    
    
    //取消
    //    UIImage *closeIMG=[UIImage imageNamed:@"bg_close_share"];
    closeButton=[[UIButton alloc] initWithFrame:CGRectMake(21, CGRectGetMaxY(lineView.frame)+15, 95.5, 34.5)];
    //    [closeButton setImage:closeIMG forState:UIControlStateNormal];
    closeButton.titleLabel.font = [UIFont fontWithName:KFont size:15];
    [closeButton setTitleColor:TotolColor forState:UIControlStateNormal];
    [closeButton setTitle:@"取消" forState:UIControlStateNormal];
    closeButton.backgroundColor=[UIColor whiteColor];
    closeButton.layer.masksToBounds=YES;
    closeButton.userInteractionEnabled=YES;
    closeButton.layer.cornerRadius=18;
    closeButton.layer.borderWidth = 1;
    closeButton.layer.borderColor = [TotolColor CGColor];
    
    [alertView addSubview:closeButton];
    
    //确定按钮
    shareButton=[[UIButton alloc] initWithFrame:CGRectMake(closeButton.right+22, CGRectGetMaxY(lineView.frame)+15, 95.5, 34.5)];
    shareButton.titleLabel.font = [UIFont fontWithName:KFont size:15];
    [shareButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [shareButton setTitle:@"确定" forState:UIControlStateNormal];
    shareButton.backgroundColor=TotolColor;
    shareButton.layer.masksToBounds=YES;
    shareButton.userInteractionEnabled=YES;
    shareButton.layer.cornerRadius=18;
    [alertView addSubview:shareButton];
    
    [shareButton addTarget:self action:@selector(doConfirm) forControlEvents:UIControlEventTouchUpInside];
    
    [closeButton addTarget:self action:@selector(doCancel) forControlEvents:UIControlEventTouchUpInside];
    
}

-(void)showShareAlertView :(NSString *)title :(NSString *)desc :(void (^)())confirm{
    
    [self initCustomerAlertView:title :desc :confirm];
    [shareButton setTitle:@"去分享" forState:UIControlStateNormal];
    
}


#pragma mark 关闭弹框
-(void)closeAlertView{
    [parentView removeFromSuperview];
    parentView=nil;
}


#pragma mark 取消
-(void)doCancel{
    if (timer) {
        [timer invalidate];
        timer=nil;
    }
    
    [self closeAlertView];
}

#pragma mark 确定
-(void)doConfirm{
    [self closeAlertView];
    confirmParam();
}

-(void)dosend{
    [parentViewOne removeFromSuperview];
    parentViewOne=nil;
    confirmParam();
}
-(void)dobuy{
    [parentViewOne removeFromSuperview];
    parentViewOne=nil;
    confirmParam();
}

-(void)closeSend{
    [parentViewOne removeFromSuperview];
    parentViewOne=nil;
}

-(void)showAlertView:(UIViewController *)viewController :(NSString *)title :(NSString *)message :(NSString *)cancelButtonTitle :(NSString *)otherButtonTitle :(void (^)())confirm :(void (^)())cancle{
    confirmParam=confirm;
    cancleParam=cancle;
    if (IAIOS8) {
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
        
        if (cancelButtonTitle.length > 0) {
            UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:cancelButtonTitle style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
                cancle();
            }];
            [alertController addAction:cancelAction];
        }
        // Create the actions.
        if (otherButtonTitle.length > 0) {
            UIAlertAction *otherAction = [UIAlertAction actionWithTitle:otherButtonTitle style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
                confirm();
            }];
            [alertController addAction:otherAction];
            
        }
        
        
        [viewController presentViewController:alertController animated:YES completion:nil];
        
    }
    else{
        UIAlertView *TitleAlert = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:otherButtonTitle otherButtonTitles:cancelButtonTitle,nil];
        [TitleAlert show];
    }
    
}
-(void)showAlertViewOne:(NSString *)title :(NSString *)desc :(void (^)())confirm{
    confirmParam=confirm;
    UIWindow *keyWindow = [[UIApplication sharedApplication] keyWindow];
    parentViewOne=[[UIView alloc] initWithFrame:keyWindow.bounds];
    parentViewOne.backgroundColor=RGBACOLOR(99, 99, 99, .2);
    parentViewOne.userInteractionEnabled=YES;
    [keyWindow addSubview:parentViewOne];
    
    
    //主容器
    UIView *alertView=[[UIView alloc] init];
    alertView.bounds=CGRectMake(0, 0, 255, 205);
    alertView.center=parentViewOne.center;
    alertView.layer.masksToBounds=YES;
    alertView.layer.cornerRadius=20;
    alertView.backgroundColor=[UIColor whiteColor];
    [parentViewOne addSubview:alertView];
    
    //标题
    UILabel *titleLabel=[[UILabel alloc] initWithFrame:CGRectMake(0, 20, 255, 30)];
    titleLabel.font=[UIFont fontWithName:KFont size:15];
    titleLabel.textColor=[UIColor blackColor];
    titleLabel.textAlignment=NSTextAlignmentCenter;
    titleLabel.text=title;
    [alertView addSubview:titleLabel];
    
    //描述
    UILabel *descLabel=[[UILabel alloc] initWithFrame:CGRectMake(5, CGRectGetMaxY(titleLabel.frame)+10, 245, 40)];
    descLabel.font=[UIFont fontWithName:KFont size:12];
    descLabel.textColor=RGBACOLOR(51, 51, 51, 1);
    descLabel.textAlignment=NSTextAlignmentCenter;
    descLabel.text=desc;
    descLabel.numberOfLines = 0;
    [alertView addSubview:descLabel];
    
    //    //发布图片
    //    UIButton *sendButton=[[UIButton alloc] initWithFrame:CGRectMake(5, CGRectGetMaxY(descLabel.frame)+15, alertView.width/2 - 10, 34.5)];
    //    [sendButton setTitle:@"去发图" forState:UIControlStateNormal];
    //    sendButton.backgroundColor=RGBACOLOR(255, 108, 92, 1);
    //    sendButton.layer.masksToBounds=YES;
    //    sendButton.userInteractionEnabled=YES;
    //
    //    [sendButton addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dosend)]];
    //    sendButton.layer.cornerRadius=5;
    //    [alertView addSubview:sendButton];
    //
    //    //分割线
    //    UIView *lineView1=[[UIView alloc] initWithFrame:CGRectMake(parentViewOne.width/2,CGRectGetMaxY(descLabel.frame)+20,1 , 34.5)];
    //    lineView1.backgroundColor=RGBACOLOR(120, 120, 120, .7);
    //    [alertView addSubview:lineView1];
    
    //去充值
    UIButton *buyMoneyButton=[[UIButton alloc] initWithFrame:CGRectMake((255-159)/2, CGRectGetMaxY(descLabel.frame)+15, 159, 34.5)];
    [buyMoneyButton setTitle:@"买糖币" forState:UIControlStateNormal];
    buyMoneyButton.titleLabel.font = [UIFont systemFontOfSize:15];
    buyMoneyButton.backgroundColor=RGBACOLOR(255, 150, 0, 1);
    buyMoneyButton.layer.masksToBounds=YES;
    buyMoneyButton.userInteractionEnabled=YES;
    
    [buyMoneyButton addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dobuy)]];
    buyMoneyButton.layer.cornerRadius=5;
    [alertView addSubview:buyMoneyButton];
    
    
    //分割线
    UIView *lineView=[[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(buyMoneyButton.frame)+17,255 , .8)];
    lineView.backgroundColor=RGBACOLOR(120, 120, 120, .7);
    [alertView addSubview:lineView];
    
    //关闭
    UIImage *closeIMG=[UIImage imageNamed:@"bg_close_share"];
    UIButton *closeButton1=[[UIButton alloc] initWithFrame:CGRectMake(255-closeIMG.size.width/2-10, CGRectGetMaxY(lineView.frame)+5, closeIMG.size.width/2, closeIMG.size.height/2)];
    [closeButton1 setImage:closeIMG forState:UIControlStateNormal];
    [closeButton1 addTarget:self action:@selector(closeSend) forControlEvents:UIControlEventTouchUpInside];
    [alertView addSubview:closeButton1];
    
}
-(void)showAlertViewOne:(UIViewController *)viewController :(NSString *)title :(NSString *)message :(NSString *)cancelButtonTitle :(NSString *)otherButtonTitle :(void (^)())confirm :(void (^)())cancle;
{
    confirmParam=confirm;
    cancleParam=cancle;
    if (IAIOS8) {
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
        
        if (cancelButtonTitle.length > 0) {
            UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:cancelButtonTitle style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
                cancle();
                
            }];
            [alertController addAction:cancelAction];
        }
        // Create the actions.
        if (otherButtonTitle.length > 0) {
            UIAlertAction *otherAction = [UIAlertAction actionWithTitle:otherButtonTitle style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
                confirm();
            }];
            [alertController addAction:otherAction];
            
        }
        
        
        [viewController presentViewController:alertController animated:YES completion:nil];
        
    }
    else{
        UIAlertView *TitleAlert = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:otherButtonTitle otherButtonTitles:cancelButtonTitle,nil];
        [TitleAlert show];
    }
    
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{
    if (buttonIndex==0) {
        confirmParam();
    }
    else{
        cancleParam();
    }
}

- (void)willPresentAlertView:(UIAlertView *)alertView
{
    for (UIView *tempView in alertView.subviews) {
        
        if ([tempView isKindOfClass:[UILabel class]]) {
            // 当该控件为一个 UILabel 时
            UILabel *tempLabel = (UILabel *) tempView;
            
            if ([tempLabel.text isEqualToString:alertView.title]) {
                // 调整对齐方式
                tempLabel.textAlignment = NSTextAlignmentLeft;
                // 调整字体大小
                [tempLabel setFont:[UIFont systemFontOfSize:20]];
            }
        }else if ([tempView isKindOfClass:[UIButton class]])
        {
            UIButton *tempBtn = (UIButton *)tempView;
            [tempBtn setTitleColor:[UIColor grayColor] forState:UIControlStateNormal];
        }
    }
}
#pragma mark 显示对话框
-(void)showHtmlDialog:(NSString *)title :(NSString *)desc :(NSString *)confirmTitle :(NSString *)jsFunction :(void (^)())confirm{
    if (parentView) {
        [parentView removeFromSuperview];
        parentView=nil;
    }
    [self initCustomerAlertView:title :desc :confirm];
    [shareButton setTitle:confirmTitle forState:UIControlStateNormal];
}




-(void)showPaySecretView:(NSString *)title :(NSString *)money :(NSString *)hint :(void (^)(NSString *code))confirm{
    if (parentView) {
        [parentView removeFromSuperview];
        parentView=nil;
    }
    self.codeConfirm=confirm;
    hintTxt=hint;
    seconds=SMSTIMEOUT;
    UIWindow *keyWindow = [[UIApplication sharedApplication] keyWindow];
    parentView=[[UIView alloc] initWithFrame:keyWindow.bounds];
    parentView.backgroundColor=RGBACOLOR(30, 30, 30, .4);
    parentView.userInteractionEnabled=YES;
    [keyWindow addSubview:parentView];
    
    //主容器
    UIView *alertView=[[UIView alloc] init];
    alertView.bounds=CGRectMake(0, 0, 239, 177);
    alertView.center=parentView.center;
    alertView.layer.masksToBounds=YES;
    alertView.layer.cornerRadius=10;
    alertView.backgroundColor=[UIColor whiteColor];
    [parentView addSubview:alertView];
    
    //标题
    UILabel *titleLabel=[[UILabel alloc] initWithFrame:CGRectMake(0, 15, 239, 15)];
    titleLabel.font=[UIFont boldSystemFontOfSize:15];
    titleLabel.textColor=RGBACOLOR(51, 51, 51, 1);
    titleLabel.textAlignment=NSTextAlignmentCenter;
    titleLabel.text=title;
    [alertView addSubview:titleLabel];
    
    //关闭
    UIImage *closeIMG=[UIImage imageNamed:@"bg_close_share"];
    closeButton=[[UIButton alloc] initWithFrame:CGRectMake(5, 5, closeIMG.size.width, closeIMG.size.height)];
    [closeButton setImage:closeIMG forState:UIControlStateNormal];
    [alertView addSubview:closeButton];
    
    
    //分割线
    UIView *lineView=[[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(titleLabel.frame)+13,239 , .8)];
    lineView.backgroundColor=RGBACOLOR(235, 235, 235, .7);
    [alertView addSubview:lineView];
    
    //描述
    UILabel *descLabel=[[UILabel alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(lineView.frame)+5, 239, 15)];
    descLabel.font=[UIFont systemFontOfSize:12];
    descLabel.textColor=RGBACOLOR(153, 153, 153, 1);
    descLabel.textAlignment=NSTextAlignmentCenter;
    descLabel.text=@"有糖支付";
    [alertView addSubview:descLabel];
    
    
    //金额
    UILabel *moneyLabel=[[UILabel alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(descLabel.frame)+5, 239, 20)];
    moneyLabel.font=[UIFont systemFontOfSize:20];
    moneyLabel.textColor=RGBACOLOR(51, 51, 51, 1);
    moneyLabel.textAlignment=NSTextAlignmentCenter;
    moneyLabel.text=money;
    [alertView addSubview:moneyLabel];
    
    //输入密码
    codeTextField=[[CodeTextField alloc] initWithFrame:CGRectMake(15, CGRectGetMaxY(moneyLabel.frame)+10, 239-30, 35)];
    codeTextField.layer.borderWidth=.6;
    codeTextField.keyboardType=UIKeyboardTypeNumberPad;
    codeTextField.font=[UIFont systemFontOfSize:0];
    //    codeTextField.secureTextEntry=YES;
    codeTextField.layer.borderColor=[RGBACOLOR(200, 200, 200, 1) CGColor];
    [alertView addSubview:codeTextField];
    [codeTextField addTarget:self action:@selector(textFieldDidChange:) forControlEvents:UIControlEventEditingChanged];
    [codeTextField becomeFirstResponder];
    
    //支付说明
    hintLable=[[UILabel alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(codeTextField.frame)+10, 239, 20)];
    hintLable.font=[UIFont systemFontOfSize:11];
    hintLable.textColor=RGBACOLOR(51, 51, 51, 1);
    hintLable.textAlignment=NSTextAlignmentCenter;
    hintLable.text=hint;
    [alertView addSubview:hintLable];
    
    timer =  [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(doTimer) userInfo:nil repeats:YES];
    [closeButton addTarget:self action:@selector(doCancel) forControlEvents:UIControlEventTouchUpInside];
}


-(void)doTimer{
    if (hintLable) {
        NSString *hint=[NSString stringWithFormat:@"%@   %d秒",hintTxt,seconds--];
        if (seconds<0) {
            [self doCancel];
        }
        NSMutableAttributedString *AttributedStr ;
        AttributedStr= [[NSMutableAttributedString alloc]initWithString:hint];
        
        [AttributedStr addAttribute:NSFontAttributeName
         
                              value:[UIFont systemFontOfSize:13.0]
         
                              range:NSMakeRange(0, AttributedStr.length)];
        
        [AttributedStr addAttribute:NSForegroundColorAttributeName
                              value:RGBACOLOR(253, 109, 93, 1)
                              range:NSMakeRange(hintTxt.length, hint.length-hintTxt.length)];
        [AttributedStr addAttribute:NSFontAttributeName
                              value:[UIFont boldSystemFontOfSize:13]
                              range:NSMakeRange(hintTxt.length, hint.length-hintTxt.length)];
        hintLable.attributedText=AttributedStr;
    }
}

- (void)textFieldDidChange:(UITextField *)textField
{
    [codeTextField setNeedsDisplay];
    if (textField == codeTextField) {
        if (textField.text.length ==6) {
            if (timer) {
                [timer invalidate];
                timer=nil;
            }
            textField.text = [textField.text substringToIndex:6];
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(.3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                self.codeConfirm(textField.text);
                [self doCancel];
            });
        }
    }
}


@end

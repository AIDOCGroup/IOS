//
//  ChagePersonViewController.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "ChagePersonViewController.h"
#import "ZKLoginTextField.h"
@interface ChagePersonViewController ()
{
    
    ZKLoginTextField *_nickFiled;//昵称
}
@end

@implementation ChagePersonViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = rgbColor(0xf2f2f2);
    self.title = @"个人资料";
    
    if (self.changeID == 1) {
        //头像
        
    }else if (self.changeID == 2){
        //昵称
        
        [self _initNickNameView];
        
    }else if (self.changeID == 3){
        //个性签名
        
    }else if (self.changeID == 4){
        //性别
        
    }else if (self.changeID == 5){
        //生日
    }else if (self.changeID == 6){
        //地区
    }

}

- (void)_initNickNameView{
    
    _nickFiled = [[ZKLoginTextField alloc] init];
    _nickFiled.backgroundColor = [UIColor whiteColor];
    _nickFiled.hideBorder = NO;
    _nickFiled.placeholder = @"请输入昵称";
    _nickFiled.clearButtonMode = UITextFieldViewModeAlways;
    _nickFiled.textColor = rgbColor(0xcccccc);
    _nickFiled.frame = CGRectMake(10, 40, kScreenWidth-20, 40);
    _nickFiled.font = [UIFont systemFontOfSize:15];
    
    [_nickFiled setClipsToBounds:YES];
    _nickFiled.layer.borderWidth = 0.7;//边框宽度
    _nickFiled.layer.borderColor = [UIColor lightGrayColor].CGColor;
    
    [self.view addSubview:_nickFiled];
}

/**
 *  TextField光标缩进
 */
- (CGRect)editingRectForBounds:(CGRect)bounds {
    return CGRectInset(bounds, 15, 0);
}
/**
 *  文字缩进
 */
- (CGRect)textRectForBounds:(CGRect)bounds {
    return CGRectInset(bounds, 15, 0);
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

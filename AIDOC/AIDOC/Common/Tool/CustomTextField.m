//
//  CustomTextField.m
//  AIDOC
//
//  Created by app on 2018/2/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "CustomTextField.h"

@implementation CustomTextField
{
    //坐标
    CGRect   _frame;
    //用label显示内容
    UILabel  *_label;
    //是否显示清空按钮
    BOOL     _clear;
    //设置leftView
    UIView   *_leftView;
    //设置字号
    CGFloat  _fontSize;
}

/**
 *  自定义初始化方法
 *
 *  @param frame       frame
 *  @param placeholder 提示语
 *  @param clear       是否显示清空按钮 YES为显示
 *  @param view        是否设置leftView不设置传nil
 *  @param font        设置字号
 *
 *  @return
 */
-(id)initWithFrame:(CGRect)frame placeholder:(NSString *)placeholder clear:(BOOL)clear leftView:(id)view fontSize:(CGFloat)font
{
    self = [super initWithFrame:frame];
    if (self) {
        _frame = frame;
        _clear = clear;
        _leftView = (UIView *)view;
        _fontSize = font;
        self.placeholder = placeholder;
        self.textColor = [UIColor clearColor];
        self.font = [UIFont systemFontOfSize:_fontSize];
        self.delegate = self;
        if (clear) {
            self.clearButtonMode = UITextFieldViewModeAlways;
        }
        if (view) {
            self.leftView = view;
            self.leftViewMode = UITextFieldViewModeAlways;
        }
        [self createLabel];
        [self addTarget:self action:@selector(textFieldDidChange:) forControlEvents:UIControlEventEditingChanged];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(dynamicHiddenUpdateKeyboard:) name:KNOTIFICATION_CellKeyboardHidden object:nil];
    }
    return self;
}

//动态更新隐藏键盘
- (void)dynamicHiddenUpdateKeyboard:(NSNotification *)notification {
    [[NSNotificationCenter defaultCenter] postNotificationName:KNOTIFICATION_KeyboardHidden object:nil];
    [self resignFirstResponder];
}

/**
 *  监听textField内容的改变
 *
 *  @param sender
 */
- (void) textFieldDidChange:(id) sender {
    UITextField *textField = (UITextField *)sender;
    
    CGSize size = [self labelText:[NSString stringWithFormat:@"%@|",textField.text] fondSize:_fontSize width:_label.frame.size.width];
    _label.frame = CGRectMake(_label.frame.origin.x, _label.frame.origin.y, _label.frame.size.width, size.height < _frame.size.height ? _frame.size.height : size.height);
    self.frame = CGRectMake(_frame.origin.x, _frame.origin.y, _frame.size.width, size.height < _frame.size.height ? _frame.size.height : size.height);
    
    if (textField.text.length == 0) {
        _label.text = @"";
        self.tintColor=[UIColor blueColor];
    }else{
        //添加一个假的光标
        self.tintColor=[UIColor clearColor];
        NSString *text = [NSString stringWithFormat:@"%@|",textField.text];
        NSMutableAttributedString *attString = [[NSMutableAttributedString alloc]initWithString:text];
        [attString addAttribute:NSForegroundColorAttributeName value:[UIColor blueColor] range:NSMakeRange(text.length - 1, 1)];
        _label.attributedText = attString;
    }
}

/**
 *  创建label
 */
-(void)createLabel
{
    _label = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, _frame.size.width, _frame.size.height)];
    if (_leftView) {
        _label.frame = CGRectMake(_leftView.frame.size.width, _label.frame.origin.y, _label.frame.size.width-_leftView.frame.size.width, _label.frame.size.height);
    }
    if (_clear) {
        _label.frame = CGRectMake(_label.frame.origin.x, _label.frame.origin.y, _label.frame.size.width-20, _label.frame.size.height);
    }
    _label.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0];
    _label.font = [UIFont systemFontOfSize:_fontSize];
    _label.numberOfLines = 0;
    [self addSubview:_label];
}

#pragma mark - UITextFieldDelegate
//点击return回收键盘
-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}
//开始编辑
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
    NSLog(@"将要编辑");
    return YES;
}
//开始编辑
- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    [[NSNotificationCenter defaultCenter] postNotificationName:KNOTIFICATION_KeyboardDisplay object:nil];
    NSLog(@"开始编辑");
}
//将要编辑完成
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
    NSLog(@"将要编辑完成");
    return YES;
}
//编辑完成
- (void)textFieldDidEndEditing:(UITextField *)textField
{
    [[NSNotificationCenter defaultCenter] postNotificationName:KNOTIFICATION_KeyboardDisplay object:nil];
    NSLog(@"编辑完成");
    if ([self.delegate1 respondsToSelector:@selector(AddMoreSuccess:)]) {
        [self.delegate1 AddMoreSuccess:textField.text];
    }
}
//点击键盘调用
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    NSLog(@"点击键盘调用");
    return YES;
}
//点击清空按钮
- (BOOL)textFieldShouldClear:(UITextField *)textField
{
    NSLog(@"清空");
    _label.text = @"";
    return YES;
}
/**
 *  计算字符串长度，UILabel自适应高度
 *
 *  @param text  需要计算的字符串
 *  @param size  字号大小
 *  @param width 最大宽度
 *
 *  @return 返回大小
 */
-(CGSize)labelText:(NSString *)text fondSize:(float)size width:(CGFloat)width
{
    NSDictionary *send = @{NSFontAttributeName: [UIFont systemFontOfSize:size]};
    CGSize textSize = [text boundingRectWithSize:CGSizeMake(width, 0)
                                         options:NSStringDrawingTruncatesLastVisibleLine |
                       NSStringDrawingUsesLineFragmentOrigin |
                       NSStringDrawingUsesFontLeading
                                      attributes:send context:nil].size;
    
    return textSize;
}

/*
 // Only override drawRect: if you perform custom drawing.
 // An empty implementation adversely affects performance during animation.
 - (void)drawRect:(CGRect)rect {
 // Drawing code
 }
 */

@end

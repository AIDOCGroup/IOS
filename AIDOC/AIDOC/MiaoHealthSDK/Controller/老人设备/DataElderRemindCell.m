//
//  DataElderRemindCell.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "DataElderRemindCell.h"

@interface DataElderRemindCell()<UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UIButton *updateBt;
@property (weak, nonatomic) IBOutlet UIButton *deleteBt;

@end

@implementation DataElderRemindCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
    _startAtTf.delegate    = self;
    _startTimeTf.delegate  = self;
    _remindTypeTf.tag = 100;
    _repeatTypeTf.tag = 101;
    _contentTf.delegate    = self;
    
    [self setSelectedBackgroundView:[[UIView alloc] init]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void) setIsAdd:(BOOL)isAdd {
    _isAdd = isAdd;
    if (isAdd) {
        [_updateBt setHidden:true];
        [_deleteBt setTitle:@"添加" forState:UIControlStateNormal];
        [_deleteBt setTitle:@"添加" forState:UIControlStateSelected];
    }
}


- (void) setRemind:(MCElderRemind *)remind {
    _remind = remind;
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    formatter.dateFormat = @"yyyy-MM-dd";
    
    
    NSDateFormatter *formatter2 = [[NSDateFormatter alloc] init];
    formatter2.dateFormat = @"HH:mm";
    

    if (remind.start_at == nil) remind.start_at = [formatter stringFromDate:[NSDate date]];
    if (remind.start_time == nil) remind.start_time = [formatter2 stringFromDate:[NSDate date]];
    if (remind.remind_type == 0) remind.remind_type = 0;
    if (remind.repeat_type == 0) remind.repeat_type = 1;
    
    _startAtTf.text    = remind.start_at;
    _startTimeTf.text  = remind.start_time;
//    _remindTypeTf.text = [NSString stringWithFormat:@"%ld", (long)remind.remind_type];
//    _repeatTypeTf.text = [NSString stringWithFormat:@"%ld", (long)remind.repeat_type];
    _contentTf.text    = remind.content;
}

- (IBAction)updateEvent:(id)sender {
    _remind.start_at    = _startAtTf.text;
    _remind.start_time  = _startTimeTf.text;
    _remind.remind_type = self.selectedTypeRow;
    _remind.repeat_type = self.selectedRepeatedRow;
    _remind.content     = _contentTf.text;
    
    [[MiaoHealthElderManager shareInstance] editRemind:_remind success:^(id  _Nullable result) {
        _alerMessage = @"编辑亲情问候成功";
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showAlerView:_alerMessage];
        });
    } failure:^(NSInteger status, NSString * _Nullable msg, NSError * _Nullable error) {
        if (error.code == 10021) {
            _alerMessage = @"编辑亲情问候失败，请输入提醒内容";
        }else{
            _alerMessage = @"编辑亲情问候失败，同一时间不能重复编辑";
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showAlerView:_alerMessage];
        });
    }];
}

- (IBAction)deleteEvent:(id)sender {
    if (_isAdd) {
        _remind.start_at    = _startAtTf.text;
        _remind.start_time  = _startTimeTf.text;
        _remind.remind_type = self.selectedTypeRow;
        _remind.repeat_type = self.selectedRepeatedRow;
        _remind.content     = _contentTf.text;
        
        [[MiaoHealthElderManager shareInstance] addRemind:_remind success:^(id  _Nullable result) {
            _alerMessage = @"编辑亲情问候成功";
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showAlerView:_alerMessage];
            });
        } failure:^(NSInteger status, NSString * _Nullable msg, NSError * _Nullable error) {
            if (error.code == 10021) {
                _alerMessage = @"添加亲情问候失败，请输入提醒内容";
            }else{
                _alerMessage = @"添加亲情问候失败，同一时间不能重复添加";
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showAlerView:_alerMessage];
            });
        }];

    } else {
        [[MiaoHealthElderManager shareInstance] deleteRemind:_remind success:^(id  _Nullable result) {
            _alerMessage = @"删除亲情问候成功";
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showAlerView:_alerMessage];
            });
        } failure:^(NSInteger status, NSString * _Nullable msg, NSError * _Nullable error) {
            if (error.code == 10021) {
                _alerMessage = @"删除亲情问候失败，请输入提醒内容";
            }else{
                _alerMessage = @"删除亲情问候失败，同一时间不能重复删除";
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showAlerView:_alerMessage];
            });
        }];
    }
}

- (void) showAlerView:(NSString *) string {
    [[[UIAlertView alloc] initWithTitle:@"消息提示" message:string delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil] show];
}


#pragma mark - UITextFieldDelegate
- (BOOL)textFieldShouldReturn:(UITextField *)theTextField {
    [theTextField resignFirstResponder];
    
    return YES;
}

- (IBAction)showPickerViewAction:(id)sender {
    self.selectedButton = (UIButton *)sender;
    if ([self.delegate respondsToSelector:@selector(dataElderRemindCell:showOrHidePickerView:tag:)]) {
        [self.delegate dataElderRemindCell:self showOrHidePickerView:YES tag:self.selectedButton.tag];
    }
}

- (IBAction)showPickerViewActionRepeat:(id)sender {
    [self showPickerViewAction:sender];
}


@end

//
//  DataElderRelationCell.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "DataElderRelationCell.h"

@interface DataElderRelationCell()<UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UIButton *updateBt;
@property (weak, nonatomic) IBOutlet UIButton *deleteBt;

@end

@implementation DataElderRelationCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
    _nameTf.delegate = self;
    _mobileTf.delegate = self;
    [self setSelectedBackgroundView:[[UIView alloc] init]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void) setIsAdd:(BOOL)isAdd {
    _isAdd = isAdd;
    if (_isAdd) {
        [_updateBt setHidden:true];
        [_deleteBt setTitle:@"添加" forState:UIControlStateNormal];
        [_deleteBt setTitle:@"添加" forState:UIControlStateSelected];
    }
}

- (void) setRelation:(MCElderRelation *)relation {
    _relation      = relation;
    _nameTf.text   = relation.name;
    _mobileTf.text = relation.mobile;
}

- (IBAction)updateEvent:(id)sender {
    _relation.name   = _nameTf.text;
    _relation.mobile = _mobileTf.text;
    [[MiaoHealthElderManager shareInstance] editRelation:_relation success:^(id  _Nullable result) {
        _alerMessage = @"编辑联系人成功";
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showAlerView:_alerMessage];
        });
    } failure:^(NSInteger status, NSString * _Nullable msg, NSError * _Nullable error) {
        _alerMessage = [NSString stringWithFormat:@"编辑联系人失败,%@",msg];
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showAlerView:_alerMessage];
        });
    }];
}

- (IBAction)deleteEvent:(id)sender {
    if (_isAdd){
        _relation.name   = _nameTf.text;
        _relation.mobile = _mobileTf.text;
        [[MiaoHealthElderManager shareInstance] addRelation:_relation success:^(id  _Nullable result) {
            _alerMessage = @"添加联系人成功";
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showAlerView:_alerMessage];
            });
        } failure:^(NSInteger status, NSString * _Nullable msg, NSError * _Nullable error) {
            _alerMessage = [NSString stringWithFormat:@"添加联系人失败,%@",msg];
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showAlerView:_alerMessage];
            });
        }];
    } else {
        [[MiaoHealthElderManager shareInstance] deleteRelation:_relation success:^(id  _Nullable result) {
            _alerMessage = @"删除联系人成功";
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showAlerView:_alerMessage];
            });
        } failure:^(NSInteger status, NSString * _Nullable msg, NSError * _Nullable error) {
            _alerMessage = [NSString stringWithFormat:@"删除联系人失败,%@",msg];
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

@end

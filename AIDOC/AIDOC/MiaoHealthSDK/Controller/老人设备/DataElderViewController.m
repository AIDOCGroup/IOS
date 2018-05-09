//
//  DataElderViewController.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "DataElderViewController.h"

#import <MiaoHealthConnect/MiaoHealthConnect.h>
#import "DataElderRelationCell.h"
#import "DataElderRemindCell.h"
#import "DataElderCell.h"
#import "DataElderEncourageCell.h"
#import "DisplayPickerView.h"

@interface DataElderViewController ()<UITableViewDelegate, UITableViewDataSource,DataElderRemindCellDelegate>

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UITableView *messageTv;

@property (nonatomic, strong) __block NSMutableArray *dataArray;
@property (nonatomic, strong) __block NSMutableArray<NSString *> *messageArray;

@property (nonatomic, strong) NSString *alerMessage;

@property (nonatomic , weak) DisplayPickerView *pickerView;

@end

@implementation DataElderViewController

- (void) setMessage:(NSString *) message {
    [_messageArray addObject:message];
    [_messageTv reloadData];
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [_tableView setDelegate:self];
    [_tableView setDataSource:self];
    
    [_messageTv setDelegate:self];
    [_messageTv setDataSource:self];
    
    _dataArray    = [NSMutableArray array];
    _messageArray = [NSMutableArray array];
    
    switch (_type) {
        case 1: {
            MCElderRelation *relation = [[MCElderRelation alloc] init];
            relation.device_sn = _device_sn;
            relation.device_no = _device_no;
            [_dataArray addObject:relation];
            self.title = @"添加联系人";
        }
            break;
        case 2: {
            MCElderRemind *remind = [[MCElderRemind alloc] init];
            remind.device_sn = _device_sn;
            remind.device_no = _device_no;
            [_dataArray addObject:remind];
            
            DisplayPickerView *pickerView = [DisplayPickerView displayPickerViewWithSelectedBlock:^(NSInteger number,NSString *title,RemindType remindType) {
                dispatch_async(dispatch_get_main_queue(), ^{
                   DataElderRemindCell *cell = (DataElderRemindCell *)[self.tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0]];
                    if (remindType == RemindTypeWithType){
                        [cell.remindTypeTf setTitle:title forState:UIControlStateNormal];
                        cell.selectedTypeRow = number;
                    }else if(remindType == RemindTypeWithRepeatType){
                        [cell.repeatTypeTf setTitle:title forState:UIControlStateNormal];
                        cell.selectedRepeatedRow = number;
                    }
                });
            }];
            pickerView.vc = self;
            [self.view addSubview:pickerView];
            self.pickerView = pickerView;
            self.title = @"添加亲情提示";
        }
            break;
        case 3: {
            __weak typeof(self) weakSelf = self;
            [[MiaoHealthElderManager shareInstance] fetchRelation:_device_sn deviceNO:_device_no queryResult:^(NSMutableArray * _Nullable result, NSError * _Nullable error) {
                if (!error) {
                    _dataArray = result;
                    __strong typeof(self) strongSelf = weakSelf;
                    [strongSelf.tableView reloadData];
                } else {
                    NSLog(@"联系人列表请求失败 :%@", error);
                }
            }];
            self.title = @"联系人列表";
        }
            break;
        case 4: {
            __weak typeof(self) weakSelf = self;
            [[MiaoHealthElderManager shareInstance] fetchRemind:_device_sn deviceNO:_device_no queryResult:^(NSMutableArray * _Nullable result, NSError * _Nullable error) {
                if (!error) {
                    _dataArray = result;
                    __strong typeof(self) strongSelf = weakSelf;
                    [strongSelf.tableView reloadData];
                } else {
                    NSLog(@"亲情提示列表请求失败 :%@", error);
                }
            }];
            
            self.title = @"亲情提示了表";
        }
            break;
        case 5: {
            __weak typeof(self) weakSelf = self;
            [[MiaoHealthElderManager shareInstance] fetchDayReport:_device_sn deviceNO:_device_no queryResult:^(NSMutableArray * _Nullable result, NSError * _Nullable error) {
                if (!error) {
                    _dataArray = result;
                    __strong typeof(self) strongSelf = weakSelf;
                    [strongSelf.tableView reloadData];
                } else {
                    NSLog(@"日报信息显示列表请求失败 :%@", error);
                }
            }];
            
            self.title = @"日报信息列表";
        }
            break;
        case 6: {
            __weak typeof(self) weakSelf = self;
            [[MiaoHealthElderManager shareInstance] fetchWearInfo:_device_sn deviceNO:_device_no queryResult:^(NSMutableArray * _Nullable result, NSError * _Nullable error) {
                if (!error) {
                    _dataArray = result;
                    __strong typeof(self) strongSelf = weakSelf;
                    [strongSelf.tableView reloadData];
                } else {
                    NSLog(@"佩戴信息显示列表请求失败 :%@", error);
                }
            }];
            
            self.title = @"佩戴信息列表";
        }
            break;
        case 7: {
            __weak typeof(self) weakSelf = self;
            [[MiaoHealthElderManager shareInstance] fetchPosition:_device_sn deviceNO:_device_no queryResult:^(NSMutableArray * _Nullable result, NSError * _Nullable error) {
                if (!error) {
                    _dataArray = result;
                    __strong typeof(self) strongSelf = weakSelf;
                    [strongSelf.tableView reloadData];
                } else {
                    NSLog(@"位置信息显示列表请求失败 :%@", error);
                }
            }];
            
            self.title = @"位置信息列表";
        }
            break;
        case 8: {
            __weak typeof(self) weakSelf = self;
            [[MiaoHealthElderManager shareInstance] fetchWarningMessage:_device_sn deviceNO:_device_no queryResult:^(NSMutableArray * _Nullable result, NSError * _Nullable error) {
                if (!error) {
                    _dataArray = result;
                    __strong typeof(self) strongSelf = weakSelf;
                    [strongSelf.tableView reloadData];
                } else {
                    NSLog(@"警告信息显示列表请求失败 :%@", error);
                }
            }];
            
            self.title = @"警告信息列表";
        }
            break;
        case 9: {
            [_dataArray addObject:@""];
            self.title = @"鼓励老人";
        }
            break;
            
            
        default:
            break;
    }
    
    [_tableView reloadData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UITableViewDelegate , DataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    if (tableView == _tableView) {
        return [self.dataArray count];
    } else {
        return [self.messageArray count];
    }
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    if (tableView == _tableView) {
        if (_type == 1 || _type == 3) {
            DataElderRelationCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ElderRelationCell"];
            [cell setRelation:self.dataArray[indexPath.row]];
            if (_type == 1) {
                [cell setIsAdd:true];
            }
            return cell;
        } else if (_type == 2 || _type == 4) {
            DataElderRemindCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ElderRemindCell"];
            cell.delegate = self;
            [cell setRemind:self.dataArray[indexPath.row]];
            if (_type == 2) {
                [cell setIsAdd:true];
            }
            return cell;
        } else if (_type == 5 || _type == 6 || _type == 7 || _type == 8) {
            DataElderCell *cell  = [tableView dequeueReusableCellWithIdentifier:@"ElderCell"];
            [cell setData:self.dataArray[indexPath.row]];
            return cell;
        } else if (_type == 9) {
            DataElderEncourageCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ElderEncourageCell"];
            cell.device_sn = _device_sn;
            cell.device_no = _device_no;
            return cell;
        }
    } else if (tableView == _messageTv) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MessageCell"];
        cell.textLabel.text   = self.messageArray[indexPath.row];
    }
    
    return nil;
}

- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    if (_type == 1 || _type == 3) {
        return 157;
    } else if (_type == 2 || _type == 4) {
        return 277;
    } else if (_type == 5 || _type == 6 || _type == 7 || _type == 8) {
        return 287;
    } else if (_type == 9) {
        return 187;
    }
    
    return 0;
}

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView{
    [self.view endEditing:YES];
    [self hidePickerView];
}

#pragma mark - 显示或者隐藏pickerView
- (void)dataElderRemindCell:(DataElderRemindCell *)dataElderRemindCell showOrHidePickerView:(BOOL)show tag:(NSInteger)tag{
    self.pickerView.remindType = (tag == 100) ? RemindTypeWithType : RemindTypeWithRepeatType;
    [UIView animateWithDuration:0.3 animations:^{
        self.pickerView.mj_origin = CGPointMake(0, kMainScreenHeight - self.pickerView.mj_h);
    }];
}

#pragma mark - 隐藏pickerView
- (void)hidePickerView{
    [UIView animateWithDuration:0.3 animations:^{
        self.pickerView.mj_origin = CGPointMake(0, kMainScreenHeight);
    }];
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

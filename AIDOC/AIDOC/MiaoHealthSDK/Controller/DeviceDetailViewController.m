//
//  DeviceDetailViewController.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceDetailViewController.h"
#import "DeviceDetailView.h"
#import "ScanDeviceCell.h"
#import "WebViewController.h"
#import "DemoZFScanViewController.h"
#import "UserInfoView.h"
#import "DataViewController.h"
#import "LEEAlert.h"
#import "SelectedListView.h"
#import "DisplayElderViewController.h"

@interface DeviceDetailViewController ()<UITableViewDelegate,UITableViewDataSource,UserInfoViewDelegate,UITextFieldDelegate>

@property (nonatomic , weak) UITableView *messageTableView;

@property (nonatomic , weak) UITableView *resultTableView;

@property (nonatomic , strong) NSMutableArray *messageArray;

@property (nonatomic , strong) NSMutableArray *resultArray;

@property (nonatomic , weak) DeviceDetailView *deviceDetailView;

@property (nonatomic, strong) NSString *uuid;

//浮层view
@property (weak , nonatomic) UIView *coverView;

@property (nonatomic, strong) MCUserInfo *userInfo;

@property (nonatomic , assign) BOOL isBLE;

@property (nonatomic , strong) UIButton *unBindButton;

@property (nonatomic , weak) UserInfoView *userInfoView;


@end

@implementation DeviceDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self setup];
    [self deviceDetailViewOperation];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

- (void)setup{
    if (self.deviceDetailFromEnum == DeviceDetailFromEnumBindDevice) {
        UIButton *button = [[UIButton alloc] init];
        [button setTitle:@"解除绑定" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button addTarget:self action:@selector(unBindAction) forControlEvents:UIControlEventTouchUpInside];
        button.mj_size = CGSizeMake(80, 50);
        self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:button];
        self.unBindButton = button;
    }
        
    DeviceDetailView *detailView = [DeviceDetailView deviceDetailViewWithFrame:CGRectMake(0, kNavigationHeight.floatValue, kMainScreenWidth, 120)];
    detailView.deviceDetailFromEnum = self.deviceDetailFromEnum;
    (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? (detailView.device = self.device) : (detailView.userDevice = self.userDevice);
    [self.view addSubview:detailView];
    self.deviceDetailView = detailView;
    
    UITableView *messageTableView = [[UITableView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(detailView.frame), kMainScreenWidth, kMainScreenHeight - 120 - kNavigationHeight.floatValue)];
    [messageTableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"MessageCell"];
    messageTableView.delegate = self;
    messageTableView.dataSource = self;
    messageTableView.tableFooterView = [[UIView alloc] init];
    [self.view addSubview:messageTableView];
    self.messageTableView = messageTableView;
    
    UITableView *resultTableView = [[UITableView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(detailView.frame), kMainScreenWidth, kMainScreenHeight - 120 - kNavigationHeight.floatValue)];
    resultTableView.tableFooterView = [[UIView alloc] init];
    [resultTableView registerClass:[ScanDeviceCell class] forCellReuseIdentifier:@"ScanDeviceCell"];
    resultTableView.delegate = self;
    resultTableView.dataSource = self;
    [self.view addSubview:resultTableView];
    self.resultTableView = resultTableView;
    
    
    _userInfo = [[MCUserInfo alloc] init];
    _userInfo.userName = @"haoletao";
    _userInfo.sex      = 0;
    _userInfo.age      = 20;
    _userInfo.height   = 180;
    _userInfo.area     = @"区域";
    _userInfo.birthDay = @"1988-05-04";
    self.coverView = self.coverView;
    
    self.messageArray = [NSMutableArray array];
    self.resultArray  = [NSMutableArray array];
}

- (void)showUserInfoView{
    [UIView animateWithDuration:0.4 animations:^{
        self.coverView.alpha  = 1;
        self.coverView.hidden = NO;
        [self.view bringSubviewToFront:self.coverView];
    }];
}

- (void)hideUserInfoView{
    [UIView animateWithDuration:0.3 animations:^{
        self.coverView.alpha  = 0.0;
        self.userInfoView.pickerView.mj_origin = CGPointMake(0, kMainScreenHeight);
    } completion:^(BOOL finished) {
        self.coverView.hidden = YES;
    }];
}

#pragma mark - userinfoViewDelegate
- (UserInfoView *)userInfoViewConfirmCallBack:(UserInfoView *)userInfoView userInfo:(MCUserInfo *)userInfo{
    [self hideUserInfoView];
    _userInfo = userInfo;
    [self fetchDeviceDataBLE];
    return userInfoView;
}

- (void)cancelCallBack{
    [self hideUserInfoView];
}


#pragma mark - lazy coverView
- (UIView *)coverView{
    if (!_coverView) {
        UIView *view = [[UIView alloc] initWithFrame:self.view.bounds];
        view.backgroundColor = [UIColor lightGrayColor];
        view.alpha = 0.0;
        view.hidden = YES;
        UserInfoView *userInfoView = [UserInfoView userInfoView];
        userInfoView.delegate = self;
        userInfoView.center = CGPointMake(self.view.center.x, self.view.center.y);
        [view addSubview:userInfoView];
        [self.view addSubview:view];
        self.userInfoView = userInfoView;
        _coverView = view;
    }
    return _coverView;
}

- (void)deviceDetailViewOperation{
    self.deviceDetailView.buttonActionBlock = ^(ButtonActionTypeEnum buttonActionTypeEnum) {
        if (buttonActionTypeEnum == ButtonActionTypeEnumBindDevice) { //绑定设备：开始搜索设备
            [self.resultArray removeAllObjects];
            [self.resultTableView reloadData];
            if (self.device.link_type == PeripheralsAttendedModeWebAuthority) {
                WebViewController *webVC = [[WebViewController alloc] init];
                [webVC setDevice:_device];
                webVC.showMessage = ^(NSString *message,NSString *device_no) {
                    _uuid = device_no;
                    [self showMessage:message];
                };
                [self.navigationController pushViewController:webVC animated:YES];
            } else if (self.device.link_type == PeripheralsAttendedModeQRCode) {
                DemoZFScanViewController * vc = [[DemoZFScanViewController alloc] init];
                vc.returnScanBarCodeValue = ^(NSString * barCodeString){
                    NSLog(@"扫描到的信息是：%@",barCodeString);
                    // 老人
                    if ([_device.device_name rangeOfString:@"e伴"].length) {
                        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                        DisplayElderViewController *elderVC = [storyboard instantiateViewControllerWithIdentifier:@"DisplayElderViewController"];
                        [elderVC setDevice_sn:_device.device_sn];
                        [elderVC setDevice_no:barCodeString];
                        [self.navigationController pushViewController:elderVC animated:YES];
                    } else {
                        [self checkDevice:barCodeString isBLE:false];
                    }
                };
                
                [self presentViewController:vc animated:YES completion:nil];
            } else if (self.device.link_type == PeripheralsAttendedModeBluetooth) {
                self.deviceDetailView.buttonTwo.enabled = NO;
                typeof(self) __weak weakSelf = self;
                [[MiaoHealthConnectManager shareInstance] scanBLEDevice:self.device.device_id timeout:10 bluetoothStatus:^(BluetoothStatus status) {
                    
                    if(status == BluetoothStatusPowerOff) {
                        [self showMessage:@"蓝牙未开启"];
                    } else if (status == BluetoothStatusConnectBegin) {
                        [self showMessage:@"开始连接"];
                    } else if (status == BluetoothStatusConnectSuccess) {
                        [self showMessage:@"连接成功"];
                    } else if (status == BluetoothStatusConnectFail) {
                        [self showMessage:@"连接失败"];
                    } else if (status == BluetoothStatusDisconnect) {
                        [self showMessage:@"连接断开"];
                    } else if (status == BluetoothStatusTimeout) {
                        [self showMessage:@"连接超时"];
                    } else if (status == BluetoothStatusPowerOn) {
                        [self showMessage:@"蓝牙开启，开始搜索"];
                    }
                } devices:^(NSArray<MCBLEDevice *> * _Nullable deviceList) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        weakSelf.resultArray = [NSMutableArray arrayWithArray:deviceList];
                        [self.view bringSubviewToFront:self.resultTableView];
                        if ([weakSelf.resultArray count] > 0) {
                            [weakSelf.resultTableView reloadData];
                        } else {
                            [weakSelf showMessage:@"蓝牙未搜索到设备"];
                        }
                    });
                }];
            }else if (self.device.link_type == PeripheralsAttendedModeWifi){
                // 使用一个变量接收自定义的输入框对象 以便于在其他位置调用
                NSArray *array = [[MiaoHealthConnectManager shareInstance] getWifiNameList];
                if (array.count) {
                    __block UITextField *tf = nil;
                     NSString *wifiName =array.firstObject;
                    [LEEAlert alert].config
                    .LeeTitle(@"温馨提示")
                    .LeeContent([NSString stringWithFormat:@"请输入%@的密码",wifiName])
                    .LeeAddTextField(^(UITextField *textField) {
                        // 这里可以进行自定义的设置
                        textField.placeholder = @"请输入wifi密码";
                        textField.textColor = [UIColor darkGrayColor];
                        tf = textField; //赋值
                    })
                    .LeeAction(@"好的", ^{
                        if (!tf.text.length) {
                            return;
                        }
                        [tf resignFirstResponder];
                        NSString *wifiPwd = [tf.text stringByReplacingOccurrencesOfString:@" " withString:@""];
                        [[MiaoHealthConnectManager shareInstance] fetchWifiConnection:wifiName wifiPwd:wifiPwd responedata:^(PeripheralsDataType peripheralsDataType, id  _Nullable result, NSError * _Nullable error) {
                            if (!error && (peripheralsDataType == PeripheralsDataTypeUroscopy)) {
                                NSString *deviceId = [result objectForKey:@"deviceId"];
                                [self checkDevice:deviceId isBLE:false];
                            }else{
                                [LEEAlert alert].config
                                .LeeTitle(@"温馨提示")
                                .LeeContent(@"网络异常，请检查网络")
                                .LeeAction(@"确认", ^{
                                    // 确认点击事件Block
                                })
                                .LeeShow(); // 设置完成后 别忘记调用Show来显示
                                return;
                            }
                        }];
                    })
                    .LeeCancelAction(@"取消", nil) // 点击事件的Block如果不需要可以传nil
                    .LeeShow();
                }
            }else if (self.device.link_type == PeripheralsAttendedModePort){
             
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                   
                });
            }
        }else if(buttonActionTypeEnum == ButtonActionTypeEnumGetNewData){ //获取最新数据、当前数据
            if ((self.device.device_sn.intValue == -1) || (self.userDevice.device_sn.intValue == -1)) {
                [[MiaoHealthConnectManager shareInstance] FetchLocalSportData:GetLocalSportDataEnumToday bluetoothDataChangeBlock:^(PeripheralsDataType peripheralsDataType, id  _Nullable result, NSError * _Nullable error) {
                    if (error) {
                        [LEEAlert alert].config
                        .LeeTitle(@"温馨提示")
                        .LeeContent(error.domain)
                        .LeeAction(@"确认", ^{
                            
                            // 确认点击事件Block
                        })
                        .LeeShow(); // 设置完成后 别忘记调用Show来显示
                        return;
                    }
                    DataViewController *dataVC = [[DataViewController alloc] init];
                    [dataVC setDataArray:[NSMutableArray arrayWithObject:result]];
                    [dataVC setPeripheralsDataType:peripheralsDataType];
                    dataVC.device_id = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id;
                    [self.navigationController pushViewController:dataVC animated:YES];
                }];
            }else{
                if (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) {
                    if (self.device.link_type == PeripheralsAttendedModeBluetooth) {
                        [self begingFetchBLEData];
                    }else{
                        for (MCDeviceFunctional *deviceFunctional in (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.deviceFunctional : self.userDevice.deviceFunctional) {
                            [self fetchDeviceDataAPI:deviceFunctional.functional_id];
                        }
                    }
                }else{
                    if ([_userDevice.device_name rangeOfString:@"e伴"].length) {
                        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                        DisplayElderViewController *elderVC = [storyboard instantiateViewControllerWithIdentifier:@"DisplayElderViewController"];
                        [elderVC setDevice_sn:_userDevice.device_sn];
                        [elderVC setDevice_no:_userDevice.device_no];
                        [self.navigationController pushViewController:elderVC animated:YES];
                    } else {
                        if (self.userDevice.link_type == PeripheralsAttendedModeBluetooth) {
                            [self begingFetchBLEData];
                        }else{
                            for (MCDeviceFunctional *deviceFunctional in (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.deviceFunctional : self.userDevice.deviceFunctional) {
                                [self fetchDeviceDataAPI:deviceFunctional.functional_id];
                            }
                        }
                    }
                }
            }
        }else if(buttonActionTypeEnum == ButtonActionTypeEnumGetHistoryData){ //获取历史数据
            if ((self.device.device_sn.intValue == -1) || (self.userDevice.device_sn.intValue == -1)) {
                [[MiaoHealthConnectManager shareInstance] FetchLocalSportData:GetLocalSportDataEnumHistory bluetoothDataChangeBlock:^(PeripheralsDataType peripheralsDataType, id  _Nullable result, NSError * _Nullable error) {
                    if (error) {
                        [LEEAlert alert].config
                        .LeeTitle(@"温馨提示")
                        .LeeContent(error.domain)
                        .LeeAction(@"确认", ^{
                            
                            // 确认点击事件Block
                        })
                        .LeeShow(); // 设置完成后 别忘记调用Show来显示
                        return;
                    }
                    if ([self.navigationController.visibleViewController isKindOfClass:[DataViewController class]]) {
                        DataViewController *dataVC = (DataViewController *)self.navigationController.visibleViewController;
                        dataVC.device_id = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id;
                        [dataVC.dataArray addObject:result];
                        [dataVC setPeripheralsDataType:peripheralsDataType];
                        [dataVC.tableView reloadData];
                        if (dataVC.dataArray != nil && [dataVC.dataArray count] > 1) {
                            [dataVC.tableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:(dataVC.dataArray.count-1) inSection:0] atScrollPosition:UITableViewScrollPositionBottom animated:YES];
                        }
                    }else{
                        DataViewController *dataVC = [[DataViewController alloc] init];
                        [dataVC setDataArray:[NSMutableArray arrayWithObject:result]];
                        [dataVC setPeripheralsDataType:peripheralsDataType];
                        dataVC.device_id = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id;
                        [self.navigationController pushViewController:dataVC animated:YES];
                    }
                }];
            }else{
                SelectedListView *view = [[SelectedListView alloc] initWithFrame:CGRectMake(0, 0, 280, 0) style:UITableViewStylePlain];
                
                view.isSingle = YES;
                
                NSMutableArray<SelectedListModel *> *array = [[NSMutableArray<SelectedListModel *> alloc] init];
                for (MCDeviceFunctional *function in (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.deviceFunctional : self.userDevice.deviceFunctional) {
                    [array addObject:[[SelectedListModel alloc] initWithSid:[[function valueForKey:@"functional_id"] integerValue] Title:[function valueForKey:@"functional_name"]]];
                }
                
                view.array = array;
                view.selectedBlock = ^(NSArray<SelectedListModel *> *array) {
                    [LEEAlert closeWithCompletionBlock:^{
                        NSLog(@"选中的%@" , array);
                        SelectedListModel *function = (SelectedListModel *)array.firstObject;
                        [self fetchDeviceDataAPI:function.sid];
                    }];
                    
                };
                
                [LEEAlert alert].config
                .LeeTitle(@"数据类型")
                .LeeItemInsets(UIEdgeInsetsMake(20, 0, 20, 0))
                .LeeCustomView(view)
                .LeeItemInsets(UIEdgeInsetsMake(0, 0, 0, 0))
                .LeeHeaderInsets(UIEdgeInsetsMake(10, 0, 0, 0))
                .LeeClickBackgroundClose(YES)
                .LeeShow();
            }
        }else if (buttonActionTypeEnum == ButtonActionTypeEnumDisConnectBlE){ //断开蓝牙
            [self disconnectBLEEvent:nil];
        }
    };
}

- (void)fetchDeviceDataAPI:(PeripheralsDataType) peripheralsDataType{
    
    typeof(self) __weak weakSelf = self;
    
    long long currentTimeInterval = [[NSDate date] timeIntervalSince1970];
//    long long startTime = (currentTimeInterval - 24 * 3600 * 7) * 1000;
//    long long endTime   = currentTimeInterval * 1000;
    long long startTime = 0;
    long long endTime   = 0;
    [[MiaoHealthConnectManager shareInstance] fetchApiDeviceData:(self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_sn : self.userDevice.device_sn device_no:(self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? _uuid : self.userDevice.device_no functionId:peripheralsDataType startTime:startTime end:endTime queryComplete:^(NSArray * _Nullable queryResponse, NSError * _Nullable error) {
        typeof(self) __strong strongSelf = weakSelf;
        DataViewController *dataVC = [[DataViewController alloc] init];
        [dataVC setDataArray:[NSMutableArray arrayWithArray:queryResponse]];
        [dataVC setPeripheralsDataType:peripheralsDataType];
        dataVC.device_id = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id;
        [strongSelf.navigationController pushViewController:dataVC animated:YES];
    }];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return (tableView == self.messageTableView) ? self.messageArray.count : self.resultArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    if (self.messageTableView == tableView) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MessageCell" forIndexPath:indexPath];
        cell.textLabel.text = self.messageArray[indexPath.row];
        return cell;
    }else{
        ScanDeviceCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ScanDeviceCell" forIndexPath:indexPath];
        cell.device = self.resultArray[indexPath.row];
        return cell;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 60;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (tableView == self.resultTableView) {
        __block MCBLEDevice *mcBleDevice = self.resultArray[indexPath.row];
        [self showMessage:@"开始绑定设备"];
        _uuid = mcBleDevice.uuid;
        [self checkDevice:_uuid isBLE:true];
        
    }
}

#pragma mark - Bind Request
- (void) checkDevice:(NSString *) uuid  isBLE: (BOOL) isBLE {
    _uuid = uuid;
    typeof(self) __weak weakSelf = self;
    [[MiaoHealthConnectManager shareInstance] checkDevice:self.device.device_sn deviceNO:uuid checkBind:^(BindDeviceStatus bindDeviceStatus, NSError * _Nullable error) {
        typeof(self) __strong strongSelf = weakSelf;
        if (error || (bindDeviceStatus == BindDeviceStatusError)) {
            [strongSelf showMessage:error.domain];
        }else{
            if ((bindDeviceStatus == BindDeviceStatusUnbound) || bindDeviceStatus == BindDeviceStatusOtherBound) {
                [strongSelf bindDevice:uuid isBLE:isBLE];
            }else{
                [strongSelf showMessage:@"设备已被自己绑定"];
                self.deviceDetailView.buttonTwo.enabled = YES;
            }
        }
    }];
}

- (void)bindDevice:(NSString *) uuid isBLE:(BOOL) isBLE {
    self.isBLE = isBLE;
    typeof(self) __weak weakSelf = self;
    [[MiaoHealthConnectManager shareInstance] bindDevice:self.device.device_sn deviceNO:uuid bind:^(NSInteger isSuccess,NSString *_Nullable device_no, NSError * _Nullable error) {
        if (isSuccess == 1) {
            [weakSelf showMessage:@"绑定成功"];
            self.deviceDetailView.buttonTwo.enabled = YES;
            if (!isBLE) {
                _uuid = device_no;
            }
        } else {
            [weakSelf showMessage:[NSString stringWithFormat:@"绑定失败:%@",error.domain]];
        }
    }];
}

#pragma mark - 获取最新数据
- (void)begingFetchBLEData{
    BOOL isFetch = false;
    for (MCDeviceFunctional *deviceFunctional in (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.deviceFunctional : self.userDevice.deviceFunctional) {
        NSInteger functional_id = [[deviceFunctional valueForKey:@"functional_id"] integerValue];
        if (functional_id == PeripheralsDataTypeBodyFat || functional_id == PeripheralsDataTypeSport || functional_id == PeripheralsDataTypeOximeter) {
            
            if (functional_id== PeripheralsDataTypeSport || functional_id== PeripheralsDataTypeOximeter) {
            }
            
            [self showUserInfoView];
            isFetch = true;
            return;
        }
    }
    
    if (!isFetch)  {
        [self fetchDeviceDataBLE];
    }

}
- (void) fetchDeviceDataBLE {
    typeof(self) __weak weakSelf = self;
    [[MiaoHealthConnectManager shareInstance] fetchBLEConnect:(self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id deviceSN:(self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_sn : self.userDevice.device_sn uuid:(self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? _uuid : self.userDevice.device_no  params:_userInfo timeout:10 bluetoothStatus:^(BluetoothStatus status) {
        if(status == BluetoothStatusPowerOff) {
            [self showMessage:@"蓝牙未开启"];
        } else if (status == BluetoothStatusConnectBegin) {
            [self showMessage:@"开始连接"];
        } else if (status == BluetoothStatusConnectSuccess) {
            [self showMessage:@"连接成功"];
        } else if (status == BluetoothStatusConnectFail) {
            [self showMessage:@"连接失败"];
        } else if (status == BluetoothStatusDisconnect) {
            [self showMessage:@"连接断开"];
        } else if (status == BluetoothStatusTimeout) {
            [self showMessage:@"连接超时"];
        }
    } responedata:^(PeripheralsDataType peripheralsDataType, id result, NSError * _Nullable error) {
        typeof(self) __strong strongSelf = weakSelf;
        if (error == nil  && peripheralsDataType == PeripheralsDataTypeMessage) {
            [strongSelf showMessage:result];
        } else if (error == nil && result != nil) {
            MCData *data = (MCData *)result;
            if (PeripheralsDataMultiply == data.functional_id) {
                DataViewController *dataVC = [[DataViewController alloc] init];
                [dataVC setDataArray:[NSMutableArray arrayWithObject:result]];
                [dataVC setPeripheralsDataType:peripheralsDataType];
                dataVC.device_id = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id;
                [strongSelf.navigationController pushViewController:dataVC animated:YES];
            }else{
                if ([strongSelf.navigationController.visibleViewController isKindOfClass:[DataViewController class]]) {
                    DataViewController *dataVC = (DataViewController *)strongSelf.navigationController.visibleViewController;
                    dataVC.device_id = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id;
                    [dataVC.dataArray addObject:result];
                    [dataVC setPeripheralsDataType:peripheralsDataType];
                    [dataVC.tableView reloadData];
                    if (dataVC.dataArray != nil && [dataVC.dataArray count] > 1) {
                        [dataVC.tableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:(dataVC.dataArray.count-1) inSection:0] atScrollPosition:UITableViewScrollPositionBottom animated:YES];
                    }
                }else{
                    DataViewController *dataVC = [[DataViewController alloc] init];
                    [dataVC setDataArray:[NSMutableArray arrayWithObject:result]];
                    [dataVC setPeripheralsDataType:peripheralsDataType];
                    dataVC.device_id = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? self.device.device_id : self.userDevice.device_id;
                    [strongSelf.navigationController pushViewController:dataVC animated:YES];
                }
            }
        }
    }];
}

#pragma mark - 解绑设备
- (void)unBindAction{
    typeof(self) __weak weakSelf = self;
    
    [[MiaoHealthConnectManager shareInstance] unbindDevice:_userDevice.device_sn deviceNO:_userDevice.device_no bind:^(NSInteger isSuccess, NSString *_Nullable device_no,NSError * _Nullable error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (isSuccess) {
                [weakSelf showMessage:@"解除设备绑定成功"];
                [LEEAlert alert].config
                .LeeTitle(@"温馨提示")
                .LeeContent(@"解除设备绑定成功")
                .LeeAction(@"我知道了", ^{
                    [self.navigationController popViewControllerAnimated:YES];
                })
                .LeeShow(); // 设置完成后 别忘记调用Show来显示
            } else {
                [weakSelf showMessage:[NSString stringWithFormat:@"解除设备绑定失败:%@",error.domain]];
            }
        });
    }];

}

#pragma mark - 断开蓝牙
- (void)disconnectBLEEvent:(id)sender {
    
    [[MiaoHealthConnectManager shareInstance] disconnectBLEDevice:_userDevice.device_id bluetoothStatus:^(BluetoothStatus status) {
        [self showMessage:(BluetoothStatusPowerOff == status) ? @"断开蓝牙成功" : @""];
    }];
}

- (void) showMessage: (NSString *) message {
    [self.messageArray addObject:message];
    [self.view bringSubviewToFront:self.messageTableView];
    [self.messageTableView reloadData];
    
    if (self.messageArray != nil && [self.messageArray count] > 1) {
        [self.messageTableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:(self.messageArray.count-1) inSection:0] atScrollPosition:UITableViewScrollPositionBottom animated:YES];
    }
}

#pragma mark - UITextFieldDelegate
- (BOOL)textFieldShouldReturn:(UITextField *)theTextField {
    [theTextField resignFirstResponder];
    
    return YES;
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
    [self.view endEditing:YES];
}


@end

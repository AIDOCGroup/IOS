//
//  WebDescriptionViewController.m
//  MiaoHealthConnectDemo
//
//  Created by 罗志平 on 17/3/14.
//  Copyright © 2017年 罗志平. All rights reserved.
//

#import "WebDescriptionViewController.h"
//view
#import "SearchEquipmentBackView.h"
//vc
#import "DeviceShowViewController.h"
#import "RecordDataViewController.h"
//
#import "DeviceDetailView.h"
#import "ScanDeviceCell.h"
#import "WebViewController.h"
#import "DemoZFScanViewController.h"
#import "UserInfoView.h"
#import "DataViewController.h"
#import "LEEAlert.h"
#import "SelectedListView.h"
#import "DisplayElderViewController.h"

@interface WebDescriptionViewController ()<UIWebViewDelegate,SearchEquipmentBackViewDelegate>
//UI
@property (strong, nonatomic) UIWebView *webView;
@property (strong, nonatomic) SearchEquipmentBackView *searchEquipmentBackView;
//date
@property (strong, nonatomic) NSMutableArray *resultArray;
@property (strong, nonatomic) NSString *uuid;
@property (nonatomic, assign) BOOL isBLE;

@end

@implementation WebDescriptionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationController.navigationBar.hidden = NO;
    self.view.backgroundColor = [UIColor whiteColor];
    self.webView = [[UIWebView alloc] init];
    self.webView.frame = CGRectMake(0, 0, kMainScreenWidth, kMainScreenHeight-70);
    self.webView.delegate = self;
    self.webView.scalesPageToFit = YES;
    self.webView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.webView];
     [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [self.webView loadRequest:[NSMutableURLRequest requestWithURL:[NSURL URLWithString:[_device des_url]]]];
    
    self.title = [self.device device_name];
    UIButton *bindButton = [[UIButton alloc] initWithFrame:CGRectMake(40, kScreenHeight+kStatusH - 70, kScreenWidth-80, 45)];
    bindButton.clipsToBounds = YES;
    bindButton.layer.cornerRadius = ButtonRoundedCorners;
    bindButton.layer.borderColor = rgbColor(0x08a4d8).CGColor;
    bindButton.layer.borderWidth = 1.0;
    [bindButton setTitle:@"绑定设备" forState:UIControlStateNormal];
    [bindButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    UIColor *topColor = rgbColor(0x6772FF);
    UIColor *bottomColor = rgbColor(0x51E2F7);
    UIImage *bgImg = [UIImage gradientColorImageFromColors:@[topColor, bottomColor] gradientType:GradientTypeLeftToRight imgSize:CGSizeMake(kScreenWidth-80, 45)];
    bindButton.backgroundColor = [UIColor colorWithPatternImage:bgImg];
    [bindButton addTarget:self action:@selector(bindAction) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:bindButton];
}


-(void)webViewDidFinishLoad:(UIWebView *)webView{
    [MBProgressHUD hideHUDForView:self.view animated:YES];
    [[MiaoHealthConnectManager shareInstance] fetchDeviceDetail:self.device.device_sn result:^(NSDictionary * _Nullable deviceDetail, NSError * _Nullable error) {
        NSLog(@"deviceDetail = %@",deviceDetail);
    }];
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error{
    [MBProgressHUD hideHUDForView:self.view animated:YES];
}

- (void)dealloc{
    self.webView.delegate = nil;
}

#pragma mark - action
- (IBAction)bindAction{
    [self bindEquipment];
}

- (void)bindEquipment{
    //绑定设备：开始搜索设备
    [self.resultArray removeAllObjects];
    if (self.device.link_type == PeripheralsAttendedModeWebAuthority) {
        WebViewController *webVC = [[WebViewController alloc] init];
        [webVC setDevice:_device];
        webVC.showMessage = ^(NSString *message,NSString *device_no) {
            _uuid = device_no;
        };
        //[self.navigationController pushViewController:webVC animated:YES];
        
        [self.searchEquipmentBackView show:TypeEquipmentBindingsFailure];
        self.searchEquipmentBackView.showFailureLabel.text = @"该设备不支持蓝牙";
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
        
        //[self presentViewController:vc animated:YES completion:nil];
        [self.searchEquipmentBackView show:TypeEquipmentBindingsFailure];
        self.searchEquipmentBackView.showFailureLabel.text = @"该设备不支持蓝牙";
    } else if (self.device.link_type == PeripheralsAttendedModeBluetooth) {
        [self.searchEquipmentBackView show:TypeSearchEquipment];
        typeof(self) __weak weakSelf = self;
        [[MiaoHealthConnectManager shareInstance] scanBLEDevice:self.device.device_id timeout:10 bluetoothStatus:^(BluetoothStatus status) {
            if(status == BluetoothStatusPowerOff) {
                self.searchEquipmentBackView.showStatusLabel.text = @"蓝牙未开启";
            } else if (status == BluetoothStatusConnectBegin) {
                self.searchEquipmentBackView.showStatusLabel.text = @"开始连接";
            } else if (status == BluetoothStatusConnectSuccess) {
                self.searchEquipmentBackView.showStatusLabel.text = @"连接成功";
            } else if (status == BluetoothStatusConnectFail) {
                [self.searchEquipmentBackView showOther:TypeEquipmentBindingsFailure];
                self.searchEquipmentBackView.showFailureLabel.text = @"连接失败";
            } else if (status == BluetoothStatusDisconnect) {
                [self.searchEquipmentBackView showOther:TypeEquipmentBindingsFailure];
                self.searchEquipmentBackView.showFailureLabel.text = @"连接断开";
            } else if (status == BluetoothStatusTimeout) {
                [self.searchEquipmentBackView showOther:TypeEquipmentBindingsFailure];
                self.searchEquipmentBackView.showFailureLabel.text = @"连接超时";
            } else if (status == BluetoothStatusPowerOn) {
                self.searchEquipmentBackView.showStatusLabel.text = @"蓝牙开启，开始搜索";
            }
        } devices:^(NSArray<MCBLEDevice *> * _Nullable deviceList) {
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.resultArray = [NSMutableArray arrayWithArray:deviceList];
                if ([weakSelf.resultArray count] > 0) {//选择设备
                    self.searchEquipmentBackView.resultArray = weakSelf.resultArray;
                    [self.searchEquipmentBackView showOther:TypeSelectEquipment];
                } else {
                    self.searchEquipmentBackView.showStatusLabel.text = @"蓝牙未搜索到设备";
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
}

#pragma mark - lazy loading
- (SearchEquipmentBackView *)searchEquipmentBackView {
    if (!_searchEquipmentBackView) {
        _searchEquipmentBackView = [[SearchEquipmentBackView alloc] init];
        _searchEquipmentBackView.delegate = self;
    }
    return _searchEquipmentBackView;
}

- (NSMutableArray *)resultArray {
    if (!_resultArray) {
        _resultArray = [NSMutableArray array];
    }
    return _resultArray;
}

#pragma mark - SearchEquipmentBackViewDelegate
//选择设备
- (void)didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __block MCBLEDevice *mcBleDevice = self.resultArray[indexPath.row];
    [self.searchEquipmentBackView showOther:TypeEquipmentBindingsStart];
    _uuid = mcBleDevice.uuid;
    [self checkDevice:_uuid isBLE:true];
}

//取消绑定
- (void)cancelBindingEquipment {
    [self.searchEquipmentBackView dissMiss];
    self.searchEquipmentBackView.showFailureLabel.text = @"";
}

//重新绑定
- (void)rebindEquipment {
    [self.searchEquipmentBackView show:TypeSearchEquipment];
    self.searchEquipmentBackView.showFailureLabel.text = @"";
    [self bindEquipment];
}

#pragma mark - Bind Request
- (void) checkDevice:(NSString *) uuid  isBLE: (BOOL) isBLE {
    _uuid = uuid;
    typeof(self) __weak weakSelf = self;
    [[MiaoHealthConnectManager shareInstance] checkDevice:self.device.device_sn deviceNO:uuid checkBind:^(BindDeviceStatus bindDeviceStatus, NSError * _Nullable error) {
        typeof(self) __strong strongSelf = weakSelf;
        if (error || (bindDeviceStatus == BindDeviceStatusError)) {
            strongSelf.searchEquipmentBackView.showStatusLabel.text = error.domain;
        }else{
            if ((bindDeviceStatus == BindDeviceStatusUnbound) || bindDeviceStatus == BindDeviceStatusOtherBound) {
                [strongSelf bindDevice:uuid isBLE:isBLE];
            }else{
                [self bindingEquipment];
                /*[strongSelf.searchEquipmentBackView showOther:TypeEquipmentBindingsSuccess];
                strongSelf.searchEquipmentBackView.showStatusLabel.text = @"设备已被自己绑定";
                [strongSelf.searchEquipmentBackView dissMiss];
                RecordDataViewController *viewController = [[RecordDataViewController alloc] init];
                viewController.uuid = strongSelf.uuid;
                viewController.device = strongSelf.device;
                viewController.deviceDetailFromEnum = strongSelf.deviceDetailFromEnum;
                viewController.isFromBinding = @"1";
                if (strongSelf.webDescriptionType == WebDescriptionTypeDefault) {
                    viewController.recordDataType = RecordDataTypeSports;
                }else if (strongSelf.webDescriptionType == WebDescriptionTypeWatchBracelet) {//手表或者手环
                    viewController.recordDataType = RecordDataTypeSports;
                }else if (strongSelf.webDescriptionType == WebDescriptionTypeBloodSugar) {//血糖仪
                    viewController.recordDataType = RecordDataTypeBloodSugar;
                }else if (strongSelf.webDescriptionType == WebDescriptionTypeBloodPressure) {//血压计
                    viewController.recordDataType = RecordDataTypeBloodPressure;
                }else if (strongSelf.webDescriptionType == WebDescriptionTypeBodyFat) {//体脂秤
                    viewController.recordDataType = RecordDataTypeBodyFat;
                }else if (strongSelf.webDescriptionType == WebDescriptionTypeHeartRate) {//心率仪
                    viewController.recordDataType = RecordDataTypeHeartRate;
                }
                [strongSelf.navigationController pushViewController:viewController animated:YES];*/
            }
        }
    }];
}

- (void)bindDevice:(NSString *) uuid isBLE:(BOOL) isBLE {
    self.isBLE = isBLE;
    typeof(self) __weak weakSelf = self;
    [[MiaoHealthConnectManager shareInstance] bindDevice:self.device.device_sn deviceNO:uuid bind:^(NSInteger isSuccess,NSString *_Nullable device_no, NSError * _Nullable error) {
        typeof(self) __strong strongSelf = weakSelf;
        if (isSuccess == 1) {
            if (!isBLE) {
                _uuid = device_no;
            }
            [self bindingEquipment];
        } else {
            [strongSelf.searchEquipmentBackView showOther:TypeEquipmentBindingsFailure];
            strongSelf.searchEquipmentBackView.showFailureLabel.text = [NSString stringWithFormat:@"绑定失败:%@",error.domain];
        }
    }];
}

#pragma mark - 绑定设备服务端
- (void)bindingEquipment {
    NSDictionary *dic = @{@"deviceId":[self.device device_id],
                          @"deviceName":[self.device device_name],
                          @"uuid":_uuid,
                          @"deviceSn":[self.device device_sn],
                          @"desUrl":[self.device des_url],
                          @"linkType":@"1",
                          @"deviceDes":[self.device device_des],
                          @"bindNum":[NSString stringWithFormat:@"%ld",(long)self.device.bindnum],
                          @"bindStatus":[NSString stringWithFormat:@"%ld",(long)self.device.bind_status],
                          @"logo":[self.device logo],
                          @"tid":self.deviceType.tid,
                          @"typeName":self.deviceType.type_name,
                          @"typeDesc":self.deviceType.type_desc,
                          @"typeLogo":self.deviceType.logo
                          };
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [YTNetworkRequest saveMyDeviceWithDic:dic success:^(id result) {
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        self.searchEquipmentBackView.showStatusLabel.text = @"绑定成功";
        [self.searchEquipmentBackView dissMiss];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            RecordDataViewController *viewController = [[RecordDataViewController alloc] init];
            viewController.uuid = self.uuid;
            viewController.device = self.device;
            viewController.deviceDetailFromEnum = self.deviceDetailFromEnum;
            viewController.isFromBinding = @"1";
            if (self.webDescriptionType == WebDescriptionTypeDefault) {
                viewController.recordDataType = RecordDataTypeSports;
            }else if (self.webDescriptionType == WebDescriptionTypeWatchBracelet) {//手表或者手环
                viewController.recordDataType = RecordDataTypeSports;
            }else if (self.webDescriptionType == WebDescriptionTypeBloodSugar) {//血糖仪
                viewController.recordDataType = RecordDataTypeBloodSugar;
            }else if (self.webDescriptionType == WebDescriptionTypeBloodPressure) {//血压计
                viewController.recordDataType = RecordDataTypeBloodPressure;
            }else if (self.webDescriptionType == WebDescriptionTypeBodyFat) {//体脂秤
                viewController.recordDataType = RecordDataTypeBodyFat;
            }else if (self.webDescriptionType == WebDescriptionTypeHeartRate) {//心率仪
                viewController.recordDataType = RecordDataTypeHeartRate;
            }else if (self.webDescriptionType == WebDescriptionTypeTemperature) {//体温计
                viewController.recordDataType = RecordDataTypeTemperature;
            }

            [self.navigationController pushViewController:viewController animated:YES];
        });
    } failure:^(NSString *error) {
        [MBProgressHUD hideHUDForView:self.view animated:YES];
    }];
}

@end

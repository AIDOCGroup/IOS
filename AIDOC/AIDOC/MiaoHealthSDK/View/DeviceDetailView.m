//
//  DeviceDetailView.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceDetailView.h"

@interface DeviceDetailView ()

@property (nonatomic , weak) UIImageView *iconView;

@property (nonatomic , weak) UILabel *nameLabel;

@property (nonatomic , weak) UILabel *linkTypeLabel;

@property (nonatomic , weak) UIButton *buttonOne;

@property (nonatomic , weak) UIButton *buttonThree;

@end

@implementation DeviceDetailView

+ (DeviceDetailView *)deviceDetailViewWithFrame:(CGRect)frame{
    return [[self alloc ] initWithFrame:frame];
}

- (instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        
        UIImageView *iconView = [[UIImageView alloc] init];
        [self addSubview:iconView];
        self.iconView = iconView;
        
        UILabel *nameLabel = [[UILabel alloc] init];
        nameLabel.numberOfLines = 0;
        nameLabel.textColor = [UIColor blackColor];
        nameLabel.font = [UIFont systemFontOfSize:15];
        [self addSubview:nameLabel];
        self.nameLabel = nameLabel;
        
        UILabel *linkTypeLabel = [[UILabel alloc] init];
        linkTypeLabel.font = [UIFont systemFontOfSize:13];
        linkTypeLabel.textColor = [UIColor lightGrayColor];
        [self addSubview:linkTypeLabel];
        self.linkTypeLabel = linkTypeLabel;
        
        UIButton *buttonOne = [[UIButton alloc] init];
        buttonOne.layer.borderColor = [UIColor groupTableViewBackgroundColor].CGColor;
        buttonOne.layer.borderWidth = 1;
        buttonOne.titleLabel.textAlignment = NSTextAlignmentLeft;
        [buttonOne setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        buttonOne.titleLabel.font = [UIFont systemFontOfSize:15];
        [buttonOne addTarget:self action:@selector(clickAction:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:buttonOne];
        self.buttonOne = buttonOne;
        
        UIButton *buttonTwo = [[UIButton alloc] init];
        [buttonTwo setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        buttonTwo.layer.borderColor = [UIColor groupTableViewBackgroundColor].CGColor;
        buttonTwo.layer.borderWidth = 1;
        buttonTwo.titleLabel.font = [UIFont systemFontOfSize:15];
        buttonTwo.titleLabel.textAlignment = NSTextAlignmentLeft;
//        buttonTwo.enabled = NO;
        [buttonTwo addTarget:self action:@selector(clickAction:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:buttonTwo];
        self.buttonTwo = buttonTwo;
        
        UIButton *buttonThree = [[UIButton alloc] init];
        buttonThree.layer.borderColor = [UIColor groupTableViewBackgroundColor].CGColor;
        buttonThree.layer.borderWidth = 1;
        [buttonThree setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        buttonThree.titleLabel.font = [UIFont systemFontOfSize:15];
        buttonThree.titleLabel.textAlignment = NSTextAlignmentLeft;
        [buttonThree addTarget:self action:@selector(clickAction:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:buttonThree];
        self.buttonThree = buttonThree;
        
        [self.iconView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.mas_left).offset(15);
            make.top.mas_equalTo(self.mas_top).offset(15);
            make.size.mas_equalTo(CGSizeMake(70, 70));
        }];
        
        [self.nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.iconView.mas_right).offset(10);
            make.top.mas_equalTo(self.iconView.mas_top);
            make.right.mas_equalTo(self.mas_right).offset(15);
        }];
        
        [self.linkTypeLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.nameLabel.mas_left);
            make.top.mas_equalTo(self.nameLabel.mas_bottom).offset(5);
            make.size.mas_equalTo(CGSizeMake(100, 20));
        }];
        
        [self.buttonOne mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.linkTypeLabel.mas_left);
            make.top.mas_equalTo(self.linkTypeLabel.mas_bottom);
            CGFloat width = (kMainScreenWidth - 100) / 3;
            make.size.mas_equalTo(CGSizeMake(width - 10, 30));
        }];
        
        [self.buttonTwo mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.buttonOne.mas_right).offset(5);
            make.top.mas_equalTo(self.buttonOne.mas_top);
            CGFloat width = (kMainScreenWidth - 100) / 3;
            make.size.mas_equalTo(CGSizeMake(width + 10, 30));
        }];
        
        [self.buttonThree mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.buttonTwo.mas_right).offset(5);
            make.top.mas_equalTo(self.buttonTwo.mas_top);
            CGFloat width = (kMainScreenWidth - 100) / 3;
            make.size.mas_equalTo(CGSizeMake(width - 10, 30));
        }];
        
    }
    return self;
}

- (void)setDeviceDetailFromEnum:(DeviceDetailFromEnum)deviceDetailFromEnum{
    _deviceDetailFromEnum = deviceDetailFromEnum;
    if (deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) { //从设备类型进来
        [self.buttonOne setTitle:@"绑定设备" forState:UIControlStateNormal];
        self.buttonOne.tag = 1000 + 1;
        [self.buttonTwo setTitle:@"获取最新数据" forState:UIControlStateNormal];
        self.buttonTwo.tag = 1000 + 2;
        [self.buttonThree setTitle:@"历史数据" forState:UIControlStateNormal];
        self.buttonThree.tag = 1000 + 3;
    }else{ //从已绑定设备列表进来
        [self.buttonOne setTitle:@"历史数据" forState:UIControlStateNormal];
        self.buttonOne.tag = 1000 + 4;
        [self.buttonTwo setTitle:@"当前数据" forState:UIControlStateNormal];
        self.buttonTwo.tag = 1000 + 2;
        [self.buttonThree setTitle:@"断开蓝牙" forState:UIControlStateNormal];
        self.buttonThree.tag = 1000 + 5;
    }
//    self.buttonTwo.enabled = (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? NO : YES;
}

- (void)setDevice:(MCDevice *)device{
    _device = device;
    [self.iconView sd_setImageWithURL:[NSURL URLWithString:device.logo] placeholderImage:[UIImage imageNamed:@""]];
    self.nameLabel.text = device.device_name;
    switch (device.link_type) {
        case PeripheralsAttendedModeBluetooth:
            self.linkTypeLabel.text = @"蓝牙设备";
            break;
        case PeripheralsAttendedModeQRCode:
            self.linkTypeLabel.text = @"二维码设备";
            break;
        case PeripheralsAttendedModeWebAuthority:
            self.linkTypeLabel.text = @"Web授权设备";
            break;
        case PeripheralsAttendedModePort:
            self.linkTypeLabel.text = @"端口接入设备";
            break;
        case PeripheralsAttendedModeWifi:
            self.linkTypeLabel.text = @"wifi接入设备";
            break;
        default:
            self.linkTypeLabel.text = @"未知设备";
            break;
    }
    if (device.device_sn.intValue == -1) {
        self.buttonOne.hidden = YES;
    }
}

- (void)setUserDevice:(MCUserDevice *)userDevice{
    _userDevice = userDevice;
    [self.iconView sd_setImageWithURL:[NSURL URLWithString:userDevice.logo] placeholderImage:[UIImage imageNamed:@""]];
    self.nameLabel.text = userDevice.device_name;
    switch (userDevice.link_type) {
        case PeripheralsAttendedModeBluetooth:
            self.linkTypeLabel.text = @"蓝牙设备";
            break;
        case PeripheralsAttendedModeQRCode:
            self.linkTypeLabel.text = @"二维码设备";
            break;
        case PeripheralsAttendedModeWebAuthority:
            self.linkTypeLabel.text = @"Web授权设备";
            break;
        case PeripheralsAttendedModePort:
            self.linkTypeLabel.text = @"端口接入设备";
            break;
        case PeripheralsAttendedModeWifi:
            self.linkTypeLabel.text = @"wifi接入设备";
            break;
        default:
            self.linkTypeLabel.text = @"未知设备";
            break;
    }
    if (userDevice.device_sn.intValue == -1) {
        self.buttonOne.hidden = YES;
    }
}

- (void)clickAction:(UIButton *)sender{
    NSInteger tag = sender.tag - 1000;
    if (tag == 2) {
        self.buttonActionBlock(ButtonActionTypeEnumGetNewData);
    }else if(tag == 1){
        self.buttonActionBlock(ButtonActionTypeEnumBindDevice);
    }else if (tag == 3 || tag == 4){
        self.buttonActionBlock(ButtonActionTypeEnumGetHistoryData);
    }else if (tag == 5){
        self.buttonActionBlock(ButtonActionTypeEnumDisConnectBlE);
    }
}

@end

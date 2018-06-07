//
//  ScanDeviceCell.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "ScanDeviceCell.h"

@interface ScanDeviceCell ()

@property (nonatomic , weak) UILabel *nameLabel;

@end

@implementation ScanDeviceCell

+ (ScanDeviceCell *)scanDeviceCellWithTableView:(UITableView *)tableView indexPath:(NSIndexPath *)indexPath{
    ScanDeviceCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ScanDeviceCell" forIndexPath:indexPath];
    if (!cell) {
        cell = [[ScanDeviceCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"ScanDeviceCell"];
    }
    return cell;
}


- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        UILabel *nameLabel = [[UILabel alloc] init];
        nameLabel.font = [UIFont systemFontOfSize:15];;
        nameLabel.textColor = [UIColor blackColor];
        nameLabel.textAlignment = NSTextAlignmentCenter;
        [self.contentView addSubview:nameLabel];
        self.nameLabel = nameLabel;
        
        [self.nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerX.mas_equalTo(self.contentView.mas_centerX);
            make.centerY.mas_equalTo(self.contentView.mas_centerY);
            make.size.mas_equalTo(CGSizeMake(kMainScreenWidth, 20));
        }];
        
        self.mj_h = 60;
    }
    return self;
}

- (void)setDevice:(MCBLEDevice *)device{
    _device = device;
    self.nameLabel.text = device.name;
}
@end

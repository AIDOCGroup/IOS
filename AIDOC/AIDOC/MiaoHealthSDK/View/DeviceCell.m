//
//  DeviceCell.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceCell.h"
@interface DeviceCell()

@property (weak, nonatomic) IBOutlet UILabel *numLabel;
@property (weak, nonatomic) IBOutlet UIImageView *deviceImageView;
@property (weak, nonatomic) IBOutlet UILabel *descLabel;
@property (weak, nonatomic) IBOutlet UILabel *enDescLabel;

@end

@implementation DeviceCell
+ (DeviceCell *)deviceCell{
    return (DeviceCell *)[[[NSBundle mainBundle] loadNibNamed:@"DeviceCell" owner:nil options:nil] lastObject];
}
- (void)awakeFromNib {
    [super awakeFromNib];
    self.mj_w = kMainScreenWidth;
    self.deviceImageView.mj_size = CGSizeMake(70, 70);
    // Initialization code
}

- (void)setNum:(NSString *)num{
    _num = num;
    self.numLabel.text = num;
}

- (void)setImageString:(NSString *)imageString{
    _imageString = imageString;
    [self.deviceImageView sd_setImageWithURL:[NSURL URLWithString:imageString]];
}

- (void)setDescString:(NSString *)descString{
    _descString = descString;
    self.descLabel.text = descString;
}

- (void)setEnDescString:(NSString *)enDescString{
    _enDescString = enDescString;
    self.enDescLabel.text = enDescString;
}
@end

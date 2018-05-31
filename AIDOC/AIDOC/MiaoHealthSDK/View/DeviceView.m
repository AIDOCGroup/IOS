//
//  DeviceView.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceView.h"

@interface DeviceView()
@property (weak, nonatomic) IBOutlet UILabel *nameLabel;
@property (weak, nonatomic) IBOutlet UILabel *enNameLabel;
@property (weak, nonatomic) IBOutlet UILabel *descriptionLabel;
@property (weak, nonatomic) IBOutlet UILabel *enDescriptionLabel;
@property (weak, nonatomic) IBOutlet UILabel *urlLabel;


@end

@implementation DeviceView

+ (DeviceView *)deviceView{
    return (DeviceView *)[[[NSBundle mainBundle] loadNibNamed:@"DeviceView" owner:nil options:nil] lastObject];
}

- (void)awakeFromNib{
    [super awakeFromNib];
    UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(clickAction)];
    self.urlLabel.userInteractionEnabled = YES;
    [self.urlLabel addGestureRecognizer:gesture];
}

- (void)setName:(NSString *)name{
    _name = name;
    self.nameLabel.text = name;
}

- (void)setEnDesc:(NSString *)enDesc{
    _enDesc = enDesc;
    self.enDescriptionLabel.text = enDesc;
}

- (void)setEnName:(NSString *)enName{
    _enName = enName;
    self.enNameLabel.text = enName;
}

- (void)setDesc:(NSString *)desc{
    _desc = desc;
    self.descriptionLabel.text = desc;
}

- (void)setUrl:(NSString *)url{
    _url = url;
    self.urlLabel.text = url;
}

- (void)clickAction{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:self.url]];
}
@end

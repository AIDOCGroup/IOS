//
//  DeviceTypeCell.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/13.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MiaoHealthConnect/MCDevice.h>

@interface DeviceTypeCell : UICollectionViewCell

@property (nonatomic , weak) MCDeviceType *deviceType;

+ (DeviceTypeCell *)deviceTypeCell:(UICollectionView *)collectionView indexPath:(NSIndexPath *)indexPath;

@end

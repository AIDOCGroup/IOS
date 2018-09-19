//
//  HomeAssetsCell.h
//  TYToken
//
//  Created by app on 2018/8/20.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AddAssetsModel.h"
@interface HomeAssetsCell : UITableViewCell

@property(nonatomic,assign)BOOL isFreezeCount;

@property(nonatomic, strong)AddAssetsModel *model;
@end

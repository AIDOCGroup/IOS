//
//  SolveMapCell.h
//  AlarmDemo
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SolveModel.h"
@interface SolveMapCell : UITableViewCell
@property (nonatomic,strong)UILabel *itemName;
@property (nonatomic,copy)NSString *imgStr;
@property (nonatomic, assign)BOOL isWhiteColor;
@property (nonatomic, strong)SolveModel *solveModel;

@end

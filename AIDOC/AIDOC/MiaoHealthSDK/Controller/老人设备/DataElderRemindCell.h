//
//  DataElderRemindCell.h
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MiaoHealthConnect/MiaoHealthConnect.h>
@class DataElderRemindCell;

@protocol DataElderRemindCellDelegate <NSObject>

- (void)dataElderRemindCell:(DataElderRemindCell *)dataElderRemindCell showOrHidePickerView:(BOOL)show tag:(NSInteger)tag;

@end

@interface DataElderRemindCell : UITableViewCell

@property (nonatomic, assign) BOOL isAdd;

@property (nonatomic, strong) MCElderRemind *remind;

@property (nonatomic, strong) NSString *alerMessage;

@property (weak, nonatomic) IBOutlet UITextField *startAtTf;
@property (weak, nonatomic) IBOutlet UITextField *startTimeTf;
@property (weak, nonatomic) IBOutlet UIButton *remindTypeTf;
@property (weak, nonatomic) IBOutlet UIButton *repeatTypeTf;
@property (weak, nonatomic) IBOutlet UITextField *contentTf;

//获取选中的textField
@property (weak, nonatomic) UIButton *selectedButton;

@property (nonatomic , assign) NSInteger selectedTypeRow;

@property (nonatomic , assign) NSInteger selectedRepeatedRow;

@property (nonatomic , weak) id<DataElderRemindCellDelegate> delegate;

@end

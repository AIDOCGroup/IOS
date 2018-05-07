//
//  DataElderRelationCell.h
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MiaoHealthConnect/MiaoHealthConnect.h>

@interface DataElderRelationCell : UITableViewCell

@property (nonatomic, assign) BOOL isAdd;

@property (nonatomic, strong) MCElderRelation *relation;

@property (nonatomic, strong) NSString *alerMessage;

@property (weak, nonatomic) IBOutlet UITextField *nameTf;
@property (weak, nonatomic) IBOutlet UITextField *mobileTf;


@end

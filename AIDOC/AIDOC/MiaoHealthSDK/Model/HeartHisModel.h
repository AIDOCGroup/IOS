//
//  HeartHisModel.h
//  AIDOC
//
//  Created by app on 2018/3/26.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseModel.h"
#import "HeartModel.h"
@interface HeartHisModel : BaseModel
@property (nonatomic , copy) NSString *day;   //日期
@property (nonatomic , copy) NSMutableArray *list;   

//@property (nonatomic , copy) NSString *date;   //日期
//@property (nonatomic , copy) NSString *time;   //年月日
//@property (nonatomic , copy) NSString *value;  //步数
@property (nonatomic , strong) HeartModel *heartModel;  //步数
@end

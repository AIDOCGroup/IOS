//
//  HeartModel.h
//  AIDOC
//
//  Created by app on 2018/3/26.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseModel.h"

@interface HeartModel : BaseModel
@property (nonatomic , copy) NSString *date;   //日期
@property (nonatomic , copy) NSString *time;   //年月日
@property (nonatomic , copy) NSString *value;  //
@property (nonatomic , copy) NSString *heart;  //脉搏


@end

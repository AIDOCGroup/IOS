//
//  HistoricalRecordModel.h
//  AIDOC
//
//  Created by app on 2018/3/25.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseModel.h"

@interface HistoricalRecordModel : BaseModel

@property (nonatomic , copy) NSString *date;   //日期
@property (nonatomic , copy) NSString *time;   //年月日
@property (nonatomic , copy) NSString *value;  //步数
@property (nonatomic , copy) NSString *kral;  //心率


@end

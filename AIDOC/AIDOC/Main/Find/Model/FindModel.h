//
//  FindModel.h
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseModel.h"

@interface FindModel : BaseModel

@property (nonatomic) int64_t postId;   //数据Id
@property (nonatomic) int64_t postCreateOn; //创建时间
@property (nonatomic) int64_t forward_num;//分享次数
@property (nonatomic) int64_t watch_num;//观看次数
@property (nonatomic,strong) NSString *title;  //新闻标题
@property (nonatomic,strong) NSString *url;

@end

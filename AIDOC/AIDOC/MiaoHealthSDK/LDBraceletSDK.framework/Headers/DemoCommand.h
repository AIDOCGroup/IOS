//
//  newCommand.h
//  LianLianPayReader
//
//  Created by HudongFang on 16/7/1.
//  Copyright © 2016年 LANDI. All rights reserved.
//

#import "BaseCommandCell.h"

typedef void (^onDelRecord)(void);
@interface DemoCommand : BaseCommandCell
@property(nonatomic,strong) onDelRecord successBlock;
@end

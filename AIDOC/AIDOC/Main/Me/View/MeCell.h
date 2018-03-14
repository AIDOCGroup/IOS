//
//  MeCell.h
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MeCell;

@protocol MeCellDelegate <NSObject>

/**
 *  点击Cell上的Button
 */
- (void)clickCellBtn:(NSInteger)tag andCellNum:(NSInteger)cellNum;

@end

@interface MeCell : UITableViewCell
@property(nonatomic,strong)NSArray *imgArr;
@property(nonatomic,strong)NSArray *titleArr;
@property (nonatomic,weak) id <MeCellDelegate> delegate;
@end

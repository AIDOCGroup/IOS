//
//  RadioButton.h
//  RadioButton
//
//  Created by ohkawa on 11/03/23.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol RadioButtonDelegate <NSObject>
-(void)radioButtonSelectedAtIndex:(NSUInteger)index inGroup:(NSString*)groupId;
@end

@interface RadioButton : UIView {
    NSString *_groupId;
    NSUInteger _index;
    UIButton *_button;
    UIImageView *_sexImgView;
    UILabel *_sexName;
}

@property(nonatomic,retain) NSString *groupId;
@property(nonatomic,assign) NSUInteger index;
@property(nonatomic,assign) BOOL  selectedSexBtn;
/**
 *  性别
 */
@property(nonatomic,copy) NSString *sex;
/**
 *  性别图片
 */
@property(nonatomic,copy) NSString *sexImg;


-(id)initWithGroupId:(NSString*)groupId index:(NSUInteger)index;
+(void)addObserverForGroupId:(NSString*)groupId observer:(id)observer;


@end

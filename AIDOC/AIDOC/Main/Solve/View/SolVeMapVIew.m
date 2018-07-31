//
//  SolVeMapVIew.m
//  AlarmDemo
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "SolVeMapVIew.h"
#import "SolveMapCell.h"
#import "SolveModel.h"
@interface SolVeMapVIew()<UITableViewDelegate,UITableViewDataSource>

@property(nonatomic, strong)UITableView *tableView;
@property(nonatomic, strong)SolveModel *solveModel;

@end

@implementation SolVeMapVIew
- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, frame.size.width, frame.size.height)];
        _tableView.backgroundColor = [UIColor colorWithWhite:0.1 alpha:0.5];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _tableView.clipsToBounds =YES;
        _tableView.layer.cornerRadius = 8;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [self addSubview:_tableView];
        
        _solveModel = [[SolveModel alloc] init];
        
    }
    return self;
}

- (void)setArr:(NSMutableArray *)arr
{
    _arr = arr;
}

#pragma -mark UITableViewDelegate,UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 3;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identify = @"SolveMapCell";
    SolveMapCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
    if (cell == nil) {
        cell = [[SolveMapCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    _solveModel = self.arr[0];
    
    if (indexPath.row == 0){
        
        cell.imgStr = @"equipment_count_icon";
        cell.itemName.text = [NSString stringWithFormat:@"%@",_solveModel.equipmentCount];
        cell.isWhiteColor = YES;
        
    }else if (indexPath.row == 1){
        cell.imgStr = @"主页面_06";
        cell.itemName.text = [NSString stringWithFormat:@"%@/%@",_solveModel.alarmCount,_solveModel.alarmExpireNum];
        cell.isWhiteColor = NO;
        
    }else if (indexPath.row == 2){
        
        cell.imgStr = @"equipment_count_icon";
        cell.itemName.text = [NSString stringWithFormat:@"%@/%@",_solveModel.dangerCount,_solveModel.dangerExpireNum];
        cell.isWhiteColor = NO;
        
    }
    
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 30;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
    if ([self.delegate respondsToSelector:@selector(toSloveCall:)]) {
        
        _solveModel = self.arr[0];
        [self.delegate toSloveCall:_solveModel.buildID];
    }

}
@end

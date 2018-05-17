//
//  DataCell.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/18.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DataCell.h"

@interface DataCell ()
@property (weak, nonatomic) IBOutlet UILabel *oneLabel;
@property (weak, nonatomic) IBOutlet UILabel *twoLabel;
@property (weak, nonatomic) IBOutlet UILabel *threeLabel;
@property (weak, nonatomic) IBOutlet UILabel *fourLabel;
@property (weak, nonatomic) IBOutlet UILabel *fiveLabel;
@property (weak, nonatomic) IBOutlet UILabel *sixLabel;
@property (weak, nonatomic) IBOutlet UILabel *sevenLabel;
@property (weak, nonatomic) IBOutlet UILabel *eightLabel;
@property (weak, nonatomic) IBOutlet UILabel *nineLabel;
@property (weak, nonatomic) IBOutlet UILabel *tenLabel;
@property (weak, nonatomic) IBOutlet UILabel *elevenLabel;
@property (weak, nonatomic) IBOutlet UILabel *twelveLabel;
@property (weak, nonatomic) IBOutlet UILabel *thirtenLabel;
@property (weak, nonatomic) IBOutlet UILabel *fourteenLabel;
@property (weak, nonatomic) IBOutlet UILabel *fifteenLabel;
@property (weak, nonatomic) IBOutlet UILabel *sixteenLabel;
@property (weak, nonatomic) IBOutlet UILabel *seventeenLabel;
@property (weak, nonatomic) IBOutlet UILabel *eightteenLabel;
@property (weak, nonatomic) IBOutlet UILabel *nineteenLabel;
@property (weak, nonatomic) IBOutlet UILabel *twentyLabel;

@end

@implementation DataCell

+ (DataCell *)dataCell{
    return (DataCell *)[[NSBundle mainBundle] loadNibNamed:@"DataCell" owner:nil options:nil].lastObject;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setPeripheralsDataType:(PeripheralsDataType)peripheralsDataType{
    _peripheralsDataType = peripheralsDataType;
    if (_peripheralsDataType == PeripheralsDataTypeBloodSugar || _peripheralsDataType == PeripheralsDataTypeThermometer || _peripheralsDataType == PeripheralsDataTypeWeighing || _peripheralsDataType == PeripheralsDataTypeHeartRate) {
        // 8为行间距
        self.mj_h = (21 + 8) * 4 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeSleep ||  _peripheralsDataType == PeripheralsDataTypeOximeter ) {
        self.mj_h = (21 + 8) * 7 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeBloodPressure || _peripheralsDataType ==PeripheralsDataTypeSport) {
        self.mj_h = (21 + 8) * 5 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeBodyFat) {
        self.mj_h = (21 + 8) * 15 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeUroscopy){
        self.mj_h = (21 + 8) * 9 +40;
    } else if (_peripheralsDataType == PeripheralsDataTypeSleepPro){
        self.mj_h = (21 + 8) * 17 + 40;
    }
}

- (void)setData:(id)data{
    _data = data;
    for (UIView *subView in self.contentView.subviews) {
        subView.hidden = YES;
    }
    if (self.peripheralsDataType == PeripheralsDataTypeBloodSugar) {
        MCBloodSugar *bloodSugar = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"血糖值 :%.2f", bloodSugar.glucose_value]];
        
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[bloodSugar.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.twoLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.threeLabel setText:[NSString stringWithFormat:@"测量源 :%@", bloodSugar.data_source != nil ? bloodSugar.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeBloodPressure) {
        MCBloodPressure *bloodPressuer = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"高血压值 :%.1ld", (long)bloodPressuer.high_press]];
        [self.twoLabel setText:[NSString stringWithFormat:@"低血压值 :%.1ld", (long)bloodPressuer.low_press]];
        [self.threeLabel setText:[NSString stringWithFormat:@"心率 :%.1ld 每分钟", (long)bloodPressuer.heart_rate]];
        
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[bloodPressuer.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.fourLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.fiveLabel setText:[NSString stringWithFormat:@"测量源 :%@", bloodPressuer.data_source != nil ? bloodPressuer.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = self.fourLabel.hidden = self.fiveLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeThermometer) {
        MCThermometer *thermometer = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"温度 :%.2f 摄氏度", thermometer.temperature]];
        
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[thermometer.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.twoLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.threeLabel setText:[NSString stringWithFormat:@"测量源 :%@", thermometer.data_source != nil ? thermometer.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeWeighing) {
        MCWeight *weight = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"体重 :%.1f KG", weight.weight]];
        [self.twoLabel setText:[NSString stringWithFormat:@"BMI :%.1f", weight.bmi]];
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[weight.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.threeLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.fourLabel setText:[NSString stringWithFormat:@"测量源 :%@", weight.data_source != nil ? weight.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = self.fourLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeBodyFat) {
        MCWeight *weight = data;
        //        [self.label1 setText:[NSString stringWithFormat:@"身高 :%.1ld", (long)weight.height]];
        [self.oneLabel setText:[NSString stringWithFormat:@"体重 :%.1f KG", weight.weight]];
        [self.twoLabel setText:[NSString stringWithFormat:@"BMI :%.1f ", weight.bmi]];
        [self.threeLabel setText:[NSString stringWithFormat:@"体脂率 :%.1f", weight.fat_ratio]];
        [self.fourLabel setText:[NSString stringWithFormat:@"肌肉量 :%.1f KG", weight.muscle]];
        [self.fiveLabel setText:[NSString stringWithFormat:@"骨重 :%.1f", weight.bone_mass]];
        [self.sixLabel setText:[NSString stringWithFormat:@"基础代谢 :%.1f", weight.metabolism]];
        [self.sevenLabel setText:[NSString stringWithFormat:@"体水分 :%.1f", weight.moisture]];
        [self.eightLabel setText:[NSString stringWithFormat:@"皮下脂肪 :%.1f", weight.subcutaneousFat]];
        [self.nineLabel setText:[NSString stringWithFormat:@"蛋白率 :%.1f", weight.proteinRate]];
        [self.tenLabel setText:[NSString stringWithFormat:@"内脏脂肪 :%.1f", weight.visceralFat]];
        [self.elevenLabel setText:[NSString stringWithFormat:@"生理年龄 :%.1f", weight.physicalAge]];
        [self.twelveLabel setText:[NSString stringWithFormat:@"阻抗值 :%.1d", weight.newAdc]];
        
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[weight.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.thirtenLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.fourteenLabel setText:[NSString stringWithFormat:@"测量源 :%@", weight.data_source != nil ? weight.data_source : @"本地数据源"]];
        
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = self.fourLabel.hidden = self.fiveLabel.hidden = self.sixLabel.hidden = self.sevenLabel.hidden = self.eightLabel.hidden = self.nineLabel.hidden = self.tenLabel.hidden = self.elevenLabel.hidden = self.twoLabel.hidden = self.thirtenLabel.hidden = self.fourteenLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeSport) {
        MCSport *sport = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"步数 :%.1ld 步", (long)sport.steps]];
        [self.twoLabel setText:[NSString stringWithFormat:@"卡路里 :%.2f kcal", sport.calories]];
        [self.threeLabel setText:[NSString stringWithFormat:@"距离 :%.1f M", sport.distance]];
        if (sport.showSleep) {
            [self.fourLabel setText:[NSString stringWithFormat:@"睡眠时间 :%.1ld 秒", (long)sport.duration]];
            [self.fiveLabel setText:[NSString stringWithFormat:@"有效睡眠时间 :%.1ld 秒", (long)sport.effect_duration]];
            NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[sport.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
            [self.sixLabel setText:[time substringToIndex:time.length - 5]];
            
            [self.sevenLabel setText:[NSString stringWithFormat:@"测量源 :%@", sport.data_source != nil ? sport.data_source : @"本地数据源"]];
            self.fourLabel.hidden = self.fiveLabel.hidden = self.sixLabel.hidden = self.sevenLabel.hidden = NO;
        }else{
            NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[sport.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
            [self.fourLabel setText:[time substringToIndex:time.length - 5]];
            [self.fiveLabel setText:[NSString stringWithFormat:@"测量源 :%@", sport.data_source != nil ? sport.data_source : @"本地数据源"]];
            self.fourLabel.hidden = self.fiveLabel.hidden = NO;
        }
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeSleep) {
        MCSleep *sleep = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"总睡眠时 间 :%.1ld 秒", (long)sleep.duration]];
        [self.twoLabel setText:[NSString stringWithFormat:@"有效睡眠时间 :%.1ld 秒", (long)sleep.effect_duration]];
        [self.threeLabel setText:[NSString stringWithFormat:@"深睡眠时间 :%.1ld 秒", (long)sleep.deep_duration]];
        [self.fourLabel setText:[NSString stringWithFormat:@"浅睡眠时间 :%.1ld 秒", (long)sleep.light_duration]];
        [self.fiveLabel setText:[NSString stringWithFormat:@"开始时间 :%@",[self timestampSwitchTime:[sleep.startTime doubleValue] andFormatter:@"yyyy-MM-dd HH:mm:ss"]]];
        [self.sixLabel setText:[NSString stringWithFormat:@"结束时间 :%@", [self timestampSwitchTime:[sleep.endTime doubleValue] andFormatter:@"yyyy-MM-dd HH:mm:ss"]]];
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[sleep.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.sevenLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.eightLabel setText:[NSString stringWithFormat:@"测量源 :%@", sleep.data_source != nil ? sleep.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = self.fourLabel.hidden = self.fiveLabel.hidden = self.sixLabel.hidden = self.sevenLabel.hidden = self.eightLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeHeartRate) {
        MCHeartRate *heartRate = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"心率 :%.1ld 每分钟", (long)heartRate.heartRate]];
        
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[heartRate.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.twoLabel setText:[time substringToIndex:time.length - 5]];
        
        
        [self.threeLabel setText:[NSString stringWithFormat:@"测量源 :%@", heartRate.data_source != nil ? heartRate.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeOximeter) {
        MCOximeter *oximeter = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"血氧 :%.1ld ", (long)oximeter.spO2]];
        [self.twoLabel setText:[NSString stringWithFormat:@"心率 :%@", @(oximeter.heartRate)]];
        
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[oximeter.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.threeLabel setText:[time substringToIndex:time.length - 5]];
        [self.fourLabel setText:[NSString stringWithFormat:@"测量源 :%@", oximeter.data_source != nil ? oximeter.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = self.fourLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataMultiply) {
        MCMultiplyDevice *device = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"睡眠时间 :%.1ld 秒", (long)device.duration]];
        [self.twoLabel setText:[NSString stringWithFormat:@"有效睡眠时间 :%.1ld 秒", (long)device.effect_duration]];
        
        [self.threeLabel setText:[NSString stringWithFormat:@"步数 :%.1ld 步", (long)device.steps]];
        [self.fourLabel setText:[NSString stringWithFormat:@"卡路里 :%.1f cal", device.calories]];
        [self.fiveLabel setText:[NSString stringWithFormat:@"距离 :%.1f M", device.distance]];
        
        [self.sixLabel setText:[NSString stringWithFormat:@"测量日期 :%@", device.date_time]];
        [self.sevenLabel setText:[NSString stringWithFormat:@"测量源 :%@", device.data_source != nil ? device.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = self.fourLabel.hidden = self.fiveLabel.hidden = self.sixLabel.hidden = self.sevenLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeUroscopy){
        MCUroscopy *uroscopy = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"蛋白质:%@", uroscopy.pro]];
        [self.twoLabel setText:[NSString stringWithFormat:@"酸碱度:%0.2f", uroscopy.ph]];
        [self.threeLabel setText:[NSString stringWithFormat:@"潜血:%@", uroscopy.bld]];
        [self.fourLabel setText:[NSString stringWithFormat:@"尿比重：%0.2f", uroscopy.sg]];
        [self.fiveLabel setText:[NSString stringWithFormat:@"微量白蛋白:%ld mg/L",(long)uroscopy.ma]];
        [self.sixLabel setText:[NSString stringWithFormat:@"肌酐:%0.2fmmol/L", uroscopy.cr]];
        [self.sevenLabel setText:[NSString stringWithFormat:@"微量白蛋白与肌酐的比值:%0.2f",uroscopy.acr]];
        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[uroscopy.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.eightLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.nineLabel setText:[NSString stringWithFormat:@"测量源 :%@", uroscopy.data_source != nil ? uroscopy.data_source : @"本地数据源"]];
        self.oneLabel.hidden = self.twoLabel.hidden = self.threeLabel.hidden = self.fourLabel.hidden = self.fiveLabel.hidden = self.sixLabel.hidden = self.sevenLabel.hidden = self.eightLabel.hidden = self.nineLabel.hidden = NO;
    } else if (self.peripheralsDataType == PeripheralsDataTypeSleepPro){
        MCSleepPro *sleepPro = data;
        [self.oneLabel setText:[NSString stringWithFormat:@"时长:%@",  sleepPro.duration != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.duration] : @"--"]];
        [self.twoLabel setText:[NSString stringWithFormat:@"有效睡眠:%@", sleepPro.effect_duration != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.effect_duration] : @"--"]];
        [self.threeLabel setText:[NSString stringWithFormat:@"开始时间:%@", sleepPro.startTime]];
        [self.fourLabel setText:[NSString stringWithFormat:@"结束时间：%@", sleepPro.endTime]];
        [self.fiveLabel setText:[NSString stringWithFormat:@"清醒时长:%@",sleepPro.awake_duration != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.awake_duration] : @"--"]];
        [self.sixLabel setText:[NSString stringWithFormat:@"清醒期占比:%@", sleepPro.awake_percent != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.awake_percent] : @"--"]];
        [self.sevenLabel setText:[NSString stringWithFormat:@"中睡时长:%@",sleepPro.moderate_duration != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.moderate_duration] : @"--"]];
        [self.eightLabel setText:[NSString stringWithFormat:@"中睡比例:%@",sleepPro.moderate_percent != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.moderate_percent] : @"--"]];
        [self.nineLabel setText:[NSString stringWithFormat:@"浅睡占比:%@",sleepPro.light_percent != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.light_percent] : @"--"]];
        [self.tenLabel setText:[NSString stringWithFormat:@"浅睡时长:%@",sleepPro.light_duration != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.light_duration] : @"--"]];
        [self.elevenLabel setText:[NSString stringWithFormat:@"深睡占比:%@",sleepPro.deep_percent != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.deep_percent] : @"--"]];
        [self.twelveLabel setText:[NSString stringWithFormat:@"深睡时长:%@",sleepPro.deep_duration != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.deep_duration] : @"--"]];
        [self.thirtenLabel setText:[NSString stringWithFormat:@"体动次数:%@",sleepPro.movement_times != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.movement_times] : @"--"]];
        [self.fourteenLabel setText:[NSString stringWithFormat:@"平均呼吸:%@",sleepPro.avg_breath != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.avg_breath] : @"--"]];
        [self.fifteenLabel setText:[NSString stringWithFormat:@"平均心率:%@",sleepPro.avg_heart_rate != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.avg_heart_rate] : @"--"]];
        [self.sixteenLabel setText:[NSString stringWithFormat:@"呼吸暂停次数:%@",sleepPro.apnea_times != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.apnea_times] : @"--"]];
        [self.seventeenLabel setText:[NSString stringWithFormat:@"呼吸暂停时长(秒):%@",sleepPro.apnea_times != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.apnea_times] : @"--"]];
        [self.eightteenLabel setText:[NSString stringWithFormat:@"呼吸次数:%@",sleepPro.breath_times != -1 ? [NSString stringWithFormat:@"%ld",(long)sleepPro.breath_times] : @"--"]];

        NSString *time = [NSString stringWithFormat:@"测量时间 :%@", [NSDate dateWithTimeIntervalSince1970:[sleepPro.measure_time doubleValue] / 1000 + 8 * 60 * 60]];
        [self.nineteenLabel setText:[time substringToIndex:time.length - 5]];
        
        [self.twentyLabel setText:[NSString stringWithFormat:@"测量源 :%@", sleepPro.data_source != nil ? sleepPro.data_source : @"本地数据源"]];
        for (UIView *subView in self.contentView.subviews) {
            subView.hidden = NO;
        }
    }
}

#pragma mark - 将某个时间戳转化成 时间
- (NSString *)timestampSwitchTime:(NSTimeInterval)timestamp andFormatter:(NSString *)format{
    if (timestamp == 0) {
        return @"0";
    }
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:format]; // （@"YYYY-MM-dd hh:mm:ss"）----------设置你想要的格式,hh与HH的区别:分别表示12小时制,24小时制
    NSDate *confromTimesp = [NSDate dateWithTimeIntervalSince1970:timestamp/1000];
    NSLog(@"timeStamp  = %@",confromTimesp);
    NSString *confromTimespStr = [formatter stringFromDate:confromTimesp];
    NSLog(@"&&&&&&&confromTimespStr = : %@",confromTimespStr);
    return confromTimespStr;
}
@end

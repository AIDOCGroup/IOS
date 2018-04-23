//
//  DataViewController.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/18.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DataViewController.h"
#import "DataCell.h"

@interface DataViewController ()<UITableViewDelegate,UITableViewDataSource>

@end

@implementation DataViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setup];
}

- (void)setup{
    self.automaticallyAdjustsScrollViewInsets = NO;
    UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, kNavigationHeight.floatValue, kMainScreenWidth, kMainScreenHeight - kNavigationHeight.floatValue)];
    tableView.delegate = self;
    tableView.dataSource = self;
    tableView.tableFooterView = [[UIView alloc] init];
    [self.view addSubview:tableView];
    self.tableView = tableView;
         if (_peripheralsDataType == PeripheralsDataTypeBloodSugar) {
        self.title = @"血糖数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeBloodPressure) {
        self.title = @"血压数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeThermometer) {
        self.title = @"温度计数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeWeighing) {
        self.title = @"体重数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeBodyFat) {
        self.title = @"体脂数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeSport) {
        self.title = @"运动数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeSleep) {
        self.title = @"睡眠数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeHeartRate) {
        self.title = @"心率数据";
    } else if (_peripheralsDataType == PeripheralsDataMultiply) {
        self.title = @"多功能设备数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeUroscopy) {
        self.title = @"尿检数据";
    } else if (_peripheralsDataType == PeripheralsDataTypeSleepPro) {
        self.title = @"专业睡眠数据";
    }
}

- (void)setPeripheralsDataType:(PeripheralsDataType)peripheralsDataType{
    _peripheralsDataType = peripheralsDataType;
    /*if (self.dataArray.count) {
        NSString *phone = [[NSUserDefaults standardUserDefaults] objectForKey:@"UserId"];
        NSTimeInterval timeStamp = [[NSDate date] timeIntervalSince1970];
        NSString *startTime = [NSString stringWithFormat:@"%f",timeStamp];
        NSString *endTime = startTime;
        if (_peripheralsDataType == PeripheralsDataTypeBloodSugar) {
            NSMutableArray<BloodSugar *> *sugarArray = [NSMutableArray<BloodSugar *> arrayWithCapacity:self.dataArray.count];
            for (MCBloodSugar *mcBloodSugar in self.dataArray) {
                BloodSugar *bs = [[BloodSugar alloc] init];
                bs.type = 1;
                bs.value = mcBloodSugar.glucose_value;
                bs.sampleTime = [mcBloodSugar.measure_time integerValue] / 1000;
                [sugarArray addObject:bs];
            }
            [BloodSugarApi uploadBloodSugarWithData:sugarArray telephone:phone];
        } else if (_peripheralsDataType == PeripheralsDataTypeBloodPressure) {
            NSMutableArray<BloodPressure *> *pressureArray = [NSMutableArray<BloodPressure *> arrayWithCapacity:self.dataArray.count];
            for (MCBloodPressure *mcBloodPressure in self.dataArray) {
                BloodPressure *bp = [[BloodPressure alloc] init];
                bp.diastolic = mcBloodPressure.low_press;
                bp.systolic = mcBloodPressure.high_press;
                bp.sampleTime = [mcBloodPressure.measure_time integerValue] / 1000;
                [pressureArray addObject:bp];
            }
            [BloodPressureApi uploadBloodPressureWithData:pressureArray telephone:phone];
        } else if (_peripheralsDataType == PeripheralsDataTypeThermometer) {
            NSMutableArray<Temperature *> *temperatureArray = [NSMutableArray<Temperature *> arrayWithCapacity:self.dataArray.count];
            for (MCThermometer *mcTemperature in self.dataArray) {
                Temperature *temp = [[Temperature alloc] init];
                float t = [[NSString stringWithFormat:@"%0.1f",mcTemperature.temperature] floatValue];
                temp.average = t;
                temp.max = t;
                temp.min = t;
                temp.beginTime = [startTime integerValue];
                temp.endTime = [endTime integerValue];
                [temperatureArray addObject:temp];
            }
            [TemperatureApi uploadTemperatureWithData:temperatureArray telephone:phone];
        } else if ((_peripheralsDataType == PeripheralsDataTypeBodyFat) || (_peripheralsDataType == PeripheralsDataTypeWeighing)) {
            NSMutableArray<Health *> *weightArray = [NSMutableArray<Health *> arrayWithCapacity:self.dataArray.count];
            for (MCWeight *mcWeight in self.dataArray) {
                Health *health = [[Health alloc] init];
                health.bmi = mcWeight.bmi;
                health.bodyFat = mcWeight.fat_ratio / 100;
                health.muscleRate = mcWeight.muscle / 100;
                health.moistureRate = mcWeight.moisture / 100;
                health.bmd = mcWeight.bone_mass;
                health.bmr = mcWeight.metabolism;
                health.sampleTime = [mcWeight.measure_time integerValue] / 1000;
                [weightArray addObject:health];
            }
            [HealthApi uploadHealthWithData:weightArray telephone:phone];
        } else if (_peripheralsDataType == PeripheralsDataTypeSport) {
            NSMutableArray<Sport *> *sportArray = [NSMutableArray<Sport *> arrayWithCapacity:self.dataArray.count];
            for (MCSport *mcSport in self.dataArray) {
                Sport *sport = [[Sport alloc] init];
                sport.step = mcSport.steps;
                sport.distance = mcSport.distance;
                sport.beginTime = [startTime integerValue];
                sport.endTime = [endTime integerValue];
                [sportArray addObject:sport];
            }
            [SportApi uploadSportWithData:sportArray telephone:phone];
        } else if (_peripheralsDataType == PeripheralsDataTypeSleep) {
            NSMutableArray<Sleep *> *sleepArray = [NSMutableArray<Sleep *> arrayWithCapacity:self.dataArray.count];
            for (MCSleep *mcSleep in self.dataArray) {
                Sleep *sleep = [[Sleep alloc] init];
                sleep.totalDuration = mcSleep.duration;
                sleep.effectiveDuration = mcSleep.effect_duration;
                sleep.deepDuration = mcSleep.deep_duration;
                sleep.lightDuration = mcSleep.light_duration;
                sleep.beginTime = [startTime integerValue];
                sleep.endTime = [endTime integerValue];
                [sleepArray addObject:sleep];
            }
            [SleepApi uploadSleepWithData:sleepArray telephone:phone];
        } else if (_peripheralsDataType == PeripheralsDataTypeHeartRate) {
            NSMutableArray<HeartRate *> *heartArray = [NSMutableArray<HeartRate *> arrayWithCapacity:self.dataArray.count];
            for (MCHeartRate *mcHeartRate in self.dataArray) {
                HeartRate *heartRate = [[HeartRate alloc] init];
                heartRate.average = mcHeartRate.heartRate;
                heartRate.max = mcHeartRate.heartRate;
                heartRate.min = mcHeartRate.heartRate;
                heartRate.beginTime = [startTime integerValue];
                heartRate.endTime = [endTime integerValue];
                [heartArray addObject:heartRate];
            }
            [HeartRateApi uploadHeartRateWithData:heartArray telephone:phone];
        } else if (_peripheralsDataType == PeripheralsDataTypeOximeter) {
            NSMutableArray<BloodOxygen *> *bloodOxygenArray = [NSMutableArray<BloodOxygen *> arrayWithCapacity:self.dataArray.count];
            for (MCOximeter *mcOximeter in self.dataArray) {
                BloodOxygen *oxygen = [[BloodOxygen alloc] init];
                oxygen.average = mcOximeter.spO2 / 100.0;
                oxygen.max = mcOximeter.spO2 / 100.0;
                oxygen.min = mcOximeter.spO2 / 100.0;
                oxygen.beginTime = [startTime integerValue];
                oxygen.endTime = [endTime integerValue];
                [bloodOxygenArray addObject:oxygen];
            }
            [BloodOxygenApi uploadBloodOxygenWithData:bloodOxygenArray telephone:phone];
        }
        else if (_peripheralsDataType == PeripheralsDataMultiply) {
            
        }
    }*/
}
- (void)setDataArray:(NSMutableArray *)dataArray{
    _dataArray = dataArray;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    DataCell *dataCell = [DataCell dataCell];
    dataCell.peripheralsDataType = self.peripheralsDataType;
    dataCell.data = self.dataArray[indexPath.row];
    return dataCell;
}

-(CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (_peripheralsDataType == PeripheralsDataTypeBloodSugar || _peripheralsDataType == PeripheralsDataTypeThermometer || _peripheralsDataType == PeripheralsDataTypeWeighing || _peripheralsDataType == PeripheralsDataTypeHeartRate) {
        // 8为行间距
        return (21 + 8) * 4 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeSleep ||  _peripheralsDataType == PeripheralsDataTypeOximeter) {
        return (21 + 8) * 7 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeBloodPressure || _peripheralsDataType == PeripheralsDataTypeSport) {
        return (21 + 8) * 5 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeBodyFat) {
        return (21 + 8) * 15 + 40;
    } else if (_peripheralsDataType == PeripheralsDataTypeUroscopy){
        return (21 + 8) * 9 +40;
    } else if (_peripheralsDataType == PeripheralsDataTypeSleepPro){
        return (21 + 8) * 17 + 40;
    }
    
    return 0;
}

@end

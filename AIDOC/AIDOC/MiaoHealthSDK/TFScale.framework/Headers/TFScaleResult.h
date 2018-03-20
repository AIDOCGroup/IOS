//
//  TFScaleResult.h
//  TFScale
//
//  Created by Yalin on 16/4/11.
//  Copyright © 2016年 tongfang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TFScaleResult : NSObject

// 设备类型 0为老秤 1为新秤
@property (nonatomic, assign) NSInteger deviceType;

// true 男 false 女
@property (nonatomic, assign) BOOL gender;
// 水分率
@property (nonatomic, assign) float waterPercentage;
// 体重
@property (nonatomic, assign) float weight;
// 体重正常范围下限 + 体重正常范围上限
@property (nonatomic, assign) float weightMax; // --------------------------
@property (nonatomic, assign) float weightMin; // --------------------------

// 脂肪肝 nil代表不支持
@property (nonatomic, assign) BOOL hepaticAdiposeInfiltration;
// 去脂体重
@property (nonatomic, assign) float LBM;    // --------------------------
// 标准体脂率
@property (nonatomic, assign) float standardFatPercentage;  // --------------------------

// 瘦体重
@property (nonatomic, assign) float fatFreeBodyWeight;
// 瘦体重正常范围下限 + 瘦体重正常范围上限
@property (nonatomic, assign) float fatFreeBodyWeightMax;
@property (nonatomic, assign) float fatFreeBodyWeightMin;

// 肌肉重
@property (nonatomic, assign) float muscleWeight;
// 肌肉重正常范围下限 + 肌肉重正常范围上限
@property (nonatomic, assign) float muscleWeightMax;
@property (nonatomic, assign) float muscleWeightMin;

// 蛋白质重
@property (nonatomic, assign) float proteinWeight;
// 蛋白质正常范围下限 + 蛋白质正常范围上限
@property (nonatomic, assign) float proteinWeightMax;
@property (nonatomic, assign) float proteinWeightMin;

// 骨重
@property (nonatomic, assign) float boneWeight;
// 骨质重正常范围下限 + 骨质重正常范围上限
@property (nonatomic, assign) float boneWeightMax;
@property (nonatomic, assign) float boneWeightMin;

// 水分重
@property (nonatomic, assign) float waterWeight;
// 细胞总水正常范围下限 + 细胞总水正常范围上限
@property (nonatomic, assign) float waterWeightMax;
@property (nonatomic, assign) float waterWeightMin;

// 脂肪重
@property (nonatomic, assign) float fatWeight;
// 脂肪重正常范围下限 + 脂肪重正常范围上限
@property (nonatomic, assign) float fatWeightMax;
@property (nonatomic, assign) float fatWeightMin;

// 体脂率
@property (nonatomic, assign) float fatPercentage;
// 体脂百分比正常范围下限 + 体脂百分比正常范围上限
@property (nonatomic, assign) float fatPercentageMax;
@property (nonatomic, assign) float fatPercentageMin;

// 腰臀比(两位小数)
@property (nonatomic, assign) float whr;
// 腰臀比正常范围下限 + 腰臀比正常范围上限
@property (nonatomic, assign) float whrMax;
@property (nonatomic, assign) float whrMin;

// 内脏脂肪率 = 0
@property (nonatomic, assign) float visceralFatPercentage;
@property (nonatomic, assign) float visceralFatPercentageMax; // --------------------------
@property (nonatomic, assign) float visceralFatPercentageMin; // --------------------------

// 体质指数
@property (nonatomic, assign) float bmi;
// 体质指数正常范围下限 + 体质指数正常范围上限
@property (nonatomic, assign) float bmiMax;
@property (nonatomic, assign) float bmiMin;

// 基础代谢率
@property (nonatomic, assign) float bmr;

// 身体年龄
@property (nonatomic, assign) float bodyAge;

// 骨骼肌
@property (nonatomic, assign) float boneMuscleWeight;
//// 骨骼肌正常范围下限 + 骨骼肌正常范围上限
@property (nonatomic, assign) float boneMuscleWeightMax;
@property (nonatomic, assign) float boneMuscleWeightMin;

// 肌肉控制(有符号)
@property (nonatomic, assign) float muscleControl;

// 脂肪控制(有符号)
@property (nonatomic, assign) float fatControl;

// 体重控制(有符号)
@property (nonatomic, assign) float weightControl;

// 标准体重
@property (nonatomic, assign) float sw;
// 标准体重正常范围下限 + 标准体重正常范围上限
@property (nonatomic, assign) float swMax;
@property (nonatomic, assign) float swMin;

// 目标体重
@property (nonatomic, assign) float goalWeight;

// 标准肌肉
@property (nonatomic, assign) float m_smm;

// 右上肢脂肪
@property (nonatomic, assign) float rightUpperExtremityFat;

// 右上肢肌肉
@property (nonatomic, assign) float rightUpperExtremityMuscle;

// 右上肢骨质
@property (nonatomic, assign) float rightUpperExtremityBone;

// 左上肢脂肪
@property (nonatomic, assign) float leftUpperExtremityFat;

// 左上肢肌肉
@property (nonatomic, assign) float leftUpperExtremityMuscle;

// 左上肢骨质
@property (nonatomic, assign) float leftUpperExtremityBone;

// 躯干肢脂肪
@property (nonatomic, assign) float trunkLimbFat;

// 躯干肢肌肉
@property (nonatomic, assign) float trunkLimbMuscle;

// 躯干肢骨质
@property (nonatomic, assign) float trunkLimbBone;

// 右下肢脂肪
@property (nonatomic, assign) float rightLowerExtremityFat;

// 右下肢肌肉
@property (nonatomic, assign) float rightLowerExtremityMuscle;

// 右下肢骨质
@property (nonatomic, assign) float rightLowerExtremityBone;

// 左下肢脂肪
@property (nonatomic, assign) float leftLowerExtremityFat;

// 左下肢肌肉
@property (nonatomic, assign) float leftLowerExtremityMuscle;

// 左下肢骨质
@property (nonatomic, assign) float leftLowerExtremityBone;

// 外水
@property (nonatomic, assign) float externalMoisture;

// 内水
@property (nonatomic, assign) float internalMoisture;

// 水肿系数
@property (nonatomic, assign) float edemaFactor;

// 肥胖度
@property (nonatomic, assign) float obesity;

// 健康得分
@property (nonatomic, assign) float score;

// 体型
@property (nonatomic, strong) NSString *physique; // --------------------------

// 脂肪肝风险度
@property (nonatomic, assign) float fattyLiverRisk; // --------------------------

@end

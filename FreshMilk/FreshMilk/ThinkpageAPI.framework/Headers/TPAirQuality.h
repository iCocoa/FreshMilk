//
//  TPAirQuality.h
//  ThinkpageAPI
//
//  描述空气质量信息
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

// 空气质量信息来源类型
typedef NS_ENUM(NSInteger, TPAirQualityType)
{
    TPAirQualityTypeCity,   // 整个城市的综合空气质量信息
    TPAirQualityTypeStation // 来自特定空气质量监测点的信息
};

@interface TPAirQuality : NSObject

// 空气质量信息来源类型
@property (nonatomic, assign)TPAirQualityType type;
// 空气质量指数(AQI)是描述空气质量状况的定量指数
@property (nonatomic, assign)double aqi;
// PM2.5颗粒物（粒径小于等于2.5μm）1小时平均值。单位：μg/m³
@property (nonatomic, assign)double pm25;
// PM10颗粒物（粒径小于等于10μm）1小时平均值。单位：μg/m³
@property (nonatomic, assign)double pm10;
// 二氧化硫1小时平均值。单位：μg/m³
@property (nonatomic, assign)double so2;
// 二氧化氮1小时平均值。单位：μg/m³
@property (nonatomic, assign)double no2;
// 一氧化碳1小时平均值。单位：mg/m³
@property (nonatomic, assign)double co;
// 臭氧1小时平均值。单位：μg/m³
@property (nonatomic, assign)double o3;
// 空气质量类别，有“优、良、轻度污染、中度污染、重度污染、严重污染”6类
// 仅当 type==TPAirQualityTypeCity 时有效
@property (nonatomic, copy)NSString *quality;
// 空气质量检测点名称
// 仅当 type==TPAirQualityTypeStation 时有效
@property (nonatomic, copy)NSString *station;
// 数据发布时间
@property (nonatomic, copy)NSDate *lastUpdateDate;

@end

//
//  TPAirDaily.h
//  ThinkpageAPI
//
//  每日空气质量预报信息
//
//  Created by Hao Gong on 16/4/27.
//  Copyright © 2016 Thinkpage. All rights reserved.
//

#ifndef TPAirDaily_h
#define TPAirDaily_h

#import <Foundation/Foundation.h>

@interface TPAirDaily : NSObject

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
@property (nonatomic, copy)NSString *quality;
// 对应日期
@property (nonatomic, copy)NSDate *date;

@end

#endif /* TPAirDaily_h */

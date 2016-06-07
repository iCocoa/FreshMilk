/*!
 @file		TPWeatherNow.h
 @brief		实时获取的当前气象信息
 @author	Shangwei Fang
 @date		Copyright (c) 2014 ThinkPage. All rights reserved.
 */

#import <Foundation/Foundation.h>


@interface TPWeatherNow : NSObject

//天气现象文字, 例如"多云"
@property (nonatomic, copy) NSString *text;
//天气现象代码，例如"4"
@property (nonatomic, copy) NSString *code;
//温度。单位为c摄氏度或f华氏度。
@property (nonatomic, assign) NSInteger temperature;
//体感温度。单位为c摄氏度或f华氏度。
@property (nonatomic, assign) NSInteger feelsLikeTemperature;
//风向文字, 例如"西北"
@property (nonatomic, copy) NSString *windDirection;
//风向角度。范围0~359, 0为正北，90为正东，180为正南，270为正西。
@property (nonatomic, assign) NSInteger windDirectionDegree;
//风速。单位为km/h公里每小时或mph英里每小时
@property (nonatomic, assign) double windSpeed;
//风力等级
@property (nonatomic, assign) double windScale;
//相对湿度, 范围0~1
@property (nonatomic, assign) double humidity;
//能见度。单位为km公里或mi英里
@property (nonatomic, assign) double visibility;
//气压。单位为mb百帕或in英寸
@property (nonatomic, assign) double pressure;
//云量。天空被云覆盖的面积占比，范围0~1
@property (nonatomic, assign) double clouds;
//露点温度
@property (nonatomic, assign) NSInteger dewPoint;
//数据更新时间
@property (nonatomic, copy)NSDate *lastUpdateDate;
//错误信息
@property (nonatomic, copy)NSString *errorInfo;

@end

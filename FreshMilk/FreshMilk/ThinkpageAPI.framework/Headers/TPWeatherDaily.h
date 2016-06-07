//
//  TPWeatherDaily.h
//  ThinkpageAPI
//
//  逐日播报的气象信息
//  Created by Hao Gong on 15/12/19.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPWeatherDaily : NSObject

//日期
@property (nonatomic, copy)NSDate *date;
//白天气象文字，例如"多云"
@property (nonatomic, copy)NSString *textForDay;
//白天气象代码, 例如"4"
@property (nonatomic, copy)NSString *codeForDay;
//夜间气象文字, 例如"多云"
@property (nonatomic, copy)NSString *textForNight;
//夜间气象代码, 例如"4"
@property (nonatomic, copy)NSString *codeForNight;
//当日最高气温
@property (nonatomic, assign)NSInteger highTemperature;
//当日最低气温
@property (nonatomic, assign)NSInteger lowTemperature;
//降水概率，范围 0～1
@property (nonatomic, assign)double chanceOfRain;
//风向文字描述，例如"西北"
@property (nonatomic, copy)NSString *windDirection;
//风向角度, 例如"255", 范围0~359
@property (nonatomic, assign)NSInteger windDirectionDegree;
//风速，单位km/h（当unit=c时）、mph（当unit=f时）
@property (nonatomic, assign)double windSpeed;
//风力等级
@property (nonatomic, assign)double windScale;

@end

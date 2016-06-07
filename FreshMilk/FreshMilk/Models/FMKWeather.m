//
//  FMKWeather.m
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKWeather.h"
#import "FMKIconfontContants.h"
#import <objc/runtime.h>

@interface FMKWeather ()
@property (nonatomic, readwrite, copy) NSDictionary *iconfontDict;
@end

@implementation FMKWeather

- (instancetype)init
{
    self = [super init];
    if (self) {
        _iconfontDict = [NSMutableDictionary dictionary];
    }
    return self;
}

- (void)setCurrentWeather:(TPWeatherNow *)currentWeather
{
    _currentWeather = currentWeather;
    
    if (_currentWeather.text.length > 0) {
        NSString *text = [[NSString alloc]initWithCString:property_getName((__bridge objc_property_t)(_currentWeather.text))  encoding:NSUTF8StringEncoding];
        if ([_currentWeather.text containsString:@"晴"]) {
            [_iconfontDict setValue:FMKIconWeatherSunny forKey:text];
        }
        if ([_currentWeather.text containsString:@"多云"]) {
            [_iconfontDict setValue:FMKIconWeatherCloudy forKey:text];
        }
        if ([_currentWeather.text containsString:@"阴"]) {
            [_iconfontDict setValue:FMKIconWeatherCloudy1 forKey:text];
        }
        if ([_currentWeather.text containsString:@"小雨"]) {
            [_iconfontDict setValue:FMKIconWeatherDrizzle forKey:text];
        }
        if ([_currentWeather.text containsString:@"中雨"]) {
            [_iconfontDict setValue:FMKIconWeatherModerateRain forKey:text];
        }
        if ([_currentWeather.text containsString:@"大雨"]) {
            [_iconfontDict setValue:FMKIconWeatherHeavyRain forKey:text];
        }
        if ([_currentWeather.text containsString:@"暴雨"]) {
            [_iconfontDict setValue:FMKIconWeatherHeavyDownpour forKey:text];
        }
        if ([_currentWeather.text containsString:@"雾"]) {
            [_iconfontDict setValue:FMKIconWeatherFoggy forKey:text];
        }
        if ([_currentWeather.text containsString:@"霾"]) {
            [_iconfontDict setValue:FMKIconWeatherThickHaze forKey:text];
        }
        if ([_currentWeather.text containsString:@"微风"]) {
            [_iconfontDict setValue:FMKIconWeatherGentleBreeze forKey:text];
        }
        if ([_currentWeather.text containsString:@"强风"]) {
            [_iconfontDict setValue:FMKIconWeatherStrongBreeze forKey:text];
        }
        if ([_currentWeather.text containsString:@"台风"]) {
            [_iconfontDict setValue:FMKIconWeatherTyphoon forKey:text];
        }
    }
}

////天气现象文字, 例如"多云"
//@property (nonatomic, copy) NSString *text;
////天气现象代码，例如"4"
//@property (nonatomic, copy) NSString *code;
////温度。单位为c摄氏度或f华氏度。
//@property (nonatomic, assign) NSInteger temperature;
////体感温度。单位为c摄氏度或f华氏度。
//@property (nonatomic, assign) NSInteger feelsLikeTemperature;
////风向文字, 例如"西北"
//@property (nonatomic, copy) NSString *windDirection;
////风向角度。范围0~359, 0为正北，90为正东，180为正南，270为正西。
//@property (nonatomic, assign) NSInteger windDirectionDegree;
////风速。单位为km/h公里每小时或mph英里每小时
//@property (nonatomic, assign) double windSpeed;
////风力等级
//@property (nonatomic, assign) double windScale;
////相对湿度, 范围0~1
//@property (nonatomic, assign) double humidity;
////能见度。单位为km公里或mi英里
//@property (nonatomic, assign) double visibility;
////气压。单位为mb百帕或in英寸
//@property (nonatomic, assign) double pressure;
////云量。天空被云覆盖的面积占比，范围0~1
//@property (nonatomic, assign) double clouds;
////露点温度
//@property (nonatomic, assign) NSInteger dewPoint;
////数据更新时间
//@property (nonatomic, copy)NSDate *lastUpdateDate;

@end

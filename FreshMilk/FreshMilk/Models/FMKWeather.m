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

//- (void)setCurrentWeather:(id)currentWeather
//{
//    _currentWeather = currentWeather;
//    
//    if (_currentWeather.text.length > 0) {
//        NSString *text = [[NSString alloc]initWithCString:property_getName((__bridge objc_property_t)(_currentWeather.text))  encoding:NSUTF8StringEncoding];
//        if ([_currentWeather.text containsString:@"晴"]) {
//            [_iconfontDict setValue:FMKIconWeatherSunny forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"多云"]) {
//            [_iconfontDict setValue:FMKIconWeatherCloudy forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"阴"]) {
//            [_iconfontDict setValue:FMKIconWeatherCloudy1 forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"小雨"]) {
//            [_iconfontDict setValue:FMKIconWeatherDrizzle forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"中雨"]) {
//            [_iconfontDict setValue:FMKIconWeatherModerateRain forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"大雨"]) {
//            [_iconfontDict setValue:FMKIconWeatherHeavyRain forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"暴雨"]) {
//            [_iconfontDict setValue:FMKIconWeatherHeavyDownpour forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"雾"]) {
//            [_iconfontDict setValue:FMKIconWeatherFoggy forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"霾"]) {
//            [_iconfontDict setValue:FMKIconWeatherThickHaze forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"微风"]) {
//            [_iconfontDict setValue:FMKIconWeatherGentleBreeze forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"强风"]) {
//            [_iconfontDict setValue:FMKIconWeatherStrongBreeze forKey:text];
//        }
//        if ([_currentWeather.text containsString:@"台风"]) {
//            [_iconfontDict setValue:FMKIconWeatherTyphoon forKey:text];
//        }
//    }
//}

@end

//
//  FMKWeather.h
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ThinkpageAPI/TPWeatherNow.h>

@interface FMKWeather : NSObject
@property (nonatomic, strong) TPWeatherNow *currentWeather;
@property (nonatomic, readonly, copy) NSDictionary *iconfontDict;
@end

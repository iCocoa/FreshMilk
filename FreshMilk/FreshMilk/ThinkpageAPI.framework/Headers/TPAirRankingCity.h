//
//  TPAirRankingCity.h
//  ThinkpageAPI
//
//  全国城市空气质量AQI排行数据
//
//  Created by Hao Gong on 16/4/27.
//  Copyright © 2016 Thinkpage. All rights reserved.
//

#ifndef TPAirRankingCity_h
#define TPAirRankingCity_h

#import <Foundation/Foundation.h>

@class TPCityInformation;

// 城市空气质量数据
@interface TPAirRankingCity : NSObject

// 城市信息
@property(nonatomic, strong) TPCityInformation *cityInformation;
// aqi数值
@property(nonatomic, assign) double aqi;
@end
#endif /* TPAirRankingCity_h */

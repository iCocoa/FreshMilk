//
//  TPWeatherHistoryHourly.h
//  ThinkpageAPI
//
//  过去的逐小时气象历史信息记录，目前仅支持24小时内的数据
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPWeatherHistoryHourly : NSObject


//天气现象文字
@property(nonatomic, copy)NSString *text;
//天气现象代码
@property(nonatomic, copy)NSString *code;
//温度。单位为c摄氏度或f华氏度
@property(nonatomic, assign)NSInteger temperature;
//体感温度。单位为c摄氏度或f华氏度
@property(nonatomic, assign)NSInteger feelsLikeTemperature;
//气压。单位为mb百帕或in英寸。
@property(nonatomic, assign)double pressure;
//相对湿度。范围0~1
@property(nonatomic, assign)double humidity;
//能见度。单位为km公里或mi英里。
@property(nonatomic, assign)double visibility;
//风向文字
@property(nonatomic, copy)NSString *windDirection;
//风向角度。0为正北，90为正东，180为正南，270为正西。
@property(nonatomic, assign)NSInteger windDirectionDegree;
//风速。单位为km/h公里每小时或mph英里每小时。
@property(nonatomic, assign)double windSpeed;
//风力等级
@property(nonatomic, assign)double windScale;
//云量，天空被云覆盖的范围占比,范围0～1
@property(nonatomic, assign)double clouds;
//露点温度
@property(nonatomic, assign)NSInteger dewPoint;
//数据记录时间
@property(nonatomic, copy)NSDate *date;

@end

//
//  TPWeatherHourly.h
//  ThinkpageAPI
//
//  逐小时预报的未来气象信息，目前仅支持中国城市
//  Created by Hao Gong on 15/12/20.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPWeatherHourly : NSObject

//时间
@property (nonatomic, copy)NSDate *date;
//气象文字信息
@property (nonatomic, copy)NSString *text;
//气象代码
@property (nonatomic, copy)NSString *code;
//温度预报
@property (nonatomic, assign)NSInteger temperature;

@end

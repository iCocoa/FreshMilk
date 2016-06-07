//
//  TPChineseCalendarDate.h
//  ThinkpageAPI
//
//  任何一个公历日期对应的农历日期、农历传统节假日、二十四节气、天干地支纪年纪月纪日、及生肖属相。
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPChineseCalendarDate : NSObject

//公历日期
@property(nonatomic, copy)NSDate *date;
//生肖属相, 例如"蛇"
@property(nonatomic, copy)NSString *zodiac;
//干支纪年, 例如"癸巳"
@property(nonatomic, copy)NSString *ganzhiYear;
//干支纪月, 例如"乙丑"
@property(nonatomic, copy)NSString *ganzhiMonth;
//干支纪日, 例如"壬寅"
@property(nonatomic, copy)NSString *ganzhiDay;
//农历年, 例如"2015"
@property(nonatomic, copy)NSString *lunarYear;
//农历月（1-13，当有闰月时，比如2014年闰9月，则10表示闰9月，11表示10月）
@property(nonatomic, copy)NSString *lunarMonth;
//农历日, 例如"1"
@property(nonatomic, copy)NSString *lunarDay;
//农历月中文名, 例如"正月"
@property(nonatomic, copy)NSString *lunarMonthName;
//农历日中文名, 例如"初一"
@property(nonatomic, copy)NSString *lunarDayName;
//农历闰月所在月份，例如"9", 0表示无闰月
@property(nonatomic, copy)NSString *lunarLeapMonth;
//农历节假日，如：春节、端午、中秋等
@property(nonatomic, copy)NSString *lunarFestival;
//二十四节气名，如：冬至、小寒、大寒、立春等
@property(nonatomic, copy)NSString *solarTerm;

@end

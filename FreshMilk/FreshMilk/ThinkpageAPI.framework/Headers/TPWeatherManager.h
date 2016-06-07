/*!
 @file		TPWeatherManager.h
 @brief		TPWeatherManager是Thinkpage SDK的主要对象。它可以用来获取Thinkpage提供的各种数据服务信息，并通过回调
            将数据或者错误信息返还给调用者。请注意它并不保证回调函数总是在主线程被调用。
 @author	Shangwei Fang
 @date		Copyright (c) 2014 ThinkPage. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "TPCity.h"

//语言类型，用来指定Thinkpage SDK返回信息的语言种类
typedef NS_ENUM(NSInteger, TPWeatherReportLanguage)
{
    kEnglish,               //英文
    kSimplifiedChinese,     //简体中文
    kTraditionalChinese     //繁体中文
};

//温度单位，当Thinkpage SDK返回的数据包含温度信息时，用来指定温度的单位
typedef NS_ENUM(NSInteger, TPTemperatureUnit)
{
    kCelsius,               //温度用摄氏度表示
    kFahrenheit             //温度用华氏度表示
};


@class TPAirQuality;
@class TPChineseCalendarDate;
@class TPCityInformation;
@class TPLifeSuggestion;
@class TPMoonInformation;
@class TPSunInformation;
@class TPWeatherAlarm;
@class TPWeatherDaily;
@class TPWeatherNow;
@class TPWeatherHourly;
@class TPWeatherHistoryHourly;
@class TPDrivingRestriction;
@class TPAirRankingCity;
@class TPAirDaily;
@class TPAirHourly;

@interface TPWeatherManager : NSObject

/*!
 *
 * 初始化一个TPWeatherManager对象
 * @param accessCode 从Thinkpage官网https://api.thinkpage.cn注册获取的API密钥(key)
 * @param userId 从Thinkpage官网https://api.thinkpage.cn注册获取的用户Id, 通常和key是绑定的
 * @returns 初始化完毕的TPWeatherManager对象
 * @discussion 只有使用这个方法初始化过的TPWeatherManager对象才能正常使用。它并不限制每个应用程序只能创建一个实例，但我们
 *             建议您这样做。accessCode(心知天气API密钥)是属于您的私密信息，TPWeatherManager使用它进行网络请求时会进行
 *             加密以确保不被意外泄露，请您在编写客户端应用程序代码时也注意避免被第三方获取该信息。调用TPWeatherManager方
 *             法时能够返回什么数据是由您的用户等级决定的，最高等级可以获取心知天气提供的所有服务数据。
 **/
- (id)initWithAccessCode:(NSString*)accessCode userId:(NSString *)userId;

/*!
 *
 * 获取指定地点的当前气象信息
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param unit 返回信息的温度单位
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数weatherNow包含所请求的气象数据，当出现错误或者
 *                          用户权限不够时错误信息通过参数error返回
 **/
- (void)getCurrentWeatherOfCity:(TPCity *)city
                     inLanguage:(TPWeatherReportLanguage)language
                           unit:(TPTemperatureUnit)unit
                     completion:(void(^)(TPWeatherNow *weatherNow, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点某一段时期内的每日气象预报信息
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param unit 返回信息的温度单位
 * @param date 返回信息的开始日期，date里的时刻信息会被自动忽略
 * @param days 共获取多少天的气象信息，起始日期由date参数指定
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数weatherDailyArray包含所请求的气象数据，当出现
                            错误或者用户权限不够时错误信息通过参数error返回
 * @discussion 最多支持未来15天的气象预报信息和昨天的历史数据
 **/
- (void)getDailyWeatherOfCity:(TPCity *)city
                   inLanguage:(TPWeatherReportLanguage)language
                         unit:(TPTemperatureUnit)unit
                     fromDate:(NSDate *)date
                         days:(NSInteger)days
                   completion:(void(^)(NSArray<TPWeatherDaily *> *weatherDailyArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点某几个小时内的逐时气象预报信息
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param unit 返回信息的温度单位
 * @param offset 起始时间距离当前时间的小时数，例如0代表这个小时，1代表下个小时
 * @param hours 共获取多少个小时的气象预报，起始时间由offset参数指定
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数weatherHourlyArray包含所请求的气象数据，当出
                            现错误或者用户权限不够时错误信息通过参数error返回
 * @discussion 目前仅支持中国城市，至多获取未来24小时内的预报信息
 **/
- (void)getHourlyWeatherOfCity:(TPCity *)city
                    inLanguage:(TPWeatherReportLanguage)language
                          unit:(TPTemperatureUnit)unit
                    hourOffset:(NSInteger)offset
                         hours:(NSInteger)hours
                    completion:(void(^)(NSArray<TPWeatherHourly *>*weatherHourlyArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点过去24小时内的逐时天气历史记录
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param unit 返回信息的温度单位
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数weatherHistoryHourlyArray包含所请求的气象数
                            据，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getHistoryHourlyWeatherOfCity:(TPCity *)city
                           inLanguage:(TPWeatherReportLanguage)language
                                 unit:(TPTemperatureUnit)unit
                           completion:(void(^)(NSArray<TPWeatherHistoryHourly *>*weatherHistoryHourlyArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点的气象预警信息
 * @param city 指定的地点
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数weatherAlarmArray包含所请求的气象预警信息数
                            据，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getWeatherAlarmsOfCity:(TPCity *)city
                           completion:(void(^)(NSArray<TPWeatherAlarm *>* weatherAlarmArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点的实时空气质量数据
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数airQualities包含所请求的空气质量数据，这是一个
                            数组，通常index为0的对象是整个城市的综合空气质量，后续对象为各个气象监测点的数据，当出现错误或
                            者用户权限不够时错误信息通过参数error返回
 **/
- (void)getAirQualitiesOfCity:(TPCity *)city
                   inLanguage:(TPWeatherReportLanguage)language
                   completion:(void(^)(NSArray<TPAirQuality *> *airQualities, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点过去24小时内的逐时空气质量数据
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数airQualities包含所请求的空气质量数据，这是一个
                            二级数组，第一级别为每个小时的逐时历史记录，第二级别为同一个时间点的不同来源空气质量数据，通常
                            index为0的对象是整个城市的综合空气质量，后续对象为各个气象监测点的数据，当出现错误或者用户权限
                            不够时错误信息通过参数error返回
 **/
- (void)getHistoryHourlyAirQualitiesOfCity:(TPCity *)city
                                inLanguage:(TPWeatherReportLanguage)language
                                completion:(void(^)(NSArray<NSArray<TPAirQuality *> *> *airQualities, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点的生活指数和建议
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数lifeSuggestion包含所请求的气象数据，当出现错误
                            或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getLifeSuggestionOfCity:(TPCity *)city
                     inLanguage:(TPWeatherReportLanguage)language
                     completion:(void(^)(TPLifeSuggestion *lifeSuggestion, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点某一段时期内的每日中国传统农历和节气信息
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param date 返回信息的开始日期，date里的时刻信息会被自动忽略
 * @param days 共获取多少天的农历信息，起始日期由date参数指定
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数chineseCalendarDateArray包含所请求的气象数
                            据，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getChineseCalendarDateOfCity:(TPCity *)city
                          inLanguage:(TPWeatherReportLanguage)language
                           startDate:(NSDate *)date
                                days:(NSInteger)days
                          completion:(void(^)(NSArray<TPChineseCalendarDate *>*chineseCalendarDateArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点某一段时期内的日出日落信息
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param date 返回信息的开始日期，date里的时刻信息会被自动忽略
 * @param days 共获取多少天的日出日落信息，起始日期由date参数指定
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数sunInformationArray包含所请求的日出日落数
                            据，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getSunInformationOfCity:(TPCity *)city
                     inLanguage:(TPWeatherReportLanguage)language
                      startDate:(NSDate *)date
                           days:(NSInteger)days
                     completion:(void(^)(NSArray<TPSunInformation *>*sunInformationArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定地点某一段时期内的月相信息
 * @param city 指定的地点
 * @param language 返回信息的语言种类
 * @param date 返回信息的开始日期，date里的时刻信息会被自动忽略
 * @param days 共获取多少天的月相信息，起始日期由date参数指定
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数moonInformationArray包含所请求的日出日落数
                            据，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getMoonInformationOfCity:(TPCity *)city
                      inLanguage:(TPWeatherReportLanguage)language
                       startDate:(NSDate *)date
                            days:(NSInteger)days
                      completion:(void(^)(NSArray<TPMoonInformation *>*moonInformationArray, NSError *error))completionHandler;

/*!
 *
 * 搜索符合特定条件的所有城市信息
 * @param city 指定的地点，这个方法支持模糊搜索，例如用字符串"bei"初始化city对象，将查询所有中英文名称中包含"bei"的城市
 * @param language 返回信息的语言种类
 * @param limit 返回信息的数量上限，可以和offset配合使用实现分页查询
 * @param offset 返回信息跳过数据，可以和limit配合使用实现分页查询，例如limit==10, offset==20将返回第三页数据
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数cityInformationArray包含所请求的城市信息数
                            据，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getCityInformationOfCity:(TPCity *)city
                      inLanguage:(TPWeatherReportLanguage)language
                           limit:(NSInteger)limit
                          offset:(NSInteger)offset
                      completion:(void(^)(NSArray<TPCityInformation *>*cityInformationArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定城市的交通限行信息
 * @param city 指定的地点
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数drivingRestriction包含返回的限行信息，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/

- (void)getDrivingRestrictionOfCity:(TPCity *)city
                         completion:(void(^)(TPDrivingRestriction * drivingRestriction, NSError *error))completionHandler;

/*!
 *
 * 获取指定城市空气质量排行榜信息
 * @param language 指定的语言
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数airRankingCities包含返回的城市排行榜，按空气质量从好到差排序，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getAirRankingInLanguage:(TPWeatherReportLanguage) language
                     completion:(void(^)(NSArray<TPAirRankingCity *>*airRankingCities, NSError *error))completionHandler;

/*!
 *
 * 获取指定城市逐日空气质量预报信息
 * @param city 指定的地点
 * @param language 指定的语言
 * @param days 指定的预报天数
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数airDailyArray包含返回的预报信息，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getAirDailyOfCity:(TPCity *)city
               inLanguage:(TPWeatherReportLanguage) language
                     days:(NSInteger)days
               completion:(void(^)(NSArray<TPAirDaily *>*airDailyArray, NSError *error))completionHandler;

/*!
 *
 * 获取指定城市空气逐小时空气质量预报信息
 * @param city 指定的地点
 * @param language 指定的语言
 * @param days 指定的预报天数
 * @param completionHandler 用于处理返回信息的回调函数，正常情况下回调参数airHourlyArray包含返回的预报信息，当出现错误或者用户权限不够时错误信息通过参数error返回
 **/
- (void)getAirHourlyOfCity:(TPCity *)city
                inLanguage:(TPWeatherReportLanguage) language
                      days:(NSInteger)days
                completion:(void(^)(NSArray<TPAirHourly *>*airHourlyArray, NSError *error))completionHandler;

@end

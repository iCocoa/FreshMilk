/*!
 @file		TPCity.h
 @brief		在Thinkpage SDK中用来泛指一个地点，大部分API都需要此对象作为参数。可以使用不同的方式创建TPCity对象，
            但它本身不具备转换信息的功能。例如，你不能使用IP地址初始化一个TPCity对象，然后试图获取它的城市名。
 @author	Shangwei Fang
 @date		Copyright (c) 2014 ThinkPage. All rights reserved.
 */


#import <Foundation/Foundation.h>
#import "CoreLocation/CLLocation.h"

@interface TPCity : NSObject
// 城市名字，可以为中文、英文或者拼音，例如"北京"、"beijing"
@property (nonatomic, copy) NSString *name;
// 城市的id，每个城市有一个唯一的id
@property (nonatomic, copy) NSString *cityid;
// 地点的经纬度
@property (nonatomic, copy) CLLocation *location;
// IP地址，例如"220.181.111.86"
@property (nonatomic, copy) NSString *ipAddress;

// 使用城市名字创建一个TPCity对象
+ (TPCity *)cityWithName:(NSString *)name;
// 使用城市Id创建一个TPCity对象
+ (TPCity *)cityWithID:(NSString *)cityid;
// 使用经纬度信息创建一个TPCity对象
+ (TPCity *)cityWithCLLocation:(CLLocation *)location;
// 使用IP地址创建一个TPCity对象
+ (TPCity *)cityWithIPAddress:(NSString *)ipAddress;
// 创建一个特殊的TPCity对象，用这个对象作为参数调用Thinkpage API时，会依据当前的IP地址自动识别城市
+ (TPCity *)cityWithAutoRecognization;

// 使用城市名字初始化一个TPCity对象
- (id)initWithName:(NSString*)name;
// 比较两个TPCity对象是否相同
- (BOOL)isEqualToCity:(TPCity *)city;
// 将TPCity对象转化为一段文字描述，具体描述方式依初始化方式不同而有所区别
- (NSString *)description;
@end

//
//  TPCityInformation.h
//  ThinkpageAPI
//
//  表示一个城市的具体信息
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPCityInformation : NSObject

//城市唯一ID, 例如"WX4EQ2XJD7V2"
@property (nonatomic, copy)NSString *cityid;
//城市名称
@property (nonatomic, copy)NSString *name;
//国家代码, 例如"CN"
@property (nonatomic, copy)NSString *countryCode;
//隶属层级，从小到大, 例如"海淀，北京，中国"
@property (nonatomic, copy)NSString *affiliations;
//IANA标准时区名称（该名称不受夏令时影响）, 例如"Asia/Shanghai"
@property (nonatomic, copy)NSString *timezone;
//相对于UTC时区的偏移量（采用夏令时的城市会因夏令时而变化）, 例如"+08:00"
@property (nonatomic, copy)NSString *timezoneOffset;

@end

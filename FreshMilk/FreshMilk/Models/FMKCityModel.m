//
//  FMKCityModel.m
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKCityModel.h"

static const NSUInteger kDefaultCityID = 440300;

@implementation FMKCityModel

+ (instancetype)defaultCity
{
    static FMKCityModel *defaultCity = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        defaultCity = [[FMKCityModel alloc] initWithCityName:@"shenzhen" cityID:kDefaultCityID longitude:114.0 latitude:22.f];
    });
    return defaultCity;
}

- (instancetype)init
{
    return [self initWithCityName:@"" cityID:0 longitude:0 latitude:0];
}

- (instancetype)initWithCityName:(NSString *)cityName
                          cityID:(NSUInteger)cityID
                       longitude:(CGFloat)longitue
                        latitude:(CGFloat)latitude
{
    self = [super init];
    if (self) {
        _cityName = cityName;
        _cityID = cityID;
        _longitude = longitue;
        _latitude = latitude;
    }
    return self;
}

@end

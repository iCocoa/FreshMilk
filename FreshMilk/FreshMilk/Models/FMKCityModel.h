//
//  FMKCityModel.h
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import <Foundation/Foundation.h>
@import CoreGraphics;

@interface FMKCityModel : NSObject

+ (instancetype)defaultCity;

@property (nonatomic, copy) NSString *cityName;
@property (nonatomic, assign) NSUInteger cityID;
@property (nonatomic, assign) CGFloat longitude;
@property (nonatomic, assign) CGFloat latitude;

@end

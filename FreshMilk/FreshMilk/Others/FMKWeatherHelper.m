//
//  FMKWeatherHelper.m
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKWeatherHelper.h"
#import "FMKSingleton.h"

static NSString *const kWeatherApiKey = @"4bsi5vayebbh3b1g";
static NSString *const kWeatherUserID = @"U9748D3C36";


@interface FMKWeatherHelper ()

@end

@implementation FMKWeatherHelper

+ (instancetype)helper
{
    return [FMKSingleton sharedInstance:[self class]];
}

@end

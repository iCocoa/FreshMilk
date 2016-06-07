//
//  FMKWeatherHelper.h
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ThinkpageAPI/TPWeatherManager.h>

typedef void(^Block)(TPWeatherNow *weather);

@interface FMKWeatherHelper : NSObject

+ (instancetype)helper;
- (void)getCurrentWeatherWithCompletionBlock:(Block)completion;

@end

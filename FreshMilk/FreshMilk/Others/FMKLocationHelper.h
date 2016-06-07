//
//  FMKLocationHelper.h
//  FreshMilk
//
//  Created by Hansen on 16/4/17.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import <Foundation/Foundation.h>
@class FMKCityModel;

typedef void(^locateSuccess)(FMKCityModel *city);
typedef void(^locateFailure)(FMKCityModel *city);

@interface FMKLocationHelper : NSObject

+ (instancetype)shareLocationManager;
- (void)startLocateWithSuccess:(locateSuccess)success failure:(locateFailure)failure;
@end

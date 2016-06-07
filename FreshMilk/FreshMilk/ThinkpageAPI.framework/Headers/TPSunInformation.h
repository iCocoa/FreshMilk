//
//  TPSunInformation.h
//  ThinkpageAPI
//
//  全球城市每天日出日落时间，对于喜欢拍摄或观赏日出日落的朋友来说是非常有用的
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPSunInformation : NSObject

//日出时间
@property (nonatomic, copy)NSDate *sunriseDate;
//日落时间
@property (nonatomic, copy)NSDate *sunsetDate;

@end

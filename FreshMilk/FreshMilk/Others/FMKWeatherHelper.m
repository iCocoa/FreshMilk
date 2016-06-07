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

#define kkey @"4bsi5vayebbh3b1g"
#define kuserID @"U9748D3C36"

@interface FMKWeatherHelper ()
@property (nonatomic, copy) Block block;
@end

@implementation FMKWeatherHelper

+ (instancetype)helper
{
    return [FMKSingleton sharedInstance:[self class]];
}

- (void)getCurrentWeatherWithCompletionBlock:(Block)completion
{
    __weak __typeof(self) weakSelf = self;
    weakSelf.block = completion;
    
    TPWeatherManager *weatherManager = [[TPWeatherManager alloc] initWithAccessCode:kkey userId:kuserID];
    
    [weatherManager getCurrentWeatherOfCity:[TPCity cityWithName:@"beijing"]
                                 inLanguage:kSimplifiedChinese
                                       unit:kCelsius
                                 completion:^(TPWeatherNow *weatherNow, NSError *err) {
                                     if(weatherNow == nil) {
                                         if (weakSelf.block) {
                                             weakSelf.block(weatherNow);
                                         }
                                     }
                                 }];
}



@end

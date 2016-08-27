//
//  FMKSingleton.m
//  FreshMilk
//
//  Created by Hansen on 16/3/10.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKSingleton.h"

@implementation FMKSingleton
+ (id)sharedInstance:(Class)className
{
    static id instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[className alloc] init];
    });
    return instance;
}
@end

//
//  FMKSingleton.h
//  FreshMilk
//
//  Created by Hansen on 16/3/10.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FMKSingleton : NSObject
+ (id)sharedInstance:(Class)className;
@end

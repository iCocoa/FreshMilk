//
//  UIColor+Helper.h
//  FreshMilk
//
//  Created by 吴海生 on 16/5/23.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Helper)
+ (UIColor *)colorWithHexString:(NSString *)color;
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat) alpha;
@end

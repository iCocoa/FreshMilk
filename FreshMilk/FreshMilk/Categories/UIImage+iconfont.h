//
//  UIImage+iconfont.h
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Iconfont)

+ (UIImage *)imageWithIconCode:(NSString *)iconCode fontName:(NSString*)fontName size:(CGFloat)size color:(UIColor *)color;

+ (UIImage *)imageWithIconCode:(NSString *)iconCode fontName:(NSString*)fontName fontSize:(CGFloat)fontSize imageSize:(CGSize)imageSize color:(UIColor *)color;

@end

//
//  UIImage+iconfont.m
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "UIImage+iconfont.h"

@implementation UIImage (Iconfont)

+ (UIImage *)imageWithIconCode:(NSString *)iconCode fontName:(NSString*)fontName size:(CGFloat)size color:(UIColor *)color
{
    return [self imageWithIconCode:iconCode fontName:fontName fontSize:size imageSize:CGSizeMake(size, size) color:color];
}

+ (UIImage *)imageWithIconCode:(NSString *)iconCode fontName:(NSString*)fontName fontSize:(CGFloat)fontSize imageSize:(CGSize)imageSize color:(UIColor *)color
{
    UIGraphicsBeginImageContextWithOptions(imageSize, NO, [[UIScreen mainScreen] scale]);
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, imageSize.width, imageSize.height)];
    label.font = [UIFont fontWithName:fontName size:fontSize];
    label.text = iconCode;
    if(color){
        label.textColor = color;
    }
    [label.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *retImage = UIGraphicsGetImageFromCurrentImageContext();
    return retImage;
}

@end

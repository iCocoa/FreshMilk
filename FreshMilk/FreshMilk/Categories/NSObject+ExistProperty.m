//
//  NSObject+ExistProperty.m
//  FreshMilk
//
//  Created by Hansen on 16/8/26.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "NSObject+ExistProperty.h"
#import <objc/runtime.h>

@implementation NSObject (ExistProperty)

- (BOOL)hasProperty:(NSString *)propertyName
{
    unsigned int count = 0;
    objc_property_t * properties = class_copyPropertyList([self class], &count);
    for (int i = 0; i < count; i++) {
        objc_property_t p = properties[i];
        NSString *name = [NSString stringWithUTF8String:property_getName(p)];
        if ([name isEqualToString:propertyName]) {
            free(properties);
            return YES;
        }
    }
    free(properties);
    return NO;
}

@end

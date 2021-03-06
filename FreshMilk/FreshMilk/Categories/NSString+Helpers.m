//
//  NSString+Helpers.m
//  FreshMilk
//
//  Created by 吴海生 on 16/4/26.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "NSString+Helpers.h"
#import <CommonCrypto/CommonDigest.h>

@implementation NSString (Helpers)

- (NSString *)md5
{
    const char *cStr = [self UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    
    CC_MD5(cStr, (CC_LONG)strlen(cStr), result);
    
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]
            ];
}

@end

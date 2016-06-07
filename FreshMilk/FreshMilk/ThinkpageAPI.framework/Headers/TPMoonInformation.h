//
//  TPMoonInformation.h
//  ThinkpageAPI
//
//  全球城市每天月出月落时间和月相信息，让依赖潮汐的海洋工作者和拍摄星星月亮的摄影爱好者的生活更美好。
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPMoonInformation : NSObject

//月出时间
@property (nonatomic, copy)NSDate *moonriseDate;
//月落时间
@property (nonatomic, copy)NSDate *moonsetDate;
//月球被照明部分比例（0~1)
@property (nonatomic, assign)double fraction;
//月相（0~1）
@property (nonatomic, assign)double phase;
//月相名称，例如"蛾眉月"
@property (nonatomic, copy)NSString *phaseName;

@end

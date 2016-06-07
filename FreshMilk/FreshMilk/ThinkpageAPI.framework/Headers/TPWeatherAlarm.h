//
//  TPWeatherAlarm.h
//  ThinkpageAPI
//
//  特定城市的气象灾害预警信息
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TPWeatherAlarm : NSObject

//灾害预警标题，例如"四川省乐山市气象台发布大雾黄色预警"
@property (nonatomic, copy)NSString *title;
//灾害预警类型, 例如"大雾"
@property (nonatomic, copy)NSString *type;
//灾害预警级别，例如"黄色"
@property (nonatomic, copy)NSString *level;
//灾害预警状态, 例如"预警中"
@property (nonatomic, copy)NSString *status;
//文本形式的灾害预警详细内容
@property (nonatomic, copy)NSString *text;
//发布时间
@property (nonatomic, copy)NSDate *publishingDate;

@end

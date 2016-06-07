//
//  TPDrivingRestriction.h
//  ThinkpageAPI
//
//  查询北京、天津、哈尔滨、成都、杭州、贵阳、长春、兰州8个城市的今天、明天和后天的
//  机动车尾号限行数据。
//
//  Created by Hao Gong on 16/4/27.
//  Copyright © 2016 Thinkpage. All rights reserved.
//

#ifndef TPDrivingRestriction_h
#define TPDrivingRestriction_h

#import <Foundation/Foundation.h>

// 单日尾号限行数据
@interface TPDrivingRestrictionItem : NSObject
// 限行日期
@property(nonatomic, copy)NSDate *date;
// 限行尾号数组
@property(nonatomic, strong)NSArray<NSString *> *plates;
// 限行备注
@property(nonatomic, copy)NSString *memo;

@end

// 交通限行数据
@interface TPDrivingRestriction : NSObject
// 处罚规定
@property(nonatomic, copy)NSString *penalty;
// 限行区域
@property(nonatomic, copy)NSString *region;
// 详细说明
@property(nonatomic, copy)NSString *remarks;
// 尾号限行数组
@property(nonatomic, strong)NSArray<TPDrivingRestrictionItem *> *restrictionItems;
@end


#endif /* TPDrivingRestriction_h */

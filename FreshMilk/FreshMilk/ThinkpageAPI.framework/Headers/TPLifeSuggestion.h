//
//  TPLifeSuggestion.h
//  ThinkpageAPI
//
//  指定城市的基本、交通、生活、运动、健康5大类共27项生活指数。目前仅支持中国城市。
//  基本类：穿衣、紫外线强度、洗车、旅游、感冒、运动
//  交通类：交通、路况
//  生活类：晾晒、雨伞、空调开启、啤酒、逛街、夜生活、约会
//  运动类：晨练、钓鱼、划船、放风筝
//  健康类：过敏、美发、化妆、风寒、防晒、空气污染扩散条件、舒适度、心情
//
//  Created by Hao Gong on 15/12/21.
//  Copyright © 2015 Thinkpage. All rights reserved.
//

#import <Foundation/Foundation.h>

//某项生活指数的描述信息或生活建议
@interface TPLifeSuggestionItem : NSObject

@property(nonatomic, copy)NSString *brief; //简要建议, 例如"不太适宜"
@property(nonatomic, copy)NSString *details;  //详细建议, 例如"您将感到很舒适，一般不需要开启空调。"

+ (instancetype)lifeSuggestionItemWithBrief:(NSString *)brief details:(NSString *)details;
@end

//包含特定城市的所有生活指数信息
@interface TPLifeSuggestion : NSObject

//空调开启建议
@property(nonatomic, strong)TPLifeSuggestionItem *airCondition;
//空气污染扩散条件
@property(nonatomic, strong)TPLifeSuggestionItem *airPollution;
//晾晒
@property(nonatomic, strong)TPLifeSuggestionItem *airing;
//过敏
@property(nonatomic, strong)TPLifeSuggestionItem *allergy;
//啤酒
@property(nonatomic, strong)TPLifeSuggestionItem *beer;
//划船
@property(nonatomic, strong)TPLifeSuggestionItem *boating;
//洗车
@property(nonatomic, strong)TPLifeSuggestionItem *carWashing;
//风寒
@property(nonatomic, strong)TPLifeSuggestionItem *chill;
//舒适度
@property(nonatomic, strong)TPLifeSuggestionItem *comfort;
//约会
@property(nonatomic, strong)TPLifeSuggestionItem *dating;
//穿衣
@property(nonatomic, strong)TPLifeSuggestionItem *dressing;
//钓鱼
@property(nonatomic, strong)TPLifeSuggestionItem *fishing;
//感冒
@property(nonatomic, strong)TPLifeSuggestionItem *flu;
//美发
@property(nonatomic, strong)TPLifeSuggestionItem *hairDressing;
//放风筝
@property(nonatomic, strong)TPLifeSuggestionItem *kiteflying;
//化妆
@property(nonatomic, strong)TPLifeSuggestionItem *makeup;
//心情
@property(nonatomic, strong)TPLifeSuggestionItem *mood;
//晨练
@property(nonatomic, strong)TPLifeSuggestionItem *morningSport;
//夜生活
@property(nonatomic, strong)TPLifeSuggestionItem *nightLife;
//路况
@property(nonatomic, strong)TPLifeSuggestionItem *roadCondition;
//购物
@property(nonatomic, strong)TPLifeSuggestionItem *shopping;
//运动
@property(nonatomic, strong)TPLifeSuggestionItem *sport;
//防晒
@property(nonatomic, strong)TPLifeSuggestionItem *sunscreen;
//交通
@property(nonatomic, strong)TPLifeSuggestionItem *traffic;
//旅游
@property(nonatomic, strong)TPLifeSuggestionItem *travel;
//雨伞
@property(nonatomic, strong)TPLifeSuggestionItem *umbrella;
//紫外线
@property(nonatomic, strong)TPLifeSuggestionItem *ultraviolet;
//数据更新时间
@property(nonatomic, copy)NSDate *lastUpdateDate;

@end

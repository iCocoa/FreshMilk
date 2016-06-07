//
//  FMKHomeViewController.m
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKHomeViewController.h"
#import "FMKWeatherHelper.h"
#import "FMKWeather.h"
#import "UIImage+Iconfont.h"
#import "FMKIconfontContants.h"
#import "UIColor+Helper.h"

@interface FMKHomeViewController ()
@property (nonatomic, strong) FMKWeather *weather;
@property (nonatomic, assign) FMKWeatherHelper *weatherHelper;
@end

@implementation FMKHomeViewController

#pragma mark - Life cycle method
- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"首页";
}

- (void)gotoWeatherPage:(id)sender
{
    NSLog(@"goto ");
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

#pragma mark - Getter method

@end

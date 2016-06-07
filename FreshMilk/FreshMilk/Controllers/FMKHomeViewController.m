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
#import <ThinkpageAPI/TPWeatherNow.h>

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
    [self setLeftNavigationBarItem];
}

- (void)setLeftNavigationBarItem
{
    __weak __typeof(self) weakSelf = self;
    
    _weatherHelper = [FMKWeatherHelper helper];
    
    [_weatherHelper getCurrentWeatherWithCompletionBlock:^(TPWeatherNow *weather) {
        if (!weather) {
            weakSelf.weather.currentWeather = weather;
            UIButton *weatherButton = [UIButton buttonWithType:UIButtonTypeCustom];
            weatherButton.frame = CGRectMake(0, 0, 44, 44);
            [weatherButton addTarget:weakSelf action:@selector(gotoWeatherPage:) forControlEvents:UIControlEventTouchUpInside];
//            NSString *iconCode = [[weakSelf.weather iconfontDict] objectForKey:@"text"];
            UIImage *weatherImage =
            
            [UIImage imageWithIconCode:FMKIconWeatherHeavyDownpour fontName:FMKIconFont fontSize:16 imageSize:CGSizeMake(44, 44) color:[UIColor colorWithHexString:@"#272636"]];
            
            [weatherButton setImage:weatherImage forState:UIControlStateNormal];
            self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:weatherButton];
        }
    }];
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

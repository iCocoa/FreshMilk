//
//  FMKBaseViewController.m
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKBaseViewController.h"
#import "UIColor+Helper.h"

@interface FMKBaseViewController ()<UIGestureRecognizerDelegate>

@end

@implementation FMKBaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor colorWithHexString:@"#f5f5f5"];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    if ([self.navigationController.viewControllers count] >= 2) {
        self.navigationController.interactivePopGestureRecognizer.enabled = YES;
        self.navigationController.interactivePopGestureRecognizer.delegate = self;
    }
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    if ([self.navigationController.viewControllers count] < 2) {
        self.navigationController.interactivePopGestureRecognizer.enabled = NO;
    }
    self.navigationController.interactivePopGestureRecognizer.delegate = nil;
}

@end

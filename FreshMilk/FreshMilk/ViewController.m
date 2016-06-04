//
//  ViewController.m
//  FreshMilk
//
//  Created by Hansen on 16/6/4.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "ViewController.h"
#import "FMKHomeViewController.h"
#import "FMKNoteViewController.h"
#import "FMKFindViewController.h"
#import "FMKMeViewController.h"
#import "FMKIconfontContants.h"

#import "UIColor+Helper.h"
#import "UIImage+Iconfont.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self addChildVc:[FMKHomeViewController class] iconCode:FMKIconHome];
    [self addChildVc:[FMKNoteViewController class] iconCode:FMKIconNote];
    [self addChildVc:[FMKFindViewController class] iconCode:FMKIconFind];
    [self addChildVc:[FMKMeViewController class] iconCode:FMKIconMe];
}

- (void)addChildVc:(Class)class iconCode:(NSString *)iconCode
{
    UIViewController *childVc = (id)[[class alloc] init];
    UIColor *normalColor = [UIColor colorWithHexString:@"#272636"];
    UIColor *highLightedColor = [UIColor colorWithHexString:@"#ea8010"];
    UIImage *normalImage = [UIImage imageWithIconCode:iconCode fontName:FMKIconFont size:30 color:normalColor];
    UIImage *highLighedImage = [UIImage imageWithIconCode:iconCode fontName:FMKIconFont size:30 color:highLightedColor];
    [self addChildVc:childVc title:childVc.title image:normalImage selectedImage:highLighedImage];
}

- (void)addChildVc:(UIViewController *)childVc title:(NSString *)title image:(UIImage *)image selectedImage:(UIImage *)selectedImage
{
    childVc.title = title;
    [childVc view];
    
    childVc.tabBarItem.image = [image imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    childVc.tabBarItem.selectedImage = [selectedImage imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    
    UIColor *titleColor = [UIColor colorWithHexString:@"#595757"];
    NSMutableDictionary *normalTextAttrs = [NSMutableDictionary dictionary];
    normalTextAttrs[NSForegroundColorAttributeName] = titleColor;
    NSMutableDictionary *selectTextAttrs = [NSMutableDictionary dictionary];
    selectTextAttrs[NSForegroundColorAttributeName] = titleColor;
    [childVc.tabBarItem setTitleTextAttributes:normalTextAttrs forState:UIControlStateNormal];
    [childVc.tabBarItem setTitleTextAttributes:selectTextAttrs forState:UIControlStateSelected];
    
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:childVc];
    [self addChildViewController:nav];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

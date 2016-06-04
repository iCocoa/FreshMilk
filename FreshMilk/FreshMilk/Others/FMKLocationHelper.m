//
//  FMKLocationHelper.m
//  FreshMilk
//
//  Created by Hansen on 16/4/17.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKLocationHelper.h"
#import "FMKSingleton.h"
@import CoreLocation;
@import UIKit;

@interface FMKLocationHelper ()<CLLocationManagerDelegate>
@property (nonatomic, strong) CLLocationManager *locationManager;
@end

@implementation FMKLocationHelper

+ (instancetype)shareLocationManager
{
    return [FMKSingleton sharedInstance:[self class]];
}

- (void)startLocate
{
    if ([CLLocationManager locationServicesEnabled]) {
        [self.locationManager startUpdatingLocation];
    }
    else if ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusDenied){
        NSLog(@"定位功能不可用，提示用户或忽略");
    }
}

#pragma mark - CLLocationManagerDelegate method
- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray<CLLocation *> *)locations
{
    CLLocation *location = [locations lastObject];
    
    CLGeocoder * geoCoder = [[CLGeocoder alloc] init];
    
    [geoCoder reverseGeocodeLocation:location completionHandler:^(NSArray *placemarks, NSError *error) {
        for (CLPlacemark * placemark in placemarks) {
            NSString *localityName = [placemark locality];
            NSArray *prefixNameArr = [localityName componentsSeparatedByString:@"市"];
            if (prefixNameArr.count > 0) {
                localityName = [prefixNameArr objectAtIndex:0];
                NSLog(@"定位城市名字=======%@",placemark);
                NSLog(@">>>>%@",localityName);
                break;
            }
        }
    }];
    [self.locationManager stopUpdatingLocation];
}

- (void)locationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation
{
    CLGeocoder * geoCoder = [[CLGeocoder alloc] init];
    
    [geoCoder reverseGeocodeLocation:newLocation completionHandler:^(NSArray *placemarks, NSError *error) {
        for (CLPlacemark * placemark in placemarks) {
            NSLog(@"定位城市名字=======%@",placemark);
            NSString *localityName = [placemark locality];
            NSArray *prefixNameArr = [localityName componentsSeparatedByString:@"市"];
            if (prefixNameArr.count > 0) {
                localityName = [prefixNameArr objectAtIndex:0];
                break;
            }
        }
    }];
    [self.locationManager stopUpdatingLocation];
}

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error
{
    if ([error code] == kCLErrorDenied){
        //访问被拒绝
    }
    if ([error code] == kCLErrorLocationUnknown) {
        //无法获取位置信息
    }
}

- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status
{
    switch (status) {
        case kCLAuthorizationStatusNotDetermined:
            if ([self.locationManager respondsToSelector:@selector(requestAlwaysAuthorization)])
            {
                [self.locationManager requestWhenInUseAuthorization];
            }
            break;
        default:
            break;
    }
}

#pragma mark - Getter method

- (CLLocationManager *)locationManager
{
    if (!_locationManager) {
        _locationManager = [[CLLocationManager alloc] init];
        _locationManager.delegate = self;
        _locationManager.desiredAccuracy = kCLLocationAccuracyHundredMeters;
        _locationManager.distanceFilter = 200;
        
        if ([UIDevice currentDevice].systemVersion.floatValue >= 8.0 && [CLLocationManager authorizationStatus] == kCLAuthorizationStatusNotDetermined) {
            [_locationManager requestWhenInUseAuthorization];
            [_locationManager requestAlwaysAuthorization];
        }
    }
    return _locationManager;
}

@end

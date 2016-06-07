//
//  FMKLocationHelper.m
//  FreshMilk
//
//  Created by Hansen on 16/4/17.
//  Copyright © 2016年 Hansen. All rights reserved.
//

#import "FMKLocationHelper.h"
#import "FMKSingleton.h"
#import "FMKCityModel.h"
@import CoreLocation;
@import UIKit;

static NSString *const kSelectedCity = @"selectedCity";

@interface FMKLocationHelper ()<CLLocationManagerDelegate>
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, strong) FMKCityModel *defaultCity;
@property (nonatomic, strong) FMKCityModel *selectedCity;
@property (nonatomic, strong) FMKCityModel *currentCity;
//@property (nonatomic, strong) FMKCityModel *lastLocateCity;
@property (nonatomic, copy) locateSuccess success;
@property (nonatomic, copy) locateFailure failure;
@end

@implementation FMKLocationHelper

+ (instancetype)shareLocationManager
{
    return [FMKSingleton sharedInstance:[self class]];
}

- (void)startLocateWithSuccess:(locateSuccess)success failure:(locateFailure)failure
{
    self.success = success;
    self.failure = failure;
    self.selectedCity = [[NSUserDefaults standardUserDefaults] objectForKey:kSelectedCity];
    self.currentCity = [[FMKCityModel alloc] init];
    [self startLocate];
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
    
    CLGeocoder *geoCoder = [[CLGeocoder alloc] init];
    
    [geoCoder reverseGeocodeLocation:location completionHandler:^(NSArray *placemarks, NSError *error) {
        if (placemarks.count > 0) {
            CLPlacemark *placemark = placemarks[0];
            NSString *currentCityName = placemark.locality;
            if (!currentCityName) {
                currentCityName = placemark.administrativeArea;
            }
            self.currentCity.cityName = currentCityName;
            self.currentCity.longitude = placemark.location.coordinate.longitude;
            self.currentCity.latitude = placemark.location.coordinate.latitude;
            
            if (!self.selectedCity) {
                self.selectedCity = self.currentCity;
                [[NSUserDefaults standardUserDefaults] setObject:self.selectedCity forKey:kSelectedCity];
            } else {
                if (![self.selectedCity.cityName isEqualToString:self.currentCity.cityName]) {
                    // 让用户选择是否切换到当前城市。
                }
            }
            
            __weak __typeof(self) weakSelf = self;
            self.success(weakSelf.currentCity);
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
    __weak __typeof(self) weakSelf = self;
    self.failure(weakSelf.selectedCity ? weakSelf.selectedCity : [FMKCityModel defaultCity]);
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

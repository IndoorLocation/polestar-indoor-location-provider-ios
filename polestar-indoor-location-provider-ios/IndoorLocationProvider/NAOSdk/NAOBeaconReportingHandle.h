//
//  NAOBeaconReportingHandle.h
//  NaoSDK
//
//  Created by Pole Star on 15/02/2016.
//  Copyright © 2016 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NAOBeaconReportingHandleDelegate.h"
#import "NAOSyncDelegate.h"
#import "NAOSensorsDelegate.h"
#import "NAOServiceHandle.h"

@class NaoContext;

/** NAO BeaconReporting Service
 
 The NAOBeaconReportingHandle inherits from NAOServiceHandle which itself inhgerits form NSObject.
 You need to create an instance for NAOBeaconReportingHandle to get access to the beacon reporting service.
 The NAOBeaconReportingHandle enables you to start the beacon reporting service.
 */
@interface NAOBeaconReportingHandle : NAOServiceHandle

/** WARNING : init not available, please use initWithKey: delegate: sensorsDelegate:
 
 */
-(instancetype _Nonnull) init __attribute__((unavailable("init not available, please use initWithKey: delegate: sensorsDelegate:")));

/** Init NAOBeaconReportingHandle with API key
 
 By default, for the beacon reporting service, the configuration file (alert.json) is located on Amazon S3.
 However, you can host this file on your own private server if you want.
 The data will be synchronised each time you call the method **synchroniseData** of your manager.
 
 @param key: The API Key is key available in the developer section of NAO Cloud. A key is associated to one and only one application.
 By Default, one API key is created at the site creation, this API key is associated with the site. The services available through this API key are the services activated on this associated site.
 
 @param delegate: Object implementing the NAOBeaconReportingHandleDelegate protocol
 
 @param sensorsDelegate: Object implementing the NAOSensorsDelegate protocol
 
 */
- (id _Nonnull)initWithKey:(NSString * _Nonnull)key delegate:(id<NAOBeaconReportingHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate;

- (id _Nonnull)initWithNaoContext:(NaoContext * _Nullable)naoContext key:(NSString * _Nonnull)key delegate:(id<NAOBeaconReportingHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate ;

@end

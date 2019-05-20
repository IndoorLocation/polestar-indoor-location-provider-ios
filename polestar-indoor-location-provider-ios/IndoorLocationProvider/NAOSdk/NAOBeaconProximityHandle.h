//
//  NAOBeaconProximityHandle.h
//  NaoSDK
//
//  Created by Pole Star on 23/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NAOBeaconProximityHandleDelegate.h"
#import "NAOSyncDelegate.h"
#import "NAOSensorsDelegate.h"
#import "NAOServiceHandle.h"

@class NaoContext;

/**  NAO Beacon Proxomity Service
 
 The NAOBeaconProximityHandle inherits from NAOServiceHandle which itself inhgerits form NSObject.
 You need to create an instance for NAOBeaconProximityHandle to get access to the Beacon Proximity service.
 The NAOBeaconProximityHandle enables you to start the beacon proximity service.
 
 */
@interface NAOBeaconProximityHandle : NAOServiceHandle

/** WARNING : init not available, please use initWithKey: delegate: sensorsDelegate:
 
 */
-(instancetype _Nonnull) init __attribute__((unavailable("init not available, please use initWithKey: delegate: sensorsDelegate:")));

/** Init Handle with key
 
 You must provide a sensorsDelegate when registering to the location manager to listen for sensor activation requests.
 Your application can embed a configuration file, if so, it must be located in a folder ** Assets.xcassets ** of your Xcode Project.
 The NAOBeaconProximityManager will automatically copy this folder in the application and it will be loaded at the moment of register.
 If you don't have a data embedded inside your application, you need to call **synchroniseData** to get the data from our server.
 
 @param key: The API Key is key available in the developer section of NAO Cloud. A key is associated to one and only one application.
 By Default, one API key is created at the site creation, this API key is associated with the site. The services available through this API key are the services activated on this associated site.
 
 @param delegate: object implementing the NAOBeaconProximityHandleDelegate protocol
 
 @param sensorsDelegate: object implementing the NAOSensorsDelegate protocol
 */
- (id _Nonnull)initWithKey:(NSString * _Nonnull)key delegate:(id<NAOBeaconProximityHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate;

- (id _Nonnull)initWithNaoContext:(NaoContext * _Nullable)naoContext key:(NSString * _Nonnull)key delegate:(id<NAOBeaconProximityHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate ;

@end

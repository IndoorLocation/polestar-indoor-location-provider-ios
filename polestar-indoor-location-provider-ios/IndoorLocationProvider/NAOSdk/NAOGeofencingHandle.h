//
//  NAOGeofencingHandle.h
//  NaoSDK
//
//  Created by Pole Star on 22/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NAOGeofencingHandleDelegate.h"
#import "NAOSyncDelegate.h"
#import "NAOSensorsDelegate.h"
#import "NAOServiceHandle.h"
#import "NAOGeofenceData.h"

@class NaoContext;

/** NAO Geofencing Service
 
 The NAOGeofencingHandle inherits from NAOServiceHandle which itself inhgerits form NSObject.
 You need to create an instance for NAOGeofencingHandle to get access to the geofencing service.
 The NAOGeofencingHandle enables you to start the geofencing service.
 */
@interface NAOGeofencingHandle : NAOServiceHandle

/** WARNING : init not available, please use initWithKey: delegate: sensorsDelegate:
 
 */
-(instancetype _Nonnull) init __attribute__((unavailable("init not available, please use initWithKey: delegate: sensorsDelegate:")));

/** Init the handle with a key
 
 You must provide a sensorsDelegate when registering to the location manager to listen for sensor activation requests.
 Your application can embed a configuration file, if so, it must be located in a folder ** Assets.xcassets ** of your Xcode Project.
 The NAOGeofencingManager will automatically copy this folder in the application and it will be loaded at the moment of register.
 If you don't have a data embedded inside your application, you need to call **synchroniseData** to get the data from our server.
 
 @param key: The API Key is key available in the developer section of NAO Cloud. A key is associated to one and only one application.
 By Default, one API key is created at the site creation, this API key is associated with the site. The services available through this API key are the services activated on this associated site.
 
 @param delegate: Object implementing the NAOGeofencingHandleDelegate protocol
 
 @param sensorsDelegate: Object implementing the NAOSensorsDelegate protocol
 */
- (id _Nonnull)initWithKey:(NSString * _Nonnull)key delegate:(id<NAOGeofencingHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate;

/**
 
 
 @param geofenceId: Id of geofence wanted
 @return: Return the NAOGeofenceData wanted
 @since 4.2.2
 */
-(NAOGeofenceData *)getGeofenceData:(int)geofenceId;

- (id _Nonnull)initWithNaoContext:(NaoContext * _Nullable)naoContext key:(NSString * _Nonnull)key delegate:(id<NAOGeofencingHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate ;

@end

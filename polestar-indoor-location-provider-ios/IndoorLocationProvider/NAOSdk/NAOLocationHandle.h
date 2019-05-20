//
//  NAOLocationHandle.h
//  NaoSDK
//
//  Created by Pole Star on 22/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NAOLocationHandleDelegate.h"
#import "NAOSyncDelegate.h"
#import "NAOSensorsDelegate.h"
#import "NAOServiceHandle.h"

#import "DBTPOWERMODE.h"

@class NaoContext;

/** Nao Location Service
 
 The NAOLocationHandle inherits from NAOServiceHandle which itself inhgerits form NSObject.
 You need to create an instance for NAOLocationHandle to get access to the location service.
 The NAOLocationHandle enables you to start the location service.
 */
@interface NAOLocationHandle : NAOServiceHandle

/** WARNING : init not available, please use initWithKey: delegate: sensorsDelegate:
 
 */
-(instancetype _Nonnull) init __attribute__((unavailable("init not available, please use initWithKey: delegate: sensorsDelegate:")));

/** Init the Handle with a key
 
 The **client** must implement the NAOLocationhandleDelegate to receive location events. Several clients can be listening the location events triggered by NAOLocationhandle. The first register will start the location service. This methods will return an error if the API key of the NAOLocationhandle is not set or not valid. You must provide a sensorsDelegate when registering to the location handle to listen for sensor activation requests. Your application can embed a database, if so, it must be located in a folder ** Assets.xcassets **. The NAOLocationhandle will automatically copy this folder in the application and it will be loaded at the moment of register. If you don't have a database embedded inside your application, you need to call **synchroniseData** to get the PDB from our server.
 
 @param key: The API Key is key available in the developer section of NAO Cloud. A key is associated to one and only one application.
 By Default, one API key is created at the site creation, this API key is associated with the site. The services available through this API key are the services activated on this associated site.
 
 @param delegate: Object implementing the NAOLocationHandleDelegate
 
 @param sensorsDelegate: Object implementing the NAOSensorsDelegate
 */
- (id _Nonnull)initWithKey:(NSString * _Nonnull)key delegate:(id<NAOLocationHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate;


//For Polestar use only
- (id _Nonnull)initWithNaoContext:(NaoContext * _Nullable)naoContext key:(NSString * _Nonnull)key delegate:(id<NAOLocationHandleDelegate> _Nonnull)delegate sensorsDelegate:(id<NAOSensorsDelegate> _Nonnull)sensorsDelegate ;


/** Database Version
 
 @return Database version: Version of the Database used.
 */
- (NSString * _Nullable)getDatabaseVersions;


@end

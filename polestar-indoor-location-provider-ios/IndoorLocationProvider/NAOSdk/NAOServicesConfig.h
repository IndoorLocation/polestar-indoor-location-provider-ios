//
//  NAOServicesConfig.h
//  NaoSDK
//
//  Created by Pole Star on 02/02/2016.
//  Copyright © 2016 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DBTPOWERMODE.h"
#import "NAOSyncDelegate.h"

@class NaoContext;

/** Configuration of NAO Services

 This class holds a configuration for all the NAO services used inside your application.
 
 */
@interface NAOServicesConfig : NSObject

/** Set the Root URL
 
 @param rootURL Url where are hosted the configuration required for the NAO services (PDB and app.json)
 */
+ (void) setRootURL:(NSString*)rootURL;

/** Get the the Root URL
 
 @return Returns the root url used by the services
 */
+ (NSString*) getRootURL;

/** Get SDK software version
 
 @return Returns the software version of the SDK used
 */
+ (NSString*) getSoftwareVersion;

/**
 
 */
+ (void)synchronizeData:(id<NAOSyncDelegate>)delegate apiKey:(NSString *)apiKey;

/**
 
 */
+ (void)startLoggingMeasurements;

/**
 
 */
+ (void)stopLoggingMeasurements;

/**
 
 */
+ (DBTPOWERMODE) getPowerMode;

/**
 
 */
+ (void)uploadNAOLogInfo;

/** Sets the Wake Up Notifier to receive notifications when the device arrives on site.
 It is based on Ibeacons.
 */
+ (void)enableOnSiteWakeUp;

/** Disable the Wake Up Notifier to not receive notifications when the device arrives on site.
 It is based on Ibeacons.
 */
+ (void)disableOnSiteWakeUp;

+ (NaoContext *)getNaoContext;

@end

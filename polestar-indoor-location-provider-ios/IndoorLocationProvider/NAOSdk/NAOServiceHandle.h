//
//  NAOServiceHandle.h
//  NaoSDK
//
//  Created by Pole Star on 03/02/2016.
//  Copyright © 2016 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NAOSyncDelegate.h"
#import "DBTPOWERMODE.h"

@protocol INaoServiceProvider;

/** NAO Service Handle
 
 Mother Handle Object of NAO Service Handles
 */
@interface NAOServiceHandle : NSObject

@property (nonatomic, retain) id<INaoServiceProvider> provider;

/** Data Synchronisation
 
 You must provide a sensorsDelegate when registering to the service handle to listen for sensor activation requests.
 The NAOServiceHandle will automatically copy this folder in the application and it will be loaded at the moment of register.
 If you don't have a data embedded inside your application, you need to call ** synchroniseData ** to get the data from our server.
 
 @param delegate: Object implementing the NAOSyncDelegate protocol
 */
- (void)synchronizeData:(id<NAOSyncDelegate>)delegate;

/** Start Service
 The service will start if not already running.
 
 */
- (BOOL)start;

/** Stop Service
 If they are no more listeners, service will shut down.
 
 */
- (void)stop;

/** API Key
 
 @return apiKey: The API Key is key available in the developer section of NAO Cloud. A key is associated to one and only one application.
 By Default, one API key is created at the site creation, this API key is associated with the site. The services available through this API key are the services activated on this associated site.
 */
- (NSString *)getApiKey;

/** Power Mode
 The power mode is used to control the trade-off between battery consumption and accuracy.
 
 @param power: The following modes are possible:
 </br>
 </br>
 
 * DBTPOWERMODE_HIGH
 </br>
 * DBTPOWERMODE_LOW
 </br>
 
 We advise to use the high accuracy only when the service is displayed to the user.
 Otherwise, if your application is in background or if the position is not displayed we advise to use the **LOW_ENERGY** mode.
 In terms of accuracy, the position in **LOW_ENERGY** mode is not as smooth as the **HIGH_ACCURACY** mode but is more than enough for most of your use the cases in background.
 
 */
- (void)setPowerMode:(DBTPOWERMODE)power;

/**
 @return power mode of the service handle
 */
- (DBTPOWERMODE)getPowerMode;


/** Sets maximum number of calibration requests.
 In some venues, magnetic interferences can cause frequent device compass decalibration.
 This method provides a way to reduce notification spam to the user.
 
 @param max: Maximum number of calibration requests to be issued. Default is -1, which is infinity. Set it to 0 to always ignore the notification.
 */
- (void)setCompassCalibrationScreenShowedMaxNumber:(int)max;

/** Sets minimum interval between calibration requests.
 Provides a way to control how often the end user will be prompted about compass calibration.
 
 @param nSec: Minimum time interval between two calibration requests, in seconds. Default is 1800 seconds (30 minutes).
 */
- (void)setTimeMinBetweenCompassCalibrationScreen:(int)nSec;

/** Resets the number of times the calibration has been displayed.
 
 */
- (void)resetCompassCalibrationScreenShowed;

@end

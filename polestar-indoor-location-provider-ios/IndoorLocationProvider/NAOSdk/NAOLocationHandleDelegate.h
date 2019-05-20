//
//  NAOLocationDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 22/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "DBNAOERRORCODE.h"
#import "DBTNAOFIXSTATUS.h"

/** The NAOLocationhandleDelegate is a protocol that is implemented by one of your objects to received the location events from the NAOLocationHandle.
 */

@protocol NAOLocationHandleDelegate <NSObject>



/** Location Error
 
 @param errCode: Indicates an error code among DBNAOERRORCODE.
 @param message: Provinding additionnal information on the message
 */
- (void) didFailWithErrorCode:(DBNAOERRORCODE)errCode andMessage:(NSString*)message;

/** Location Change
 Returns the **location** of the user. The location coordinates are in WGS84 format.
 Locations are sent approximately every second when the status of the NAOLocationhandle is **AVAILABLE**.
 
 @param location: Location of the user provided as a CLLocation object.
 Course value (ie compass bearing) is set to -1000 at the start of the service and it may take up to 6 locations to get a valid value.
 Value will stay at -1000 if compass is disabled.
 If compass calibration is needed, NAOSensorDelegate.requiresCompassCalibration is triggered.
 When the compass is calibrated again, NAOSensorDelegate.didCompassCalibrated is triggered.
 
 */
- (void) didLocationChange:(CLLocation *) location;


/** Location Status
 Indicates the status of the NAO Location service
 
 @param status: location status, one of DBTNAOFIXSTATUS.
 */
- (void) didLocationStatusChanged:(DBTNAOFIXSTATUS) status;


/** Enter Site (Optional)
 
 Site is determined by the positioning area which is actually where the positioning graph is drawn.
 Triggered when e.g. receiving the first signal from a beacon/access point in the covered area.
 
 IMPORTANT: This is not based on accurate geofencing and should not to be relied on when time/precision is required.
        Use NAO Geofencing service instead for such use cases or request advice from Pole Star team.
 
 @param name: name of the site defined on NAO Cloud
 */
@optional
- (void) didEnterSite:(NSString *)name;

/** Exit Site (Optional)
 
 Site is determined by the positioning area which is actually where the positioning graph is drawn.
 Triggered after no beacon/access point in the covered area has been seen for some time.
 
 Can come after a significant delay due to app foreground/background status etc.
 
 IMPORTANT: This is not based on accurate geofencing and should not to be relied on when time/precision is required.
        Use NAO Geofencing service instead for such use cases or request advice from Pole Star team.
 
 @param name: name of the site defined on NAO Cloud
 
 */
@optional
- (void) didExitSite:(NSString *)name;


@end

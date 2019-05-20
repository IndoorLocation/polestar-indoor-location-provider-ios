//
//  NAOGeofencingHandleDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 22/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NaoAlert.h"
#import "DBNAOERRORCODE.h"

/** NAOGeofencingHandleDelegate is a protocol that is implemented by one of your objects to received the geofences events from the NAOGeofencingHandle.
 
 */
@protocol NAOGeofencingHandleDelegate <NSObject>


/** This method notifies of an error
 
 @param errCode: Indicates an error code among DBNAOERRORCODE.
 @param message: Message providing additionnal information on the error.
 */
- (void) didFailWithErrorCode:(DBNAOERRORCODE)errCode andMessage:(NSString*)message;

/** This method notifies of a new NAO Alert

 An alert is event which is sent to the application based on the exit or the entrance of a geofence. You can configure the alerts in the NAO Cloud page dedicated to geonotifications.
 Alerts are an easy way to contextualize the digital content of your application. If no alert is configured on a given geofence, nothing will be send to the application, it is as if the geofence were inactive.
 
 @param alert: Object containing configuration information provided on NAO Cloud.
 */
- (void) didFireNAOAlert:(NaoAlert*) alert;

@end

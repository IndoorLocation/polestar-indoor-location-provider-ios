//
//  NAOGeofenceHandleDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 22/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NAOGeofencingHandleDelegate.h"

/** NAOGeofenceHandleDelegate.
 
 */
@protocol NAOGeofenceHandleDelegate <NAOGeofencingHandleDelegate>


/** Receives notification when entering a geofence.
 
 @param regionId: id of the region affected by the change
 @param regionName: name of the region affected by the change
 @since 4.1.2
 */
- (void) didEnterGeofence:(int)regionId andName:(NSString*)regionName;

/** Receives notification when leaving a geofence.
 
 @param regionId: id of the region affected by the change
 @param regionName: name of the region affected by the change
 @since 4.1.2
 */
- (void) didExitGeofence:(int)regionId andName:(NSString*)regionName;

@end

//
//  NAOBeaconProximityHandleDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 23/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DBTBEACONSTATE.h"
#import "DBNAOERRORCODE.h"


/** Beacon Proximity Error Codes
 
 */
typedef enum {
    NAOBEACON_KEY,
    NAOBEACON_INTERNET_CONNECTION
} NAOBEACON_MANAGER_ERROR ;


/** NAOBeaconProximityHandleDelegate receives event from NAOBeaconProximityHandle
 
 */
@protocol NAOBeaconProximityHandleDelegate <NSObject>

/** Beacon Proximity Error
 
 Notifies of an error.
 
 @param errCode: Indicates an error code among DBNAOERRORCODE.
 @param message: Message containning additionnal information
 */
- (void) didFailWithErrorCode:(DBNAOERRORCODE)errCode andMessage:(NSString*)message;

/** Beacon Ranging
 
 This method indicates that a new beacon is visible and is ranged. You can access the ranging parameters through the beacon object.
 
 @param beaconPublicID: Public ID of the beacon, it is the label of indicated on the beacon
 @param rssi: Received Signal Strength Indicator of the beacon
 */
- (void) didRangeBeacon:(NSString*)beaconPublicID withRssi:(int)rssi;

/** Proximity Change
 
 Indicates that the proximity from the beacon has changed (Near or Far).

 @param proximity: Indicates the proximity of the beacon (Near or Far)
 @param beaconPublicID: Public ID of the beacon, it is the label of indicated on the beacon
 */
- (void) didProximityChange:(DBTBEACONSTATE)proximity forBeacon:(NSString*)beaconPublicID;


@end

//
//  NAOBeaconReportingHandleDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 15/02/2016.
//  Copyright © 2016 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DBNAOERRORCODE.h"

/** NAOBeaconReportingHandleDelegate receives NAOBeaconReportingHandle event
 
 */
@protocol NAOBeaconReportingHandleDelegate <NSObject>

/** NAO BeaconReporting Error
 
 @param errCode: Indicates an error code among DBNAOERRORCODE.
 @param message: The message contains additionnal information.
 */
- (void) didFailWithErrorCode:(DBNAOERRORCODE)errCode andMessage:(NSString*)message;


@end

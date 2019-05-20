//
//  NAOAnalyticsHandleDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 23/11/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DBNAOERRORCODE.h"

/** NAOAnalyticsHandleDelegate receives NAOAnalyticsHandle event
 
 */
@protocol NAOAnalyticsHandleDelegate <NSObject>

/** NAO Analytics Error
 
 @param errCode: Indicates an error code among DBNAOERRORCODE.
 @param message: The message contains additionnal information.
 */
- (void) didFailWithErrorCode:(DBNAOERRORCODE)errCode andMessage:(NSString*)message;


@end

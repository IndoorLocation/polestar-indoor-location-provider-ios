//
//  NAOSynchronizableDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 18/12/2015.
//  Copyright © 2015 POLE STAR SA. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DBNAOERRORCODE.h"

/** Synchronisation Delegate
 
 The syncDelegate will be notified of the result of the synchronisation by the following methods.
 */
@protocol NAOSyncDelegate <NSObject>

/** Synchronisation Success
 
 */
- (void)  didSynchronizationSuccess;

/** Synchronisation Failure
 
 @param errorCode : Error code 
 @param message: Message detailling why the synchronisation has failed.
 */
- (void)  didSynchronizationFailure:(DBNAOERRORCODE)errorCode msg:(NSString*) message;

@end

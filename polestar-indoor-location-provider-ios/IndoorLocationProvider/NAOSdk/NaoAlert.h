//
//  NAOAlert.h
//  NAOMicroService
//
//  Created by J.CHOUKI on 06/03/2014.
//  Copyright (c) 2014 Pole Star. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DBNAOAlertRule.h"

@class DBNaoAlert;


/** NaoAlert
 Object returned on trigger by GeofencingHandleDelegate
 */
@interface NaoAlert : NSObject

/** Alert unique identifier */
@property (readonly) int identifier;

/** Alert name : name of the alert set in nao-cloud */
@property (readonly) NSString *name;

/** Alert content : Additional data (optional text value from nao-cloud) */
@property (readonly) NSString *content;

/** Alert rules : All rules fulfilled to trigger the alert */
@property (readonly) NSArray<DBNAOAlertRule *> *rules;


- (id)initWithDBNaoAlert:(DBNaoAlert *)dbNaoAlert;

@end
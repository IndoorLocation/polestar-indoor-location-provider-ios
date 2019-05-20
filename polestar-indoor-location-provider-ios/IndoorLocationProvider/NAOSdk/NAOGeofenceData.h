//
//  NAOGeofenceData.h
//  NaoSDK
//
//  Created by Pole Star on 08/12/2016.
//  Copyright © 2016 POLE STAR SA. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DBNAOGeofenceData;

/** Region data 
 @since 4.2.2*/
@interface NAOGeofenceData : NSObject

/** regionId linked to the data */
@property (readonly) int32_t regionId;

/** siteId linked to the data */
@property (readonly) int32_t siteId;

/** name entered by client from NAO Cloud */
@property (readonly) NSString * name;

/** category entered by client from NAO Cloud */
@property (readonly) NSString * category;

-(instancetype)initWithDBNAOGeofenceData:(DBNAOGeofenceData *)dbNAOGeofenceData;

@end

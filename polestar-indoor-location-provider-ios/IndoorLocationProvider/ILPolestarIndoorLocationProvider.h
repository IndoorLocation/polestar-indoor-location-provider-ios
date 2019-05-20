#import <IndoorLocation/IndoorLocation.h>
#import "NAOLocationHandle.h"
#import "NAOLocationHandleDelegate.h"
#import "NAOSyncDelegate.h"
#import "NAOSensorsDelegate.h"
#import "DBNAOERRORCODE.h"
#import "DBTNAOFIXSTATUS.h"

@interface ILPolestarIndoorLocationProvider : ILIndoorLocationProvider <NAOSyncDelegate, NAOLocationHandleDelegate, NAOSensorsDelegate>

@property (nonatomic, strong) NAOLocationHandle * locationHandle;
@property (nonatomic, strong) NSDictionary<NSNumber*,NSNumber*>* floorByAltitude;

- (instancetype)initWithPolestarKey:(NSString*) apiKey;

@end

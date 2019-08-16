#import "ILPolestarIndoorLocationProvider.h"

@implementation ILPolestarIndoorLocationProvider {
    BOOL shouldStart;
    BOOL isStarted;
    BOOL isDataSync;
}

- (instancetype)initWithPolestarKey:(NSString*) apiKey
{
    self = [super init];
    if (self) {
        shouldStart = NO;
        isStarted = NO;
        isDataSync = NO;
        _locationHandle = [[NAOLocationHandle alloc] initWithKey:apiKey
                                                        delegate:self
                                                 sensorsDelegate:self];
        [_locationHandle synchronizeData:self];
    }
    return self;
}

- (BOOL) supportsFloor {
    return true;
}

- (void) start {
    if (isStarted) {
        return;
    }
    if (isDataSync) {
        [_locationHandle start];
        isStarted = YES;
        shouldStart = NO;
    }
    else {
        shouldStart = YES;
    }
}

- (void) stop {
    [_locationHandle stop];
}

- (BOOL) isStarted {
    return isStarted;
}

- (void)didSynchronizationFailure:(DBNAOERRORCODE)errorCode msg:(NSString *)message {
    NSLog(@"NAOSyncError %@", message);
}

- (void)didSynchronizationSuccess {
    isDataSync = YES;
    if (shouldStart) {
        [self start];
    }
}

- (void)didFailWithErrorCode:(DBNAOERRORCODE)errCode andMessage:(NSString *)message {
    [self dispatchDidFailWithError:[NSError errorWithDomain:@"ILPolestarIndoorLocationProvider" code:errCode userInfo:nil]];
}

- (void)didLocationChange:(CLLocation *)location {
    ILIndoorLocation* indoorLocation = [[ILIndoorLocation alloc] initWithProvider:self latitude:location.coordinate.latitude longitude:location.coordinate.longitude floor:[NSNumber numberWithDouble:location.altitude/5]];
    indoorLocation.accuracy = location.horizontalAccuracy;
    if (_floorByAltitude) {
        NSNumber* floor = _floorByAltitude[[NSNumber numberWithDouble:location.altitude]];
        if (floor) {
            indoorLocation.floor = floor;
        }
        else {
            [self dispatchDidFailWithError:[NSError errorWithDomain:@"ILPolestarIndoorLocationProvider : No floor found" code:0 userInfo:nil]];
        }
    }
    [self dispatchDidUpdateLocation:indoorLocation];
}

- (void)didLocationStatusChanged:(DBTNAOFIXSTATUS)status {
    
}

- (void)requiresBLEOn {
    
}

- (void)requiresCompassCalibration {
    
}

- (void)requiresLocationOn {
    
}

- (void)requiresWifiOn {
    
}

@end

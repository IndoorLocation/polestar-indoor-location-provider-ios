//
//  NAOSensorsDelegate.h
//  NaoSDK
//
//  Created by Pole Star on 21/01/2016.
//  Copyright © 2016 POLE STAR SA. All rights reserved.
#import <UIKit/UIKit.h>

/** Each service handle must set a NAOSensorsDelegate which has the following methods to request sensor activation.
 
 */
@protocol NAOSensorsDelegate <NSObject>

/** Wifi Activation Request

 Notifies that the Wifi is off and required by the service. You should usually display a pop-up to the user asking to switch on its Wifi.
 */
- (void) requiresWifiOn;

/** BLE Activation Request

 Notifies that the BLE (Bluetooth 4.0) is off and required by the service. You should usually display a pop-up to the user asking to switch on its BLE.
 */
- (void) requiresBLEOn;

/** Location Activation Request
 
 Notifies that the Location services are off and required by the service. You should usually display a pop-up to the user asking to switch on its Location services.
 */
- (void) requiresLocationOn;

/** Compass Calibration Request
 
 Notifies that the compass need to be calibrated.
 */
- (void) requiresCompassCalibration;


/** Compass Calibrated (Optional)
 
 Notifies that the compass is now calibrated
 */
@optional
- (void) didCompassCalibrated;

@end

#import <UIKit/UIKit.h>
#import <Mapbox/Mapbox.h>
#import <MapwizeForMapbox/MapwizeForMapbox.h>
#import "ILPolestarIndoorLocationProvider.h"

@interface ViewController : UIViewController  <MWZMapwizePluginDelegate>

@property (weak, nonatomic) IBOutlet MGLMapView *mglMapView;
@property (nonatomic, strong) MapwizePlugin* mapwizePlugin;

@end


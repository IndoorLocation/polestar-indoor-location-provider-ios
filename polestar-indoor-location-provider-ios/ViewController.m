#import "ViewController.h"
#import <MapwizeUI/MapwizeUI.h>

@interface ViewController () <MWZMapwizeViewDelegate>

@property (nonatomic, retain) MWZMapwizeView* mapwizeView;

@end

@implementation ViewController {
    ILPolestarIndoorLocationProvider* provider;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initMapwize];
}

- (void) initMapwize {
    MWZUIOptions* opts = [[MWZUIOptions alloc] init];
    MWZMapwizeViewUISettings* settings = [[MWZMapwizeViewUISettings alloc] init];
    
    self.mapwizeView = [[MWZMapwizeView alloc] initWithFrame:self.view.frame
                                              mapwizeOptions:opts
                                                  uiSettings:settings];
    self.mapwizeView.delegate = self;
    self.mapwizeView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.mapwizeView];
    [[NSLayoutConstraint constraintWithItem:self.mapwizeView
                                  attribute:NSLayoutAttributeLeft
                                  relatedBy:NSLayoutRelationEqual
                                     toItem:self.view
                                  attribute:NSLayoutAttributeLeft
                                 multiplier:1.0f
                                   constant:0.0f] setActive:YES];
    [[NSLayoutConstraint constraintWithItem:self.mapwizeView
                                  attribute:NSLayoutAttributeTop
                                  relatedBy:NSLayoutRelationEqual
                                     toItem:self.view
                                  attribute:NSLayoutAttributeTop
                                 multiplier:1.0f
                                   constant:0.0f] setActive:YES];
    [[NSLayoutConstraint constraintWithItem:self.mapwizeView
                                  attribute:NSLayoutAttributeBottom
                                  relatedBy:NSLayoutRelationEqual
                                     toItem:self.view
                                  attribute:NSLayoutAttributeBottom
                                 multiplier:1.0f
                                   constant:0.0f] setActive:YES];
    [[NSLayoutConstraint constraintWithItem:self.mapwizeView
                                  attribute:NSLayoutAttributeRight
                                  relatedBy:NSLayoutRelationEqual
                                     toItem:self.view
                                  attribute:NSLayoutAttributeRight
                                 multiplier:1.0f
                                   constant:0.0f] setActive:YES];
}

- (void)mapwizeView:(MWZMapwizeView *)mapwizeView didTapOnPlaceInformationButton:(MWZPlace *)place {
    
}

- (void)mapwizeView:(MWZMapwizeView *)mapwizeView didTapOnPlaceListInformationButton:(MWZPlaceList *)placeList {
    
}

- (void)mapwizeViewDidTapOnFollowWithoutLocation:(MWZMapwizeView *)mapwizeView {
    
}

- (void)mapwizeViewDidTapOnMenu:(MWZMapwizeView *)mapwizeView {
    
}

- (void) mapwizeViewDidLoad:(MWZMapwizeView*) mapwizeView {
    provider = [[ILPolestarIndoorLocationProvider alloc] initWithPolestarKey:@"emulator"];
    [provider start];
    [mapwizeView.mapwizePlugin setIndoorLocationProvider:provider];
}

- (BOOL) mapwizeView:(MWZMapwizeView *)mapwizeView shouldShowInformationButtonFor:(id<MWZObject>)mapwizeObject {
    if ([mapwizeObject isKindOfClass:MWZPlace.class]) {
        return YES;
    }
    return NO;
}

@end

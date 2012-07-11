
#import "BullsEyeAppDelegate.h"
#import "BullsEyeViewController.h"

@implementation BullsEyeAppDelegate

@synthesize window = _window;
@synthesize viewController = _viewController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
	self.viewController = [[BullsEyeViewController alloc] initWithNibName:@"BullsEyeViewController" bundle:nil]; 
	self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    return YES;
}

@end


#import <UIKit/UIKit.h>

@class BullsEyeViewController;

// This is the "application delegate". Every app has one. It is notified of
// events that concern the entire application, such as: the application has
// been loaded and is ready for use, or: the user pressed the Home button and
// the app will now be suspended in the background.
//
// For the Bull's Eye game we don't need to do anything here. When we created
// the project, Xcode made a default application delegate for us. It loads our
// main screen, BullsEyeViewController, and makes it visible.
//
@interface BullsEyeAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) BullsEyeViewController *viewController;

@end

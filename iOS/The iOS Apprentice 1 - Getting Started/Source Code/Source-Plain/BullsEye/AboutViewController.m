
#import "AboutViewController.h"

@implementation AboutViewController

// This is the same as in BullsEyeViewController. It forces the screen into
// the landscape orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return UIInterfaceOrientationIsLandscape(interfaceOrientation);
}

// This action is called when the user taps the Close button. In response, we
// dismiss the About screen and automatically return to the main game screen
// (BullsEyeViewController).
- (IBAction)close
{
	[self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
}

@end

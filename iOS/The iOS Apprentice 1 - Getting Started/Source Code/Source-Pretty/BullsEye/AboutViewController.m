
#import "AboutViewController.h"

@implementation AboutViewController

@synthesize webView;

- (void)viewDidLoad
{
	[super viewDidLoad];

	// Load the BullsEye.html file into the web view.
	NSString *htmlFile = [[NSBundle mainBundle] pathForResource:@"BullsEye" ofType:@"html"];
	NSData *htmlData = [NSData dataWithContentsOfFile:htmlFile];
	NSURL *baseURL = [NSURL fileURLWithPath:[[NSBundle mainBundle] bundlePath]];
	[self.webView loadData:htmlData MIMEType:@"text/html" textEncodingName:@"UTF-8" baseURL:baseURL];
}

- (void)viewDidUnload
{
	[super viewDidUnload];
	self.webView = nil;
}

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

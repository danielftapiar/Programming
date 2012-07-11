
#import <QuartzCore/QuartzCore.h>
#import "BullsEyeViewController.h"
#import "AboutViewController.h"

@implementation BullsEyeViewController {

	// This is the current value of the slider. Whenever the player drags the
	// slider, we update this variable with the new value.
	int currentValue;

	// At the start of each round, we calculate a random target value and store
	// it in this variable. This is the value that the player has to try to set
	// on the slider.
	int targetValue;

	// This variable keeps track of the player's score.
	int score;

	// This variable stores how many rounds the player has played so far.
	int round;
}

// When we declare a @property, we also have to synthesize it.
@synthesize slider;
@synthesize targetLabel;
@synthesize scoreLabel;
@synthesize roundLabel;

// This method puts the target value, the player's total score and the current
// round number in the labels. I put this into a method of its own, so we don't
// have to duplicate this code all the time.
- (void)updateLabels
{
	self.targetLabel.text = [NSString stringWithFormat:@"%d", targetValue];
	self.scoreLabel.text = [NSString stringWithFormat:@"%d", score];
	self.roundLabel.text = [NSString stringWithFormat:@"%d", round];
}

// This method starts a new round.
- (void)startNewRound
{
	// Increment the round number.
	round += 1;

	// Calculate the new target value. We use the arc4random() function to get
	// a random number. This can be a very large number, so we use the modulo
	// operator (%) to restrict it to be a number between 0 and 99. Because we
	// want the target to be between 1 and 100, we have to add 1 to this number
	// to get it in our desired range.
	targetValue = 1 + (arc4random() % 100);

	// Reset the slider to its center position.
	currentValue = 50;
	self.slider.value = currentValue;
}

// This method starts a new game. It resets the score and the round number to
// 0, and then calls the startNewRound method to begin the first round.
- (void)startNewGame
{
	score = 0;
	round = 0;
	[self startNewRound];
}

// This method is called while the app is starting up. At some point the main 
// view controller will be created (that is us). The view controller will load
// its view from the nib file and connect the properties to the view's user
// interface elements. When that is done, it sends the viewDidLoad message to
// give us a chance to do some initialization of our own before the app starts
// in earnest. We use this opportunity to set up the game and the labels.
- (void)viewDidLoad
{
	[super viewDidLoad];
	
	UIImage *thumbImageNormal = [UIImage imageNamed:@"SliderThumb-Normal"];
	[self.slider setThumbImage:thumbImageNormal forState:UIControlStateNormal];

	UIImage *thumbImageHighlighted = [UIImage imageNamed:@"SliderThumb-Highlighted"];
	[self.slider setThumbImage:thumbImageHighlighted forState:UIControlStateHighlighted];

	UIImage *trackLeftImage = [[UIImage imageNamed:@"SliderTrackLeft"] stretchableImageWithLeftCapWidth:14 topCapHeight:0];
	[self.slider setMinimumTrackImage:trackLeftImage forState:UIControlStateNormal];

	UIImage *trackRightImage = [[UIImage imageNamed:@"SliderTrackRight"] stretchableImageWithLeftCapWidth:14 topCapHeight:0];
	[self.slider setMaximumTrackImage:trackRightImage forState:UIControlStateNormal];

	[self startNewGame];
	[self updateLabels];
}

// The viewDidUnload method is called when the iPhone is low on free memory.
// In our simple game this is unlikely to happen, but a good app should handle
// this situation anyway. We simply set all our outlet properties to nil, so we
// no longer keep references to these user interface elements.
- (void)viewDidUnload
{
	[super viewDidUnload];
	self.slider = nil;
	self.targetLabel = nil;
	self.scoreLabel = nil;
	self.roundLabel = nil;
}

// This tells the iPhone whether the app can be used in portrait orientation or
// in landscape orientation, or both. It is called when the app starts up and 
// when users rotate their iPhone. Our game only allows landscape orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return UIInterfaceOrientationIsLandscape(interfaceOrientation);
}

// This method is called when the player taps the "Hit Me!" button. It will
// show the results for this round in an alert view popup.
- (IBAction)showAlert
{
	// Calculate how far off the slider's value is from the target value.
	// We use the abs() function to always make this a positive number.
	int difference = abs(targetValue - currentValue);

	// Calculate how many points the player has scored. The player gets more
	// points the closer he is to the target. The maximum score is 100 points.
	int points = 100 - difference;

	// It's fun to change the title of the alert popup depending on how well
	// the player did. In addition, we give the player 100 bonus points if he
	// has a perfect score and 50 bonus points if he was very close.
	NSString *title;
	if (difference == 0) {
		title = @"Perfect!";
		points += 100;
	} else if (difference < 5) {
		if (difference == 1) {
			points += 50;
		}
		title = @"You almost had it!";
	} else if (difference < 10) {
		title = @"Pretty good!";
	} else {
		title = @"Not even close...";
	}

	// Add the points for this round to the total score.
	score += points;

	// The message part of the alert view shows the number of points the player
	// has scored in this round. We use NSString's stringWithFormat method to
	// create this text string. The format specifier %d will be replaced by the
	// value of the points variable.
	NSString *message = [NSString stringWithFormat:@"You scored %d points", points];

	// Now that we have the title and the message, we can create the actual
	// UIAlertView object and show it to the user. We set its delegate parameter
	// to "self", which means that our alertView:didDismissWithButtonIndex:
	// method will be called after the user pressed the OK button to close the
	// alert (see at the bottom of this source file).
	UIAlertView *alertView = [[UIAlertView alloc]
		initWithTitle:title
		message:message
		delegate:self
		cancelButtonTitle:@"OK"
		otherButtonTitles:nil];

	// This will show the alert view on the screen.
	[alertView show];
}

// This method is called when the player moves the slider.
- (IBAction)sliderMoved:(UISlider *)sender
{
	// The position of the slider is a value between 1 and 100, and may contain
	// digits after the decimal point. We round the value to a whole number and
	// store it in the currentValue variable.
	currentValue = lroundf(sender.value);

	// If you want to see the current value as you're moving the slider, then
	// uncomment the NSLog() line below (remove the //) and keep an eye on the
	// output console when you run the app.

	//NSLog(@"currentValue %d", currentValue);
}

// This method is called when the player taps the "Start Over" button.
- (IBAction)startOver
{
	// Create a Core Animation transition. This will crossfade from what is
	// currently on the screen to the changes we're making below.
	CATransition *transition = [CATransition animation];
	transition.type = kCATransitionFade;
	transition.duration = 1;
	transition.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];

	// This is pretty simple. We do the same thing we did in viewDidLoad,
	// start a new game (which also starts the first round) and update the
	// labels to show these changes on the screen.
	[self startNewGame];
	[self updateLabels];

	// This starts the animation.
	[self.view.layer addAnimation:transition forKey:nil];
}

// This method is called when the player taps the info button. We will show a
// new screen that explains the game play rules.
- (IBAction)showInfo
{
	// First, we create the new screen's view controller (AboutViewController
	// in our case). This will load the nib for that screen.
	AboutViewController *controller = [[AboutViewController alloc] initWithNibName:@"AboutViewController" bundle:nil];

	// If you change modalTransitionStyle, the animation is different.
	controller.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;

	// To actually show the new screen, you must "present" it. Now the new
	// view controller takes over. BullsEyeViewController will not receive any
	// events until the About screen is closed.
	[self presentViewController:controller animated:YES completion:nil];
}

// This method is called when the player taps the OK button in the alert view.
- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
	// Start a new round and show it on the screen.
	[self startNewRound];
	[self updateLabels];
}

@end

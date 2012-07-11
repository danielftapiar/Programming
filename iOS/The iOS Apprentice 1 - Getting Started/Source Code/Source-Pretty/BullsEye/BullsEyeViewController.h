
#import <UIKit/UIKit.h>

// This is the main screen for our game. It has a view that shows a slider,
// several buttons and labels. It also handles all the game logic.
//
// This controller conforms to the UIAlertViewDelegate protocol, so it can
// be notified when the user taps the OK button in the alert view that we show
// at the end of a round.
//
@interface BullsEyeViewController : UIViewController <UIAlertViewDelegate>

// These outlet properties are connected to the user interface elements (the 
// slider, labels and buttons) that we are interested in. Now we can refer to
// these controls from our code.
@property (nonatomic, strong) IBOutlet UISlider *slider;
@property (nonatomic, strong) IBOutlet UILabel *targetLabel;
@property (nonatomic, strong) IBOutlet UILabel *scoreLabel;
@property (nonatomic, strong) IBOutlet UILabel *roundLabel;

// These action methods let us know when the player is interacting with the
// slider or the buttons.
- (IBAction)showAlert;
- (IBAction)sliderMoved:(UISlider *)sender;
- (IBAction)startOver;
- (IBAction)showInfo;

@end

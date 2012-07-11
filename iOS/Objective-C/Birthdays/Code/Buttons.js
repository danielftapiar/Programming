/*

File: Buttons.js

Abstract: Abstract button creation for Birthdays
	example widget.

Version: 1.1


Disclaimer: IMPORTANT:  This Apple software is supplied to you by 
Apple Inc. ("Apple") in consideration of your agreement to the
following terms, and your use, installation, modification or
redistribution of this Apple software constitutes acceptance of these
terms.  If you do not agree with these terms, please do not use,
install, modify or redistribute this Apple software.

In consideration of your agreement to abide by the following terms, and
subject to these terms, Apple grants you a personal, non-exclusive
license, under Apple's copyrights in this original Apple software (the
"Apple Software"), to use, reproduce, modify and redistribute the Apple
Software, with or without modifications, in source and/or binary forms;
provided that if you redistribute the Apple Software in its entirety and
without modifications, you must retain this notice and the following
text and disclaimers in all such redistributions of the Apple Software. 
Neither the name, trademarks, service marks or logos of Apple Inc. 
may be used to endorse or promote products derived from the Apple
Software without specific prior written permission from Apple.  Except
as expressly stated in this notice, no other rights or licenses, express
or implied, are granted by Apple herein, including but not limited to
any patent rights that may be infringed by your derivative works or by
other works in which the Apple Software may be incorporated.

The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.

IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

Copyright (C) 2006-2007 Apple Inc. All Rights Reserved.

*/

var BUTTON_IMAGE_DIR = "Images/button/";
var LEFT = "left.png";
var LEFT_PRS = "left_press.png";
var MID = BUTTON_IMAGE_DIR + "mid.png";
var MID_PRS = BUTTON_IMAGE_DIR + "mid_press.png";
var RIGHT = "right.png";
var RIGHT_PRS = "right_press.png";

var ROUND_END_WIDTH = 5;
var FLAT_END_WIDTH = 2;
var HEIGHT = 20;

// Build our control buttons using the AppleButton class and bundled image files
function CreateButton(buttonID, text, buttonStyle, onclick) {
	var buttonElement = document.getElementById(buttonID);

	if (!buttonElement.loaded) {
		buttonElement.loaded = true;
		
		var lImgWidth = FLAT_END_WIDTH;
		var rImgWidth = FLAT_END_WIDTH;
		if (buttonStyle == "leftEnd") {
			lImgWidth = ROUND_END_WIDTH;
		} else if (buttonStyle == "rightEnd") {
			rImgWidth = ROUND_END_WIDTH;
		}
		
		var imgPrefix = BUTTON_IMAGE_DIR + buttonStyle + "_";
		buttonElement.object = new AppleButton(buttonElement, text, HEIGHT, imgPrefix + LEFT, imgPrefix + LEFT_PRS, lImgWidth, MID, MID_PRS, imgPrefix + RIGHT, imgPrefix + RIGHT_PRS, rImgWidth, onclick);
		// extra padding so the button does not hug the text
		buttonElement.object.textElement.style.width = (parseInt(document.defaultView.getComputedStyle(buttonElement, null).getPropertyValue("width"), 10) - (lImgWidth + rImgWidth)) + "px";
	}

	return buttonElement.object;
}
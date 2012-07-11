/*

File: Birthdays.js

Abstract: Basic display code and plug-in interfacing for Birthdays
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

var scrollbar, scrollArea;

var DAY_ERR = "No birthdays today.";
var WEEK_ERR = "No more birthdays this week.";
var MONTH_ERR = "No more birthdays this month.";
var PLUGIN_ERR = "Birthdays plug-in could not be found";

function loaded() {
	
	// Create buttons
	CreateButton("today", "Today", "leftEnd", showTodaysBirthdays);
	CreateButton("thisWeek", "Week", "mid", showThisWeeksBirthdays);
	CreateButton("thisMonth", "Month", "rightEnd", showThisMonthsBirthdays);
	
	// Create scroll area
	scrollbar = new AppleVerticalScrollbar(document.getElementById("myScrollBar"));
	scrollArea = new AppleScrollArea(document.getElementById("parentDiv"), scrollbar);
	scrollArea.scrollsHorizontally = false;
	scrollArea.singlepressScrollPixels = 10;
	scrollArea.focus(); // for key control when first loading in Safari
	
	window.onfocus = function () { scrollArea.focus(); }
	window.onblur = function () { scrollArea.blur(); }

	if (window.widget) {
		widget.onshow = onShow;
	} else {
		onShow();
	}
}

var lastDay;

function onShow() {
	// If it's a new day, refresh the content
	if (lastDay) {
		var today = new Date();
		if ((today.getDate() != lastDay.getDate()) ||
			(today.getMonth() != lastDay.getMonth()) ||
			(today.getYear() != lastDay.getYear())) {
			showTodaysBirthdays();
			lastDay = today;
		}
	} else {
		// No existing date; load initial content
		showTodaysBirthdays();
		lastDay = new Date();
	}
}

var oldControl;

// Switches between the content DIVs.
function showContent(newContent) {
	
	document.getElementById("errorDiv").style.display = "none";
	
	clearResults();
	
	if (newContent) {
		parentDiv.appendChild(newContent);
	}
	
	// Resize, reposition the scrollthumb
	scrollArea.reveal(newContent);
	scrollArea.refresh();
}

function clearResults() {
	var parentDiv = document.getElementById("parentDiv");
	if (parentDiv.firstChild) {
		parentDiv.removeChild(parentDiv.firstChild);
	}

}
var lastControl = null;
// Easy hack on AppleButton to add state between the three
function updateControl(newControl) {
	if (lastControl) {
		lastControl.object._setPressed(false);
	}
	newControl.object._setPressed(true);
	lastControl = newControl;
}

/* 
 * Plug-In interface functions
 *
 * The birthdays{Today | ThisWeek | ThisMonth} functions
 * return a 2D array of people in Address Book with upcoming
 * birthdays.  Each entry of the array represents a person and
 * is itself an array of three items:
 *  -- First and Last name [0]
 *  -- Birthday in m/y format [1]
 *  -- Address Book GUID [2]
 */
 
function showTodaysBirthdays() {
	clearResults();
	updateControl(document.getElementById("today"));
	if (window.BirthdaysPlugIn) {
		var bdays = BirthdaysPlugIn.birthdaysToday();
		if (!bdays || bdays.length==0) {
			showError(DAY_ERR);
		} else {
		
			showContent(buildResultsTable(bdays));
		}
	} else {
		showError(PLUGIN_ERR);
	}
	refreshFunction = showTodaysBirthdays;
}

function showThisWeeksBirthdays(event) {
	clearResults();
	updateControl(document.getElementById("thisWeek"));
	if (window.BirthdaysPlugIn) {
		var bdays = BirthdaysPlugIn.birthdaysThisWeek();
		if (!bdays || bdays.length==0) {
			showError(WEEK_ERR);
		} else {
			showContent(buildResultsTable(bdays));
		}
	} else {
		showError(PLUGIN_ERR);
	}
	refreshFunction = showThisWeeksBirthdays;
}

function showThisMonthsBirthdays(event) {
	clearResults();
	updateControl(document.getElementById("thisMonth"));
	if (window.BirthdaysPlugIn) {
		var bdays = BirthdaysPlugIn.birthdaysThisMonth();
		if (!bdays || bdays.length==0) {
			showError(MONTH_ERR);
		} else {
			showContent(buildResultsTable(bdays));
		}
	} else {
		showError(PLUGIN_ERR);
	}
	refreshFunction = showThisMonthsBirthdays;
}

function showError(error) {
	var errorDiv = document.getElementById("errorDiv");
	if (errorDiv.firstChild) {
		errorDiv.removeChild(errorDiv.firstChild);
	}
	errorDiv.appendChild(document.createTextNode(error));
	errorDiv.style.display = "block";
}

function hideError() {
	document.getElementById("errorDiv").style.display = "block";
}

/*
 * buildResultsTable takes arrays returned from the plug-in and 
 * organizes them in a table for display in our widget
 */
function buildResultsTable(resultsArray) {		
	var resultsTable = document.createElement("div");
	resultsTable.setAttribute("class", "mainContent");

	for (var i=0; i<resultsArray.length; i++) {
		var info = resultsArray[i];
		var rowDiv = document.createElement("div");
		rowDiv.setAttribute("class", "resultsRow row" + (i % 2));
		var link = document.createElement("a");
		link.setAttribute("href", "javascript:widget.openURL('addressbook://" + info[3] + "')");
		var firstName = info[0];
		var lastName = info[1];
		if (firstName.length==0 && lastName.length==0) {
			firstName = "[No";
			lastName = "Name]";
		}
		link.appendChild(document.createTextNode(firstName + " " + lastName + " (" + info[2] + ")"));
		rowDiv.appendChild(link);
		resultsTable.appendChild(rowDiv);
	}
	
	return resultsTable;
}
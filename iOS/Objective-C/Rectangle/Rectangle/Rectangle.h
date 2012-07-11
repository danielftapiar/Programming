//
//  Rectangle.h
//  Rectangle
//
//  Created by Daniel Tapia on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GraphicObject.h"

@class XYPoint;

@interface Rectangle : GraphicObject {
@private
    float width;
@protected
    float height;
    XYPoint *origin;
    XYPoint *topLeft;
    XYPoint *topRight;
    XYPoint *bottomRight;
    
    
}

@property float width, height;


//set initial values
-(void) setOrigin: (XYPoint *) pt;

//operations
-(Rectangle *) initWithWidth: (int) w andHeight: (int) h;
-(float) width;
-(float) height;
-(float) area;
-(float) perimeter;
-(void) print;
-(XYPoint *) origin;
-(XYPoint *) topLeft;
-(XYPoint *) topRight;
-(XYPoint *) bottomRight;
-(void) translate: (XYPoint *) vector;
-(Rectangle *) intersect: (Rectangle *) r;
-(void) RectangleCreated;
-(int) countRectangleCreated;



//display
/*
-(void) printOrigin;
-(void) printArea;
-(void) printPerimeter;
*/

-(void) dealloc;
@end
//
//  Rectangle.m
//  Rectangle
//
//  Created by Daniel Tapia on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Rectangle.h"
#import "XYPoint.h"

@implementation Rectangle
@synthesize width, height;

int gNumberOfRectangles;

-(Rectangle *) initWithWidth:(int)w andHeight:(int)h
{
    width = w;
    height = h;
    
    [self RectangleCreated];
    return [Rectangle alloc];
    
}

-(float) area
{
    return width*height;
}

-(float) perimeter
{
    return (2*width+2*height);
}

-(void) print
{
   
    
    NSLog(@"\n The Area of the Rectangle is:       %f \n The Perimeter of the Rectangle is:  %f \n The Height of the Rectangle is:     %f \n The Width of the Rectangle is:      %f \n", [self area], [self perimeter], height, width);
    
    
   
}

-(void) setOrigin:(XYPoint *)pt
{
    if(origin)
        [origin release];
    else if(bottomRight)
        [bottomRight release];
    else if(topRight)
        [topRight release];
    else if(topLeft)
        [topLeft release];
    
    else{
    origin=[[XYPoint alloc] init];
    [origin setX:pt.x andSetY:pt.y];
   
    bottomRight = [[XYPoint alloc] init];
    [bottomRight setX:(pt.x+width) andSetY:pt.y];
    
    topLeft  = [[XYPoint alloc] init];
    [topLeft setX:pt.x andSetY:(pt.y + height)];
    
    topRight  = [[XYPoint alloc] init];
    [topRight setX:(pt.x + width) andSetY:(pt.y + height)];
    }


    
}
-(XYPoint *) origin
{
    return origin;
}
-(XYPoint *) topLeft
{
    return topLeft;
}
-(XYPoint *) topRight
{
    return topRight;
}
-(XYPoint *) bottomRight
{
    return bottomRight;
}

-(void) translate:(XYPoint *)vector
{
    [self setOrigin:vector];
}

-(Rectangle *) intersect:(Rectangle *)r
{
    XYPoint *intersectedOrigin = [[XYPoint alloc] init];
    Rectangle  *newRectangle = [[Rectangle alloc] init];
    
    
    
    if ( (r.origin.x > origin.x && r.origin.x < bottomRight.x ) && (r.origin.y > origin.y && r.origin.y < topLeft.y ) ) {
        
        [newRectangle setWidth:(bottomRight.x-r.origin.x)];
        [newRectangle setHeight:(topLeft.y - r.origin.y)];
        [intersectedOrigin setX:r.origin.x andSetY:r.origin.y];
       
    }
    
    
    
    
    return newRectangle;
    
    
}

-(void) RectangleCreated
{
    extern int gNumberOfRectangles;
    gNumberOfRectangles +=1;
    
}
-(int) countRectangleCreated
{
    return gNumberOfRectangles;
}

-(void) dealloc
{
    if (origin==0) {
         [origin release];
    }
   
    [super dealloc];
    
}


@end

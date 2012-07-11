//
//  XYPoint.m
//  Rectangle
//
//  Created by Daniel Tapia on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#import "XYPoint.h"

@implementation XYPoint
@synthesize x,y;

-(float) retrieveX
{
    return x;
}

-(float) retrieveY
{
    return y;
}

-(void) setX:(float)xValue andSetY:(float)yValue
{
    x=xValue;
    y=yValue;
}

-(void) printXY
{
    NSLog(@"( %f, %f )", x,y);
}



@end

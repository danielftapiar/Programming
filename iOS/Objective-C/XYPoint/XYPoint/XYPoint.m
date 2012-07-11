//
//  XYPoint.m
//  XYPoint
//
//  Created by Daniel Tapia on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "XYPoint.h"

@implementation XYPoint

-(void) setX:(int)coordinateX
{
    x=coordinateX;
}

-(void) setY:(int)coordinateY
{
    y=coordinateY;
}

-(void) print
{
    NSLog(@"The Coordinates are set to (%i, %i)", x,y);
}

-(int) retrieveX
{
    return x;
}

-(int) retrieveY
{
    return y;
}

@end

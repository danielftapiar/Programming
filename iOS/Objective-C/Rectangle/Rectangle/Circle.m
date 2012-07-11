//
//  Circle.m
//  Rectangle
//
//  Created by Daniel Tapia on 9/27/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import "Circle.h"


@implementation Circle
@synthesize radius;

-(float) perimeter
{
    return (2*PI*radius);
}

-(float) area
{
    return (PI*radius*radius);
}

@end

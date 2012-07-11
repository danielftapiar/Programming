//
//  main.m
//  Rectangle
//
//  Created by Daniel Tapia on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Rectangle.h"
#import "XYPoint.h"
#import "GraphicObject.h"
#import "Circle.h"
#import "Triangle.h"
#import "Square.h"

int gNumberOfRectangles;


int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    Square *mySquare=[[Square alloc] initWithSide:4 ];
    
    [mySquare print];
    
    
    
    
    [pool drain];
    return 0;
}


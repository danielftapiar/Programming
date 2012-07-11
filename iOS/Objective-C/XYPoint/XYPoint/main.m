//
//  main.m
//  XYPoint
//
//  Created by Daniel Tapia on 9/19/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYPoint.h"



int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    XYPoint *coordinate = [XYPoint new];
    [coordinate setX:4];
    [coordinate setY:10];
    [coordinate print];
    
    NSLog(@"The retrived numbers are %i and %i", [coordinate retrieveX], [coordinate retrieveY]);
    [coordinate release];
    

    [pool drain];
    return 0;
}


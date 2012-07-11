//
//  main.m
//  Complex
//
//  Created by Daniel Tapia on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Complex.h"



int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    Complex *number=[[Complex alloc] init];
    Complex *number2=[[Complex alloc] init], *result;
    
    [number setReal:4 setImaginary:3];
    [number2 setReal:5 setImaginary:6];
    [number print];
    [number2 print];
    result=[number add:number2];
    [result print];
    
    
    
    
    [number release];
    [number2 release];
    [result release];
    
    [pool drain];
    return 0;
}


//
//  main.m
//  Fraction
//
//  Created by Daniel Tapia on 9/19/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fraction.h"
#import "Complex.h"
#import "XYPoint.h"
#import " MathOps.h"
#import "Comparison.h"
#import "NSMutableArray+ArraySort.h"

int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    
    Fraction *a,*b,*c;
    float converstion;
    int var;
    
    a = [[Fraction alloc] init ];
    b = [Fraction new];
    c = [Fraction new];
    
    [a setTo:5 over:4];
    [b setTo:3 over:4];
    [c setTo:7 over:8];
        
    if([a isEqualTo:c]==YES)
    {
        NSLog(@"They are the same");
        [a print];
        [c print];
        
    }
    converstion=[a convertFractionToNumber];
    
    var = [a compare:a];
    
    if(var==0)
    {
        NSLog(@"They are the same");
    }
    if(var==-1)
    {
        NSLog(@"The reciver compares less than the argument");
    }
    if(var==1)
    {
        NSLog(@"The reciver compares greater than the argument");
    }
    
    
    NSLog(@"The converted number is: %f", converstion);
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    
    NSMutableArray *myArray = [NSArray arrayWithObjects:a,b,c, nil];
    Fraction *totalSum = [[Fraction alloc] init];
            
    [totalSum setTo:0 over:1];
    for (Fraction *myFrac in myArray) {
        [myFrac print];
        totalSum = [totalSum add:myFrac];
        
    }

    [myArray sortUsingSelector:@selector(numerator)];
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    
    [a release];
    [b release];
    [c release];
    
    
    
    
    [pool drain];
    return 0;
}


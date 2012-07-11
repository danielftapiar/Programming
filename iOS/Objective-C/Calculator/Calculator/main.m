//
//  main.m
//  Calculator
//
//  Created by Daniel Tapia on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Calculator.h"



int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    Calculator *newCalculator = [[Calculator alloc] init];
       
    [newCalculator setAcumulator:40];
    [newCalculator add:30];
    [newCalculator div:10];
    [newCalculator squared];
    [newCalculator squared];
    
    
    
    
    
    
    [newCalculator release];
    
    
    
    
        
    
    [pool drain];
    return 0;
}


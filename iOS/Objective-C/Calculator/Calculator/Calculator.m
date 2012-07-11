//
//  Calculator.m
//  Calculator
//
//  Created by Daniel Tapia on 9/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Calculator.h"


@implementation Calculator
@synthesize acumulator;



-(void) setAcumulator:(double)value
{
    acumulator=value;
}

-(void) clear
{
    acumulator=0;
}

-(double) acumulator
{
    return acumulator;
}

-(void) print
{
    NSLog(@"The Acumulator is at: %g", acumulator);
}

-(double) add:(double)value
{
    acumulator += value;
    [self print];

    return acumulator;
}

-(double) sub:(double)value
{
    acumulator -= value;
    [self print];
    return acumulator;
}

-(double) mul:(double)value
{
    acumulator *= value;
    [self print];
    return acumulator;
}

-(double) div:(double)value
{
    acumulator /=value;
    [self print];
    return acumulator;
}

-(double) changeSign
{
    acumulator *=-1;
    [self print];
    return acumulator;
}

-(double) reciprocal
{
    acumulator = 1/acumulator;
    [self print];
    return acumulator;
}

-(double) squared
{
    [self mul:acumulator];
    return acumulator;
}


@end

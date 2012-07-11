//
//  Comparison.m
//  Fraction
//
//  Created by Daniel Tapia on 10/8/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import "Comparison.h"


@implementation Fraction (Comparison)

-(BOOL) isEqualTo:(Fraction *)f
{
    [self reduce];
    [f reduce];
    if (numerator==f.numerator && denominator==f.denominator) {
        return YES;
    }
    else
        return NO;
    
}
-(int) compare:(Fraction *)f
{
    if([self convertFractionToNumber] < [f convertFractionToNumber])
    {
        return -1;
    }
    if([self convertFractionToNumber] > [f convertFractionToNumber])
    {
        return 1;
    }
    else
        return 0;
    
}
  
@end

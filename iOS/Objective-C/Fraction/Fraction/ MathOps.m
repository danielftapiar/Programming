//
//   MathOps.m
//  Fraction
//
//  Created by Daniel Tapia on 10/6/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import " MathOps.h"


@implementation Fraction(MathOps)

-(Fraction *) add: (Fraction *) f
{
    Fraction *result=[[Fraction alloc] init];
    int resultNum, resultDen;
    
    resultNum = (numerator * f.denominator) + (denominator * f.numerator);
    resultDen = (denominator*f.denominator);
    
    [result setTo:resultNum over:resultDen];
    [result reduce];
    return result;
    
}

-(Fraction *) sub:(Fraction *)f
{
    Fraction *result=[[Fraction alloc] init];
    int resultNum, resultDen;
    
    resultNum = (numerator * f.denominator) - (denominator * f.numerator);
    resultDen = (denominator*f.denominator);
    
    [result setTo:resultNum over:resultDen];
    [result reduce];
    return result;
}

-(Fraction *) div:(Fraction *)f
{
    Fraction *result = [[Fraction alloc] init];
    [result setTo:numerator * f.denominator over:denominator*f.numerator];
    [result reduce];
    return result;
    
}

-(Fraction *) mult:(Fraction *)f
{
    Fraction *result = [[Fraction alloc] init];
    [result setTo:numerator*f.numerator over:denominator * f.denominator];
    [result reduce];
    return result;
    
}

-(Fraction *) inverse:(Fraction *)f
{
    Fraction *result = [[Fraction alloc] init];
    [result setTo:f.denominator over:f.numerator];
    return result;
    
}
@end

//
//  Fraction.m
//  Fraction
//
//  Created by Daniel Tapia on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Fraction.h"


@implementation Fraction
@synthesize numerator, denominator;

static int gCounter;
static int gAddCounter;


-(BOOL) print
{
    bool flag=true;
    if (denominator==1) {
        NSLog(@"%i", numerator);
    }
    else
        NSLog(@"%i/%i", numerator, denominator);
    
    return flag;
    
}

-(int) getNumerator
{
    return numerator;
}

-(int) getDenominator
{
    return denominator;
}

-(Fraction *) initWith:(int) n: (int) d
{
    self=[super init];
    
    if (self) {
        [self setTo:n over:d];
    }
    
    return self;
}

-(void) setTo:(int)n over:(int)d
{
    numerator=n;
    denominator=d;
}
/*
-(id) add:(id)frac

{
    id  result=[[Fraction alloc]init];
    int resultDenominator, resultNumerator, getNumerator, getDenominator;
    
    getNumerator = [frac getNumerator];
    getDenominator = [frac getDenominator];
    
    resultNumerator=numerator*getDenominator+denominator*getNumerator;
    resultDenominator= denominator*getDenominator;
    
    [result setTo:resultNumerator over:resultDenominator];
    [result reduce];
    
    extern int gAddCounter;
    gAddCounter++;
    
    
    return result;
    
}

-(Fraction *) multiply: (Fraction *) f
{
    Fraction *result=[[Fraction alloc] init];
    [result setTo:(f.numerator*numerator) over:(f.denominator*denominator)];
    [result reduce];
    return result;
    
}
-(Fraction *) subtract: (Fraction *) f
{
    Fraction *result=[[Fraction alloc] init];
    [result setTo:numerator*f.denominator-denominator*f.numerator over:denominator*f.denominator];
    [result reduce];
    return result;
    
}
-(Fraction *) divide: (Fraction *) f
{
    Fraction *result = [[Fraction alloc] init];
    [result setTo:numerator*f.denominator over:denominator*f.numerator];
    [result reduce];
    return result;
    
}
 */
-(void) reduce
{
    int u = numerator;
    int v = denominator;
    int temp;
    
    while (v!= 0) {
        temp = u %v;
        u = v;
        v = temp;
        
    }
    numerator /= u;
    denominator /= u;
}
-(float) convertFractionToNumber
{
    float convertion=((float)numerator / (float)denominator);
    return convertion;
    
}

+(Fraction *) allocF
{
    extern int gCounter;
    gCounter++;
    
    return [Fraction alloc];
    
}

+(int) count
{
   extern int gCounter;
    return gCounter;
    
}

+(int) addCount;
{
    extern int gAddCounter;
    
    return gAddCounter;
    
}
@end

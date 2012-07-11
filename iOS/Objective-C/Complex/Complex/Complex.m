//
//  Complex.m
//  Complex
//
//  Created by Daniel Tapia on 9/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Complex.h"

@implementation Complex
@synthesize real, imaginary;


-(void) setReal: (int) r setImaginary: (int) i
{
    real=r;
    imaginary=i;
    
}

-(int) getReal
{
    return real;
}

-(int) getImaginary
{
    return imaginary;
}

-(void) print   
{
    NSLog(@"%i + %ii", real,imaginary);
}

-(Complex *) add: (Complex *) n
{
    Complex *result = [[Complex alloc] init];
    [result setReal:real+n.real];
    [result setImaginary:imaginary+n.imaginary];
    return result;
    
}

@end


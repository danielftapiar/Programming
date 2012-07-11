//
//  Fraction.h
//  Fraction
//
//  Created by Daniel Tapia on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface Fraction : NSObject 
{
    
    int numerator;
    int denominator;
    
}

@property int numerator, denominator;

-(BOOL) print;
-(int) getNumerator;
-(int) getDenominator;
-(Fraction *) initWith:(int) n: (int) d;
-(void) setTo: (int) n over: (int) d;
/*
-(id) add: (id) f;
-(Fraction *) multiply: (Fraction *) f;
-(Fraction *) subtract: (Fraction *) f;
-(Fraction *) divide: (Fraction *) f;
*/
-(void) reduce;
-(float) convertFractionToNumber;
+(Fraction *) allocF;
+(int) count;
+(int) addCount;




@end


//
//  Calculator.h
//  Calculator
//
//  Created by Daniel Tapia on 9/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface Calculator : NSObject {
    
    double acumulator;
}
@property double acumulator;

//acumulator methods

-(void) setAcumulator: (double) value;
-(void) clear;
-(double) acumulator;
-(void) print;
//calculator methods

-(double) add: (double) value;
-(double) sub: (double) value;
-(double) div: (double) value;
-(double) mul: (double) value;

//advanced methods

-(double)  changeSign;
-(double) reciprocal;
-(double) squared;
@end

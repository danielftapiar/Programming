//
//   MathOps.h
//  Fraction
//
//  Created by Daniel Tapia on 10/6/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fraction.h"

@interface Fraction (MathOps)

-(Fraction *) add: (Fraction *) f;
-(Fraction *) sub: (Fraction *) f;
-(Fraction *) div: (Fraction *) f;
-(Fraction *) mult: (Fraction *) f;
-(Fraction *) inverse: (Fraction *) f;



@end


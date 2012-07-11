//
//  Comparison.h
//  Fraction
//
//  Created by Daniel Tapia on 10/8/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fraction.h"

@interface Fraction (Comparison)
-(BOOL) isEqualTo: (Fraction *) f;
-(int) compare : (Fraction *) f;

@end

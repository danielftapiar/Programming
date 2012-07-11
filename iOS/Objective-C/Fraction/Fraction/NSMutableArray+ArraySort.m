//
//  NSMutableArray+ArraySort.m
//  Fraction
//
//  Created by Matías Quijada on 10/18/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "NSMutableArray+ArraySort.h"

@implementation NSMutableArray (ArraySort)

-(void) sortTheArray
{
    [self sortUsingSelector:@selector(compare:)];
}

@end

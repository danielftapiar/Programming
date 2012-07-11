//
//  Square.m
//  Rectangle
//
//  Created by Daniel Tapia on 10/4/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import "Square.h"


@implementation Square

-(Square *) initWithSide: (int) s;
{
    rect = [[Rectangle alloc] init];
    [self setSide:s];
    
    return [self init];
    
}

-(void) setSide:(int)s
{
    [rect setWidth:s];
    [rect setHeight:s];
    
}
     
-(int) side
{
    return [rect width];
}

-(int) area;
{
    return [rect area];
}

-(int) perimeter
{
    return [ rect perimeter];
}

-(void) print
{
    NSLog(@"The square's side is: %i", [self side]);
}
     
@end

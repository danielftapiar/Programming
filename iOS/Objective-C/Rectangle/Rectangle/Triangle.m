//
//  Triangle.m
//  Rectangle
//
//  Created by Daniel Tapia on 9/27/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import "Triangle.h"


@implementation Triangle

-(void) setBase:(float)b setHeight:(float) h
{
    base=b;
    height=h;
    hypotenuse=sqrtf((height*height+base*base));
}
-(float) perimeter
{
    return (height+base+hypotenuse);
}
-(float) area
{
    return (base*height)/2;
}

-(float) Hypotenuse;
{
    return  hypotenuse;
}

-(void) print
{
    NSLog(@"\nThe Base of the Triangle is: %f \n The Height of the triangle is: %f \n The Hipotenuse of the Triangle is: %f \n The area of the Triangle is: %f \n The Perimeter of the Triangle is: %f", base,height,hypotenuse, [self area], [self perimeter]);
}


@end

//
//  Circle.h
//  Rectangle
//
//  Created by Daniel Tapia on 9/27/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GraphicObject.h"
#import "Math.h"
#define PI 3.141592654

@interface Circle : GraphicObject {

    float radius;
}

@property float radius;

-(float) radius;
-(float) perimeter;
-(float) area;

@end

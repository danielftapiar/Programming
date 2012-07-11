//
//  Triangle.h
//  Rectangle
//
//  Created by Daniel Tapia on 9/27/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GraphicObject.h"

@interface Triangle : GraphicObject {

    float height;
    float base;
    float hypotenuse;
}

-(void) setBase:(float)b setHeight:(float) h;
-(float) perimeter;
-(float) area;
-(float) Hypotenuse;
-(void) print;


@end

//
//  XYPoint.h
//  Rectangle
//
//  Created by Daniel Tapia on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface XYPoint : NSObject {
    
    float x;
    float y;
}

-(void) setX: (float)xValue andSetY:(float)yValue;
-(void) printXY;


@property float x,y;

@end

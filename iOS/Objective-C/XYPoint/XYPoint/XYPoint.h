//
//  XYPoint.h
//  XYPoint
//
//  Created by Daniel Tapia on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface XYPoint : NSObject {
    
    int x;
    int y;
}

-(void) setX: (int) coordinateX;
-(void) setY: (int) coordinateY;
-(void) print;
-(int) retrieveX;
-(int) retrieveY;

@end

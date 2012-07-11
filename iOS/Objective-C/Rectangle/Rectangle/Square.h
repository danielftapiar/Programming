//
//  Square.h
//  Rectangle
//
//  Created by Daniel Tapia on 10/4/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Rectangle.h"

@interface Square : NSObject {
    
    Rectangle *rect;
}
-(Square *) initWithSide: (int) s;
-(void) setSide: (int) s;
-(int) side;
-(int) area;
-(int) perimeter;
-(void) print;



@end

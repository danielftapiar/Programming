//
//  GraphicObject.h
//  Rectangle
//
//  Created by Daniel Tapia on 9/27/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface GraphicObject : NSObject {

    int fillColor; //32-bit Color
    BOOL filled; // Is the Object Filled?
    int lineColor; // 32-bit line color
}

@property int fillColor, lineColor;
@property BOOL filled;


@end

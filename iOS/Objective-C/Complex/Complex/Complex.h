//
//  Complex.h
//  Complex
//
//  Created by Daniel Tapia on 9/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Complex : NSObject {
    
    int real;
    int imaginary;
    
}

@property int real, imaginary;

-(void) setReal: (int)r setImaginary: (int) i;
-(int) getReal;
-(int) getImaginary;
-(void) print;
-(Complex *) add: (Complex *) n;

@end
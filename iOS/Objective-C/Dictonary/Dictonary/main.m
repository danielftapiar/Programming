//
//  main.m
//  Dictonary
//
//  Created by Daniel Tapia on 10/13/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>

int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
  
    NSDictionary *glossary = [NSDictionary dictionaryWithObjectsAndKeys:
                              @"A class defined so other classes can inherit from it", @"abstract class", 
                              @"To implment all the methods defined in a protocol", @"adopot", 
                              @"Storing an object for later use",@"archiving"
                              , nil];
    NSString *key1;
    
    
    for(key1 in glossary)
    {
        NSLog(@"%@ || %@", key1, [glossary objectForKey:key1]);
                             
    }
    
    
    [pool drain];
    return 0;
}


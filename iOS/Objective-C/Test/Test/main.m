//
//  main.m
//  Test
//
//  Created by Daniel Tapia on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MINIMUM(a,b) ( ( (a) < (b) ) ? (a) : (b) )
#define AND &&
#define OR ||
#define MAXIMUM(a,b) ( ( (a) > (b) ) ? (a) : (b) )
#define MAX3(a,b,c)  ( ( (MAXIMUM(a,b) ) > (c) ) ? (MAXIMUM(a,b)) : (c) ) 
#define IS_UPPER_CASE(x)  ( (x) >= 'A' && (x) <='Z' )
#define IS_LOWER_CASE(x)  ( (x) >= 'a' && (x) <= 'z' )
#define IS_ALPHABETIC(x)  ( IS_LOWER_CASE(x) OR IS_UPPER_CASE(x) )
#define IS_DIGIT(x) ( (x) > 1 AND (x) < 9 )
#define IS_SPECIAL(x) ( (IS_DIGIT(x) OR IS_ALPHABETIC(x) ? 0:1) )
#define ABSOLUTE_VALUE(x) (       (x) > (-x) ? (x) : (-x)       )



int main (int argc, const char * argv[])
{
    @autoreleasepool {
        
        NSMutableDictionary *dic = [NSMutableDictionary dictionary];
        
        [dic setObject:@"One" forKey:@"1"];
        [dic setObject:@"Two" forKey:@"2"];
        [dic setObject:@"Three" forKey:@"3"];
        
        NSMutableString *str;
        str = [NSMutableString stringWithString:@"Object"];
        NSLog(@"Retain Count: %lx", [str retainCount]);
        
        [dic setObject:str forKey:@"Object"];
        NSLog(@"Retain Count: %lx", [str retainCount]);
        
        [dic removeObjectForKey:@"Object"];
        NSLog(@"Retain Count: %lx", [str retainCount]);
        
        
        
    }
    
    
    return 0;
    
}



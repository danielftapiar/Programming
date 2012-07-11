//
//  AddressBook.m
//  Address Book
//
//  Created by Daniel Tapia on 10/11/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import "AddressBook.h"

@implementation AddressBook


-(id) initWithName:(NSString *)name
{
    self = [super init];
    if (self) {
        bookName = [[NSString alloc] initWithString:name];
        book = [[NSMutableArray alloc] init];
        
    }
    return self;
    
    
}

-(void) addCard:(AddressCard *)theCard
{
    [book addObject:theCard];
}

-(unsigned long int) entries
{
    return [book count];
}

-(void) list
{
    NSLog(@"========= Contents of: %@ ========= ", bookName);
    
    for (AddressCard *theCard in book) {
        NSLog(@"%-20s %s    %-32s", [theCard.name UTF8String],[theCard.lastName UTF8String],[theCard.email UTF8String]);
        
    }
    NSLog(@"=====================================================");
}

- (void)dealloc
{
    [book release];
    [bookName release];
    [super dealloc];
}

-(NSMutableArray *) lookup:(NSString *)theName
{
    NSRange stringRange;
    NSMutableArray *matchArray=[[NSMutableArray alloc] initWithCapacity:[book count]];
    
    for ( AddressCard *theCard in book) {
        stringRange=[[[theCard name] lowercaseString  ]rangeOfString:[theName lowercaseString]];
        if ( [[theCard name] rangeOfString:theName].location != NSNotFound) {
            
            [matchArray addObject:theCard];
        
        }
        
        if( [[theCard lastName] rangeOfString:theName ].location != NSNotFound)
        {
            [matchArray addObject:theCard];
        }
        
    }
   
    return matchArray;

}

-(void) removeCard:(AddressCard *)theCard
{
    [book removeObjectIdenticalTo:theCard];
    
}

-(void) sort
{
    [book sortUsingSelector:@selector(compareNames:)];
    
}

-(BOOL) removeName:(NSString *)theName
{
    NSMutableArray *matchArray =[self lookup:theName];
    if ([matchArray count] == 1) {
        [self removeCard:[matchArray objectAtIndex:0]];
        return YES;
    }
    else
        return NO;
    
}

@end

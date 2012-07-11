//
//  AddressCard.m
//  Address Book
//
//  Created by Daniel Tapia on 10/11/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import "AddressCard.h"


@implementation AddressCard
@synthesize name, email, lastName;



/*
-(void) setName:(NSString *)theName
{
    [name release];
    name = [[NSString alloc] initWithString:theName];
    
}

-(void) setEmail:(NSString *)theEmail
{
    [email release];
    email=[[NSString alloc] initWithString:theEmail];
}

-(NSString *) name
{
    return name;
}

-(NSString *) email
{
    return email;
}
*/
-(void) print
{
    
    NSLog (@"====================================");
    NSLog (@"|                                   |");
    NSLog (@"|      %s %-21s |", [name UTF8String],[lastName UTF8String]);
 //   NSLog (@"|      %-29s|", [lastName UTF8String] );
    NSLog (@"|      %-29s|", [email UTF8String]);
    NSLog (@"|                                   |");
    NSLog (@"|                                   |");
    NSLog (@"|                                   |");
    NSLog (@"|                                   |");
    NSLog (@"====================================");

    
}                                                                        

-(void) setName:(NSString *)theName andLastName:(NSString *)theLastName andEmail:(NSString *)theEmail
{
    [self setName:theName];
    [self setEmail:theEmail];
    [self setLastName:theLastName];
    
}

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

- (void)dealloc
{
    [name release];
    [email release];
    
    [super dealloc];
}

-(NSComparisonResult) compareNames:(id)element 
{
    return [name compare:[element name]];
}

@end

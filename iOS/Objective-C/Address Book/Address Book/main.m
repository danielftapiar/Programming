//
//  main.m
//  Address Book
//
//  Created by Daniel Tapia on 10/11/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressCard.h"
#import "AddressBook.h"


int main (int argc, const char * argv[])
{

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    
    NSString *aName=@"Daniel";
    NSString *aLastName=@"Tapia";
    NSString *aEmail=@"danielf.tapiar@gmail.com";
    
    NSString *bName=@"Daniela";
    NSString *bLastName=@"Ramirez";
    NSString *bEmail=@"dany_011@hotmail.com";
    
    NSString *cName=@"Mauricio";
    NSString *cLastName=@"Tapia";
    NSString *cEmail=@"xhunter_587@gmail.com";
    
    NSString *dName=@"Tomas";
    NSString *dLastName=@"Tapia";
    NSString *dEmail=@"tomasa.tapiaa@gmail.com";
    
    NSString *eName = @"Matias";
    NSString *eLastName=@"Quijada";
    NSString *eEmail = @"adf@gmail.com";
    
    NSMutableArray *matchLookup;
    
    
    
    AddressCard *card1 = [[AddressCard alloc] init];
    AddressCard *card2 = [[AddressCard alloc] init];
    AddressCard *card3 = [[AddressCard alloc] init];
    AddressCard *card4 = [[AddressCard alloc] init];
    AddressCard *card5 = [[AddressCard alloc] init];
    
    AddressCard *lookupName;
    
    [card1 setName:aName andLastName:aLastName andEmail:aEmail];
    [card2 setName:bName andLastName:bLastName andEmail:bEmail];
    [card3 setName:cName andLastName:cLastName andEmail:cEmail];
    [card4 setName:dName andLastName:dLastName andEmail:dEmail];
    [card5 setName:eName andLastName:eLastName andEmail:eEmail];
    
    
    
    AddressBook *myBook = [[AddressBook alloc] initWithName:@"Daniel's Address Book"];
    
    [myBook addCard:card2];
    [myBook addCard:card1];
    [myBook addCard:card3];
    [myBook addCard:card4];
    [myBook addCard:card5];
    
    [myBook list];
    
    NSLog(@"Look up:Daniel");
    matchLookup = [myBook lookup:@"Daniel"];
    
    if(matchLookup != nil)
    {
        for(lookupName in matchLookup)
        {
            [lookupName print];
        }
    }
    else
        NSLog(@"Not Found");
    
    [matchLookup release];
    
    
    BOOL isItRemoved;
    
    isItRemoved=[myBook removeName:@"Tomas"];
    if (isItRemoved==YES) {
        NSLog(@"The object was removed succesfully");
    }
    else
        NSLog(@"The object was not removed");
    [myBook list];
    
    
    [card1 release];
    [card2 release];
    [card3 release];
    [card4 release];
    
    
    [myBook release];
    
    
    
    [pool drain];
    return 0;
}


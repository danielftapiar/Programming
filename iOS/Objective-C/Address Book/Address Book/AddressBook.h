//
//  AddressBook.h
//  Address Book
//
//  Created by Daniel Tapia on 10/11/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressCard.h"

@interface AddressBook : NSObject {

    NSString *bookName;
    NSMutableArray *book;
}

-(id) initWithName: (NSString *) name;
-(void) addCard: (AddressCard *) theCard;
-(unsigned long int) entries;
-(void) list;
-(void) dealloc;
-(NSMutableArray *) lookup: (NSString *) theName;
-(void) removeCard: (AddressCard *) theCard;
-(void) sort;
-(BOOL) removeName:(NSString *) theName;





@end

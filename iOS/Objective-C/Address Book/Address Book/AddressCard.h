//
//  AddressCard.h
//  Address Book
//
//  Created by Daniel Tapia on 10/11/11.
//  Copyright 2011 Estudiante Universidad Tecninca Federico Santa Maria. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface AddressCard : NSObject {

    NSString *name;
    NSString *lastName;
    NSString *email;
    
    
}
@property (copy, nonatomic) NSString *name, *email, *lastName;

-(void) print;
-(void) setName: (NSString *) theName andLastName: (NSString *) theLastName andEmail: (NSString *) theEmail;
-(NSComparisonResult) compareNames: (id) element;




@end

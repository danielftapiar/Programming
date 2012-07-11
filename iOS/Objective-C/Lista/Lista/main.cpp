//
//  main.cpp
//  Lista
//
//  Created by Daniel Tapia on 8/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

class Lista {
    
private:
    
    struct node
    {
        int value;
        node *next;
    }*db;
    
public:
    
    
    Lista ()
    {
        db=new node;
        db->next=NULL;
    }
    
    void append(int number)
    {
        node *aux=db;
        
        if (aux->next==NULL) 
        {
            aux->next=new node;
            aux=aux->next;
            aux->value=number;
            aux->next=NULL;
        }
        
        else
        {
            while (aux->next!=NULL) 
            {
                aux=aux->next;
            } 
            aux->next=new node;
            aux=aux->next;
            aux->value=number;
            aux->next=NULL;
            
        }
    }
    
    bool search (int number)
    {
        bool exists=false;
        node *aux=db;
        while (aux->next!=NULL)
        {
            if (aux->value==number) {
                exists=true;
                return exists;
            }
            aux=aux->next;
        }
        if (aux->value==number) {
            exists=true;
            return exists;
        }
        return false;
    }
    
    int retrieve (int number)
    {
        node *aux=db;
        while(aux->next!=NULL)
        {
            if(aux->value==number)
            {
                //add a function that deletes the number found from the list
            }
            aux=aux->next;
            
            if (aux->value==number) {   
                //add a function that deletes the number found from the list
            }
        }
        return number;
    }
    
        
    /*
     void del (int number)
     {
     node *aux1, *aux2;
     if (db->value==number) {
     aux1=db;
     aux2=db->next;
     
     
     
     }
     }
     */
    
    int length()
    {
        int cont=0;
        node *aux=db;
        if (db==NULL) {
            return cont;
        }
        else
        {
            while (aux->next!=NULL) {
                cont++;
                aux=aux->next;
            }
        }
        return cont;
    }
    
    void display()
    {
        node *aux=db;
        
        while (aux->next!=NULL) {
            aux=aux->next;
            cout<< aux->value<<",";
        }
        
        cout<<endl;
        
        
        
    }
    
    
    ~Lista()
    {
        node *aux=db;
        while (db->next!=NULL)
        {
            aux=db;
            db=db->next;
            delete aux;
        }
        delete db;
    }
    
    
};



int main (int argc, const char * argv[])
{
    int menu=0,appendNum,searchFor,length, retrievedNumber;
    bool search;
    char YesOrNo;
    Lista object;
    
    
    while (menu!=5) {
        
        cout<<"   Menu"<<endl;
        cout<<"1. Append"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Length"<<endl;
        cout<<"4. Retrive"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>menu;
        
        
        switch (menu) {
                
            case 1:
                cout<<"Append the following number:";
                cin>>appendNum;
                object.append(appendNum);
                cout<<endl;
                object.display();
                cout<<endl;
                break;
                
            case 2:
                
                cout<<"Search for:";
                cin>>searchFor;
                cout<<endl;
                search=object.search(searchFor);
                if (search==false) {
                    cout<<"The number is not on the List"<<endl<<endl;
                    
                    
                }
                else
                {
                    cout<<"The number is on the List"<<endl<<endl;
                    cout<<"Retrieve The Number?"<<endl;
                    cout<<" (Y)Yes or (N)No"<<endl;
                    cin>>YesOrNo;
                    if (YesOrNo=='Y') {
                        retrievedNumber=object.retrieve(searchFor);
                        cout<<retrievedNumber<<endl;
                        
                    }
                    
                }
                object.display(); 
                cout<<endl;
                break;
                
            case 3:
                
                length=object.length();
                cout<<"The length of the List is:"<<length<<endl;
                break;
            
                
                
                
                
                
                
            default:
                break;
        }
        
    }
    
    
    
    
    return 0;
}



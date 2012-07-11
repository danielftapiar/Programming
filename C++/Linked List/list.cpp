#include <iostream>
#include <string>

using namespace std;

class List{
	
private:
	struct node {
		int data;
		node *next;
	};
	node *root;
	
public:	
	List();		//constructor
	~List();	//destructor
	void append(int value);
	void show();
};

List::List(){	//constructor
	root=NULL;
}

List::~List (){	//destructor
	delete root;
}

void List::append(int value){
	
	if (root==NULL)
	{
		root=new node;
		root->data=value;
		root->next=NULL;
	}
	else
	{
		node *tmp, *nodo;
		tmp=root;
		while (tmp->next!=NULL)
		{
			tmp=tmp->next;
		}
		nodo= new node;
		nodo->data=value;
		nodo->next=NULL;
		tmp->next=nodo;
	}
}

void List::show(){
	
	node *tmp;
	for ( tmp = root; tmp != NULL; tmp=tmp->next)
	{
		cout<<tmp->data<<",";
	}
	cout<<endl;
	
}
int main (int argc, char const* argv[])
{
	int number;
	List object;
	string status="Active";
	while(status!="exit")
	{
		cout<<"Ingrese un Numero"<< endl;
		cin>>number;
		object.append(number);
		object.show();
		
	}
	return 0;
}



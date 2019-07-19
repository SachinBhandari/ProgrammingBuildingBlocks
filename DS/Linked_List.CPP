#include<iostream.h>
#include<conio.h>
#include<process.h>

struct list
{
	int info;
	struct list *link;
}; //point the structue 'node'

class supp
{
	struct list *node;
	struct list *start=NULL;
	public:
	void traverse();
	void display();
	void insert();
	void del();
};

void supp::traverse()
{
	int data;
	char ch;
	start=NULL;
	do
	{
		cout<<"\nEnter a no:";
		cin>>data;
		if(start==NULL)
		{
			start=new list;
			node=start;
			node->info=data;
		}
		else
		{
			node->link=new list;
			node=node->link;
			node->info=data;
		}
		cout<<"Do you want to contiue (y/n)";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
		node->link=NULL;
}

void supp::display()
{

	node=start;
	cout<<"\n";
	do
	{
		cout<<node->info<<" ";
	}while((node=node->link)!=NULL);
}

void supp::insert()
{
	int a,ch,b;
	struct list *newnode;
	cout<<"\nEnter the element you want to insert:";
	cin>>a;
	cout<<"\n1.At starting\n2.At End\n3.At middle";
	cout<<"\nEnter the choice:";
	cin>>ch;
	switch(ch)
	{
		case 1: newnode=new list;
			newnode->info=a;
			newnode->link=start;
			start=newnode;
			break;
		case 2: node=start;
			while(node->link!=NULL)
			{
				node=node->link;
			}
			node->link=newnode=new list;
			newnode->info=a;
			newnode->link=NULL;
			break;
		case 3: node=start;
			cout<<"\nEnter the no after which u wnt 2 insert:";
			cin>>b;
			while(node->info!=b)
			{
				node=node->link;
			}
			newnode=new list;
			newnode->link=node->link;
			newnode->info=a;
			node->link=newnode;
			break;
		case 4:	exit(1);
		default:cout<<"\nWrong choice!!";
			exit(1);
	}
}

void supp::del()
{
	int a,flag=0;
	if(start==NULL)
	{
		cout<<"First of all enter something you dump fellow!!";
	}
	else
{
	cout<<"\n Enter a element to delete:";
	cin>>a;
	node=start;
	while(node->link!=NULL)
	{
		if(node->link->info==a)
		{
			node->link=node->link->link;
			flag=1;
			break;
		}
		node=node->link;
	}
	if(flag==0)
	{
		cout<<"\nElement not found!";
	}
}

}

void main()
{
	clrscr();
	int c;
	supp s;

	while(1)
	{
		cout<<"\n1.Travese\n2.Insert\n3.Display\n4.Delete\n5.Exit";
		cout<<"\nEnter the choice:";
		cin>>c;
		switch(c)
		{
			case 1:s.traverse();
				break;
			case 2:s.insert();
				break;
			case 3:s.display();
				break;
			case 4:s.del();
				break;
			default:cout<<"Wrong choice!";
				exit(1);
		}
	}
}
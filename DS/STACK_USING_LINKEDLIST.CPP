# include<conio.h>
# include<iostream.h>
# include<process.h>

struct node
{ 	int info;
	node *next;
}*top,*ptr,*newptr;

void pop();
void push(int);
void display();


const size=5;
void main()
{       clrscr();
	int choice;
	int insert;
	cout<<"\n1.Push\n2.Pop\n3.Quit"<<endl;
	top=NULL;
	do
  {
	cout<<"\nEnter choice:";
	cin>>choice;
	if(choice==1)
     {
	 cout<<"\nEnter the no to push:";
	 cin>>insert;
	push(insert);

     }
	else
	if(choice==2)
     {
	pop();

     }

	else
	if(choice==3)
     {
	exit(0);
     }
     else
     {
	cout<<"\nWrong key pressed";
	continue;
     }
     if(top)
     {	cout<<"\nLinked stack is:\n";
	display();
     }

  }while(1);

}



void pop()
{       node *temp;
	if(top==NULL)
     {  cout<<"\nStack underflow";
	getch();
	exit(0);
     }

	else
     {  temp=top;
	cout<<"\nPopped element:"<<temp->info<<endl;
	top=top->next;
	delete (temp);

     }

}

void push(int insert)
{       newptr=new node;
	if(newptr)
      {	newptr->info=insert;
	newptr->next=top;
	top=newptr;
      }
	else
      {	cout<<"\ncannot create node\n";
	exit(0);
      }
}

void display()
{       node *temp=top;
	while(temp)
     {  cout<<temp->info<<"<-";
	temp=temp->next;
     }
	cout<<"NULL";
}

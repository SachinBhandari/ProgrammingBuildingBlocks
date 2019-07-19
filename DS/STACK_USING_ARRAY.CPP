# include<conio.h>
# include<iostream.h>
# include<process.h>

void display(int stack[],int &top);
void pop(int stack[],int &top);
void push(int stack[],int item,int &top,int size);
const size=5;
void main()
{       clrscr();
	int stack[size],item,choice,top;
	top=-1;
	cout<<"\n1.Push\n2.Pop\n3.Quit"<<endl;
	do
  {
	cout<<"\nEnter choice:";
	cin>>choice;
	if(choice==1)
     {
	 cout<<"\nEnter the no to push:";
	 cin>>item;
	 push(stack,item,top,size);

     }
	else
	if(choice==2)
     {
	pop(stack,top);
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

	if(top>=0)
     {
	cout<<"\nStack after operation\n";
	display(stack,top);
      }
  }while(1);

}


void pop(int stack[],int &top)
{
	if(top==-1)
    {
	cout<<"\nStack underflow";
	getch();
	exit(1);
    }
	else
    {
	cout<<"\nPopped element is:"<<stack[top]<<endl;
	top--;
    }
}

void push(int stack[],int item,int &top,int size)
{ 	if(top==size-1)
    {
	cout<<"\nStack overflow";
	getch();
	exit(1);
    }
	else
    {
	top++;
	stack[top]=item;
    }
}



void display(int stack[],int &top)
{
	cout<<stack[top]<<"<- top"<<endl;
	for(int i=top-1;i>=0;i--)
	cout<<stack[i]<<endl;
}
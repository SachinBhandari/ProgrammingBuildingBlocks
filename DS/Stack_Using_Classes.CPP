#include<iostream.h>
#include<conio.h>
#include<process.h>
	class stack
{
	int a[10];
	int top;
	public:
	void push(int v);
	void pop();
	void display();
	stack()
	{
	 top=-1;
	}
};

	void stack::push(int v)
{
	if(top==9)
	{
		cout<<"\nStack overflow!!";
		exit(1);
	}
	else
	{
		top++;
		a[top]=v;
	}
}

	void stack::pop()
{

	if(top==-1)
	{
		cout<<"\nStack underflow!";
		exit(1);
	}
	else
	{
		cout<<"\nPopped element is:"<<a[top];
		top--;
	}
}

	void stack::display()
{
	cout<<"\nStack is\n";
	for(int i=0;i<=top;i++)
	{
		cout<<a[i]<<" ";
	}
}

	void main()
{
	clrscr();
	int val,ch;
	stack s;
	cout<<"\n\n1.Push\n2.Pop\n3.Display";
	while(1)
	{
		cout<<"\nEnter the choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\nEnter the element to push:";
				cin>>val;
				s.push(val);
				break;
			case 2:	s.pop();
				break;
			case 3:	s.display();
				break;
			default:cout<<"Wrong choice!";
				break;
		}

	}

}

#include<iostream.h>
#include<conio.h>

int top=-1;
char postfix[20];
char infix[20];
char oper[20];

void push(char a)
{
	top++;
	oper[top]=a;
}

char pop()
{
	char s;
	s=oper[top];
	top--;
	return(s);
}
int prec(char a){
   if(a=='+' || a=='-'){
	return 1;
   }
   else
   if(a=='*' || a=='/')
	return 2;
   return 0;
}

void main()
{
	clrscr();
	int i=0,j=0;
	cout<<"Enter the infix expression: ";
	cin>>infix;
	while(infix[i]!='\0')
	{
		cout<<postfix<<endl;
		cout<<oper<<endl;
		if((int)infix[i]>=48 && (int)infix[i]<=57)
		{
			postfix[j]=infix[i];
			j++;
			i++;
		}
		else
		if(infix[i]==')')
		{
			while(oper[top]!='(')
			{
				postfix[j]=pop();
				j++;
			}
			top--;
			i++;
		}
		else
		if(infix[i]=='('){
			push(infix[i]);
			i++;
		}
		else
		{
			if(prec(infix[i])>prec(oper[top]))
			{
				push(infix[i]);
				i++;
			}
			else
			{
				while(prec(infix[i])<prec(oper[top]))
				{
					postfix[j]=pop();
					j++;
				}
				push(infix[i]);
				i++;

			}
		}
	}
	while(top!=-1)
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	cout<<"Postfix exp:"<<postfix;
	getch();
}
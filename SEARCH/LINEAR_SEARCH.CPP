//program to find the integer and its index using linear search meathod


#include<iostream.h>
#include<conio.h>
int linear_search(int A[],int N,int FIND);
void main()
{
	clrscr();
	int a[20],n,index,find;
	cout<<"\nEnter the no of terms:";
	cin>>n;
	cout<<"\nEnter the Elements";
	for(int i=0;i<n;i++)
    {	cout<<"\nA["<<i<<"]:";
	cin>>a[i];
    }
	cout<<"\nEntered elements are";
	for(i=0;i<n;i++)
	cout<<"\nA["<<i<<"]:"<<a[i];
	cout<<"\nEnter the element you want to find:";
	cin>>find;
	index=linear_search(a,n,find);
	if(index==-1)
	cout<<"\n Unsuccessful search";
	else
	cout<<"\nElement is found at index "<<index;
	getch();
}
	int linear_search(int A[],int N,int FIND)
{	for(int i=0;i<N;i++)
	{ if(FIND==A[i])
	return i;
	}
	 return (-1);
}
#include<iostream.h>
#include<conio.h>
void selection(int a[],int n);
void main()
{
	clrscr();
	int a[20],n;
	cout<<"\nEnter the no of terms:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	selection(a,n);
	getch();
}

void selection(int a[],int n)
{
	int min,pos;
	for(int i=0;i<n-1;i++)
	{
		min=a[i];
		pos=i;
		for(int j=i+1;j<n;i++)
		{
		 if(a[j]<min)
		 {
			min=a[j];
			pos=j;
		 }
		}
		a[pos]=a[i];
		a[i]=min;
	}
	cout<<"\nArray after sorting is:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
}


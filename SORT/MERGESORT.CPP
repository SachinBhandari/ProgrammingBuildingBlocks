#include<iostream.h>
#include<conio.h>
#define maxsize 30
void divide(int a[],int p,int q);
void merge_sort(int a[],int p,int q,int r);
void main()
{
	clrscr();
	int a[maxsize],n;
	cout<<"\nEnter the no of elments: ";
	cin>>n;
	cout<<"\nEnter the elements in array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	divide(a,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	getch();
}
void divide(int a[],int p,int q)
{
	int r;
	if(p<q)
	{
		r=((p+q)/2);
		divide(a,p,r);
		divide(a,(r+1),q);
		merge_sort(a,p,q,r);
	}
}

void merge_sort(int a[], int p,int q, int r)
{
	 int n1=r-p;
	 int n2=q-r-1;
	 int L[8],R[8];
	 for(int i=0;i<=n1;i++)
	 {
	  L[i]=a[p+i];
	 }
	 for(int j=0;j<=n2;j++)
	 {
	  R[j]=a[r+j+1];
	 }
	 i=0;
	 j=0;
	 for(int k=p;k<=q;k++)
	 {
	     if(i<=n1 && j<=n2)
	     {

		if(L[i]<R[j])
		{
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
	     }
	     else
	     if(i>n1)
	     {
	       for(j=j;j<=n2;j++)
	       {
			a[k]=R[j];
			k++;
	       }
	     }
	     else{

		for(i=i;i<=n1;i++)
		{
			a[k]=L[i];
			k++;
		}

	     }
	  }
}
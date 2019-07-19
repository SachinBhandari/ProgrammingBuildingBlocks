# include<iostream.h>
# include<conio.h>
void bubble_sort(int A[],int N);
void main()
{	clrscr();
	int a[20],n,flag=0;
	cout<<"\n Enter the no of terms:";
	cin>>n;
	cout<<"\n Enter elements:";
	for(int i=0;i<n;i++)
	{ cin>>a[i];
	}
	cout<<"\nArray is:"<<endl;
	for(i=0;i<n;i++)
   {    cout<<a[i]<<" ";
   }
	for(i=0;i<n-1;i++)
   {    if(a[i]<a[i+1])
	{  flag=0;
	}
	else
	{       flag=1;
		break;
	}
    }
	if(flag==0)
	cout<<"\nArray is already sorted";
	else
	bubble_sort(a,n);
	getch();
}

void bubble_sort(int A[],int N)
{ int temp;
    for(int i=0;i<N;i++)
	{
	  for(int j=0;j<N-1;j++)
	    { if(A[j]>A[j+1])
	       { temp=A[j];
		 A[j]=A[j+1];
		 A[j+1]=temp;
	       }
	     }
	  cout<<"\nAfter iteration"<<i+1<<":";
	  for(int k=0;k<N;k++)
		cout<<A[k]<<" ";
	}
}
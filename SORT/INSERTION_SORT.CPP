]# include<iostream.h>
# include<conio.h>
void insertion_sort(int A[],int N);
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
	insertion_sort(a,n);
	getch();
}

void insertion_sort(int A[],int N)
{   int j,temp,k;
    for(int i=1;i<N;i++)
	{
	  temp=A[i];
	  j=i-1;
	    while(temp<A[j] && j>=0)
	    {
	      A[j+1]=A[j];
	      j--;
	    }
	  A[j+1]=temp;
	  cout<<"\nAfter iteration"<<i<<":";
	  for(k=0;k<N;k++)
		cout<<A[k]<<" ";
	}
}

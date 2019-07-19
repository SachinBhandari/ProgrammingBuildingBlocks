# include<conio.h>
# include<iostream.h>

void bubble_sort(int A[],int N);
int binary_search(int a[],int seach,int n);

void main()
{
	clrscr();
	int a[20],n,search,position;
	cout<<"\nEnter the no of terms:";
	cin>>n;
	cout<<"\nEnter the elements:\n";
	for(int i=0;i<n;i++)
     {
	cin>>a[i];
     }
	bubble_sort(a,n);
	cout<<"\nArray is:";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\nEnter the no to be search:";
	cin>>search;
	position=binary_search(a,search,n);
	if(position==-1)
	cout<<"\nUnsuccessful search !!";
	else
	cout<<a[position]<<" found at position: "<<position+1;
	getch();
}



void bubble_sort(int A[],int N)
{
	int temp;
	for(int i=0;i<N;i++)
  {
	for(int j=0;j<N-1;j++)
    { 	if(A[j]>A[j+1])
      { temp=A[j];
	A[j]=A[j+1];
	A[j+1]=temp;
      }
    }
  }
}


int binary_search(int a[],int search,int n)
{
	int beg,mid,last;
	beg=0;
	last=n-1;
	while(beg<=last)
    {
	mid=(beg+last)/2;
	if(a[mid]==search)
	return mid;
	else
	if(a[mid]>search)
	last=mid-1;
	else
	beg=mid+1;
    }
     return -1;
}


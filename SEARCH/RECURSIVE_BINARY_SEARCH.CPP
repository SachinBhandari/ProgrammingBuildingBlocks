#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

int binary_search(int a[],int s,int e,int search);

void main()
{
	clrscr();
	int a[1000];
	int search;
	int q;
	double save_time;
	clock_t start,end;
	for(int i=0;i<1000;i++)
	{
	 a[i]=i+1;
	}
	cout<<"Enter the no to search: ";
	cin>>search;
	start=clock();
	q=binary_search(a,0,999,search);
	delay(55);
	end=clock();
	save_time=(double)((end-start)/(CLK_TCK));
	if(q==1){
	cout<<"Search successfull !";
	}
	else if(q==0)
	cout<<"Unsuccessfull !";
	cout<<"\nTime Taken: "<<save_time;
	getch();

}

int binary_search(int a[],int s,int e,int search)
{
	int mid;
	mid=(s+e)/2;
	if(a[mid]==search)
	{
		return 1;
	}
	else
	if(s==e)
	{
		return 0;
	}
	else if(search<a[mid]){
		e=mid-1;
		return(binary_search(a,s,e,search));
	}
	else if(search>a[mid]){
		s=mid+1;
		return(binary_search(a,s,e,search));
	}
	return 0;
}
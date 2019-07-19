# include<conio.h>
# include<iostream.h>
# include<process.h>
class subtract
{int a[20][20],b[20][20],d[20][20],r,c,p,q;
 public:
 void enter();
 void calc();
 void display();
 };
 void subtract::enter()
 {cout<<"\nEnter the number of rows and column of matrix A:";
  cin>>r>>c;
  cout<<"\nEnter the number of rows and column of matrix B:";
  cin>>p>>q;
  if(r==p&&c==q)
  {cout<<"\nSubtraction of matix is possible:";
   cout<<"\n Enter the elements of matrix A:";
  for(int i=0;i<r;i++)
  { for(int j=0;j<c;j++)
   {cout<<"\nElements:["<<i<<"]["<<j<<"]:";
    cin>>a[i][j];}
 }
 cout<<"\n Enter the elements of matrix B:";
  for( i=0;i<r;i++)
 { for(int j=0;j<c;j++)
   {cout<<"\nElements:["<<i<<"]["<<j<<"]:";
    cin>>b[i][j];
    }
   }

 cout<<"\nEntered matrix A is:";
 for(i=0;i<r;i++)
 { cout<<"\n";
   for(int j=0;j<c;j++)
   cout<<a[i][j]<<" ";
 }
 cout<<"\nEntered matrix B is:";
 for(i=0;i<r;i++)
 { cout<<"\n";
   for(int j=0;j<c;j++)
   cout<<b[i][j]<<" ";
 }
}
else

{cout<<"\n Subtraction of matrix is not possible";
 getch();
 exit(0); }

 }
void subtract::calc()
{
  for(int i=0;i<r;i++)
 { for(int j=0;j<c;j++)
   d[i][j]=a[i][j]-b[i][j];
   }
}
void subtract::display()
{cout<<"\n Subtraction of the matrices is";
 for(int i=0;i<r;i++)
 { cout<<"\n";
   for(int j=0;j<c;j++)
   cout<<d[i][j]<<" ";
 }
 }
 void main()
{ clrscr();
  subtract sub;
  sub.enter();
  sub.calc();
  sub.display();
  getch();
}
#include<iostream.h>
#include<conio.h>
#include<process.h>
class Add
{int a[20][20], b[20][20], c[20][20];
 int m, n, p, q, i, j;
 public:
 void cal();
 void enter();
 void show();
};
 void Add :: cal()
{
for(i=0;i<m;i++)
{for(j=0;j<n;j++)
c[i][j]=a[i][j]+b[i][j]; }
}
 void Add :: enter()
{cout<<"\nInput row & column for A & B:";
cin>>m>>n>>p>>q;
if((m==p) && (n==q))
cout<<"\Matrix can be added";
else
{cout<<"\nMatrix cannot be added";
getch();
exit(0); }
cout<<"\nInput A:";
for(i=0;i<m;i++)
{for(j=0;j<n;j++)
cin>>a[i][j];    }
cout<<"\nInput B:";
for(i=0;i<p;i++)
{for(j=0;j<q;j++)
cin>>b[i][j]; }
cal();
}
 void Add :: show()
 {cout<<"\nMatrix A:";
 for(i=0;i<m;i++)
{cout<<"\n";
 for(j=0;j<n;j++)
 cout<<" "<<a[i][j];}
 cout<<"\nMatrix B:";
 for(i=0;i<m;i++)
{cout<<"\n";
 for(j=0;j<n;j++)
 cout<<" "<<b[i][j];}
cout<<"\nSum:\n";
for(i=0;i<m;i++)
{cout<<"\n";
for(j=0;j<n;j++)
cout<<" "<<c[i][j]; }
}
void main()
{clrscr();
Add A;
A.enter();
A.show();
getch();
}
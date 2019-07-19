#include<iostream.h>
#include<conio.h>
#include<process.h>
class multiply
{int a[20][20],b[20][20],c[20][20];
 int m, n, p, q, k, i, j;
 public:
 void cal();
 void enter();
 void show();
};
  void multiply :: cal()
{for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
{c[i][j]=0;
for(k=0;k<n;k++)
c[i][j]=c[i][j]+a[i][k]*b[k][j];  }}
}
 void multiply :: enter()
{cout<<"\nInput row & column for A & B:";
cin>>m>>n>>p>>q;
if((n==p))
cout<<"\Matrix can be multiplied";
else
{cout<<"\nMatrix cannot be multiplied";
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
void multiply :: show()
{cout<<"\nMatrix A:";
 for(i=0;i<m;i++)
{cout<<"\n";
 for(j=0;j<n;j++)
 cout<<" "<<a[i][j];}
 cout<<"\nMatrix B:";
 for(i=0;i<p;i++)
{cout<<"\n";
 for(j=0;j<q;j++)
 cout<<" "<<b[i][j];}
cout<<"\nProduct:\n";
for(i=0;i<m;i++)
{cout<<"\n";
for(j=0;j<q;j++)
{c[i][j]=0;
for(k=0;k<n;k++)
c[i][j]=c[i][j]+a[i][k]*b[k][j];
cout<<" "<<c[i][j]; }  }
}
void main()
{clrscr();
multiply m;
m.enter();
m.show();
getch();
}

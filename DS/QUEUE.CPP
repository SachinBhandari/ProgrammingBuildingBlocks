# include<conio.h>
# include<iostream.h>
# include<process.h>
int front=-1,rear=-1;

void display(int queue[],int &front,int &rear);
void DELETE(int queue[],int &front,int &rear);
void INSERT(int queue[],int item,int &front,int &rear);
int const size=5;


void main()
{
	clrscr();
	int queue[size],item,choice;
	cout<<"\n1.Insert\n2.Delete\n3.Quit"<<endl;
	do
  {
	cout<<"\nEnter choice:";
	cin>>choice;
	if(choice==1)
     {
	 cout<<"\nEnter the no to insert:";
	 cin>>item;
	 INSERT(queue,item,front,rear);

     }
	else
	if(choice==2)
     {
	DELETE(queue,front,rear);
     }

	else
	if(choice==3)
     {
	exit(0);
     }
     else
     {
	cout<<"\nWrong key pressed";
	continue;
     }

  }while(1);

}

void INSERT(int queue[],int item,int &front,int &rear)
{
	if(rear==size-1)
     {
	cout<<"\nQueue overflow";
	getch();
	exit(0);
     }
	rear++;
	queue[rear]=item;
	if(rear==0)
	front=0;
	display(queue,front,rear);
}

void DELETE(int queue[],int &front,int &rear)
{
	if(front==-1)
    {
	cout<<"\nQueue undeflow";
	getch();
	exit(0);
    }
	cout<<"\nDelete element is: "<<queue[front];
	front++;
	if(front==rear)
	front=rear=-1;
	display(queue,front,rear);

}

void display(int queue[],int &front,int &rear)
{
	cout<<"\nArray is\n";
	int i=front;
	while(i<=rear)
     {
	cout<<queue[i];
	if(i!=rear)
	cout<<"<-";
	i++;
      }
}
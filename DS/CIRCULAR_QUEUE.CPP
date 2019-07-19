# include<conio.h>
# include<iostream.h>
# include<process.h>
int front=-1,rear=-1;

int const size=5;

void display(int queue[],int &front,int &rear)
{
	if(front!=-1)
  {
	if(front<=rear)
     {
	for(int i=front;i<rear;i++)
	cout<<queue[i]<<"<-";
	cout<<queue[rear];
     }
	else
     {
	for(int i=front;i<size-1;i++)
	cout<<queue[i]<<"<-";
	for(i=0;i<rear;i++)
	cout<<queue[i]<<"<-";
	cout<<queue[rear];

     }

  }
	else
	cout<<"\nQueue is empty";
}


void INSERT(int queue[],int item,int &front,int &rear)
{
	if(rear==size-1)
	rear=0;
	else
	rear++;
	if(front==rear)
    {	cout<<"Queue overflow";
	getch();
	exit(0);
    }
	queue[rear]=item;
	if(front==-1)
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
	cout<<"\nDeleted element is:"<<queue[front]<<endl;

	if(front==rear)
	front=rear=-1;
	else
    {
	if(front==size-1)
	front=0;
	else
	front++;
    }
	display(queue,front,rear);

}



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

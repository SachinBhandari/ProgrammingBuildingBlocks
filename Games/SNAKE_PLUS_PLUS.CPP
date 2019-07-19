#include<graphics.h>

#include<dos.h>
#include<bios.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip.h>

#define UP 18432
#define DOWN 20480
#define LEFT 19200
#define RIGHT 19712
#define ESC 283
int count=0;
int speed=20;
int cellx[40];
int celly[40];
int length=40;
int bg_color=3;
int snake_color=6;
int cordinate_x;
int cordinate_y;
void play_terminate(int force_quit);

class SCORE
{
	public:
	int points;
	SCORE()
	{
		points=0;
	}

}score;
class body
{
	public:
	int x,y;
	body()
	{
		x=220;
		y=220;
	}
}head,tail;

class monitor
{
	public:
	int key_pressed;
}mono;

class FOOD
{
	public:
	int food_size;
	int food_color;
	int special_food_color;
	int x[4],y[4];
	void display(int [],int []);
	void food_position();
	int food_strike();
	void food_disappear();
	FOOD()
{
	food_color=1;
	food_size=3;
	special_food_color=5;
}
}food;
void FOOD::food_disappear()
{
    if(count<5)
    {
	for(int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
	    {
		putpixel(x[i],y[j],bg_color);
	    }
    }
    else{
	for(int i=0;i<4;i++)
	    for(int j=0;j<4;j++)
	    {
		putpixel(x[i],y[j],bg_color);
	    }
    }
    if(count==5)
    count=0;
}
int FOOD::food_strike()
{
    if(count<5)
    {
	for(int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
	    {
		if(x[i]==head.x && y[j]==head.y)
		{
			score.points+=10;
		       /*	outtextxy(getmaxx()/2,20,"Score:");
			outtextxy(getmaxx()/2+20,20,(score.points));*/
			return 1;
		}
	    }
    }
    else{
	for(int i=0;i<4;i++)
	    for(int j=0;j<4;j++)
	    {
		if(x[i]==head.x && y[j]==head.y)
		{
			score.points+=15;
/*			outtextxy(getmaxx()/2,20,"Score:");
			outtextxy(getmaxx()/2+20,20,(score.points));*/

			return 1;
		}
	    }
    }
    return 0;
}

void FOOD::food_position()
{
	count++;
	srand(time(0));
	x[0]=rand()%getmaxx();
	y[0]=rand()%getmaxy();
	if(x[0]<cordinate_x-597)
	x[0]=x[0]+41;
	if(x[0]>cordinate_x-44)
	x[0]=x[0]-45;
	 if(y[0]<cordinate_y-447)
	y[0]=y[0]+31;
	if(y[0]>cordinate_y-33)
	y[0]=y[0]-35;
	if(count<5)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				x[i]=x[0]+i;
				y[j]=y[0]+j;
			}
	}else
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				x[i]=x[0]+i;
				y[j]=y[0]+j;
			}
	}
	display(x,y);
}

void FOOD::display(int x[],int y[])
{
    if(count<5)
    {
	for(int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
			putpixel(x[i],y[j],food_color);
    }else
    {
	for(int i=0;i<4;i++)
	    for(int j=0;j<4;j++)
		putpixel(x[i],y[j],special_food_color);
    }

}
/*
class boundary
{
	public:
	int left_boundary,up_boundary,right_boundary,down_boundary;
	boundary(){
	       //	leftboundary=cordinate_x-600,(cordinate_y-450),cordinate_x-40,cordinate_y-30
	}
} */

//updates the cell within the body
void update()
{
	for(int i=length-1;i>0;i--){
		cellx[i]=cellx[i-1];
		celly[i]=celly[i-1];
	}
	cellx[0]=head.x;
	celly[0]=head.y;
	tail.x=cellx[length-1];
	tail.y=celly[length-1];
}


//code for moving in up direction
void move_up()
{
	while(!kbhit())
	{
		if((getpixel(head.x,head.y)==snake_color) || (head.y==(cordinate_y-449)))
		play_terminate(2);
		if(food.food_strike()==1)
		{
			food.food_disappear();
			food.food_position();
		}
		delay(speed);
		putpixel(head.x,head.y--,snake_color);
		update();
		putpixel(tail.x,tail.y,bg_color);
	}
	mono.key_pressed=_bios_keybrd(_KEYBRD_READ);
}

//code for moving in down direction
void move_down()
{
		while(!kbhit())
	{
		if((getpixel(head.x,head.y)==snake_color) || (head.y==(cordinate_y-32)))
		play_terminate(2);
		if(food.food_strike()==1)
		{
			food.food_disappear();
			food.food_position();
		}
		delay(speed);
		putpixel(head.x,head.y++,snake_color);
		update();
		putpixel(tail.x,tail.y,bg_color);
	}
	mono.key_pressed=_bios_keybrd(_KEYBRD_READ);
}

//code for moving in left direction
void move_left()
{
		while(!kbhit())
	{
		if((getpixel(head.x,head.y)==snake_color) || (head.x==(cordinate_x-598)))
		play_terminate(2);
		if(food.food_strike()==1)
		{
			food.food_disappear();
			food.food_position();
		}
		delay(speed);
		putpixel(head.x--,head.y,snake_color);
		update();
		putpixel(tail.x,tail.y,bg_color);
	}
	mono.key_pressed=_bios_keybrd(_KEYBRD_READ);
}

//code for moving in right direction
void move_right()
{
		while(!kbhit())
	{
		if((getpixel(head.x,head.y)==snake_color) || (head.x==(cordinate_x-42)))
		play_terminate(2);
		if(food.food_strike()==1)
		{
			food.food_disappear();
			food.food_position();
		}
		delay(speed);
		putpixel(head.x++,head.y,snake_color);
		update();
		putpixel(tail.x,tail.y,bg_color);
	}
	mono.key_pressed=_bios_keybrd(_KEYBRD_READ);
}

void play_terminate(int force_quit)
{
	if(force_quit==1)
	{	outtextxy(100,110, "Exiting!!");
	}else
	if(force_quit==2)
	{	outtextxy(100,110, "Out!!");
	}
	getch();
	getch();
	closegraph();
	exit(0);
}

void main()
{
	clrscr();
	int gdriver = DETECT, gmode;
	int i=0;


	mono.key_pressed=RIGHT;


	/* initialize graphics mode */
	initgraph(&gdriver, &gmode, "");

	/*getting the coordinates of the screen*/
	cordinate_x=getmaxx();
	cordinate_y=getmaxy();
	rectangle((cordinate_x-600),(cordinate_y-450),cordinate_x-40,cordinate_y-30);
	rectangle((cordinate_x-599),(cordinate_y-449),cordinate_x-41,cordinate_y-31);

	/*Change the background color*/
	setbkcolor(bg_color);
	food.food_position();
	while(i<length)
	{
		cellx[i]=head.x;
		celly[i]=head.y;
		i++;
	}
	tail.x=cellx[i-1]-length;
	tail.y=celly[i-1];
	while(1){
		if(mono.key_pressed==ESC)
		{
			play_terminate(1);
		}else
		if(mono.key_pressed==LEFT){
		  move_left();
		  if(mono.key_pressed==RIGHT)
		  {
			mono.key_pressed=LEFT;
		  }
		}else
		if(mono.key_pressed==RIGHT){
		  move_right();
		  if(mono.key_pressed==LEFT)
		  {
			mono.key_pressed=RIGHT;
		  }
		}
		else
		if(mono.key_pressed==UP){
		  move_up();
		  if(mono.key_pressed==DOWN)
		  {
			mono.key_pressed=UP;
		  }
		}
		else
		if(mono.key_pressed==DOWN){
		  move_down();
		  if(mono.key_pressed==UP)
		  {
			mono.key_pressed=DOWN;
		  }
		}
		else
		move_right();
	}
}



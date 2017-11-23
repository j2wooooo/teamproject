#include<stdio.h>
#include<stdlib.h>
extern struct map_info
{
	int put;
	int color;
	int dfvalue;
	int atvalue;
};

extern int x;
extern int y;

void gotoxy(int x, int y);

void makedfvaluemap(int player);
int findlargestdfvalue();

extern struct map_info mi[20][20];

void computstone(int player)
{
	int exitflag = 0;

	// defend
	makedfvaluemap(player);
	int pos = findlargestdfvalue();// find put the location

	// atteck
			int a=1;
			int b=1;
			int c=rand()%2;
	if(pos == 100000) // first put
	{


			if(c == 0 && mi[x+a][y+2*b].put != 1)
			{
				y = y+2*b;
				//break;
			}
			else if(c == 0 && mi[x-a][y-2*b].put != 1)
			{
				y = y-2*b;
				//break;
			}
			else if(c == 1 && mi[x+a][y].put != 1)
			{
				x = x+a;
				//break;
			}
			else if(c == 1 && mi[x-a][y].put != 1)
			{
				x = x-a;
				//break;
			}
	}
	else
	{
		x = pos/100;
		y = pos%100;
	}
	printf("\n\n%d%d%d\n",a,b,c);
	printf("%d%d",x,y);

	if (player == 2)
	{
		gotoxy(10,50);printf("computer");printf("○");sleep(1);
		gotoxy(x,y);
		printf("○");
		mi[x][y/2].put = 1;
		mi[x][y/2].color = 1;

	}
	else
	{
		//gotoxy(10,50);printf("computer");printf("●");sleep(1);
		gotoxy(x,y);
		printf("●");
		mi[x][y/2].put = 1;
		mi[x][y/2].color = 2;

	}
	return;
}
#include"Gain.h"
#include<iostream>
#include<windows.h>
using namespace std;
Gain::Gain(char s)
{
	x=2;type=s;
	y=rand()%40+5;
	exist=true;
	direction=true;
	int speed=1;
}

Gain::~Gain()
{

}

void Gain::move()
{
	speed++;
    if(speed%8==0)  x++;
   	if(direction&& speed%8==0)
	{
		y--;
		if(y<5)  direction=false;
	}
	else if(speed%8==0)
	{
		y++;
		if(y>40)
			direction=true;
	}

	if(x>hhSize-2 || y<1 || y>=vvSize-1 )
		exist=false;
}
void Gain::update(ConsoleScreen & cs)
{
	move();
	if(exist)
	{
		if(type=='B')
			cs.screen[x][y]='B';
		else if(type=='H')
			cs.screen[x][y]='H';
		else if(type=='L')
			cs.screen[x][y]='L';
	}
}

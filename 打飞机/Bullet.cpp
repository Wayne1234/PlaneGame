#include"Bullet.h"
#include<iostream>
using namespace std;

Bullet::Bullet()
{
	speed=1;
}

Bullet::Bullet(int sx,int sy,int t)
{
	if(type==1||type==111)
		x=sx-1;
	else
		x=sx+1;
	y=sy; type=t;
}
Bullet::~Bullet()
{

}

void Bullet::update(ConsoleScreen & cs)
{
	speed++;
	if(type==1|| type==111)  x--;
	else if(type==2) if(speed%1==0) x++;
	if(x>1&&x<hhSize-1)
		cs.screen[x][y]='*';
	if(x>1&&x<hhSize-1&&y>2&&y<vvSize-2&&type==111)
	{
		cs.screen[x][y-2]='*';cs.screen[x][y+2]='*';
	}

}
bool Bullet::kill(int sx,int sy)
{
	if(type==1 || type==2)
	{
		if(x==sx&& y==sy)
		{
			x=-1;  y=-1;
			return true;
		}
	}
   else if(type==111)
	{	
		if( x==sx&& ( y==sy ||  y==(sy-2) || y==(sy+2) )  )
		{
			x=-1;  y=-1;
			return true;
		}
	}
	return false;
}
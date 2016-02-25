#include"Enemy.h"
#include<stdlib.h>
#include<time.h>
#include<windows.h>
Enemy::Enemy()
{
	x=1;y=rand()%40+5;
	speed=1;   //用来间接调节速度
	alive=true;
	type=rand()%2;
	for(int i=0;i<max_enemy_bullet;i++)
		e_bullet[i]=NULL;
	add_bullet();
}

bool Enemy::move(Player * p)
{
	speed++;
	if(type==1&&speed%2==0 && alive)
	{			x++;
		if(speed%7==0)
			add_bullet();
	}
	else if(speed%4==0 && alive)
	{
		x++;
		if(speed%9==0)
			add_bullet();
	}
	be_killed(p);
	if(x>hhSize-1|| alive==false)
		return true;
	else
		return false;
}

void Enemy::be_killed(Player * p)
{
	for(int i=0;i<max_bullet;i++)
		if(p->bullet[i]!=NULL)
			if(p->bullet[i]->kill(x,y))
			{
				alive=false;
				p->score+=100;
			}
}
void Enemy::update(ConsoleScreen& cs)
{
	if(alive&&x<cs.hScreenSize-1&&y<cs.vScreenSize-1&& y>0)
	{
		if(type==1)
			cs.screen[x][y]='T';
		else 
			cs.screen[x][y]='W';
	}
	for(int i=0;i<max_enemy_bullet;i++)
		if(e_bullet[i]!=NULL)
			e_bullet[i]->update(cs);
}

void Enemy::add_bullet()
{
	for(int i=0;i<max_enemy_bullet;i++)
	{
		if(e_bullet[i]==NULL) break;
		else if(e_bullet[i]->x<1 || y<1 )
		{
			e_bullet[i]=NULL;
		}
	}
	for(int i=0;i<max_bullet;i++)
	{
		if(e_bullet[i]==NULL)
		{
			e_bullet[i]=new Bullet(x,y,2);
			break;
		}
	}
}


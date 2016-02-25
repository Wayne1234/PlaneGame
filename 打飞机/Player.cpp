#include"Player.h"
#include<iostream>
#include<iomanip>
using namespace std;

Player::Player(int sx,int sy)
{ 
	x=sx;  y=sy; alive=true;
	HP=20;score=0;
	for(int i=0;i<max_bullet;i++)
		bullet[i]=NULL;

	gain_bullet=1;
	gain_HP=false;
	gain_bomb=3;
}

Player::~Player()
{

}

void Player::move(CONTROL t)
{
	if(alive)
	{
	if(t==DOWN)  x++;
	else if(t==UP) x--;
	else if(t==LEFT) y--;
	else if(t==RIGHT) y++;
	}
}

void Player::reach_gain(Gain * g)
{
	if(g->exist&& x==g->x &&( y==g->y || y-1==g->y || y+1==g->y ))
	{
		if(g->type=='L')
			gain_bullet=111;
		else if(g->type=='B')
			gain_bomb++;
		else if(g->type=='H')
			HP+=5;
		g->exist=false;
	}
}

void Player::update(ConsoleScreen& cs,EnemyList & e_list,Boss * b)
{
	be_killed(e_list);
	b->kill(this);
	//·É»úÄ£ÐÍ ¡°=0=¡±
	if(alive)
	{
	cs.screen[x][y]='0'; 
	if(y>1)cs.screen[x][y-1]='>';
	if(y<cs.vScreenSize-2)cs.screen[x][y+1]='<';
	}
	else
	{
		cs.screen[x][y]='v';
		if(y>1)cs.screen[x][y-1]='-';
		if(y<cs.vScreenSize-2)cs.screen[x][y+1]='-';
	}
	for(int i=0;i<max_bullet;i++)
		if(bullet[i]!=NULL)
			bullet[i]->update(cs);
}

void Player::add_bullet(int type,ConsoleScreen& cs)
{
	for(int i=0;i<max_bullet;i++)
	{
		if(bullet[i]==NULL) break;
		else if(bullet[i]->x<1 || y<1 )
		{
			bullet[i]=NULL;
		}
	}
	for(int i=0;i<max_bullet;i++)
	{
		if(bullet[i]==NULL)
		{
			bullet[i]=new Bullet(x,y,type);
						bullet[i]->update(cs);
			break;
		}
	}
}

void Player::use_bomb(EnemyList &enemylist ,Boss * b)
{
	if(gain_bomb==0) ;
	else
	{
		gain_bomb--;
		enemylist.realse_enemy();
		if(b!=NULL){ b->bomb_demaged(); score+=1000; }
	}
}

void Player::be_killed(EnemyList & e_list )
{
	if(e_list.kill(x,y))
	{
		if(HP>0)
		{
	       HP--;
		   	gain_bullet=1;
		}
		else	if(HP<=0)
		{
			HP=0;
			alive=false;
		}
	}
}
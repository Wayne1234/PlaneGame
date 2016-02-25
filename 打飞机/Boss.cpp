#include"Boss.h"
#include<stdlib.h>
#include<windows.h>
Boss::Boss()
{

	x=2; y=25;
	HP=50;
	alive=true;
	left_right=true;
	for(int i=0;i<max_boss_bullet;i++)
		b_bullet[i]=NULL;
}

void  Boss::move(Player * p)
{
	if(alive&& left_right)
	{
		y--;
		if(y<5)
			left_right=false;
			be_killed(p);
	}
	else if(alive)
	{
		y++;
		if(y>40)
			left_right=true;
		be_killed(p);
	}add_bullet();

}

void Boss::be_killed(Player * p)
{
	for(int i=0;i<max_bullet;i++)
		if(p->bullet[i]!=NULL)
			if(p->bullet[i]->kill(x,y))
			{
				HP--;
				if(HP<=0) alive=false;
				p->score+=100;
			}
}

void Boss::kill(Player * p)
{
		for(int i=0;i<max_boss_bullet;i++)
		{
			if(b_bullet[i]!=NULL)
			{
				if(b_bullet[i]->x==p->x&& ( b_bullet[i]->y==p->y || b_bullet[i]->y -1==p->y  || b_bullet[i]->y+1==p->y) )
				{
					if(p->HP>1)  { p->HP--;  p->gain_bullet=1; }
					else	if(p->HP<=1) {p->HP=0; p->alive=false; }

				}
			}
		}
}
void Boss::bomb_demaged()
{
	HP-=20;
	if(HP<=0) alive=false;
}
void Boss::update(ConsoleScreen& cs,Player * p)
{
	move(p);
	if(alive&&x<cs.hScreenSize-1&&y<cs.vScreenSize-1&& y>0)
	{	
		cs.screen[x][y]='o'; cs.screen[x][y-1]='v'; cs.screen[x][y+1]='v'; 
		cs.screen[x][y-2]='|'; cs.screen[x][y+2]='|'; 
		cs.screen[x-1][y-1]='-';cs.screen[x-1][y]='-';cs.screen[x-1][y+1]='-';
		cs.screen[x+1][y-1]='-';cs.screen[x+1][y]='-';cs.screen[x+1][y+1]='-';
	}
	if(alive)
	{
	for(int i=0;i<max_boss_bullet;i++)
		if(b_bullet[i]!=NULL)
		{
			b_bullet[i]->update(cs);
			cs.screen[ b_bullet[i]->x ][ b_bullet[i]->y-1]='*';
			cs.screen[ b_bullet[i]->x ][ b_bullet[i]->y+1]='*';
		}
	}
}

void Boss::add_bullet()
{
	for(int i=0;i<max_boss_bullet;i++)
	{
		if(b_bullet[i]==NULL) break;
		else if(b_bullet[i]->x>hhSize-3 || y<1 )
		{
			b_bullet[i]=NULL;
		}
	}
	for(int i=0;i<max_boss_bullet;i++)
	{
		if(b_bullet[i]==NULL)
		{
			b_bullet[i]=new Bullet(x,y,2);
			break;
		}
	}
}


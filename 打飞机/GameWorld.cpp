#include "GameWorld.h"
#include<windows.h>
#include <conio.h>
#include<stdlib.h> 
#include<cmath>
GameWorld::GameWorld(void):cs()
{

}

GameWorld::~GameWorld(void)
{

}

CONTROL GameWorld::checkKeyBoardInput()
{
	CONTROL turn = NONE;
	//bool set=0;
	if(_kbhit()){
		char ch = _getch();
		switch(ch){
		//向右 d
		case 100:	turn = RIGHT;	break;
		//向上 w
		case 119:	turn = UP;	break;
		//向左 a
		case 97:	turn = LEFT;	break;
		//向下 s
		case 115:	turn = DOWN;	break;
		//press p to exit
		//case 105:   turn = SET;  enemylist.add_enemy(); break;//添加一个敌人
		case 'r':   turn = RESTART; restart();break;
		case 'p':	system("pause");exit(0);break;
		case 'k':if(p->alive)p->add_bullet(p->gain_bullet,cs);break;
		case 'j':if(p->alive) p->use_bomb(enemylist,b);break;
		case 'q': turn= START ;break; 
		default:	;
		}
	}
	return turn;
}

void GameWorld::mystart()
{
	cs.begin();
	while(true)
	{
		CONTROL t=checkKeyBoardInput();
		if(t==START)
			start();
	}
}

int GameWorld::start()
{
	p=new Player(hhSize/2,vvSize/2);
	 g=new Gain('H');
	 b=new	Boss;	
	 int add_enemy=0;
	 int add_gain=0;
	update();
	while(p->score<5000)
	{
		add_enemy=rand()%10;
		add_gain=rand()%10;
		if(add_enemy==1)
			enemylist.add_enemy();
		if(b->alive==false)
		{
			int temp=rand()% 20;
			if(temp==0)
				b=new Boss;
		}
		if(add_gain==0 && g->exist==false )
		{
			int type=0;
			type=rand()%3;
			if(type==0)
				 g=new Gain('L');
			else if(type==1)
				g=new Gain('B');
			else if(type==2)
				g=new Gain('H');
		}
		p->reach_gain(g);
		update();
		CONTROL t=checkKeyBoardInput();
		if(t!=NONE)
		{
			Player temp= *p;
			temp.move(t);
			if(!checkOutOfBoundary(temp.x,temp.y))
			{
				p->move(t);
				p->reach_gain(g);
				update();
			}
					update();
			continue;
		}
	}
	cs.end(p);
	return 0;
}

void GameWorld::update()
{
	cs.reset();
	enemylist.update(cs,p);
	b->update(cs,p);
	p->update(cs,enemylist,b);
	g->update(cs);
	cs.update(p);
}

bool GameWorld::checkOutOfBoundary(int x, int y)
{
	if(x<1||y<1||x>cs.hScreenSize-2||y>cs.vScreenSize-2)
		return true;
	else
		return false;
}
void GameWorld::restart()
{
	p = new Player(hhSize/2,vvSize/2);
	cs.reset();
	p->update(cs,enemylist,b);
	cs.update(p);
}

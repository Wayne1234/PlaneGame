#ifndef BULLET_H
#define BULLET_H
#include"CommonDefinitions.h"
#include"ConsoleScreen.h"
class Bullet
{
	int x,y;
	int type;
	int speed;  //间接调节速度
public:
	Bullet();
	Bullet(int ,int,int);
	~Bullet();
	void update(ConsoleScreen &cs);
	bool kill(int x,int y);
	friend GameWorld;
	friend Player;
	friend Enemy;
	friend Boss;
	friend EnemyList;
};
#endif
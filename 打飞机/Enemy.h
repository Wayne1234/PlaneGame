#ifndef ENEMY_H
#define ENEMY_H
#include "CommonDefinitions.h"
#include "ConsoleScreen.h"
#include"Player.h"
#include"Bullet.h"
const int max_enemy_bullet=10;
class Enemy
{
	int x,y;
	int speed;
	int direction;
	Bullet * e_bullet[max_enemy_bullet];
	bool alive;
	int type;
public:
	Enemy();
	bool move(Player * p);
	void update(ConsoleScreen& cs);
	void be_killed(Player *p);
	void add_bullet();
	friend GameWorld;
	friend Player;
	friend EnemyList;
};
#endif
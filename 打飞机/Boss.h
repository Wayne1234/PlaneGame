#ifndef BOSS_H
#define BOSS_H
#include "CommonDefinitions.h"
#include "ConsoleScreen.h"
#include"Player.h"
#include"Bullet.h"
const int max_boss_bullet=5;
class Boss
{
	int x,y;
	bool left_right;
	Bullet * b_bullet[max_boss_bullet];
	bool alive;
	int HP;
public:
	Boss();
	void  move(Player * p);
	void update(ConsoleScreen& cs,Player * p);
	void be_killed(Player *p);
	void add_bullet();
	void bomb_demaged();
	void kill(Player * p);
	friend GameWorld;
	friend Player;
};
#endif
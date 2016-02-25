#ifndef PLAYER_H
#define PLAYER_H
#include "CommonDefinitions.h"
#include "ConsoleScreen.h"
#include"Bullet.h"
#include"Gain.h"
#include"Boss.h"
#include"EnemyList.h" 
const int max_bullet=20;
class Player
{
	int x,y;  //分别表示行，列
	bool alive;
	int HP;
	int score;

	//增益系统
	int  gain_bullet;
	bool gain_HP;
	int gain_bomb;

	Bullet *bullet[max_bullet];

public:
	Player(int sx,int sy);
	~Player(void);

	//move one step to the given direction
	void move(CONTROL t);

	//draw the play on the given screen
	void update(ConsoleScreen& cs,EnemyList & e_list,Boss * g);

	void add_bullet(int type,ConsoleScreen& cs);

	void be_killed(EnemyList & e_list );

	void reach_gain(Gain * g);

	void use_bomb(EnemyList & enemylist,Boss * b);

	friend GameWorld;
	friend ConsoleScreen;
	friend Enemy;
	friend Boss;
};
#endif
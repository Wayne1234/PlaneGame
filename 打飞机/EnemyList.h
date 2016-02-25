#ifndef ENEMYLIST_H
#define ENEMYLIST_H
#include"Enemy.h"
#include "CommonDefinitions.h"
#include "ConsoleScreen.h"
class EnemyList
{
	struct node
	{
		Enemy * enemy;
		node *next;
	} *head;
public:
	EnemyList();
	~EnemyList();
	void add_enemy();
	void remove_enemy(node *p);
	void update(ConsoleScreen &cs,Player *p);
	bool kill(int sx,int sy);
	void realse_enemy();

	friend GameWorld;
	friend Player;
};
#endif
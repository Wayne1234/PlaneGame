#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H
#include"CommonDefinitions.h"
#include"Player.h"
class ConsoleScreen
{
	const int hScreenSize;
	const int vScreenSize;
	char** screen;
public:
	ConsoleScreen(int hSize = 20, int vSize = 50);
	~ConsoleScreen(void);

	//paint the screen according to its screen array.
	void update(Player *p);

	//reset the screen
	void reset();
	
	//clear the screen
	void clear();

	//the  end
	void end(Player * p);

	//the begin 
	void begin();

	friend Player;
	friend Enemy;
	friend EnemyList;
	friend Bullet;
	friend Gain;
	friend Boss;
	friend GameWorld;
};

#endif
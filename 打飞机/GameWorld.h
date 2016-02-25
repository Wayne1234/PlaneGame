#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include<iostream>
#include<windows.h>
#include"ConsoleScreen.h"
#include "Player.h"
#include"Enemy.h"
#include"EnemyList.h"
#include"Bullet.h"
#include"Gain.h"
#include"Boss.h"
#include "CommonDefinitions.h"
using namespace std;


class GameWorld
{
	//cs controls the content displayed in the screen.
	ConsoleScreen cs;

	//p represents the player in the game
	Player* p;

	EnemyList enemylist;

	//Gain ����ϵͳ

	Gain *g;

	Boss * b;
public:

	GameWorld(void);
	~GameWorld(void);

	//check the keyboard input to control the program 
	CONTROL checkKeyBoardInput();

	//start the game
	int start();

	void mystart();

	//update everything in the game, including the player and the screen
	void update();

	//check whether the given position is out of the screen
	bool checkOutOfBoundary(int x, int y);
	//bool enemyout(int);//����ȫ����Enemy�����ж��Ƿ�ȫ������Ļ��
	void restart();
};



#endif
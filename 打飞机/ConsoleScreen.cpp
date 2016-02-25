#include"ConsoleScreen.h"
#include<Windows.h>
#include<iostream>
#include<iomanip>
using namespace std;

ConsoleScreen::ConsoleScreen(int hSize,int vSize ):hScreenSize(hSize),vScreenSize(vSize)
{
	screen=new char *[hSize];
	for(int i=0;i<hSize;i++)
		screen[i]=new char [vSize];
	for(int i=0;i<vSize;i++) 
	{
		screen[0][i]='-';
		screen[hSize-1][i]='-';
	}
	for(int i=1;i<hSize-1;i++)
	{
		screen[i][0]='|';
		screen[i][vSize-1]='|';
	}
	for(int i=1;i<hSize-1;i++)
		for(int j=1;j<vSize-1;j++)
			screen[i][j]=' ';
}

ConsoleScreen::~ConsoleScreen()
{
	for(int i=0;i<hScreenSize;i++)
		delete []screen[i];
	screen=NULL;
}
void ConsoleScreen::update(Player *p )
{
	clear();
	for(int i=0;i<hScreenSize;i++)
	{
		for(int j=0;j<vScreenSize;j++)
			cout<<screen[i][j];
		if(i==2)
			cout<<"   "<<"HP : "<<p->HP<<"  ";
		else if(i==3)
			cout<<"   "<<"Score : "<<p->score<<"   ";
		else if(i==4)
			cout<<"   "<<"Bullet_type : "<<p->gain_bullet<<"  ";
		else if(i==5)
			cout<<"   "<<"Bomb :"<<p->gain_bomb<<"  ";
		cout<<endl;
	}
	cout<<"press 'w a s d ' to control the direction\n";
	cout<<"press k to shot and "<<"press J to use a bomb \n";
	cout<<"press r to revive \n";
	cout<<"press p to stop\n";
}

void ConsoleScreen::reset()
{
	for(int i=1;i<hScreenSize-1;i++)
		for(int j=1;j<vScreenSize-1;j++)
			screen[i][j]=' ';
}

void ConsoleScreen::end(Player * p)
{
	clear();
	reset();
	for(int i=0;i<hScreenSize;i++)
	{	
		if(i==10)
		{
			char str[20]="YOU WIN! WOW~~";
			for(int x=0;x<13;x++)
				screen[i][18+x]=str[x];
		}
		for(int j=0;j<vScreenSize;j++)
			cout<<screen[i][j];

		cout<<endl;
	}
}

void ConsoleScreen::begin()
{
	clear();
	reset();
	for(int i=0;i<hScreenSize;i++)
	{	
		if(i==10)
		{
			char str[20]="Press Q to Start";
			for(int x=0;x<16;x++)
				screen[i][18+x]=str[x];
		}
		if(i==11)
		{
			char str[20]="Press P to Exit";
			for(int x=0;x<15;x++)
				screen[i][18+x]=str[x];
		}
		for(int j=0;j<vScreenSize;j++)
			cout<<screen[i][j];

		cout<<endl;
	}
}

void ConsoleScreen::clear()
{
	COORD coordScreen={0,0};
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut,coordScreen);
}

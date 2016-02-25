#ifndef GAIN_H
#define GAIN_H
#include"ConsoleScreen.h"
const int max_gain_num=3;
class Gain
{
	//��������
	// B : ը��   H����Ѫ   L����ǿ�ӵ�
	char  type;
	bool exist;
	int x,y;
	int speed;
	bool direction;
public:
	Gain(char  s);
	~Gain();
	void move();
	void update(ConsoleScreen & cs);

	friend Player;
	friend GameWorld;
};
#endif
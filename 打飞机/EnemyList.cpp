#include"EnemyList.h"
#include<iostream>
using namespace std;
EnemyList::EnemyList()
{
	head=new node;
	head->enemy=NULL;
	head->next=NULL;
}
EnemyList::~EnemyList()
{
	node *temp=head;
	while(temp!=NULL)
	{
		temp=head->next;
		delete head->enemy;delete head;
		head=temp;
	}
}

void EnemyList::realse_enemy()
{
	node *temp=head;
	while(temp!=NULL)
	{
		temp=head->next;
		delete head->enemy;delete head;
		head=temp;
	}
	head=new node;
	head->enemy=NULL;
	head->next=NULL;
}

void EnemyList::add_enemy()
{
	node* p=new node;
	p->next=NULL;
	p->enemy=new Enemy;
	p->next=head->next;
	head->next=p;
}

void EnemyList::remove_enemy(node *p)  //删除结点的下一个结点
{
	node*temp=p->next;
	p->next=temp->next;
	delete temp->enemy;
	delete temp;
}

void EnemyList::update(ConsoleScreen & cs,Player * p)
{
	node *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->next->enemy->move(p))
			remove_enemy(temp);
		else
		{
			temp->next->enemy->update(cs);
			temp=temp->next;
		}
	}
}

bool EnemyList::kill(int sx,int sy)
{
	for(node *temp=head;temp->next!=NULL; temp=temp->next)
	{
		if(temp->next->enemy->x==sx && temp->next->enemy->y==sy )
		{
			remove_enemy(temp);
			return true;
		}
		for(int i=0;i<max_enemy_bullet;i++)
			if(temp->next->enemy->e_bullet[i]!=NULL)
				if(temp->next->enemy->e_bullet[i]->kill(sx,sy))
					return true;
	}
	return false;
}
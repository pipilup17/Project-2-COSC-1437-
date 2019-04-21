#pragma once
#include "string"
#include "Character.h"

class Enemy : public Character
{
private:
	int damage;
	int level; //
	char actEn;
	char choice[5] = { '1','2','3','B','C', };
	/*char actEn2[3] = { '1','B','C' };
	char actEn3[4] = { '1','2','B','C' };
	char actEn4[5] = { '1','2','3','B','C' };*/
public:
	Enemy(string, int);
	void setLevel(int);
	void setAction(char act);
	char getAction();
	void setDamage(int);
	char random();
	int getDamage() const;
};
#pragma once
#include "string"
#include "Character.h"

class Enemy : public Character
{
private:
	int level;
	char actEn;
	char choice[5] = { '1','2','3','B','C'};
public:
	Enemy(string, int);
	void setLevel(int);
	char getAction();
	char random();
};
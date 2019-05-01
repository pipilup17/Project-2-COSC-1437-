#pragma once
#include "string"
#include "Character.h"

class Enemy : public Character
{
private:
	int level;
	char actEn;
	char choice[7] = { 'A','B','1','2','C','3','4' };
public:
	Enemy() {};
	Enemy(string, int);
	//void setLevel(int);
	char getAction();
	char random(int);
	Enemy operator+(const Enemy&) const;
};
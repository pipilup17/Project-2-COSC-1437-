#pragma once
#include "string"
#include "Character.h"

class Enemy : public Character
{
private:
	float damage;
	int level; //
	char actEn;
public:
	Enemy(string, int);
	void setAction(char act);
	char getAction();
	void setDamage(int);
	float getDamage() const;
};
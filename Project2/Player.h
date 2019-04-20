#pragma once
#include "Character.h"
#include "string"
using namespace std;
class Player : public Character
{
private:
	char action;
	float damage;
public:
	Player(string n);
	void setAction(char);
	char getAction() const; 

	void setDamage(float);
	float getDamage() const;
};
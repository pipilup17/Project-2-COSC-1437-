#pragma once
#include "Character.h"
#include "string"
using namespace std;
class Player : public Character
{
private:
	int damage;
public:
	Player(string n);
	void setAction(char);
	int getDamage() const;
};
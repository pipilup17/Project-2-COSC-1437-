#pragma once
#include "Character.h"
#include "string"
using namespace std;
class Player : public Character
{
private:
	int mana;
	int maxMana;
public:
	Player(string, int);
	void setMana(int);
	int getMana();
	void recoverMana();
};
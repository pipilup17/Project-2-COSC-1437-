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
	//void setAction(char action, string moveName[], float mana[], float dam[]);
	void setMana(int);
	int getMana();
	void recoverMana();
};
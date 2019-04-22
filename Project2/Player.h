#pragma once
#include "Character.h"
#include "string"
using namespace std;
class Player : public Character
{
private:
	int mana;
public:
	Player(string n);
	//void setAction(char action, string moveName[], float mana[], float dam[]);
	
};
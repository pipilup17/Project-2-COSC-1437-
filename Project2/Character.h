#pragma once
#include "string"
using namespace std;

class Character
{
protected:
	int damage, maxHp, hp, level;
	string name;
	float block;
public:
	Character() {};
	Character(string, int, int);
	void setName(string);
	void setHP(int);;
	string getName() const;
	int getHP() const;
	virtual void setAction(char ch, string moveName[], int mana[], int dam[]);
	void setBlock(float);
	float getBlock() const;
	int getDamage() const;
	int getLevel()
	{
		return level;
	}
	virtual void recoverMana() {};
	virtual char random(int a) { return 0; }
	virtual int getMana() { return 0; }
	virtual void setMana(int) {};
};                                                                                                                                                                                                                                                                                                                                                                                                       
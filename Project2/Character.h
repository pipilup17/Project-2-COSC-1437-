#pragma once
#include "string"
using namespace std;

class Character
{
private:
	string name;
	int hp, mana;
	float block;
protected:
public:
	Character() {};
	Character(string, int, int);
	void setName(string);
	void setHP(int);
	void setMana(int);
	string getName() const;
	int getHP() const;
	int getMana() const;
	virtual void setAction(char) = 0;
	void setBlock(float);
	float getBlock();
};                                                                                                                                                                                                                                                                                                                                                                                                       
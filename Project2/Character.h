#pragma once
#include "string"
using namespace std;

class Character
{
private:
	int damage, hp;
	string name;
	float block;
protected:
public:
	Character() {};
	Character(string, int);
	void setName(string);
	void setHP(int);;
	string getName() const;
	int getHP() const;
	virtual void setAction(char ch, string moveName[], int mana[], int dam[]);
	//virtual void setAction(char, string moveName[], float mana[], float dam[]) = 0;
	void setBlock(float);
	float getBlock() const;
	int getDamage() const;
};                                                                                                                                                                                                                                                                                                                                                                                                       
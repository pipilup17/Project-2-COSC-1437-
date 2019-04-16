#pragma once
#include "string"
using namespace std;

class Character
{
private:
	string name;
	float hp;
	float mana;
public:
	/*Character(string, float, float);*/
	void setName(string);
	void setHP(float);
	void setMana(float);
	string getName() const;
	float getHP() const;
	float getMana() const;
	virtual void setAction(char) = 0;
};
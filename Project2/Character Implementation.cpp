#include "Character.h"

using namespace std;

//Character::Character(string n, float h, float m)
//{
//	name = n;
//	hp = h;
//	mana = m;
//}

void Character::setName(string n)
{
	name = n;
}

string Character::getName() const
{
	return name;
}

void Character::setHP(float h)
{
	hp = h;
}

float Character::getHP() const
{
	return hp;
}

void Character::setMana(float m)
{
	mana = m;
}

float Character::getMana() const
{
	return mana;
}
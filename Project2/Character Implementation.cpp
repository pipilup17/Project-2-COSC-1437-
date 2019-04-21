#include "Character.h"

using namespace std;

Character::Character(string n, int h, int m)
{
	name = n;
	hp = h;
	mana = m;
}

void Character::setName(string n)
{
	name = n;
}

string Character::getName() const
{
	return name;
}

void Character::setHP(int h)
{
	hp = h;
}

int Character::getHP() const
{
	return hp;
}

void Character::setMana(int m)
{
	mana = m;
}

int Character::getMana() const
{
	return mana;
}

void Character::setBlock(float b)
{
	block = b;
}

float Character::getBlock()
{
	return block;
}
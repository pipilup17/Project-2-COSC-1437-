
#include "Character.h"
#include "iostream"
using namespace std;

Character::Character(string n, int h, int lvl)
{
	name = n;
	hp = h + 5 * lvl;
	level = lvl;
	maxHp = h + 5 * lvl;
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
	if (h < 0)
		hp = 0;
}

int Character::getHP() const
{
	return hp;
}

void Character::setBlock(float b)
{
	block = b;
}

float Character::getBlock() const
{
	return block;
}

void Character::setAction(char ch, string moveName[], int mana[], int dam[])
{
	char action = ch;
	if (isdigit(action))
	{
		int x = action - '0';
		cout << "_________________________\n" << endl;
		cout << name << " uses " << moveName[x - 1] << "!" << endl;
		damage = dam[x - 1];
		block = 0;
	}
	else if (toupper(action) == 'B')
	{
		cout << "_________________________\n" << endl;
		cout << name << " blocks!" << endl;
		damage = 0;
		block = 0.75;
	}
	else if (toupper(action) == 'C')
	{
		cout << "_________________________\n" << endl;
		cout << name << " heals!" << endl;
		damage = 0;
		block = 0;
		hp = hp + 0.25*maxHp;
		if (hp > 30)
			hp= 30 ;
	}
	else if (toupper(action) == 'A')
	{
		cout << "_________________________\n" << endl;
		cout << name << " attacks!" << endl;
		damage = 3;
		block = 0;
	}
}

int Character::getDamage() const
{
	return damage;
}
#include "Player.h"
#include "string"
#include "iostream"
using namespace std;

Player::Player(string n)
{
	setName(n);
	setHP(20);
	setMana(30);
}

void Player::setAction(char ch)
{
	action = ch;
	if (isdigit(action))
	{
		int x = action - '0';
		setDamage(x);
	}
	else if (toupper(action) == 'B')
	{
		setDamage(0);
	}
	else if (toupper(action) == 'C')
	{
		setDamage(0);
	}
}

char Player::getAction() const
{
	return action;
}

void Player::setDamage(int x)
{
	damage = 5 * x; // This may be for special attack. suppose special attack is lvl 2 or sth (x=2), the damage will be higher.
}

float Player::getDamage() const
{
	return damage;
}
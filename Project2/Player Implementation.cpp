#include "Player.h"
#include "string"

Player::Player(string n)
{
	setName(n);
	setHP(20);
	setMana(30);
}

void Player::setAction(char ch)
{
	action = ch;
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
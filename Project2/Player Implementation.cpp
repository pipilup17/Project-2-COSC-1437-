
#include "Player.h"
#include "string"
#include "iostream"
using namespace std;

Player::Player(string n, int lvl):Character(n, 30, lvl)
{
	mana = 12 * lvl;
	maxMana = 12 * lvl;
}

void Player::setMana(int m)
{
	mana = m;
}

int Player::getMana()
{
	return mana;
}

void Player::recoverMana()
{
	mana = mana + 3;
	if (mana > maxMana)
		mana = maxMana;
}

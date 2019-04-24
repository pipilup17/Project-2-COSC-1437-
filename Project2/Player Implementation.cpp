
#include "Player.h"
#include "string"
#include "iostream"
using namespace std;

Player::Player(string n):Character(n,30)
{
	mana = 30;
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
}

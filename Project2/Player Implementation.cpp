#include "Player.h"
#include "string"
#include "iostream"
using namespace std;

Player::Player(string n):Character(n,20,30)
{
	action = '/n';
	damage = 0;
}

void Player::setAction(char ch)
{
	action = ch;
	if (isdigit(action))
	{
		int x = action - '0';
		setDamage(x);
		switch (x)
		{
		case (1): 
			cout << getName() << " attack" << endl;
			break;
		case (2):
			cout << getName() << " uses Fireball" << endl;
			break;
		case (3): 
			cout << getName() << " uses Thunder" << endl;
			break;
		} //More option below here if needed
	}
	else if (toupper(action) == 'B')
	{
		setDamage(0);
	}
	else if (toupper(action) == 'C')
	{
		setDamage(0);
	}
	cout << getName() << "'s Damage in class: " << damage << endl;
}

char Player::getAction() const
{
	return action;
}

void Player::setDamage(float x)
{
	damage = 5 * x;
}

float Player::getDamage() const
{
	return damage;
}
#include "Player.h"
#include "string"
#include "iostream"
using namespace std;

Player::Player(string n):Character(n,30,30)
{
	damage = 0;
}

void Player::setAction(char ch)
{
	char action = ch;
	if (isdigit(action))
	{
		int x = action - '0';
		setBlock(0);
		damage = 5 * x; // do a general formula or actually make it different in the conidtions below. May be fun to make it different but idk
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
		cout << getName() << " blocks!" << endl;
		damage = 0;
		setBlock(0.75);
	}
	else if (toupper(action) == 'C')
	{
		cout << getName() << " heals!" << endl;
		damage = 0;
		setBlock(0);
		setHP(getHP() + 15);
		if (getHP() > 30) //Maybe create a max HP variable (that can changes with level value in the parameter) so the condition will be dynamic
		{
			setHP(30);
		}
		// or maybe create a heal function and add the value to HP.
	}
}




int Player::getDamage() const
{
	return damage;
}
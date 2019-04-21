#include "Enemy.h"
#include "iostream"
#include "string"
#include "ctime"
using namespace std;
Enemy::Enemy(string n, int lvl)
{
	setName(n);
	setLevel(lvl);
}

void Enemy::setLevel(int lvl)
{
	setHP(15+lvl*10);

}

void Enemy::setAction(char ch)
{
	char actEn = ch;
	if (isdigit(actEn))
	{
		int x = actEn - '0';
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
	else if (toupper(actEn) == 'B')
	{
		cout << getName() << " blocks!" << endl;
		damage = 0;
		setBlock(0.75);
	}
	else if (toupper(actEn) == 'C')
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

	/*actEn = ch;
	if (isdigit(actEn))
	{
		int x = actEn - '0';
		setDamage(x);

	}
	else if (toupper(actEn) == 'B')
	{
		setDamage(0);
	}
	else if (toupper(actEn) == 'C')
	{
		setDamage(0);
	}*/
char Enemy::getAction()
{
	return actEn;
}

void Enemy::setDamage(int x)
{
	damage = 5*x; // This may be for special attack. suppose special attack is lvl 2 or sth (x=2), the damage will be higher.
}

int  Enemy::getDamage() const
{
	return damage;
}

char Enemy::random()
{
	srand(time(0));
	actEn = choice[rand() % 5];
	return actEn;
}


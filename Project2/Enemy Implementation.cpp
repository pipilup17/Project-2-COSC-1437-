#include "Enemy.h"
#include "string"

Enemy::Enemy(string n, int lvl)
{
	switch (lvl)
	{
	case (1): 
		setName(n);
		setHP(15);
		setMana(5);
		break;
	case(2):
		setName(n);
		setHP(30);
		setMana(20);
		break;
	case(3):
		setName(n);
		setHP(50);
		setMana(30);
		break;
	}
}


void Enemy::setAction(char ch)
{
	actEn = ch;
}

char Enemy::getAction()
{
	return actEn;
}

void Enemy::setDamage(int x)
{
	damage = 5 * x; // This may be for special attack. suppose special attack is lvl 2 or sth (x=2), the damage will be higher.
}

float  Enemy::getDamage() const
{
	return damage;
}
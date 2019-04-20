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
	actEn = ch;
	if (isdigit(actEn))
	{
		float x = actEn - '0';
		setDamage(x);
		
	}
	else if (toupper(actEn) == 'B')
	{
		setDamage(0);
	}
	else if (toupper(actEn) == 'C')
	{
		setDamage(0);
	}
	cout << "\nENEMY'S DAMAGE IN CLASS: " << getDamage() << endl;
}

char Enemy::getAction()
{
	return actEn;
}

void Enemy::setDamage(float x)
{
	damage = x; // This may be for special attack. suppose special attack is lvl 2 or sth (x=2), the damage will be higher.
}

float  Enemy::getDamage() const
{
	return damage;
}

char Enemy::random()
{
	srand(time(0));
	actEn = choice[rand() % 5];
	return actEn;
}


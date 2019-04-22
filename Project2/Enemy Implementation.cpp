
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

char Enemy::getAction()
{
	return actEn;
}

char Enemy::random()
{
	srand(time(0));
	actEn = choice[rand() % 5];
	return actEn;
}



#include "Enemy.h"
#include "iostream"
#include "string"
#include "ctime"
using namespace std;
Enemy::Enemy(string n, int lvl):Character(n,5,lvl)
{
	actEn = 'N';
}

//void Enemy::setLevel(int lvl)
//{
//	setHP(15+lvl*10);
//
//}

char Enemy::getAction()
{
	return actEn;
}

char Enemy::random(int lvl)
{
	int ran = 0;
	switch (lvl)
	{
	case (1): 
		ran = 3;
		break;
	case (2): 
		ran = 5;
		break;
	case (3): 
		ran = 7;
		break;
	}
	srand(time(0));
	actEn = choice[rand() % ran];
	return actEn;
}

Enemy Enemy::operator+(const Enemy& enemy) const
{
	Enemy tempEnemy;
	tempEnemy.hp = hp + enemy.hp;
	tempEnemy.maxHp = maxHp + enemy.maxHp;
	return tempEnemy;
}


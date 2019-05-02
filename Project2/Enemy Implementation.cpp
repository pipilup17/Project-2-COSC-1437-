
#include "Enemy.h"
#include "iostream"
#include "string"
#include "ctime"
using namespace std;
Enemy::Enemy(string n, int lvl):Character(n,30,lvl)
{
	actEn = 'N';
	level = lvl;
}

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
		ran = 6;
		break;
	}
	srand(time(0));
	actEn = choice[rand() % ran];
	return actEn;
}

bool operator<(const Enemy& En1, const Enemy& En2)
{
	return (En1.level < En2.level);
}


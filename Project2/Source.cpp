#include "iostream"
#include "fstream"
#include "string"
#include "Player.h"
#include "Enemy.h"

using namespace std;
char action(Player& pl, int mana[]);
void Battle(Player& pl, Enemy& en, string moveName[], int mana[], int dam[]);
void victoryLoss(Player& pl, Enemy en);
void clearScreen();
//char menu()
//{
//	char option;
//	cout << "A. New Game \n"
//		"B. Continue \n"
//		"C. How To Play \n"
//		"D. Exit \n"
//		"Option: ";
//	cin >> option;
//	return option;
//}
//
//void outPlayerData()
//{
//	ofstream outData("Player.dat");
//	if (outData.is_open())
//	{
//		outData >> 
//	}
//}
char action(Player& pl, int mana[])
{
	char action = 'm';
	bool repeat = true;
	while (repeat == true)
	{
		while (toupper(action) != 'A' && toupper(action) != 'B' && toupper(action) != 'C' && toupper(action) != 'D')
		{
			cout << "\n||Your hp: " << pl.getHP()<<" ||" << " Your mana: "<< pl.getMana() << endl;
			cout << "|| A. Attack  || B. Block\n"
				"|| C. Heal    || D. Special             Choose your action: ";
			cin >> action;
		}
		if (toupper(action) == 'D')
		{ // Will Improve the menu code later
			int x = 6;
			while (x>5)
			{
				cout << "\n_________________________" << endl;
				cout << "\n|| 1. Fireball || 2. Gale\n"
					"|| 3. Icicle   || 4. Thunder\n"
					"|| 0. Back     || 5. Earthquake         Choose your action: ";
				cin >> action;
				x = action - '0';
			}
			if (x == 0)
			{
				repeat = true;
				cout << "_________________________" << endl;
			}
			else if (pl.getMana() < mana[x - 1])
			{
				cout << "_________________________" << endl;
				cout << "\nInsufficient mana" << endl;
				cout << "_________________________" << endl;
				repeat = true;
			}
			else
			{
				pl.setMana(pl.getMana() - mana[x - 1]);
				repeat = false;
			}
		}
		else repeat = false;
	}
	clearScreen();
	return action;
}



int main()
{
	Player pl("Bob");
	Enemy en("Slime", 1);
	string moveName[5];
	int dam[5], mana[5];
	ifstream inData("Moveset.txt");
	if (inData.is_open())
	{
		string na;
		int da, ma;
		int i = 0;
		while (inData >> moveName[i] >> dam[i] >> mana[i])
			i++;
	}

	Battle(pl, en, moveName, dam, mana);
	victoryLoss(pl, en);
	system("pause");
	return 0;
}

void victoryLoss(Player& pl, Enemy en)
{
	if (pl.getHP() == 0)
	{
		cout << "_________________________\n" << endl;
		cout << "GAME OVER!" << endl;
		cout << "_________________________\n" << endl;
	}
	else if (en.getHP() == 0)
	{
		cout << "_________________________\n" << endl;
		cout << "You are victorious!" << endl;
		cout << "_________________________\n" << endl;
	}
}

void clearScreen()
{
	for (int i = 0; i < 50; i++)
		cout << endl;
}

void Battle(Player& pl, Enemy& en, string moveName[], int mana[], int dam[])
{
	while (pl.getHP() > 0 && en.getHP() > 0)
	{
		ifstream inSlime("Slime.txt");
		cout << "_________________________\n" << endl;
		if (inSlime.is_open())
			cout << inSlime.rdbuf();
		cout << en.getName() << "'s hp:" << en.getHP() << endl;
		cout << "_________________________" << endl;
		pl.setAction(action(pl, mana), moveName, mana, dam);
		en.setAction(en.random(), moveName, mana, dam);
		int a = pl.getHP() - (en.getDamage() - pl.getBlock()*en.getDamage());
		pl.setHP(a);
		int t = en.getHP() - (pl.getDamage() - en.getBlock()*pl.getDamage());
		en.setHP(t);
		pl.recoverMana();
		cout << "_________________________" << endl;
		cout << "\n" << pl.getName() <<" recovers 3 mana" << endl;
	}
}
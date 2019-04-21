#include "iostream"
#include "fstream"
#include "string"
#include "Player.h"
#include "Enemy.h"
using namespace std;

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
char action(Player pl)
{
	char action = 'm';
	bool repeat = true;
	while (repeat == true)
	{
		while (toupper(action) != 'A' && toupper(action) != 'B' && toupper(action) != 'C')
		{
			cout << "\n||Your hp: " << pl.getHP()<<" ||" << endl;
			cout << "|| A. Attack  || B. Block\n"
				"|| C. Heal    || Choose your action: ";
			cin >> action;
		}
		if (action == 'A' || action == 'a')
		{
			cout << "\n_________________________" << endl;
			cout << "\n|| 1. Normal Attack || 2. Fireball\n"
				"|| 3. Thunder       || 4. Hailstorm\n" //or sth
				"|| 0. Back          || Choose your action: ";
			cin >> action;
			if (action == '0')
			{
				repeat = true;
				cout << "_________________________" << endl;
			}
			else repeat = false;
		}
		else repeat = false;
	}
	return action;
}

int main()
{
	Player pl("Bob");
	Enemy en("Slime", 1);
	ifstream inSlime("Slime.txt");
	while (pl.getHP() > 0 && en.getHP() > 0)
	{
		cout << "_________________________\n" << endl;
		if (inSlime.is_open())
			cout << inSlime.rdbuf();
		cout << en.getName() <<"'s hp:" << en.getHP() << endl;
		cout << "_________________________" << endl;
		pl.setAction(action(pl));
		en.setAction(en.random());
		int a = pl.getHP() - (en.getDamage() - pl.getBlock()*en.getDamage());
		pl.setHP(a);
		int t = en.getHP() - (pl.getDamage() - en.getBlock()*pl.getDamage());
		en.setHP(t);
		for (int i = 0; i < 45; i++)
			cout << endl;
	}

	if (pl.getHP() == 0)
	{
		cout << "_________________________\n" << endl;
		cout << "GAME OVER!" << endl;
		cout << "_________________________\n" << endl;
	}
	else if (en.getHP()==0)
	{
		cout << "_________________________\n" << endl;
		cout << "You are victorious!" << endl;
		cout << "_________________________\n" << endl;
	}
	system("pause");
	return 0;
}

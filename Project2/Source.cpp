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
char action()
{
	char action = 'm';
	bool repeat = true;
	while (repeat == true)
	{
		while (toupper(action) != 'A' && toupper(action) != 'B' && toupper(action) != 'C')
		{
			cout << "A. Attack \n"
				"B. Block \n"
				"C. Heal \n"
				"Choose your action: ";
			cin >> action;
		}
		if (action == 'A' || action == 'a')
		{
			cout << "\n1. Normal Attack \n"
				"2. Fireball \n" //or sth
				"0. Back \n"
				"Choose your action: ";
			cin >> action;
			if (action == '0')
				repeat = false;
			else repeat = false;
		}
		else repeat = false;
	}
	return action;
}

int main()
{
	Player pl("Bob");
	cout << pl.getHP() << endl;
	Enemy en("Slime", 1);
	while (pl.getHP() > 0 && en.getHP() > 0)
	{
		pl.setAction(action());
		cout << "PTSD" << endl;
		pl.setHP(0);
		cout << pl.getHP() << endl;
	}
	system("pause");
	return 0;
}
#include "iostream"
#include "fstream"
#include "string"
#include "Player.h"
#include "Enemy.h"

using namespace std;
char action(Character *pl, int mana[]);
void Battle(Character* pl, Character* en, string moveName[], int mana[], int dam[], int& lvl);
void victoryLoss(Character* pl, Character* en, int& lvl, bool& repeat);
void clearScreen();
void story(int& lvl);
void displayStory(int& lvl, string& a, int& j);
void How_to_play();

char menu() // return for a possible game mode. If not, change to void
{
	char option = 'j';
	bool repeat = true;
	while (repeat == true)
	{
		cout << "_________________________\n" << endl;
		option = 'j';
		cout << "A. New Game \n"
			//"B. Continue \n"
			"B. How To Play \n";
			//"C. Exit \n";
			
		while (toupper(option) != 'A' &&toupper(option) != 'B' && toupper(option) != 'C')
		{
			cout << "Option: ";
			cin >> option;
		}
		if (toupper(option) == 'B')
		{
			How_to_play();
			repeat = true;
		}
		else if (toupper(option) == 'A')
			repeat = false;
	}
	return option;
}

//void outPlayerData(Character *pl)
//{
//	ofstream outData("Player.dat");
//	if (outData.is_open())
//	{
//		outData >> 
//	}
//}

string newPlayer(int& lvl)
{
	string name;
	clearScreen();
	cout << "\n_________________________" << endl;
	cout << "\nPlease enter your name: ";
	cin >> name;
	lvl = 1;
	return name;
}

char action(Character *pl, int mana[])
{
	char action = 'm';
	bool repeat = true;
	while (repeat == true)
	{
		while (toupper(action) != 'A' && toupper(action) != 'B' && toupper(action) != 'C' && toupper(action) != 'D')
		{
			cout << "\n||Your hp: " << pl->getHP()<<" ||" << " Your mana: "<< pl->getMana() << endl;
			cout << "|| A. Attack  || B. Block\n"
				"|| C. Heal    || D. Special             Choose your action: ";
			cin >> action;
		}
		if (toupper(action) == 'D')
		{
			int x = 6;
			while (x>5)
			{
				cout << "\n_________________________" << endl;
				cout << "\n|| 1. Fireball || 2. Gale\n"
					"|| 3. Icicle   || 4. Thunder\n"
					"|| 0. Back     || 5. Earthquake         Choose your action: ";  // Terrible lookinng function
				cin >> action;
				x = action - '0';
			}
			if (x == 0)
			{
				repeat = true;
				cout << "_________________________" << endl;
			}
			else if (pl->getMana() < mana[x - 1])
			{
				cout << "_________________________" << endl;
				cout << "\nInsufficient mana" << endl;
				cout << "_________________________" << endl;
				repeat = true;
			}
			else
			{
				pl->setMana(pl->getMana() - mana[x - 1]);
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
	string moveName[5], name;
	int dam[5], mana[5], lvl;
	bool repeat = true;
	string monsterName[3] = { "Questionable One Line Function Slime", "Endless Loop Skeleton", "No Semicolon Demon" };
	ifstream inData("Moveset.txt");
	if (inData.is_open())
	{
		string na;
		int da, ma;
		int i = 0;
		while (inData >> moveName[i] >> dam[i] >> mana[i])
			i++;
	}

	menu();
	name = newPlayer(lvl);

	
	while (repeat == true)
	{
		story(lvl);
		clearScreen();
		Character *ch[2] = { new Player(name, lvl), new Enemy(monsterName[lvl - 1],lvl)};
		Battle(ch[0], ch[1], moveName, dam, mana, lvl);
		victoryLoss(ch[0], ch[1], lvl, repeat);
		if (lvl > 3)
		{
			repeat = false;
		}
	}
	story(lvl);
	system("pause");
	return 0;
}

void victoryLoss(Character* pl, Character* en, int& lvl, bool& repeat)
{
	if (pl->getHP() == 0)
	{
		clearScreen();
		cout << "_________________________\n" << endl;
		cout << "GAME OVER!" << endl;
		cout << "_________________________\n" << endl;
		repeat = false;
	}
	else if (en->getHP() == 0)
	{
		clearScreen();
		cout << "_________________________\n" << endl;
		cout << "You are victorious!" << endl;
		cout << "_________________________\n" << endl;
		lvl++;
		char choice = 'a';
		
		while (toupper(choice) != 'Y' && toupper(choice) != 'N')
		{
			cout << "Would you like to continue? Y/N    Enter:";
			cin >> choice;
		}
		if (toupper(choice)=='Y')
			repeat = true;
		else repeat = false;
	}
}

void clearScreen()
{
	for (int i = 0; i < 50; i++)
		cout << endl;
}

void Battle(Character *pl, Character *en, string moveName[], int mana[], int dam[], int& lvl)
{
	while (pl->getHP() > 0 && en->getHP() > 0)
	{

		ifstream inEnemy(to_string(lvl) + "Enemy.txt");
		cout << "_________________________\n" << endl;
		if (inEnemy.is_open())
			cout << inEnemy.rdbuf();
		cout << en->getName() << "'s hp:" << en->getHP() << endl;
		cout << "_________________________" << endl;
		pl->setAction(action(pl, mana), moveName, mana, dam);
		en->setAction(en->random(lvl), moveName, mana, dam);
		int a = pl->getHP() - (en->getDamage() - pl->getBlock()*en->getDamage());
		pl->setHP(a);
		int t = en->getHP() - (pl->getDamage() - en->getBlock()*pl->getDamage());
		en->setHP(t);
		pl->recoverMana();
		cout << "_________________________" << endl;
		cout << "\n" << pl->getName() <<" recovers 3 mana" << endl;
	}
}

void story(int& lvl)
{
	int j;
	string a;
	switch (lvl)
	{
	case (1):
	{
		j = 4;
		displayStory(lvl, a, j);
		break;
	}
	case (2):
	{
		j = 2;
		displayStory(lvl, a, j);
		break;
	}
	case (3):
	{
		j = 2;
		displayStory(lvl, a, j);
		break;
	}
	case (4):
	{
		j = 3;
		displayStory(lvl, a, j);
		break;
	}
	}
}

void displayStory(int& lvl, string& a, int& j)
{
	for (int i = 1; i < j + 1; i++)
	{
		clearScreen();
		ifstream inData;
		inData.open("Level_"+ to_string(lvl) + "_" + to_string(i) + ".txt");
		if (inData.is_open())
		{
			cout << inData.rdbuf();
			cout << "\nPress any key to continue: ";
			cin >> a;
		}
	}
}

void How_to_play()
{
	ifstream inData("HowToPlay.txt");
	clearScreen();
	cout << "_________________________\n" << endl;
	if (inData.is_open())
	{
		cout << inData.rdbuf() <<endl;
	}
}

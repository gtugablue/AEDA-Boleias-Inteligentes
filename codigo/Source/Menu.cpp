#include "../headers/Menu.h"

Menu::Menu()
{


}

string Menu::readString()const
{
	string cenas;
	getline(cin, cenas);
	return cenas;

}

int Menu::readDigit()const
{
	int a;

	do
	{
		cin >> a;
		cin.ignore();
	} while (!isdigit(a));
	return a;
}

bool Menu::readYesOrNo()const
{
	char a;

	do
	{
		if (a == 'y')
		{
			return true;
		}
		else
			return false;

	} while (a != 'y' || a != 'n');
}

void Menu::showMenu(vector<string> itens)
{
	for (size_t i = 0; itens.size(); ++i)
	{
		cout << i << ". " << itens[i] << endl;
	}
	return;
}

int Menu::showLoginMenu()
{
	vector<string> itens =
	{
		"Login",
		"Sign up"
	};
	showMenu(itens);
	return readDigit();
}
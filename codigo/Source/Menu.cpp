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
	char c;

	do
	{
		c = _getch();
	} while (!isdigit(c));
	return c - '0';
}

bool Menu::readYesOrNo()const
{
	char c;

	do
	{
		c = _getch();
	} while (c != 'y' && c != 'n');
	return c == 'y';
}

void Menu::showMenu(vector<string> itens)
{
	for (size_t i = 0; i < itens.size(); ++i)
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
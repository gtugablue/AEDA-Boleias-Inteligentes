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

int Menu::readDigit(unsigned from, unsigned to) const
{
	char c;

	do
	{
		c = _getch();
	} while (!isdigit(c) || c < ('0' + from) || c > ('0' + to));
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
	vector<string> items =
	{
		"Login",
		"Sign up"
	};
	showMenu(items);
	return readDigit(0, items.size() - 1);
}
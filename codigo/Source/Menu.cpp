#include "../headers/Menu.h"

Menu::Menu()
{


}

string Menu::readString() const
{
	string cenas;
	getline(cin, cenas);
	return cenas;

}

int Menu::readDigit() const
{
	int a;

	do
	{
		cin >> a;
		cin.ignore();
	} while (!isdigit(a));
	return a;
}

void Menu::showMenu(vector<string> itens)
{
	for (size_t i = 0; itens.size(); ++i)
	{
		cout << i << ". " << itens[i] << endl;
	}
	return;
}
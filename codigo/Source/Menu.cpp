#include "../headers/Menu.h"

Menu::Menu()
{


}

string Menu::readString()
{
	string cenas;
	getline(cin, cenas);
	return cenas;

}

int Menu::readDigit()
{
	int a;

	do
	{
		cin >> a;
		cin.ignore();
	} while (!isdigit(a));
	return a;
}
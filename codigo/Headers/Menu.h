#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "Membro.h"

using namespace std;

class Menu
{
private:
	Membro* utilizador;
public:
	Menu();

	string readString();
	string readPassword();
	char readDigit();

	void showLoginMenu();
};

#endif
#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "Membro.h"
#include <ctype.h>

using namespace std;

class Menu
{
private:
	Membro* utilizador;
public:
	Menu();

	string readString();
	string readPassword();
	int readDigit();

	void showMenu(vector<string> itens);
	int showLoginMenu();
	int showMainMenu();
	int showAnuncios();
	int showVehicles();
	int showVehicleInfo();
};

#endif

#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Membro.h"

using namespace std;

class Menu
{
private:
	Membro* utilizador;
public:
	Menu();

	string readString() const;
	string readPassword() const;
	int readDigit(unsigned from, unsigned to) const;
	bool readYesOrNo() const;

	void showMenu(vector<string> itens);
	int showLoginMenu();
	int showMainMenu();
	int showAnuncios();
	int showVehicles();
	int showVehicleInfo();
};

#endif

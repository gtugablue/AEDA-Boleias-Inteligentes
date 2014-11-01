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

	static string readString() const;
	static string readPassword() const;
	static int readDigit(unsigned from, unsigned to) const;
	static bool readYesOrNo() const;

	static void showString(const string &str);

	void showMenu(vector<string> itens);
	void showLoginMenu();
	int showMainMenu();
	int showAnuncios();
	int showVehicles();
	int showVehicleInfo();
};

#endif

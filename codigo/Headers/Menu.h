#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Membro.h"
#include "BoleiasInteligentes.h"

using namespace std;

class Menu
{
public:
	Menu(BoleiasInteligentes* boleiasInteligentes);

	static string readString();
	static string readPassword();
	static int readDigit(unsigned from, unsigned to);
	static bool readYesOrNo();

	static void showString(const string &str);

	void showMenu(vector<string> itens);
	void showLoginMenu();
	void showMainMenu();
	void showAnuncios();
	void showVehicles();
	void showVehicleInfo();
};

#endif

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
private:
	Membro* utilizador;
public:
	Menu();

	static string readString();
	static string readPassword();
	static int readDigit(unsigned from, unsigned to);
	static bool readYesOrNo();

	static void showString(const string &str);

	void showMenu(vector<string> itens);
	void showLoginMenu();
	int showMainMenu();
	int showAnuncios();
	int showVehicles();
	int showVehicleInfo();
};

#endif

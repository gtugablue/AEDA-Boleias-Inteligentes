#include <iostream>
#include "../headers/Menu.h"
#include "../headers/BoleiasInteligentes.h"

using namespace std;

int main()
{
	BoleiasInteligentes boleiasInteligentes("/data/");
	Menu menu(&boleiasInteligentes);
	menu.showLoginMenu();
	return 0;
}

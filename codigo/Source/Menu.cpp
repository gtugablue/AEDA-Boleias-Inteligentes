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

string Menu::readPassword() const
{
	string password;
	char c;
	while ((c = _getch()) != '\n')
	{
		if (c = '\b')
		{
			cout << '\b' << '\b';
		}
		else
		{
			password += _getch();
			cout << '*';
		}
	}
	return password;
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

void Menu::showLoginMenu()
{
	vector<string> items =
	{
		"Login",
		"Sign up"
	};
	showMenu(items);
	int n = readDigit(0, items.size() - 1);

	switch (n)
	{
	case 0:	// Login
	{
		cout << "Username: ";
		string username = readString();
		cout << endl;
		cout << "Password: ";
		string password = readPassword();
		cout << endl;
		utilizador = login(username, password);
		return;
	}
	case 1:	// Sign up
	{
		cout << "Empresa? (y/n)";
		bool empresa = readYesOrNo();
	}
	default: // ERRO
	}
}
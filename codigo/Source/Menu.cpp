#include "../headers/Menu.h"

Menu::Menu(BoleiasInteligentes* boleiasInteligentes):
boleiasInteligentes(boleiasInteligentes)
{
}

string Menu::readString()
{
	string cenas;
	getline(cin, cenas);
	return cenas;

}

string Menu::readPassword()
{
	string password;
	char c;
	while ((c = _getch()) != '\r')
	{
		if (c == '\b')
		{
			cout << '\b' << '\b';
		}
		else
		{
			password += c;
			cout << '*';
		}
	}
	return password;
}

int Menu::readDigit(unsigned from, unsigned to)
{
	unsigned char c;

	do
	{
		c = _getch();
	} while (!isdigit(c) || c < ('0' + from) || c >('0' + to));
	return c - '0';
}

bool Menu::readYesOrNo()
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
		cout << "Password: ";
		string password = readPassword();
		cout << endl;
		try
		{
			utilizador = boleiasInteligentes->login(username, password);
			showMainMenu();
		}
		catch (LoginException<string> e)
		{
			cout << e.info << endl;
			return showLoginMenu();
		}
		return;
	}
	case 1:	// Sign up
	{
		cout << "Empresa? (y/n)";
		bool empresa = readYesOrNo();
		cout << endl;
		cout << "Nome: ";
		string nome = readString();
		cout << "Password: ";
		string password = readPassword();
		cout << endl;
		if (empresa)
		{
			cout << "Website (deixe em branco se nao existir): ";
			string website = readString();
		}
		else
		{
			// TODO
		}
		return;

	}
	default: // ERRO
		return;
	}
}

void Menu::showMainMenu()
{
	vector<string> items =
	{
		"Editar conta",
		"Anuncios",
		"Veiculos",
		"Logout"
	};
	showMenu(items);
	int n = readDigit(0, items.size() - 1);
	// TODO
	return;
}
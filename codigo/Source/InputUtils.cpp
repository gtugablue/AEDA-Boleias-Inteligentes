#include "../Headers/InputUtils.h"

string InputUtils::readLine()
{
	string cenas;
	getline(cin, cenas);
	return cenas;
}

int InputUtils::readInt()
{
	int n;
	cin >> n;
	if (!(cin >> n))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		throw InvalidInputException<string>("Insira um inteiro");
	}
	return n;
}

double InputUtils::readDouble()
{
	int n;
	cin >> n;
	if (!(cin >> n))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		throw InvalidInputException<string>("Insira um numero decimal");
	}
	return n;
}

string InputUtils::readPassword()
{
	string password;
	char c;
	while ((c = _getch()) != '\r')
	{
		if (c == '\b')
		{
			if (password.size() > 0)
			{
				password.pop_back();
				cout << "\b \b";
			}
		}
		else
		{
			password += c;
			cout << '*';
		}
	}
	return password;
}

int InputUtils::readDigit(unsigned from, unsigned to)
{
	unsigned char c;

	do
	{
		c = _getch();
	} while (!isdigit(c) || c < ('0' + from) || c >('0' + to));
	return c - '0';
}

bool InputUtils::readYesOrNo(unsigned char yes, unsigned char no)
{
	char c;

	do
	{
		c = _getch();
	} while (c != yes && c != no);
	return c == yes;
}

void InputUtils::pause()
{
	system("pause");
}
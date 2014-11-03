#include "../Headers/InputUtils.h"

string InputUtils::readString()
{
	string cenas;
	getline(cin, cenas);
	return cenas;
}

string InputUtils::readPassword()
{
	string password;
	char c;
	while ((c = _getch()) != '\r')
	{
		if (c == '\b')
		{
			password.pop_back();
			cout << "\b \b";
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
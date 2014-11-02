#include "../Headers/empresa.h"

Empresa::Empresa()
{
	
}

Empresa::Empresa(const string &nome, const string &utilizador, const string &password, const string &website):
Membro(nome, utilizador, password)
{
	this->website = website;
}

void Empresa::signup()
{
	Membro::signup();
	cout << "Website (deixe em branco se nao existir): ";
	website = InputUtils::readString();
}

void Empresa::edit()
{
	Membro::edit();
	cout << "Pretende alterar o website (y/n)?" << endl;
	if (InputUtils::readYesOrNo())
	{
		cout << "Introduza o novo website: ";
		getline(cin, website);
	}
}
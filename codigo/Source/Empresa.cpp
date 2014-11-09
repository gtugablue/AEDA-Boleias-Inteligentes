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
	cout << "Website (deixe em branco se nao existir): ";
	website = InputUtils::readLine();
}

void Empresa::edit()
{
	Membro::edit();
	cout << "Pretende alterar o website (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza o novo website: ";
		getline(cin, website);
	}
}

void Empresa::save(ofstream &file, vector<Combustivel> *combustiveis)
{
	file << 1 << endl;
	Membro::save(file, combustiveis);
}

void Empresa::show() const
{
	Membro::show();
	cout << "Website: " << website << endl;
}
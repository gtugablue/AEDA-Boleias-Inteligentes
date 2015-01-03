#include "../Headers/empresa.h"

Empresa::Empresa():
motoristas(Motorista("", Coordenadas(0, 0), Coordenadas(0, 0)))
{
	
}

Empresa::Empresa(const string &nome, const string &utilizador, const string &password, const string &website):
Membro(nome, utilizador, password), motoristas(Motorista("", Coordenadas(0, 0), Coordenadas(0, 0)))
{
	this->website = website;
}

Coordenadas Empresa::getMorada() const
{
	return garagem;
}

const BST<Motorista> &Empresa::getMotoristas() const
{
	return motoristas;
}

void Empresa::addMotorista(const Motorista &motorista)
{
	motoristas.insert(motorista);
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
	file << website << endl;
	garagem.save(file);
}

void Empresa::load(ifstream &file, vector<Combustivel> *combustiveis)
{
	Membro::load(file, combustiveis);
	garagem.load(file);
}

void Empresa::show() const
{
	Membro::show();

	cout << "Website: " << website << endl;

	cout << "Garagem: " << endl;
	garagem.show();

}

void Empresa::insertOld(ClientesAntigos &c1)
{
	clientes.insert(c1);

}


void Empresa::removeOld(const ClientesAntigos &c1)
{
	const string x = c1.getutilizador();
	unordered_set<ClientesAntigos,hstr,eqstr>::iterator it;

	for (it = clientes.begin(); it != clientes.end(); it++)
	{
		if (it->getutilizador() == x)
		{
			clientes.erase(it);
		}

	}
}



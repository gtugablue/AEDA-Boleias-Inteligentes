#include "../headers/Membro.h"

Membro::Membro()
{

}

Membro::Membro(string nome, string utilizador, string password)
{
	this->nome = nome;
	this->utilizador = utilizador;
	this->password = password;
}

string Membro::getNome()const
{
	return nome;
}

string Membro::getUtilizador()const
{
	return utilizador;
}

vector<Veiculo *> Membro::getVeiculos()
{
	vector<Veiculo *> veiculosPtr;
	for (size_t i = 0; i < veiculos.size(); ++i)
	{
		veiculosPtr.push_back(&veiculos[i]);
	}
	return veiculosPtr;
}

string Membro::getPassword()const
{
	return password;
}

void Membro::setNome(string &nome)
{
	this->nome = nome;
}

void Membro::setPassword(string &password)
{
	this->password = password;
}

void Membro::setUtilizador(string &utilizador)
{
	this->utilizador = utilizador;
}

void Membro::addVeiculo(Veiculo veiculo)
{
	veiculos.push_back(veiculo);
}

void Membro::removeVeiculo(Veiculo* veiculo)
{
	// TODO
}

bool Membro::operator==(const Membro &membro1) const
{
	return utilizador == membro1.utilizador;
}

void Membro::edit()
{
	cout << "Pretende alterar o nome (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza o novo nome: ";
		getline(cin, nome);
	}
	cout << "Pretende alterar a password (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza a nova password: ";
		getline(cin, password);
	}
}

void Membro::load(ifstream &file, vector<Combustivel> *combustiveis)
{
	unsigned numVeiculos;
	getline(file, nome);
	getline(file, utilizador);
	getline(file, password);
	file >> numVeiculos;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < numVeiculos; ++i)
	{
		Veiculo veiculo;
		veiculo.load(file, combustiveis);
		veiculos.push_back(veiculo);
	}
}

void Membro::save(ofstream &file, vector<Combustivel> *combustiveis)
{
	file << nome << endl;
	file << utilizador << endl;
	file << password << endl;
	file << veiculos.size() << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		veiculos[i].save(file, combustiveis);
	}
}

void Membro::show()
{
	cout << "Nome: " << nome << endl;
	cout << "Utilizador: " << utilizador << endl;
}

bool Membro::temVeiculo() const
{
	return veiculos.size() > 0;
}
#include "../headers/Membro.h"

Membro::Membro()
{

}

Membro::Membro(string nome, string utilizador, string password)
{
	this ->nome=nome;
	this->utilizador=utilizador;
	this ->password=password;
}

string Membro::getNome()const
{
	return nome;
}

string Membro::getUtilizador()const
{
	return utilizador;
}

string Membro::getPassword()const
{
	return password;
}

void Membro::setNome(string &nome)
{
	this->nome=nome;
}

void Membro::setPassword(string &password)
{
	this->password=password;
}

void Membro::setUtilizador(string &utilizador)
{
	this ->utilizador=utilizador;
}

void Membro::addveiculo(Veiculo v)
{
	veiculos.push_back(v);
}

bool Membro::operator==(const Membro &membro1) const
{
	return utilizador == membro1.utilizador;
}

void Membro::signup()
{
	cout << "Nome: ";
	nome = InputUtils::readString();
	cout << "Username: ";
	utilizador = InputUtils::readString();
	cout << "Password: ";
	password = InputUtils::readPassword();
	cout << endl;
}

void Membro::load()
{
	Veiculo veiculo;
	int N;
	int i = 0;
	fstream file;
	float preco;
	string filename, nome, utilizador, password, marca, name;
	unsigned mes, ano, cilindrada;
	while (!file.eof())
	{
		getline(file, nome);
		getline(file, utilizador);
		getline(file, password);

		file >> N;
		cin.ignore(1000, '\n');
		for (size_t i = 0; i < N; ++i)
		{
			veiculo.load();
			veiculos.push_back(veiculo);

		}

	}

}
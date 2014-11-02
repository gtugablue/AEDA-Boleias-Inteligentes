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

void Membro::edit()
{
	cout << "Pretende alterar o nome (y/n)?" << endl;
	if (InputUtils::readYesOrNo())
	{
		cout << "Introduza o novo nome: ";
		getline(cin, nome);
	}
	cout << "Pretende alterar a password (y/n)?" << endl;
	if (InputUtils::readYesOrNo())
	{
		cout << "Introduza a nova password: ";
		getline(cin, password);
	}
}

void Membro::load()
{
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
			Veiculo veiculo;
			veiculo.load();
			veiculos.push_back(veiculo);

		}

	}

}

void Membro::save(const string &filename)
{
	fstream file;
	file.open(filename);
	file << getNome() << endl;
	file << getUtilizador() << endl;
	file << getPassword() << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		file << veiculos.at(i).getMarca() << endl;
		file << veiculos.at(i).getMes() << endl;
		file << veiculos.at(i).getAno() << endl;
		file << veiculos.at(i).getCilindrada() << endl;
		file << veiculos.at(i).getCombustivel() << endl;
	}
}
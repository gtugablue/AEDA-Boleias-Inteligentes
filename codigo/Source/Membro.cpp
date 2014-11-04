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

vector<Veiculo> Membro::getVeiculos()const
{
	return veiculos;
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

void Membro::load(ifstream &file)
{
	int N;
	int i = 0;
	unsigned mes, ano, cilindrada;
	cout << "b";
	while (getline(file, nome))
	{
		getline(file, utilizador);
		getline(file, password);
		file >> N;
		file.ignore(1000, '\n');
		for (size_t i = 0; i < N; ++i)
		{
			Veiculo veiculo;
			veiculo.load();
			veiculos.push_back(veiculo);
		}
	}
	file.close();
}

void Membro::save(const string &ficheiro)
{
	fstream file;
	file.open(ficheiro);
	file << getNome() << endl;
	file << getUtilizador() << endl;
	file << getPassword() << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		file << veiculos.at(i).getMarca() << endl;
		file << veiculos.at(i).getMes() << endl;
		file << veiculos.at(i).getAno() << endl;
		file << veiculos.at(i).getCilindrada() << endl;
		file << veiculos.at(i).getCombustivel()->getNome() << endl;
		file << veiculos.at(i).getCombustivel()->getPreco() << endl;
	}
	file.close();
}

void Membro::show()
{
	cout << "Nome: " << nome << endl;
	cout << "Utilizador: " << utilizador << endl;
}

void Membro::criar()
{
	string name, utiliz, passw;
	cout << "Introduza o nome do Membro" << endl;
	getline(cin, nome);
	cout << "Introduz o utilizador" << endl;
	getline(cin, utiliz);
	cout << "Introduz a password" << endl;
	getline(cin, passw);

}
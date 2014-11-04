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
	string utilizador2;
	cout << "Nome: ";
	nome = InputUtils::readString();
	while (1)
	{
		try
		{
			cout << "Username: ";
			getline(cin, utilizador2);
			if (utilizador2 == utilizador)
			{
				throw InvalidUtilizador<string>("Utilizador já exitente");
			}
			else
				utilizador = InputUtils::readString();
		}
			catch (InvalidUtilizador<string>e)
			{
				cout << "Erro: " << e.info << endl << endl;
			}
		}
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
	unsigned numVeiculos;
	while (getline(file, nome))
	{
		getline(file, utilizador);
		getline(file, password);
		file >> numVeiculos;
		file.ignore(1000, '\n');
		for (size_t i = 0; i < numVeiculos; ++i)
		{
			Veiculo veiculo;
			veiculo.load();
			veiculos.push_back(veiculo);
		}
	}
	file.close();
}

void Membro::save(ofstream &file)
{
	file << nome << endl;
	file << getUtilizador() << endl;
	file << getPassword() << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		// TODO
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
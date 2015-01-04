#include "../headers/Particular.h"

Particular::Particular()
{

}

Particular::Particular(string nome, string utilizador, string password) :Membro(nome,utilizador,password)
{

}

void Particular::setMorada(const Coordenadas &morada)
{
	this->morada = morada;
}

vector<pair<Membro*, unsigned>> Particular::getConhecidos() const
{
	return conhecidos;
}

Coordenadas Particular::getMorada() const
{
	return morada;
}

void Particular::show()
{
	Membro::show();

	cout << "Morada: " << endl;
	morada.show();

	cout << endl << "Veiculos: " << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		veiculos[i]->show();
		cout << endl;
	}
}

void Particular::signup()
{
}

void Particular::edit()
{
	Membro::edit();
	cout << "Pretende alterar a morada (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza a nova morada: ";
		getline(cin, nome);
	}
}

void Particular::save(ofstream &file, vector<Combustivel> *combustiveis)
{
	file << 0 << endl;
	Membro::save(file, combustiveis);
	morada.save(file);
}

void Particular::load(ifstream &file, vector<Combustivel> *combustiveis)
{
	Membro::load(file, combustiveis);
	morada.load(file);
}

void Particular::updateConhecidos(vector<Membro *> passageiros)
{
	for (size_t i = 0; i < passageiros.size(); ++i)
	{
		if (passageiros[i] == this)
		{
			continue;
		}
		int found = -1;
		for (size_t found = 0; found < conhecidos.size(); found++)
		{
			if (conhecidos[found].first == passageiros[i])
			{
				found = true;
				break;
			}
		}
		if (found == -1)
		{
			conhecidos.push_back(make_pair(passageiros[i], 0));
		}
		else
		{
			conhecidos[found].first++;
		}
	}
}

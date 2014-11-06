#include "../headers/Particular.h"

Particular::Particular()
{

}

Particular::Particular(string nome, string utilizador, string password) :Membro(nome,utilizador,password)
{

}

void Particular::show()
{
	cout << "Nome: " << nome << endl;
	cout << "Utilizador: " << utilizador << endl;
	cout << endl << "Veiculos: " << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		veiculos[i].show();
		cout << endl;
	}
}

void Particular::signup()
{
}

void Particular::save(ofstream &file, vector<Combustivel> *combustiveis)
{
	file << 0 << endl;
	Membro::save(file, combustiveis);
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
#include "../headers/Particular.h"

Particular::Particular()
{

}

Particular::Particular(string nome, string utilizador, string password) :Membro(nome,utilizador,password)
{

}

void Particular::showparticulares()
{
	cout << "Particular " << endl;
	cout << endl;
	cout << "Nome :" << nome << endl;
	cout << "Utilizador" << utilizador << endl;
	cout << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		veiculos.at(i).showVeiculo();
	}
}
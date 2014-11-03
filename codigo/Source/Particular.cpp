#include "../headers/Particular.h"

Particular::Particular()
{

}

Particular::Particular(string nome, string utilizador, string password) :Membro(nome,utilizador,password)
{

}

void Particular::show()
{
	cout << "Particular " << endl;
	cout << endl;
	cout << "Nome :" << nome << endl;
	cout << "Utilizador" << utilizador << endl;
	cout << endl << "Veiculos: " << endl;
	for (size_t i = 0; i < veiculos.size(); i++)
	{
		veiculos[i].show();
		cout << endl;
	}
}

void Particular::signup()
{
	Membro::signup();
}
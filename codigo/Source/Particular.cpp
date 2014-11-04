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
	cout << "Data de nascimento: " << dataNascimento << endl;
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

void Particular::save(ofstream &file)
{
	file << 0 << endl;
	Membro::save(file);
}
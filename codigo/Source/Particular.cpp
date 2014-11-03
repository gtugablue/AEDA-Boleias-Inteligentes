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
	cout << "Nome :" << getNome() << endl;
	cout << "Utilizador" << getUtilizador() << endl;
	
}
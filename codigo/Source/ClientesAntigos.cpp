#include "../Headers/ClientesAntigos.h"

string ClientesAntigos::getutilizador()const
{
	return cliente->getUtilizador();
}

void ClientesAntigos::showOne()const
{
	cout << "Nome :" << cliente->getNome() << endl;
	cout << "Utilizador :" << cliente->getUtilizador() << endl;
	cout << "Contacto :" << cliente->getContacto() << endl;
	cout << "Morada :" << endl;
	cliente->getMorada().show();
}



void ClientesAntigos::setutilizador(string &nome)
{
	cliente->setUtilizador(nome);
}

void ClientesAntigos::setnome(string &nome)
{
	cliente->setNome(nome);
}

void ClientesAntigos::setcontacto(string &contacto)
{
	cliente->setcontacto(contacto);
}

Particular* ClientesAntigos::getcliente()
{
	return cliente;
}
#include "../Headers/ClientesAntigos.h"

ClientesAntigos::ClientesAntigos(string utilizador, string contacto, string morada)
{
	this->utilizador = utilizador;
	this->contacto = contacto;
	this->morada = morada;



}
ClientesAntigos::ClientesAntigos()
{

}

void ClientesAntigos::showOne()const
{
	cout << "Informacao sobre o cliente" << endl;
	cout << "Utilizador :" << utilizador << endl;
	cout << "Contacto :" << contacto << endl;
	cout << "Morada :" << morada << endl;
	
}



void ClientesAntigos::setutilizador(string &utilizador)
{
	this->utilizador = utilizador;
}

void ClientesAntigos::setmorada(string &morada)
{
	this->morada = morada;
}

void ClientesAntigos::setcontacto(string &contacto)
{
	this->contacto = contacto;
}

string ClientesAntigos::getutilizador()const
{
	return utilizador;
}

void ClientesAntigos::loadClientes(ifstream &file)
{
	unsigned numBoleias;
	string nome, destino;
	getline(file, utilizador);
	getline(file, contacto);
	getline(file, morada);
	cout << utilizador;

	cout << contacto;
	
	cout << morada;
	
	file >> numBoleias;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < numBoleias; i++)
	{
		getline(file, nome);
		getline(file, destino);
		Boleias y = Boleias(nome, destino);
		registos.push_back(y);

	}

}

void ClientesAntigos::saveClientes(ofstream &file)const
{
	file << utilizador << endl;
	file << contacto << endl;
	file << morada << endl;
	file << registos.size() << endl;
	for (size_t i = 0; i < registos.size(); i++)
	{
		file << registos[i].getNome() << endl;
		file << registos[i].getDestino() << endl;

	}

}


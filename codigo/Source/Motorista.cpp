#include "../headers/Motorista.h"

using namespace std;

Motorista::Motorista()
{

}

Motorista::Motorista(const string &nome, const Coordenadas &morada, const Coordenadas &garagem) :
nome(nome), morada(morada), distancia(morada.calcDistancia(garagem))
{

}

void Motorista::setNome(const string &nome)
{
	this->nome = nome;
}

void Motorista::setMorada(const Coordenadas &morada)
{
	this->morada = morada;
}

string Motorista::getNome() const
{
	return nome;
}

Coordenadas Motorista::getMorada() const
{
	return morada;
}

void Motorista::criar(const Coordenadas &garagem)
{
	cout << "Introduza o nome: ";
	getline(cin, nome);
	cout << "Morada: " << endl;
	morada.criar();
}

void Motorista::editar(const Coordenadas &garagem)
{
	
}

void Motorista::updateDistancia(const Coordenadas &garagem)
{
	distancia = morada.calcDistancia(garagem);
}

bool Motorista::operator<(const Motorista &motorista) const
{
	if (distancia == motorista.distancia)
	{
		return nome > motorista.nome;
	}
	else
	{
		return distancia > motorista.distancia;
	}
}
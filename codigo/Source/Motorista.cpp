#include "../headers/Motorista.h"

using namespace std;

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

void Motorista::updateDistancia(const Coordenadas &garagem)
{
	distancia = morada.calcDistancia(garagem);
}

bool Motorista::operator<(const Motorista &motorista) const
{
	// TODO
	return true;
}
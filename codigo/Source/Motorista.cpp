#include "../headers/Motorista.h"

using namespace std;

Motorista::Motorista(const string &nome, const Coordenadas &morada) :
nome(nome), morada(morada)
{

}

bool Motorista::operator<(const Motorista &motorista) const
{
	// TODO
	return true;
}
#ifndef _MOTORISTA_H
#define _MOTORISTA_H

#include <string>
#include "Coordenadas.h"

class Motorista
{
private:
	std::string nome;
	Coordenadas morada;
public:
	Motorista(const std::string &nome, const Coordenadas &morada);
	std::string getNome() const;
	Coordenadas getMorada() const;
	bool operator<(const Motorista &motorista) const;
};

#endif
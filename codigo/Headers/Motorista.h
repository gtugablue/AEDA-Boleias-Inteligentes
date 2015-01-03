#ifndef _MOTORISTA_H
#define _MOTORISTA_H

#include <string>
#include "Coordenadas.h"

using namespace std;

class Motorista
{
private:
	string nome;
	Coordenadas morada;
public:
	string getNome() const;
	Coordenadas getMorada() const;
};

#endif
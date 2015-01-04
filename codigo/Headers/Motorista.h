#ifndef _MOTORISTA_H
#define _MOTORISTA_H

#include <string>
#include <iostream>
#include "Coordenadas.h"

class Motorista
{
private:
	std::string nome;
	Coordenadas morada;
	double distancia;
public:
	Motorista();
	Motorista(const std::string &nome, const Coordenadas &morada, const Coordenadas &garagem);
	void setNome(const std::string &nome);
	void setMorada(const Coordenadas &morada);
	std::string getNome() const;
	Coordenadas getMorada() const;
	double getDistancia() const;
	void criar(const Coordenadas &garagem);
	void editar(const Coordenadas &garagem);
	void updateDistancia(const Coordenadas &garagem);
	bool operator<(const Motorista &motorista) const;
	bool operator==(const Motorista &motorista) const;
	friend ostream &operator<<(ostream &os, const Motorista &motorista);
};

ostream &operator<<(ostream &os, const Motorista &motorista);

#endif
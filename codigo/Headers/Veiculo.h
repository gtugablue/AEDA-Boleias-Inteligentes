#ifndef _VEICULO_H
#define _VEICULO_H

#include <string>
#include "Combustivel.h"

using namespace std;

class Veiculo
{
private:
	string marca;
	unsigned mes;
	unsigned ano;
	unsigned cilindrada;
	Combustivel* combustivel;
public:
	Veiculo();
	Veiculo(string marca, unsigned mes, unsigned ano, unsigned cilindrada, Combustivel* combustivel);
	string getMarca() const;
	unsigned getMes() const;
	unsigned getAno() const;
	unsigned getCilindrada() const;
	Combustivel* getCombustivel() const;
	void setMarca(string &marca);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
	void setCilindrada(unsigned cilindrada);
	void setCombustivel(Combustivel* combustivel);
};

#endif

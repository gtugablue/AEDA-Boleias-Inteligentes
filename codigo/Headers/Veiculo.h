#ifndef _VEICULO_H
#define _VEICULO_H

#include <string>
#include "Combustivel.h"
#include <iostream>
#include<fstream>

using namespace std;

class Veiculo
{
private:
	string marca;
	unsigned mes;
	unsigned ano;
	unsigned cilindrada;
	Combustivel* combustivel;
	unsigned int lotacao;
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
	void load();
	void setCombustivel(Combustivel* combustivel);
	void showVeiculo();
	void criar();
};

#endif

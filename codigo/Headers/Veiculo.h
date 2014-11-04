#ifndef _VEICULO_H
#define _VEICULO_H

#include <string>
#include "Combustivel.h"
#include <iostream>
#include <fstream>
#include "Data.h"
#include <vector>

#include "InputUtils.h"

using namespace std;

class Veiculo
{
private:
	string marca;
	string modelo;
	unsigned mes;
	unsigned ano;
	unsigned cilindrada;
	Combustivel *combustivel;
	unsigned int lotacao;
public:
	Veiculo();
	Veiculo(string marca, unsigned mes, unsigned ano, unsigned cilindrada, Combustivel* combustivel);
	string getMarca() const;
	unsigned getMes() const;
	unsigned getAno() const;
	unsigned getCilindrada() const;
	void setMarca(string &marca);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
	void setCilindrada(unsigned cilindrada);
	void load(ifstream &file); // TODO
	void save(ofstream &file);
	void setCombustivel(Combustivel *combustivel);
	void escolherCombustivel();
	void show() const;
	void criar();
	void editar();

	friend ostream& operator<<(ostream &os, const Veiculo &veiculo);
};

#endif

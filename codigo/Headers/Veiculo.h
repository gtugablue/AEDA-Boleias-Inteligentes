#ifndef _VEICULO_H
#define _VEICULO_H

#include <string>
#include "Combustivel.h"
#include <iostream>
#include <fstream>
#include "Data.h"
#include <vector>
#include "OutputUtils.h"
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
	float consumo; // l/100km
public:
	Veiculo();
	string getMarca() const;
	string getModelo() const;
	unsigned getLotacao() const;
	unsigned getMes() const;
	unsigned getAno() const;
	unsigned getCilindrada() const;
	float getConsumo() const;
	Combustivel *getCombustivel();
	void setMarca(string &marca);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
	void setCilindrada(unsigned cilindrada);
	void load(ifstream &file, vector<Combustivel> *combustiveis);
	void save(ofstream &file, vector<Combustivel> *combustiveis);
	void setCombustivel(Combustivel *combustivel);
	Combustivel* escolherCombustivel(vector<Combustivel> *combustiveis);
	void show() const;
	void criar(vector<Combustivel> *combustiveis);
	void editar();
	friend ostream& operator<<(ostream &os, const Veiculo &veiculo);
	friend ostream& operator<<(ostream &os, Veiculo *veiculo);
};

#endif

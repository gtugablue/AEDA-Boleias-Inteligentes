#ifndef _MEMBRO_H
#define _MEMBRO_H

#include <string>
#include <vector>
#include "Veiculo.h"
#include <iostream>
#include <fstream>
#include "InputUtils.h"

using namespace std;

class Membro
{
protected:
	string nome;
	string utilizador;
	string password;
	vector<Veiculo> veiculos;
public:
	Membro();
	Membro(string nome, string utilizador, string password);
	string getNome() const;
	string getUtilizador() const;
	string getPassword() const;
	vector<Veiculo *> getVeiculos();
	void setNome(string &nome) ;
	void setUtilizador(string &utilizador);
	void setPassword(string &password);
	void setVeiculos(const vector<Veiculo> &veiculo);
	void addVeiculo(Veiculo veiculo);
	void removeVeiculo(Veiculo* veiculo);
	void load(ifstream &file, vector<Combustivel> *combustiveis);
	virtual void save(ofstream &file, vector<Combustivel> *combustiveis);
	virtual void signup() = 0;
	virtual void edit();
	void show();
	
	bool operator==(const Membro &membro1) const;
};

template<class T>
class UtilizadorRepetidoException
{
public:
	T info;
	UtilizadorRepetidoException(T info)
	{
		this->info = info;
	}
};

#endif

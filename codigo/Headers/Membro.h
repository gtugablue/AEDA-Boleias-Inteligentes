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
	vector<Veiculo> getVeiculos()const;
	void setNome(string &nome) ;
	void setUtilizador(string &utilizador);
	void setPassword(string &password);
	void setVeiculos(const vector<Veiculo> &veiculo);
	void addVeiculo(Veiculo veiculo);
	void removeVeiculo(Veiculo* veiculo);
	void load(ifstream &file);
	void save(const string &ficheiro);
	virtual void signup();
	virtual void edit();
	void show();
	void criar();

	bool operator==(const Membro &membro1) const;
};

#endif

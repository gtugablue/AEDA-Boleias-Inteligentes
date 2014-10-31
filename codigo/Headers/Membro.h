#ifndef _MEMBRO_H
#define _MEMBRO_H

#include <string>
#include <vector>
#include "Veiculo.h"

using namespace std;

class Membro
{
protected:
	string nome;
	string utilizador;
	string password;
	vector<Veiculo> veiculos;
public:
	Membro(string nome, string utilizador, string password);
	string getNome() const;
	string getUtilizador() const;
	string getPassword() const;
	void setNome(string &nome) ;
	void setUtilizador(string &utilizador);
	void setPassword(string &password);
	void setVeiculos(const vector<Veiculo> &veiculo);
};

#endif

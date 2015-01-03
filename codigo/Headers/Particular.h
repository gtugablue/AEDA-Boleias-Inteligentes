#ifndef _PARTICULAR_H
#define _PARTICULAR_H

#include "Membro.h"
#include "Data.h"
#include "Veiculo.h"
#include <vector>

using namespace std;

class Particular : public Membro  ///Classe derivada da classe m�e membro
{
private:
	Coordenadas morada;
	vector<pair<Membro *, unsigned>> conhecidos;
public:
	Particular();///Construtor por defeito da classe
	Particular(string nome, string utilizador, string password);///Construtor com par�metros da classe
	vector<pair<Membro*, unsigned>> getConhecidos() const;
	void show();///Fun��o que imprime no ecr� a informa��o de um particular
	void signup();///Fun��o que permite a um particular criar conta na API
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Fun��o que grava a informa��o de um particular no ficheiro respectivo
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Fun��o que carrega a informa��o de um particular do ficheiro para o programa
	void updateConhecidos(vector<Membro *> passageiros);///Fun��o que permite editar os cada conhecido desse mesmo particular
};

#endif

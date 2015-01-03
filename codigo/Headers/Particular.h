#ifndef _PARTICULAR_H
#define _PARTICULAR_H

#include "Membro.h"
#include "Data.h"
#include "Veiculo.h"
#include <vector>

using namespace std;

class Particular : public Membro  ///Classe derivada da classe mãe membro
{
private:
	Coordenadas morada;
	vector<pair<Membro *, unsigned>> conhecidos;
public:
	Particular();///Construtor por defeito da classe
	Particular(string nome, string utilizador, string password);///Construtor com parâmetros da classe
	vector<pair<Membro*, unsigned>> getConhecidos() const;
	void show();///Função que imprime no ecrã a informação de um particular
	void signup();///Função que permite a um particular criar conta na API
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Função que grava a informação de um particular no ficheiro respectivo
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Função que carrega a informação de um particular do ficheiro para o programa
	void updateConhecidos(vector<Membro *> passageiros);///Função que permite editar os cada conhecido desse mesmo particular
};

#endif

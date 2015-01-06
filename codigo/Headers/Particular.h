#ifndef _PARTICULAR_H
#define _PARTICULAR_H

#include "Membro.h"
#include "Data.h"
#include "Veiculo.h"
#include "Coordenadas.h"
#include <vector>
#include <queue>

using namespace std;

class Particular : public Membro  ///Classe derivada da classe mãe membro
{
private:
	Coordenadas morada;
	vector<pair<Membro *, unsigned>> conhecidos;
public:
	Particular();///Construtor por defeito da classe
	Particular(string nome, string utilizador, string password);///Construtor com parâmetros da classe
	void setMorada(const Coordenadas &morada);///Método para alterar a morada de um particular
	Coordenadas getMorada() const; // Função para retornar a morada
	vector<pair<Membro*, unsigned>> getConhecidos() const;
	void show();///Função que imprime no ecrã a informação de um particular
	void signup();///Função que permite a um particular criar conta na API
	void edit();///Função que permite editar a informação de um particular
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Função que grava a informação de um particular no ficheiro respectivo
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Função que carrega a informação de um particular do ficheiro para o programa
	void updateConhecidos(vector<Membro *> passageiros);///Função que permite editar os cada conhecido desse mesmo particular
	bool operator<(const Particular &particular) const;
};

class ParticularPtr
{
private:
	Particular *particular;
public:
	ParticularPtr(Particular *particular) : particular(particular) { }
	Particular operator*() { return *particular; }
	bool operator<(const ParticularPtr &particularPtr) const { return *particular < *(particularPtr.particular); }
};

#endif

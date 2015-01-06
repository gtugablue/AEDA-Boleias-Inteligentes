#ifndef _PARTICULAR_H
#define _PARTICULAR_H

#include "Membro.h"
#include "Data.h"
#include "Veiculo.h"
#include "Coordenadas.h"
#include <vector>
#include <queue>

using namespace std;

class Particular : public Membro  ///Classe derivada da classe m�e membro
{
private:
	Coordenadas morada;
	vector<pair<Membro *, unsigned>> conhecidos;
public:
	Particular();///Construtor por defeito da classe
	Particular(string nome, string utilizador, string password);///Construtor com par�metros da classe
	void setMorada(const Coordenadas &morada);///M�todo para alterar a morada de um particular
	Coordenadas getMorada() const; // Fun��o para retornar a morada
	vector<pair<Membro*, unsigned>> getConhecidos() const;
	void show();///Fun��o que imprime no ecr� a informa��o de um particular
	void signup();///Fun��o que permite a um particular criar conta na API
	void edit();///Fun��o que permite editar a informa��o de um particular
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Fun��o que grava a informa��o de um particular no ficheiro respectivo
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Fun��o que carrega a informa��o de um particular do ficheiro para o programa
	void updateConhecidos(vector<Membro *> passageiros);///Fun��o que permite editar os cada conhecido desse mesmo particular
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

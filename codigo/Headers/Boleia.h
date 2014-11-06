#ifndef _VIAGEM_H
#define _VIAGEM_H

#include "Coordenadas.h"
#include "Veiculo.h"
#include "Particular.h"
#include "Data.h"
#include "Membro.h"
#include "Hora.h"
#include "Preco.h"

using namespace std;

class Boleia
{
private:
	string titulo;
	string descricao;
	Coordenadas origem;
	Coordenadas destino;
	Preco preco;
	vector<Particular*> passageiros; // N�mero total de pessoas no ve�culo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; // se for igual ao inicio � um evento
	Membro* condutor;
	Veiculo* veiculo;
	Hora hora;

public:
	Boleia();
	Boleia(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Preco &preco, const vector<Particular*> &passageiros, const Data &dataInicio, const Data &dataFim, Membro *condutor, Veiculo *veiculo, const Hora &hora);
	Membro* getCondutor() const;
	Veiculo* getVeiculo() const;
	vector<Particular *> getPassageiros() const;
	void setCondutor(Membro* condutor);
	void setVeiculo(Veiculo* veiculo);
	void adicionarPassageiro(Particular* passageiro);
	void removerPassageiro(Particular* passageiro);
	bool isMembroInBoleia(Membro* membro) const;
	void show();
	void load(ifstream &file, vector<Membro *> *membros);
	void save(ofstream &file, vector<Membro *> *membros);
	friend ostream& operator<<(ostream& os, Boleia* boleia);
};

#endif
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
	vector<Particular*> passageiros; /// N�mero total de pessoas no ve�culo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; /// se for igual ao inicio � um evento
	Membro* condutor;
	Veiculo* veiculo;
	Hora hora;

public:
	Boleia();///Construtor por defeito
	Boleia(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Preco &preco, const vector<Particular*> &passageiros, const Data &dataInicio, const Data &dataFim, Membro *condutor, Veiculo *veiculo, const Hora &hora);///Construtor com par�metros do objecto da classe boleia.
	Membro* getCondutor() const;///M�todo para retornar o condutor da boleia.
	Veiculo* getVeiculo() const;///M�todo para retornar o veiculo usado na boleia.
	vector<Particular *> getPassageiros() const;///M�todo para retornar o vector onde est�o contidos todos os passageiros.
	void setCondutor(Membro* condutor);///M�todo para alterar o condutor da viagem
	void setVeiculo(Veiculo* veiculo);///M�todo para alterar o veiculo da viagem
	void adicionarPassageiro(Particular* passageiro);///Fun��o para adicionar um passageiro a boleia.
	void removerPassageiro(Particular* passageiro);///Fun��o para remover um passageiro da boleia.
	bool isMembroInBoleia(Membro* membro) const;///Fun��o para confirmar se um certo membro est� presente na boleia.
	void show();///Fun��o para mostrar no ecr� da consola toda a informa��o da boleia.
	void load(ifstream &file, vector<Membro *> *membros);///Fun��o para descarregar a informa��o de um txt relativa a uma boleia .
	void save(ofstream &file, vector<Membro *> *membros);///Fun��o para gravar a informa��o de uma boleia no txt de boleia.
	friend ostream& operator<<(ostream& os, Boleia* boleia);///Overload do operadro de impress�o de uma boleia no ecr� da consola.
};

#endif
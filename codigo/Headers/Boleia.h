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
	vector<Particular*> passageiros; /// Número total de pessoas no veículo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; /// se for igual ao inicio é um evento
	Membro* condutor;
	Veiculo* veiculo;
	Hora hora;

public:
	Boleia();///Construtor por defeito
	Boleia(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Preco &preco, const vector<Particular*> &passageiros, const Data &dataInicio, const Data &dataFim, Membro *condutor, Veiculo *veiculo, const Hora &hora);///Construtor com parâmetros do objecto da classe boleia.
	Membro* getCondutor() const;///Método para retornar o condutor da boleia.
	Veiculo* getVeiculo() const;///Método para retornar o veiculo usado na boleia.
	vector<Particular *> getPassageiros() const;///Método para retornar o vector onde estão contidos todos os passageiros.
	void setCondutor(Membro* condutor);///Método para alterar o condutor da viagem
	void setVeiculo(Veiculo* veiculo);///Método para alterar o veiculo da viagem
	void adicionarPassageiro(Particular* passageiro);///Função para adicionar um passageiro a boleia.
	void removerPassageiro(Particular* passageiro);///Função para remover um passageiro da boleia.
	bool isMembroInBoleia(Membro* membro) const;///Função para confirmar se um certo membro está presente na boleia.
	void show();///Função para mostrar no ecrã da consola toda a informação da boleia.
	void load(ifstream &file, vector<Membro *> *membros);///Função para descarregar a informação de um txt relativa a uma boleia .
	void save(ofstream &file, vector<Membro *> *membros);///Função para gravar a informação de uma boleia no txt de boleia.
	friend ostream& operator<<(ostream& os, Boleia* boleia);///Overload do operadro de impressão de uma boleia no ecrã da consola.
};

#endif
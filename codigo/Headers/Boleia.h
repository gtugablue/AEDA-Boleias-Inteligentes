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
	Membro* condutor; // NULL se ainda não existir
	Veiculo* veiculo; // NULL se ainda não existir
	Coordenadas origem;
	Coordenadas destino;
	Preco preco;
	vector<Particular*> passageiros; // Número total de pessoas no veículo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; // se for igual ao inicio é um evento
	Hora horaInicio;
	Hora horaFim;
	char diaDaSemana; // 0 a 6, para o caso de ser uma boleia periódica

public:
	Boleia(Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim, const Hora &horaInicio, const Hora &horaFim);
	Boleia(Membro* condutor, Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim, const Hora &horaInicio, const Hora &horaFim);
	Membro* getCondutor() const;
	Veiculo* getVeiculo() const;
	vector<Particular *> getPassageiros() const;
	void setCondutor(Membro* condutor);
	void setVeiculo(Veiculo* veiculo);
	void adicionarPassageiro(Particular* passageiro);
	void removerPassageiro(Particular* passageiro);
	bool isMembroInBoleia(Membro* membro) const;
	void show();
	void cria();
	void edit();
};

#endif
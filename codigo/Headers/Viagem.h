#ifndef _VIAGEM_H
#define _VIAGEM_H

#include "Coordenadas.h"
#include "Veiculo.h"
#include "Particular.h"
#include "Data.h"

using namespace std;

class Viagem
{
private:
	Membro* condutor; // NULL se ainda n�o existir
	Veiculo* veiculo; // NULL se ainda n�o existir
	Coordenadas origem;
	Coordenadas destino;
	vector<Particular*> passageiros; // N�mero total de pessoas no ve�culo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; // se for igual ao inicio � um evento
public:
	Viagem(Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim);
	Viagem(Membro* condutor, Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim);
	Membro* getCondutor() const;
	Veiculo* getVeiculo() const;
	vector<Particular*> getPassageiros() const;
	void setCondutor(Membro* condutor);
	void setVeiculo(Veiculo* veiculo);
	void adicionarPassageiro(Particular* passageiro);
	void removerPassageiro(Particular* passageiro);
	void showViagem();
	void criaViagem();
};

#endif

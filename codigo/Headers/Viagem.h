#ifndef _VIAGEM_H
#define _VIAGEM_H

#include "Coordenadas.h"
#include "Veiculo.h"
#include "Particular.h"

using namespace std;

class Viagem
{
private:
	Membro* condutor; // NULL se ainda n�o existir
	Veiculo* veiculo; // NULL se ainda n�o existir
	Coordenadas inicio;
	Coordenadas fim;
	vector<Particular*> passageiros; // N�mero total de pessoas no ve�culo = passageiros + 1 (condutor)
public:
	Viagem();
	Viagem(Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim);
	Viagem(Membro* condutor, Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim);
	Membro* getCondutor() const;
	Veiculo* getVeiculo() const;
	Coordenadas getInicio() const;
	Coordenadas getFim() const;
	vector<Particular*> getPassageiros() const;
	void setCondutor(Membro* condutor);
	void setVeiculo(Veiculo* veiculo);
	void setInicio(const Coordenadas &inicio);
	void setFim(const Coordenadas &fim);
	void adicionarPassageiro(Particular* passageiro);
	void removerPassageiro(Particular* passageiro);
};

#endif

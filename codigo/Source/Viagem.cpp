#include "../headers/Viagem.h"
Viagem::Viagem() :
inicio(Coordenadas(0.0, 0.0)), fim(Coordenadas(0.0, 0.0))
{

}
Viagem::Viagem(Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim) :
inicio(inicio), fim(fim)
{
	this->condutor = NULL;
	this->veiculo = veiculo;
}

Viagem::Viagem(Membro* condutor, Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim) :
inicio(inicio), fim(fim)
{ 
	this->condutor = condutor;
	this->veiculo = veiculo;
}

Membro* Viagem::getCondutor() const
{
	return condutor;
}

Veiculo* Viagem::getVeiculo()const
{
	return veiculo;

}

Coordenadas Viagem::getInicio()const
{
	return inicio;
}

Coordenadas Viagem::getFim()const
{
	return fim;
}

void Viagem::setCondutor(Membro* condutor)
{
	this->condutor = condutor;
}

void Viagem::setFim(const Coordenadas &fim)
{
	this->fim = fim;
}
void Viagem::setInicio(const Coordenadas &inicio)
{
	this->inicio = inicio;
}

void Viagem::setVeiculo(Veiculo* veiculo)
{
	this->veiculo = veiculo;
}

vector<Particular*>Viagem::getPassageiros() const
{
	return  passageiros;
}


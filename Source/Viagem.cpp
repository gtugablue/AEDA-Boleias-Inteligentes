#include "Viagem.h"

Viagem::Viagem(Membro* condutor, Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim)
{
	this ->condutor=condutor;
	this ->veiculo=veiculo;
	this ->inicio=inicio;
	this ->fim =fim;
}

Membro* Viagem:: getCondutor() const
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
	this ->condutor=condutor;
}

void Viagem::setFim(const Coordenadas &fim)
{
	this ->fim=fim;
}
void Viagem::setInicio(const Coordenadas &inicio)
{
	this ->inicio=inicio;
}

void Viagem::setVeiculo(Veiculo* veiculo)
{
	this ->veiculo=veiculo;
}

vector<Particular*>Viagem:: getPassageiros() const
{
	return  passageiros;
}


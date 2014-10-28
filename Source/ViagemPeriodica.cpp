#include "../headers/ViagemPeriodica.h"

ViagemPeriodica::ViagemPeriodica(char diaDaSemana, Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim):
Viagem(veiculo, inicio, fim)
{
	this->diaDaSemana = diaDaSemana;
}

ViagemPeriodica::ViagemPeriodica(char diaDaSemana, Membro* condutor, Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim):
Viagem(condutor, veiculo, inicio, fim)
{
	this->diaDaSemana = diaDaSemana;
}

char ViagemPeriodica::getDiaDaSemana() const
{
	return diaDaSemana;
}

void ViagemPeriodica::setDiaDaSemana(char diaDaSemana)
{
	this->diaDaSemana = diaDaSemana;
	return;
}

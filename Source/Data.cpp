#include "../headers/Data.h"

Data::Data(unsigned dia, unsigned mes, unsigned ano)
{
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

unsigned Data::getDia() const
{
	return dia;
}

unsigned Data::getMes() const
{
	return mes;
}

unsigned Data::getAno() const
{
	return ano;
}

void Data::setDia(unsigned dia)
{
	this->dia = dia;
	return;
}

void Data::setMes(unsigned mes)
{
	this->mes = mes;
	return;
}

void Data::setAno(unsigned ano)
{
	this->ano = ano;
	return;
}

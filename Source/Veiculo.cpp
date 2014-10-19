#include "Veiculo.h"

Veiculo::Veiculo(string marca, unsigned mes, unsigned ano,unsigned cilindrada)
{
	this ->marca=marca;
	this->mes=mes;
	this->ano=ano;
	this->cilindrada=cilindrada;
}

string Veiculo::getMarca() const
{
	return marca;
}

unsigned Veiculo::getMes()const
{
	return mes;
}

unsigned Veiculo::getAno()const
{
	return ano;
}

string Veiculo::getCilindrada()const
{
	return cilindrada;
}

void Veiculo::setMarca(string &marca)
{
	this->marca=marca;

}

void Veiculo::setAno(unsigned ano)
{
	this->ano=ano;
}

void Veiculo::setMes(unsigned mes)
{
	this->mes=mes;
}

void Veiculo::setCilindrada(unsigned cilindrada)
{
  this ->cilindrada=cilindrada;
}


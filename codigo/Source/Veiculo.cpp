#include "../headers/Veiculo.h"

Veiculo::Veiculo(string marca, unsigned mes, unsigned ano,unsigned cilindrada, Combustivel* combustivel)
{
	this->marca = marca;
	this->mes = mes;
	this->ano = ano;
	this->cilindrada = cilindrada;
	this->combustivel = combustivel;
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

unsigned Veiculo::getCilindrada()const
{
	return cilindrada;
}

Combustivel* Veiculo::getCombustivel() const
{
	return combustivel;
}

void Veiculo::setMarca(string &marca)
{
	this->marca = marca;
	return;

}

void Veiculo::setAno(unsigned ano)
{
	this->ano = ano;
	return;
}

void Veiculo::setMes(unsigned mes)
{
	this->mes = mes;
	return;
}

void Veiculo::setCilindrada(unsigned cilindrada)
{
	this->cilindrada = cilindrada;
	return;
}

void Veiculo::setCombustivel(Combustivel* combustivel)
{
	this->combustivel = combustivel;
	return;
}

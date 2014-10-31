#include "../headers/Combustivel.h"

Combustivel::Combustivel(const string &nome, float preco)
{
	this ->nome=nome;
	this ->preco=preco;
}

string Combustivel::getNome()const
{
	return nome;
}

float Combustivel::getPreco()const
{
	return preco;
}

void Combustivel::setNome(const string &nome)
{
	this ->nome=nome;
}

void Combustivel::setPreco(const float &preco)
{
	this ->preco=preco;
}

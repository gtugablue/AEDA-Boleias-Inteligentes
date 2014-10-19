#include "Membro.h"

Membro::Membro(string nome, string utilizador, string password)
{
	this ->nome=nome;
	this->utilizador=utilizador;
	this ->password=password;
}

string Membro::getNome()const
{
	return nome;
}

string Membro::getUtilizador()const
{
	return utilizador;
}

string Membro::getPassword()const
{
	return password;
}

void Membro::setNome(string &nome)
{
	this->nome=nome;
}

void Membro::setPassword(string &password)
{
	this->password=password;
}

void Membro::setUtilizador(string &utilizador)
{
	this ->utilizador=utilizador;
}

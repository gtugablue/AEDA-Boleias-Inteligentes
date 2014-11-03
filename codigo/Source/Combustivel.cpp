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

void Combustivel::criar()
{
	string nome;
	float preco;
	cout << "Introduza o nome do combustivel:" << endl;
	getline(cin, nome);
	cout << "Introduza o preco:" << endl;
	cin >> preco;
}

void Combustivel::show() const
{
	cout << "Combustivel: " << nome << endl;
}
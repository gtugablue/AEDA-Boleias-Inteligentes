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
	cout << "Introduza o nome do combustivel: ";
	getline(cin, nome);
	cout << "Introduza o preco: ";
	cin >> preco;
	cin.ignore(1000, '\n');
}

void Combustivel::show() const
{
	cout << "Combustivel: " << nome << endl;
}

void Combustivel::load(ifstream &file)
{
	getline(file, nome);
	file >> preco;
	file.ignore(1000, '\n');
}

void Combustivel::save(ofstream &file) const
{
	file << nome << endl;
	file << preco << endl;
}

ostream& operator<<(ostream &os, const Combustivel &combustivel)
{
	return os << combustivel.nome;
}
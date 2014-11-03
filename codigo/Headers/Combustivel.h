#ifndef _COMBUSTIVEL_H
#define _COMBUSTIVEL_H

#include <string>
#include <iostream>

using namespace std;

class Combustivel
{
private:
	string nome;
	float preco;
public:
	Combustivel(const string &nome, float preco);
	void setNome(const string &nome);
	void setPreco(const float &preco);
	string getNome() const;
	float getPreco() const;
	void criar();
};

#endif

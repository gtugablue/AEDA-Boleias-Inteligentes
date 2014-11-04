#ifndef _COMBUSTIVEL_H
#define _COMBUSTIVEL_H

#include <string>
#include <iostream>
#include <fstream>

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
	void show() const;
	void load(ifstream &file);
	void save(ofstream &file) const;
};

#endif

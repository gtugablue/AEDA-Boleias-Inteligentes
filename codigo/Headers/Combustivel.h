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
	Combustivel(const string &nome, float preco);///Construtor com par�metros da classe.
	void setNome(const string &nome);///M�todo que altera o nome do combustivel.
	void setPreco(const float &preco);///M�todo que altera o pre�o do combustivel.
	string getNome() const;///M�todo que retorna o nome do Combustivel
	float getPreco() const;///M�todo que retorna o pre�o do Combustivel
	void criar();///Fun��o responsavel por criar um Combustivel novo.
	void show() const;///Fun��o que mostra no ecr� da Consola toda a informa��o relativa a um Combustivel.
	void load(ifstream &file);///Fun��o que faz load de toda a informa��o relativa combustiveis presente no ficheiro de combustiveis.
	void save(ofstream &file) const;///Fun��o que grava a informa��o de um combustivel no respectivo ficheiro txt.

	friend ostream& operator<<(ostream &os, const Combustivel &combustivel);///Overload do operador de impress�o no ecr� da Consola da informa��o rela tiva a um combustivel.
};

#endif

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
	Combustivel(const string &nome, float preco);///Construtor com parâmetros da classe.
	void setNome(const string &nome);///Método que altera o nome do combustivel.
	void setPreco(const float &preco);///Método que altera o preço do combustivel.
	string getNome() const;///Método que retorna o nome do Combustivel
	float getPreco() const;///Método que retorna o preço do Combustivel
	void criar();///Função responsavel por criar um Combustivel novo.
	void show() const;///Função que mostra no ecrã da Consola toda a informação relativa a um Combustivel.
	void load(ifstream &file);///Função que faz load de toda a informação relativa combustiveis presente no ficheiro de combustiveis.
	void save(ofstream &file) const;///Função que grava a informação de um combustivel no respectivo ficheiro txt.

	friend ostream& operator<<(ostream &os, const Combustivel &combustivel);///Overload do operador de impressão no ecrã da Consola da informação rela tiva a um combustivel.
};

#endif

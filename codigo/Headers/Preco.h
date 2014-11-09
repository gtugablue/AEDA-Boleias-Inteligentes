#ifndef _PRECO_H
#define _PRECO_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "InputUtils.h"
#include <iomanip>

using namespace std;

class Preco
{
private:
	float combustivel;
	float desgaste;
	vector<pair<string, float>> outrasDespesas;
public:
	Preco();///Construtor por defeito da classe
	Preco(float combustivel, float desgaste, const vector<pair<string, float>> &outrasDespesas);///Construtor com parâmetros da classe
	void showDespesas() const;///Função que mostra no ecrã todas as despesas
	float getCombustivel() const;///Método que retorna o preço do combustivel usado
	float getDesgaste() const;///Método que retorna o preco do desgaste
	vector<pair<string, float>> getOutrasDespesas() const;///Método que retorna as restantes despesas associadas a uma boleia
	void setCombustivel(float combustivel);///Método que permite alterar o preco de um combustivel
	void setDesgaste(float desgaste);///Método que permite alterar o preço do desgaste
	friend ostream& operator<<(ostream &os, const Preco &preco);///Overload do operador << que permite mostrar no ecra os parametros da classe
	void show() const;///Função que mostra no ecra da consola toda a informação sobre um preço
	float calcularTotal() const;///Função que calcula o preço total da viagem somando o custo individual de ada despesa
	void updatePrecoCombustivel(float consumo, float precoCombustivel, double distancia);///Função que permite fazer update ao preco do combustivel
	void criar();///Função que permite criar um preço novo
	void save(ofstream &file);///Função que grava toda a informação de um preço no ficheiro txt respectivo
	void load(ifstream &file);///Função que carrega a informação contida num txt sobre um determinado preço para o programa
	friend ostream& operator<<(ostream &os, const Preco &preco);///Overload do operador de impressao no ecra que permite imprimir na consola a informação relativa a um determinado preço
};

#endif
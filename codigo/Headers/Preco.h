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
	Preco(float combustivel, float desgaste, const vector<pair<string, float>> &outrasDespesas);///Construtor com par�metros da classe
	void showDespesas() const;///Fun��o que mostra no ecr� todas as despesas
	float getCombustivel() const;///M�todo que retorna o pre�o do combustivel usado
	float getDesgaste() const;///M�todo que retorna o preco do desgaste
	vector<pair<string, float>> getOutrasDespesas() const;///M�todo que retorna as restantes despesas associadas a uma boleia
	void setCombustivel(float combustivel);///M�todo que permite alterar o preco de um combustivel
	void setDesgaste(float desgaste);///M�todo que permite alterar o pre�o do desgaste
	friend ostream& operator<<(ostream &os, const Preco &preco);///Overload do operador << que permite mostrar no ecra os parametros da classe
	void show() const;///Fun��o que mostra no ecra da consola toda a informa��o sobre um pre�o
	float calcularTotal() const;///Fun��o que calcula o pre�o total da viagem somando o custo individual de ada despesa
	void updatePrecoCombustivel(float consumo, float precoCombustivel, double distancia);///Fun��o que permite fazer update ao preco do combustivel
	void criar();///Fun��o que permite criar um pre�o novo
	void save(ofstream &file);///Fun��o que grava toda a informa��o de um pre�o no ficheiro txt respectivo
	void load(ifstream &file);///Fun��o que carrega a informa��o contida num txt sobre um determinado pre�o para o programa
	friend ostream& operator<<(ostream &os, const Preco &preco);///Overload do operador de impressao no ecra que permite imprimir na consola a informa��o relativa a um determinado pre�o
};

#endif
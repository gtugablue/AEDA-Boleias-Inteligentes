#ifndef _VEICULO_H
#define _VEICULO_H

#include <string>
#include "Combustivel.h"
#include <iostream>
#include <fstream>
#include "Data.h"
#include <vector>
#include "OutputUtils.h"
#include "InputUtils.h"

using namespace std;

class Veiculo
{
private:
	string marca;
	string modelo;
	unsigned mes;
	unsigned ano;
	unsigned cilindrada;
	Combustivel *combustivel;
	unsigned int lotacao;
	float consumo; // l/100km
public:
	Veiculo();///Construtor por defeito da classe
	string getMarca() const;///M�todo que retorna a marca do veiculo
	string getModelo() const;///M�todo que retorna o modelo do veiculo
	unsigned getLotacao() const;///M�todo que retorna a lota��o do veiculo
	unsigned getMes() const;///M�todo que retorna o mes em que foi comprado o veiculo
	unsigned getAno() const;///M�todo que retorna o ano em que foi comprado o veiculo
	unsigned getCilindrada() const;///M�todo que retorna a cilindrada do veiculo
	float getConsumo() const;///M�todo que retorna o consumo do veiculo
	Combustivel *getCombustivel();///M�todo que retorna o combustivel do veiculo
	void setMarca(string &marca);///M�todo que permite alterar a marca do veiculo
	void setMes(unsigned mes);///M�todo que permite alterar o mes do veiculo
	void setAno(unsigned ano);///M�todo que permite alterar o ano do veiculo
	void setCilindrada(unsigned cilindrada);///M�todo que permite alterar a cilindrada do veiculo
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Fun��o que carrega a informa��o relativa a um veiculo contida no respectivo txt para o programa
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Fun��o que grava a informa��o relativa a um veiculo no ficheiro txt respectivo
	void setCombustivel(Combustivel *combustivel);///Fun��o que permite alterar o combustivel
	Combustivel* escolherCombustivel(vector<Combustivel> *combustiveis);///Fun��o que permite escolher o combustivel que queremos associar ao veiculo a partir de um vector onde est�o todos os combustiveis existentes
	void show() const;///Fun��o que mostra no ecr� toda a informa��o de um veiculo
	void criar(vector<Combustivel> *combustiveis);///Fun��o que permite criar um veiculo
	void editar(vector<Combustivel> *combustiveis);///Fun��o que permite editar a informa��o de um veiculo
	friend ostream& operator<<(ostream &os, const Veiculo &veiculo);///Overload do operador << que permtie a impress� no ecra dos parametros do veiculo
	friend ostream& operator<<(ostream &os, Veiculo *veiculo);
};

#endif

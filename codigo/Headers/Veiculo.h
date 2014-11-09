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
	string getMarca() const;///Método que retorna a marca do veiculo
	string getModelo() const;///Método que retorna o modelo do veiculo
	unsigned getLotacao() const;///Método que retorna a lotação do veiculo
	unsigned getMes() const;///Método que retorna o mes em que foi comprado o veiculo
	unsigned getAno() const;///Método que retorna o ano em que foi comprado o veiculo
	unsigned getCilindrada() const;///Método que retorna a cilindrada do veiculo
	float getConsumo() const;///Método que retorna o consumo do veiculo
	Combustivel *getCombustivel();///Método que retorna o combustivel do veiculo
	void setMarca(string &marca);///Método que permite alterar a marca do veiculo
	void setMes(unsigned mes);///Método que permite alterar o mes do veiculo
	void setAno(unsigned ano);///Método que permite alterar o ano do veiculo
	void setCilindrada(unsigned cilindrada);///Método que permite alterar a cilindrada do veiculo
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Função que carrega a informação relativa a um veiculo contida no respectivo txt para o programa
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Função que grava a informação relativa a um veiculo no ficheiro txt respectivo
	void setCombustivel(Combustivel *combustivel);///Função que permite alterar o combustivel
	Combustivel* escolherCombustivel(vector<Combustivel> *combustiveis);///Função que permite escolher o combustivel que queremos associar ao veiculo a partir de um vector onde estão todos os combustiveis existentes
	void show() const;///Função que mostra no ecrã toda a informação de um veiculo
	void criar(vector<Combustivel> *combustiveis);///Função que permite criar um veiculo
	void editar(vector<Combustivel> *combustiveis);///Função que permite editar a informação de um veiculo
	friend ostream& operator<<(ostream &os, const Veiculo &veiculo);///Overload do operador << que permtie a impressã no ecra dos parametros do veiculo
	friend ostream& operator<<(ostream &os, Veiculo *veiculo);
};

#endif

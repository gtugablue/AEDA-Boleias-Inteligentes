#ifndef _DATA_H
#define _DATA_H
#include <iostream>
#include "InputUtils.h"
#include <fstream>

using namespace std;

class Data
{
protected:
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;
public:
	Data();///Construtor por defeito da classe
	Data(unsigned dia, unsigned mes, unsigned ano);///Construtor com parametros da classe.
	unsigned getDia() const;///m�todo para retornar o parametro dia de uma data
	unsigned getMes() const;///m�todo para retornar o parametro mes de uma data
	unsigned getAno() const;///metodo para retornar o paramentro ano de uma data
	void setDia(unsigned dia);///m�todo para alterar o dia de uma data
	void setMes(unsigned mes);///metodo para alterar o mes de uma data
	void setAno(unsigned ano);///metodo para alterar o ano de uma data
	bool operator < (const Data &data)const;///Overload do operador < para comparar datas
	void save(ofstream &file);///Fun��o que grava a informa��o relativa a uma data no ficheiro correspondente.
	void load(ifstream &file);///Fun��o que carrega a informa��o relativa a uma data para a execu��o de um programa
	void criar();///Fun��o que permite criar uma nova data
	void editar();///Fun��o que permite editar uma data ja existente
	bool isBissexto() const;///Fun��o que verifica se um ano � bissexto e retorna true caso seja verdade

	bool operator==(const Data &data) const;///Overload do operador de igualdade para que seja possivel comparar datas.
	friend ostream& operator<<(ostream &os, const Data &data);///Overload do operador de impress�o para que seja possivel mostar uma data na consola.
};


///Tratamento da excep��o para quando se introduz parametros invalidos numa data.
template<class T>
class DataInvalidaException
{
public:
	T info;
	DataInvalidaException(T info)
	{
		this->info = info;
	}
};

#endif

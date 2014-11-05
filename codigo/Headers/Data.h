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
	Data();
	Data(unsigned dia, unsigned mes, unsigned ano);
	unsigned getDia() const;
	unsigned getMes() const;
	unsigned getAno() const;
	void setDia(unsigned dia);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
	bool operator < (const Data &data)const;
	void save(ofstream &file);
	void load(ifstream &file);
	void criar();
	void editar();
	bool isBissexto() const;
	void showData()const

	friend ostream& operator<<(ostream &os, const Data &data);
};

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

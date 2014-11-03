#ifndef _DATA_H
#define _DATA_H
#include <iostream>
#include "InputUtils.h"

using namespace std;

class Data
{
protected:
	unsigned dia;
	unsigned mes;
	unsigned ano;
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
	void show();
	void criar();
	void editar();
	bool isBissexto() const;
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

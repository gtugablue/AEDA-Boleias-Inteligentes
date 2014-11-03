#ifndef _DATA_H
#define _DATA_H
#include <iostream>

using namespace std;

class Data
{
protected:
	unsigned dia;
	unsigned mes;
	unsigned ano;
public:
	Data(unsigned dia, unsigned mes, unsigned ano);
	unsigned getDia() const;
	unsigned getMes() const;
	unsigned getAno() const;
	void setDia(unsigned dia);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
	bool operator < (const Data &data)const;
	void showdata();
};

#endif

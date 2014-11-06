#ifndef _HORA_H
#define _HORA_H

#include <fstream>
#include<iostream>

using namespace std;

class Hora
{
private:
	unsigned hora;
	unsigned minuto;
public:
	Hora();
	void show() const;
	Hora(unsigned hora, unsigned minuto);
	unsigned getHora() const;
	unsigned getMinuto() const;
	void setHora(unsigned hora);
	void setMinuto(unsigned minuto);
	bool operator<(const Hora &horas);
	void save(ofstream &file);
	void load(ifstream &file);
	void criar();
};

#endif

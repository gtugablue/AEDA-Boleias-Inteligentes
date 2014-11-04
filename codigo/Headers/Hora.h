#ifndef _HORA_H
#define _HORA_H

#include <fstream>

using namespace std;

class Hora
{
private:
	unsigned hora;
	unsigned minuto;
public:
	Hora();
	Hora(unsigned hora, unsigned minuto);
	unsigned getHora() const;
	unsigned getMinuto() const;
	void setHora(unsigned hora);
	void setMinuto(unsigned minuto);
	bool operator<(const Hora &horas);
	void save(ofstream &file);
	void load(ifstream &file);
};

#endif

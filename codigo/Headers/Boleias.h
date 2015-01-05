#ifndef _BOLEIAS_H
#define _BOLEIAS_H

#include<iostream>
#include<string>

using namespace std;
class Boleias
{
	string nome;
	string destino;
public:
	Boleias(string nome,string destino);
	string getNome()const{ return nome; }
	string getDestino()const { return destino; }

};

#endif


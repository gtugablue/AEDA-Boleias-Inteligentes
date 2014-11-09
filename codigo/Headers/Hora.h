#ifndef _HORA_H
#define _HORA_H

#include <fstream>
#include "InputUtils.h"

using namespace std;

class Hora
{
private:
	unsigned hora;
	unsigned minuto;
public:
	Hora();///Construtor por defeito da classe
	void show() const;///Função que permite mostrar na Consola a informação referente a uma hora
	Hora(unsigned hora, unsigned minuto);///Construtor com parâmetros da classe
	unsigned getHora() const;///Método para retornar a hora
	unsigned getMinuto() const;///Método para retornar os minutos
	void setHora(unsigned hora);///Método para alterar a hora
	void setMinuto(unsigned minuto);///Método para alterar os minutos
	bool operator<(const Hora &horas);///Overload do operadro < de forma a se puder comparar horas
	void save(ofstream &file);///Função responsavel por gravar as informações relativas as hora no respectivo ficheiro
	void load(ifstream &file);///Função responsavel por descarregar a informação de um ficheiro sobre as horas
	void criar();///Função para criar uma nova hora
	void editar();///Função para editar as informações referentes a uma hora ja existente

	friend ostream& operator<<(ostream &os, const Hora &hora);///Overload do operador de impressão de forma a se puder imprimir as informações relativas a uma determinada hora no ecra da consola
};

#endif

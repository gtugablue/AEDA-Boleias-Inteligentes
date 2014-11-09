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
	void show() const;///Fun��o que permite mostrar na Consola a informa��o referente a uma hora
	Hora(unsigned hora, unsigned minuto);///Construtor com par�metros da classe
	unsigned getHora() const;///M�todo para retornar a hora
	unsigned getMinuto() const;///M�todo para retornar os minutos
	void setHora(unsigned hora);///M�todo para alterar a hora
	void setMinuto(unsigned minuto);///M�todo para alterar os minutos
	bool operator<(const Hora &horas);///Overload do operadro < de forma a se puder comparar horas
	void save(ofstream &file);///Fun��o responsavel por gravar as informa��es relativas as hora no respectivo ficheiro
	void load(ifstream &file);///Fun��o responsavel por descarregar a informa��o de um ficheiro sobre as horas
	void criar();///Fun��o para criar uma nova hora
	void editar();///Fun��o para editar as informa��es referentes a uma hora ja existente

	friend ostream& operator<<(ostream &os, const Hora &hora);///Overload do operador de impress�o de forma a se puder imprimir as informa��es relativas a uma determinada hora no ecra da consola
};

#endif

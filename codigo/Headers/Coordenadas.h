#ifndef _COORDENADAS_H
#define _COORDENADAS_H
#include <iostream>
#include <fstream>
#include "InputUtils.h"
#include <math.h>

using namespace std;

class Coordenadas
{
private:
	double latitude;
	double longitude;
public:
	Coordenadas();///Construtor por defeito da classe.
	Coordenadas(const Coordenadas &coordenadas);///Construtor com um objecto da classe
	Coordenadas(double latitude, double longitude);///Construtor com parametros da classe.
	double getLatitude() const;///Método para retornar a latitude de uma coordenada.
	double getLongitude() const;///Método para retornar a longitude de uma coordenada.
	void setLatitude(double latitude);///Método para alterar a latitude de uma coordenada.
	void setLongitude(double longitude);///Método para alterar a longitude de uma coordenada
	double toRad(double degrees) const;///Função para passar um determinado valor em graus para radianos.
	double calcDistancia(const Coordenadas &coordenadas) const;///Função para calcular a distancia entre duas coordenadas diferentes.
	void show() const;///Função para mostrar no ecra da Consola umas determinadas coordenadas.
	void criar();///Função para criar novas coordenadas.
	void editar();///Função responsavel por editar informação referente a coordenadas ja existentes.
	void load(ifstream &file);///Função responsavel por fazer load da informação das coordenadas presentes num txt.
	void save(ofstream &file);///Função responsavel por gravar as informações das coordenadas num ficheiro txt no final da execução do programa.
};

#endif

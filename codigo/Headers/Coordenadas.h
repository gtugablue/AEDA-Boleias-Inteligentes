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
	double getLatitude() const;///M�todo para retornar a latitude de uma coordenada.
	double getLongitude() const;///M�todo para retornar a longitude de uma coordenada.
	void setLatitude(double latitude);///M�todo para alterar a latitude de uma coordenada.
	void setLongitude(double longitude);///M�todo para alterar a longitude de uma coordenada
	double toRad(double degrees) const;///Fun��o para passar um determinado valor em graus para radianos.
	double calcDistancia(const Coordenadas &coordenadas) const;///Fun��o para calcular a distancia entre duas coordenadas diferentes.
	void show() const;///Fun��o para mostrar no ecra da Consola umas determinadas coordenadas.
	void criar();///Fun��o para criar novas coordenadas.
	void editar();///Fun��o responsavel por editar informa��o referente a coordenadas ja existentes.
	void load(ifstream &file);///Fun��o responsavel por fazer load da informa��o das coordenadas presentes num txt.
	void save(ofstream &file);///Fun��o responsavel por gravar as informa��es das coordenadas num ficheiro txt no final da execu��o do programa.
};

#endif

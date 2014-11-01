#ifndef _BOLEIAS_INTELIGENTES_H
#define _BOLEIAS_INTELIGENTES_H

#include "Anuncio.h"
#include "AnuncioOferta.h"
#include "AnuncioProcura.h"
#include <iostream>
#include "Coordenadas.h"
#include "Combustivel.h"
#include "Veiculo.h"
#include "Preco.h"
#include "Viagem.h"
#include "Particular.h"
#include "Empresa.h"

using namespace std;

class BoleiasInteligentes
{
private:
	string dataFolder;
	vector<Combustivel*> combustiveis;
	vector<Particular> membros;
	vector<Empresa> empresas;
	Membro* utilizador;
public:
	BoleiasInteligentes(const string &dataFolder);

	void load();
	void loadCombustiveis();
	void loadParticulares();
	void loadEmpresas();
	void loadAnunciosOferta();
	void loadAnunciosProcura();

	void save();
	void saveCombustiveis();
	void saveParticulares();
	void saveEmpresas();
	void saveAnunciosOferta();
	void saveAnunciosProcura();

	Coordenadas BoleiasInteligentes::criarCoordenadas();
	Veiculo BoleiasInteligentes::criarVeiculo();
	Combustivel BoleiasInteligentes::criarCombustivel();
	Anuncio BoleiasInteligentes::criarAnuncio();
};
#endif
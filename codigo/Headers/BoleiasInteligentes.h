#ifndef _BOLEIAS_INTELIGENTES_H
#define _BOLEIAS_INTELIGENTES_H

#include "Anuncio.h"
#include "AnuncioOferta.h"
#include "AnuncioProcura.h"
#include <iostream>
#include <string>
#include <vector>
#include "Coordenadas.h"
#include "Combustivel.h"
#include "Veiculo.h"
#include "Preco.h"
#include "Viagem.h"
#include "Membro.h"
#include "Particular.h"
#include "Empresa.h"

using namespace std;

class BoleiasInteligentes
{
private:
	string dataFolder;
	vector<Combustivel*> combustiveis;
	vector<Particular> particulares;
	vector<Empresa> empresas;
	Membro* utilizador = NULL;
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

	void addEmpresa(const Empresa &empresa);
	void addParticular(const Particular &particular);

	static Membro* login(const string &username, const string &password);
};

template<class T>
class UtilizadorInexistenteException
{
public:
	T info;
};

template<class T>
class PasswordErradaException
{
public:
	T info;
};

#endif
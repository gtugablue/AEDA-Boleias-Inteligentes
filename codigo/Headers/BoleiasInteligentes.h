#ifndef _BOLEIAS_INTELIGENTES_H
#define _BOLEIAS_INTELIGENTES_H

#include "Anuncio.h"
#include "AnuncioOferta.h"
#include "AnuncioProcura.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Coordenadas.h"
#include "Combustivel.h"
#include "Veiculo.h"
#include "Preco.h"
#include "Viagem.h"
#include "Membro.h"
#include "Particular.h"
#include "Empresa.h"
#include <algorithm>

using namespace std;

class BoleiasInteligentes
{
private:
	const string dataFolder;
	static const string ficheiroCombustiveis;
	static const string ficheiroMembros;
	static const string ficheiroAnuncios;
	vector<Combustivel> combustiveis;
	vector<Membro*> membros;
	vector<Anuncio*> anuncios;
	vector<Viagem> viagens;
	Membro* utilizadorAtual = NULL;
public:
	BoleiasInteligentes(const string &dataFolder);

	void load();
	void loadCombustiveis();
	void loadMembros();
	void loadAnunciosOferta();
	void loadAnunciosProcura();

	void save();
	void saveCombustiveis();
	void saveMembros();
	void saveAnunciosOferta();
	void saveAnunciosProcura();

	Coordenadas BoleiasInteligentes::criarCoordenadas();
	Veiculo BoleiasInteligentes::criarVeiculo();
	Combustivel BoleiasInteligentes::criarCombustivel();
	Anuncio BoleiasInteligentes::criarAnuncio();

	void addEmpresa(const Empresa &empresa);
	void addParticular(const Particular &particular);

	Membro* login(const string &username, const string &password);
};

template<class T>
class LoginException
{
public:
	T info;
	LoginException(T info)
	{
		this->info = info;
	}
};

#endif
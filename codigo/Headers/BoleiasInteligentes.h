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
#include "Boleia.h"
#include "Membro.h"
#include "Particular.h"
#include "Empresa.h"
#include <algorithm>
#include "InputUtils.h"

using namespace std;

#define BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE	8

class BoleiasInteligentes
{
private:
	const string dataFolder;
	static const string ficheiroCombustiveis;
	static const string ficheiroMembros;
	static const string ficheiroAnuncios;
	static const string ficheiroPrecos;
	vector<Combustivel> combustiveis;
	vector<Membro*> membros;
	vector<Anuncio*> anuncios;
	vector<Boleia> viagens;
	Membro* utilizadorAtual = NULL;
public:
	BoleiasInteligentes(const string &dataFolder);

	void showmembro();
	void showviagem();
	void loadAnuncios();
	
	void start();

	void load();
	void loadCombustiveis();
	void loadMembros();
	void loadAnunciosOferta();
	void loadAnunciosProcura();
	void loadPrecos();

	void save();
	void saveCombustiveis();
	void saveMembros();
	void saveAnunciosOferta();
	void saveAnunciosProcura();

	void addEmpresa(const Empresa &empresa);
	void addParticular(const Particular &particular);
	vector<AnuncioOferta*> getAnunciosOferta() const;
	vector<AnuncioProcura*> getAnunciosProcura() const;
	vector<Anuncio*> getAnunciosByMembro(Membro* membro) const;

	Membro* login(const string &username, const string &password);


	// MENU
	void showMenu(vector<string> itens);
	void showLoginMenu();
	void showMainMenu();
	void showAnunciosMenu();
	void showVeiculosMenu();
	void showBoleiasMenu();

	template<class T>
	int showList(const vector<T> &v) const;
	template<class T>
	int showList(const vector<T> &v, int page) const;

	void showAnuncios();
	void showVehicles();
	void showVehicleInfo();

	void clearScreen() const;
	void pause() const;
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

template<class T>
class PaginaInexistenteException
{
public:
	T info;
	PaginaInexistenteException(T info)
	{
		this->info = info;
	}
};

template<class T>
class EmptyException
{
public:
	T info;
	EmptyException(T info)
	{
		this->info = info;
	}
};

template<class T>
class ProibidoException
{
public:
	T info;
	ProibidoException(T info)
	{
		this->info = info;
	}
};

#endif
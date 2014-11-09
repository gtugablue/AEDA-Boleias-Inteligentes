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
#include "OutputUtils.h"

using namespace std;

///Classe principal

class BoleiasInteligentes
{
private:
	const string dataFolder;
	static const string ficheiroCombustiveis;
	static const string ficheiroMembros;
	static const string ficheiroAnuncios;
	static const string ficheiroBoleias;
	vector<Combustivel> combustiveis;
	vector<Membro*> membros;
	vector<Anuncio*> anuncios;
	vector<Boleia> boleias;
	Membro* utilizadorAtual = NULL;
public:
	BoleiasInteligentes(const string &dataFolder);

	void showmembro();///Fun��o que mostra no ecr� toda a informa��o de um determinado membro.
	void showviagem();///Fun��o que mostra no ecr� toda a informa��o de uma determinada boleia.
	
	void start();///Fun��o que da inicio ao programa fazendo load da informa��o dos ficheiros e mostrando o menu inicial da aplica��o.

	void load();///Fun��o que engloba todas as outras fun��es responsaveis por fazer load da informa��o contida nos ficheiros txt para os respectivos vectores.
	void loadCombustiveis();///Fun��o que faz load da informa��o do txt de combustiveis para o vector de combustiveis.
	void loadMembros();///Fun��o que faz load da informa��o contida no ficheiro de membros para o vector de membros.
	void loadAnuncios();///Fun��o que faz load da informa��o contida no ficheiro de anuncios para o vector de anuncios.
	void loadBoleias();///Fun��o que faz laod da informa��o contida no ficheiro de boleias para o vector de boleias

	void save();///Fun��o geral que engloba todas as fun��es responsaveis por gravar as altera��es no fim do programa para o txt.
	void saveCombustiveis();///Fun��o que grava todas altera��es feitas no vector de combustiveis para o ficheiro de combustiveis
	void saveMembros();///Fun��o que grava todas as altera��es feitas no vector de membros para o ficheiro de membros.
	void saveAnuncios();///Fun��o que grava todas as altera��es feitas no vector de anuncios durante a execu��o do programa.
	void saveBoleias();///Fun��o que grava todas as altera��es feitas no vector de boleias durante a execu��o de programas para o ficheiro.

	void addEmpresa(const Empresa &empresa);///fun��o que adiciona um membro do tipo empresa ao vector de membros.
	void addParticular(const Particular &particular);///fun��o que adiciona um mebro do tipo particular ao vector de membros.
	vector<AnuncioOferta *> getAnunciosOferta() const;///M�todo que retorna todos os anuncios de oferta.
	vector<AnuncioProcura *> getAnunciosProcura() const;///M�todo que retorna todos os anuncios de procura.
	vector<Anuncio *> getAnunciosByMembro(Membro* membro) const;///Fun��o que retorna um vector com todos os anuncios pertencentes a um determinado anunciante.
	vector<Boleia *> getBoleiasWhereMembroExists(Membro* membro);///Fun��o que retorna um vector com todos os anuncios em que um determinado membro esta presente independentemente de que forma.
	vector<Combustivel> getCombustiveis();///Fun��o que retorna um vector com todos os combustiveis existentes.

	Membro* login(const string &username, const string &password);///Fun��o que permite fazer login na aplica��o boleias inteligentes.
	bool existsUtilizador(const string &username) const;///Fun��o que retorna true caso um determinado utilizador exista na base de dados da aplica��o.


	// MENU
	void showMenu(vector<string> itens);///Fun��o geral que mostra todas as op��es de um determinado menu.
	void showLoginMenu();///Fun��o que mostra o menu inicial onde � possivel fazer login na API ou criar uma conta nova.
	void showMainMenu();///Fun��o que mostra o menu principal a partir do qual se tem acesso a todas as op��es da API.
	void showAnunciosMenu();///Fun��o que mostra o menu dedicado aos anuncios onde se pode fazer as CRUD Options relativas ao mesmo.
	void showVeiculosMenu();///Fun��o que mostra o menu dedicado aos veiculos onde se pode fazer as CRUD Options relativas ao mesmo.
	void showBoleiasMenu();///Fun��o que mostra o menu dedicado as boleias onde se pode fazer as CRUD Options relativas ao mesmo.

	void showAnuncios();///Fun��o que mostra  todos os anuncio.
	void showVehicles();///Fun��o que mostra todos os veiculos
	void showVehicleInfo();///Fun��o que mostra a informa��o de cada veiculo.

	void sortAnuncios(const Coordenadas &origem, const Coordenadas &destino, int left, int right);///Funcao que ordena os anuncios por distancia
};


///Tratamento da excep��o relativa a erros de Login.
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
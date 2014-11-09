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

	void showmembro();///Função que mostra no ecrã toda a informação de um determinado membro.
	void showviagem();///Função que mostra no ecrã toda a informação de uma determinada boleia.
	
	void start();///Função que da inicio ao programa fazendo load da informação dos ficheiros e mostrando o menu inicial da aplicação.

	void load();///Função que engloba todas as outras funções responsaveis por fazer load da informação contida nos ficheiros txt para os respectivos vectores.
	void loadCombustiveis();///Função que faz load da informação do txt de combustiveis para o vector de combustiveis.
	void loadMembros();///Função que faz load da informação contida no ficheiro de membros para o vector de membros.
	void loadAnuncios();///Função que faz load da informação contida no ficheiro de anuncios para o vector de anuncios.
	void loadBoleias();///Função que faz laod da informação contida no ficheiro de boleias para o vector de boleias

	void save();///Função geral que engloba todas as funções responsaveis por gravar as alterações no fim do programa para o txt.
	void saveCombustiveis();///Função que grava todas alterações feitas no vector de combustiveis para o ficheiro de combustiveis
	void saveMembros();///Função que grava todas as alterações feitas no vector de membros para o ficheiro de membros.
	void saveAnuncios();///Função que grava todas as alterações feitas no vector de anuncios durante a execução do programa.
	void saveBoleias();///Função que grava todas as alterações feitas no vector de boleias durante a execução de programas para o ficheiro.

	void addEmpresa(const Empresa &empresa);///função que adiciona um membro do tipo empresa ao vector de membros.
	void addParticular(const Particular &particular);///função que adiciona um mebro do tipo particular ao vector de membros.
	vector<AnuncioOferta *> getAnunciosOferta() const;///Método que retorna todos os anuncios de oferta.
	vector<AnuncioProcura *> getAnunciosProcura() const;///Método que retorna todos os anuncios de procura.
	vector<Anuncio *> getAnunciosByMembro(Membro* membro) const;///Função que retorna um vector com todos os anuncios pertencentes a um determinado anunciante.
	vector<Boleia *> getBoleiasWhereMembroExists(Membro* membro);///Função que retorna um vector com todos os anuncios em que um determinado membro esta presente independentemente de que forma.
	vector<Combustivel> getCombustiveis();///Função que retorna um vector com todos os combustiveis existentes.

	Membro* login(const string &username, const string &password);///Função que permite fazer login na aplicação boleias inteligentes.
	bool existsUtilizador(const string &username) const;///Função que retorna true caso um determinado utilizador exista na base de dados da aplicação.


	// MENU
	void showMenu(vector<string> itens);///Função geral que mostra todas as opções de um determinado menu.
	void showLoginMenu();///Função que mostra o menu inicial onde é possivel fazer login na API ou criar uma conta nova.
	void showMainMenu();///Função que mostra o menu principal a partir do qual se tem acesso a todas as opções da API.
	void showAnunciosMenu();///Função que mostra o menu dedicado aos anuncios onde se pode fazer as CRUD Options relativas ao mesmo.
	void showVeiculosMenu();///Função que mostra o menu dedicado aos veiculos onde se pode fazer as CRUD Options relativas ao mesmo.
	void showBoleiasMenu();///Função que mostra o menu dedicado as boleias onde se pode fazer as CRUD Options relativas ao mesmo.

	void showAnuncios();///Função que mostra  todos os anuncio.
	void showVehicles();///Função que mostra todos os veiculos
	void showVehicleInfo();///Função que mostra a informação de cada veiculo.

	void sortAnuncios(const Coordenadas &origem, const Coordenadas &destino, int left, int right);///Funcao que ordena os anuncios por distancia
};


///Tratamento da excepção relativa a erros de Login.
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
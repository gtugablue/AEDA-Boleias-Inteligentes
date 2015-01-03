#ifndef _EMPRESA_H
#define _EMPRESA_H

#include "Membro.h"
#include "Boleia.h"
#include "Coordenadas.h"
#include "ClientesAntigos.h"
#include "Motorista.h"
#include "BST.h"
#include <vector>
#include <unordered_set>

using namespace std;

class Empresa : public Membro   ///Classe derivada da classe m�e Membro
{
	string website;
	Coordenadas garagem;
	unordered_set<ClientesAntigos>clientes;
	BST<Motorista> motoristas;
public:
	Empresa();///Construtor por defeito da classe
	Empresa(const string &nome, const string &utilizador, const string &password, const string &website);///Construtor com par�metros da classe.
	void signup();///Fun��o que cria um novo website
	void edit();///Fun��o que permite editar a informa��o de um website
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Fun��o que grava a informa��o relativa a uma empresa.
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Fun��o para carregar a informa��o de uma empresa
	void show() const;///Fun��o que permite mostrar no ecra toda a informa��o relativa a uma empresa
};

#endif
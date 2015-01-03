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

class Empresa : public Membro   ///Classe derivada da classe mãe Membro
{
	string website;
	Coordenadas garagem;
	unordered_set<ClientesAntigos>clientes;
	BST<Motorista> motoristas;
public:
	Empresa();///Construtor por defeito da classe
	Empresa(const string &nome, const string &utilizador, const string &password, const string &website);///Construtor com parâmetros da classe.
	void signup();///Função que cria um novo website
	void edit();///Função que permite editar a informação de um website
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Função que grava a informação relativa a uma empresa.
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Função para carregar a informação de uma empresa
	void show() const;///Função que permite mostrar no ecra toda a informação relativa a uma empresa
};

#endif
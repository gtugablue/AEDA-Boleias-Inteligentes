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
struct hstr {
	int operator() (const ClientesAntigos &cli) const {
		int v = 0;
		const string s1 = cli.getutilizador();
		for (unsigned int i = 0; i < s1.size(); i++)
			v = 37 * v + s1[i];
		return v;
	}
};
struct eqstr {
	bool operator() ( const ClientesAntigos &s1,  const ClientesAntigos &s2) const {
		return s1.getutilizador() == s2.getutilizador();
	}
};
class Empresa : public Membro   ///Classe derivada da classe mãe Membro
{
private:
	string website;
	Coordenadas garagem;
	unordered_set<ClientesAntigos, hstr, eqstr>clientes;
	BST<Motorista>motoristas;
public:
	
	Empresa();///Construtor por defeito da classe
	Empresa(const string &nome, const string &utilizador, const string &password, const string &website);///Construtor com parâmetros da classe.
	void signup();///Função que cria um novo website
	void edit();///Função que permite editar a informação de um website
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Função que grava a informação relativa a uma empresa.
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Função para carregar a informação de uma empresa
	void show() const;///Função que permite mostrar no ecra toda a informação relativa a uma empresa
	void insertOld(ClientesAntigos &c1);
	void removeOld(const ClientesAntigos &c1);
	

	
	
};



#endif
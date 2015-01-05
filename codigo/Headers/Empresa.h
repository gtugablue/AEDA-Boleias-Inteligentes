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
#include "OutputUtils.h"

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
	BST<Motorista> motoristas;
	unsigned numMotoristas;
public:
	Empresa();///Construtor por defeito da classe
	Empresa(const string &nome, const string &utilizador, const string &password, const string &website);///Construtor com parâmetros da classe.
	void setMorada(const Coordenadas &morada);
	Coordenadas getMorada() const;
	const BST<Motorista> &getMotoristas() const;
	void addMotorista(const Motorista &motorista);
	void editMotorista(const string &nome);
	void removeMotorista(const string &nome);
	void signup();///Função que cria um novo website
	void edit();///Função que permite editar a informação de um website
	void save(ofstream &file, vector<Combustivel> *combustiveis);///Função que grava a informação relativa a uma empresa.
	void load(ifstream &file, vector<Combustivel> *combustiveis);///Função para carregar a informação de uma empresa
	void show() const;///Função que permite mostrar no ecra toda a informação relativa a uma empresa
	void showMotoristasByNome() const;
	void insertOld(ClientesAntigos &c1);///funcao que insere na hash table
	void removeOld(string nome);///funcao que remove da hash table
	void showOld();///funcao que mostra todos os clientes por nome
	bool exists(string nome);///funcao que verifica se um cliente existe
	void editOld();///funcao que edita a informacao de um cliente
	void createOld();///funcao que cria um cliente
	ClientesAntigos existsutil(string nome);///funcao que retorna um cliente
	void showone();///funcao que mostra todas a informacao de um determinado cliente
	void loadclients();///funcao que carrega a informacao de clientes
};

#endif
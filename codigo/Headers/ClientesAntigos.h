#ifndef _CLIENTES_ANTIGOS_
#define _CLIENTES_ANTIGOS

#include <vector>
#include <string>

#include "Boleia.h"
#include "Boleias.h"

class ClientesAntigos
{
	string utilizador;
	string contacto;
	string morada;
	vector<Boleias>registos;
	
public:
	ClientesAntigos(string utilizador, string contacto, string morada);///Construtor da classe
	ClientesAntigos();///Construtor por defeito da classe
	string getutilizador() const;///funcao que retorna o utilizador
	string getMorada()const;///funcao que retorna a morada
	string getContacto()const;///funcao que retorna o contacto
	void showOne()const;///funcao que mostra um cliente
	void criar();///funcao que cria um cliente
	void setutilizador(string &nome);///funcao que altera o utilizador
	void setmorada(string &morada);///funcao que altera a morada
	void setnome(string &nome);///funcao que altera o nome
	void setcontacto(string &contacto);///funcao que altera o contacto
	Particular* getcliente();///funcao que retorna o cliente
	void loadClientes(ifstream &file);///funcao que faz load de todos os clientes
	void saveClientes(ofstream &file)const;///funcao que grava toda a informação de clientes
};

#endif

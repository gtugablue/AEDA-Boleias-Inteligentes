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
	ClientesAntigos(string utilizador, string contacto, string morada);
	ClientesAntigos();
	string getutilizador() const;
	string getMorada()const;
	string getContacto()const;
	void showOne()const;
	void criar();
	void setutilizador(string &nome);
	void setmorada(string &morada);
	void setnome(string &nome);
	void setcontacto(string &contacto);
	Particular* getcliente();
	void loadClientes(ifstream &file);
	void saveClientes(ofstream &file)const;
};

#endif

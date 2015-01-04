#ifndef _CLIENTES_ANTIGOS_
#define _CLIENTES_ANTIGOS

#include <vector>
#include <string>

#include "Boleia.h"

class ClientesAntigos
{
	vector<Boleia*>registos;
	Particular* cliente;
public:
	string getutilizador() const;
	void showOne()const;
	void setutilizador(string &nome);
	void setnome(string &nome);
	void setcontacto(string &contacto);
	Particular* getcliente();
};

#endif

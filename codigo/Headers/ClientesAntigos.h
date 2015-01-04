#ifndef _CLIENTES_ANTIGOS_
#define _CLIENTES_ANTIGOS

#include <vector>
#include <string>

#include "Boleia.h"

class ClientesAntigos
{
	vector<Boleia*>registos;
	Membro* cliente;
public:
	 string getutilizador() const;
	 void show()const;
	 void setutilizador(string nome);
};

#endif

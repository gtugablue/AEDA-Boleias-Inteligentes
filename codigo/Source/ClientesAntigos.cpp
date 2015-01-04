#include "../Headers/ClientesAntigos.h"

 string ClientesAntigos::getutilizador()const
{
	return cliente->getUtilizador();
}

 void ClientesAntigos::show()const
 {
	 cliente->show();
 }

 void ClientesAntigos::setutilizador(string nome)
 {
	 cliente->setUtilizador(nome);
 }
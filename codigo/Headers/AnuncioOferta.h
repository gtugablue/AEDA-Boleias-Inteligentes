#ifndef _ANUNCIO_OFERTA_H
#define _ANUNCIO_OFERTA_H

#include "Anuncio.h"
#include <vector>

using namespace std;

class AnuncioOferta: public Anuncio
{
private:
	Preco* preco;
	vector<Particular*> passageiros;
public:
	AnuncioOferta(const string &titulo, const string &descricao, Preco* preco, Viagem* viagem, Membro* anunciante);
	void setAnunciante(Membro* anunciante);
	Membro* getAnunciante() const;
};

#endif

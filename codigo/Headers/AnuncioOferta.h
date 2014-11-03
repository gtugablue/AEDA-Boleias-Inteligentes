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
	AnuncioOferta();
	AnuncioOferta(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim, Preco* preco);
	void setAnunciante(Membro* anunciante);
	Membro* getAnunciante() const;
	void criar();
	friend ostream& operator<<(ostream &os, const AnuncioOferta &anuncio);
};

#endif

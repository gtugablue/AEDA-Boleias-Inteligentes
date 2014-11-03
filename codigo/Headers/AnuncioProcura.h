#ifndef _ANUNCIO_PROCURA_H
#define _ANUNCIO_PROCURA_H

#include "Anuncio.h"
#include "Boleia.h"
#include <vector>

class AnuncioProcura: public Anuncio
{
private:
	vector<Membro*> condutoresCandidatos;
public:
	AnuncioProcura();
	AnuncioProcura(Particular* anunciante);
	void adicionarCondutorCandidato(const Membro* condutor);
	void setAnunciante(Particular* anunciante);
	Particular* getAnunciante() const;
	void criar();
	friend ostream& operator<<(ostream &os, const AnuncioProcura &anuncio);
	void editar();
};

#endif

#ifndef _ANUNCIO_PROCURA_H
#define _ANUNCIO_PROCURA_H

#include "Anuncio.h"
#include "Viagem.h"
#include <vector>

class AnuncioProcura: public Anuncio
{
private:
	vector<Membro*> condutoresCandidatos;
	vector<Membro*> passageiros;
public:
	AnuncioProcura(Particular* anunciante);
	void adicionarCondutorCandidato(const Membro* condutor);
	void setAnunciante(Particular* anunciante);
	Particular* getAnunciante() const;
	void criar(Membro* utilizadorAtual);
};

#endif

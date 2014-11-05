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
	void adicionarCondutorCandidato(Membro* condutor);
	void setAnunciante(Particular* anunciante);
	Particular* getAnunciante() const;
	void criar();
	void save(ofstream &file, vector<Membro *> *membros);
	void load(ifstream &file, vector<Membro *> *membros);
	friend ostream& operator<<(ostream &os, const AnuncioProcura &anuncio);
	void editar();
	void show()const;
};

#endif

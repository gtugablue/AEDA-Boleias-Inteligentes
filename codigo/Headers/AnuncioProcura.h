#ifndef _ANUNCIO_PROCURA_H
#define _ANUNCIO_PROCURA_H

#include "Anuncio.h"
#include "Boleia.h"
#include <vector>

class AnuncioProcura: public Anuncio
{
private:
	vector<pair<Membro *, Preco>> condutoresCandidatos;
public:
	AnuncioProcura();
	AnuncioProcura(Particular* anunciante);
	void adicionarCondutorCandidato(pair<Membro *, Preco> &condutorCandidato);
	void setAnunciante(Particular* anunciante);
	Particular* getAnunciante() const;
	void criar(vector<Combustivel> *combustiveis);
	void save(ofstream &file, vector<Membro *> *membros);
	void load(ifstream &file, vector<Membro *> *membros);
	friend ostream& operator<<(ostream &os, const AnuncioProcura &anuncio);
	void editar();
	void show()const;
};

#endif

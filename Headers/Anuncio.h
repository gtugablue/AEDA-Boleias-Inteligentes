#ifndef _ANUNCIO_H
#define _ANUNCIO_H

#include "Membro.h"
#include "Particular.h"
#include "Viagem.h"

using namespace std;

class Anuncio
{
private:
	string titulo;
	string descricao;
	vector<Particular *> candidatos;
	float precoTotal;
	Viagem* viagem;
public:
	Anuncio(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, Viagem* viagem);
	string getTitulo() const;
	string getDescricao() const;
	Coordenadas getOrigem() const;
	Coordenadas getDestino() const;
	virtual Membro* getAnunciante() const = 0;
	void setTitulo(const string &titulo);
	void setDescricao(const string &descricao);
	void setOrigem() const;
	void setDestino() const;
	virtual void setAnunciante() const = 0;
	void adicionarCandidato(Particular* candidato);
	void aceitarCandidato(Particular* candidato);
	void removerCandidato(Particular* candidato);
	void calcularPrecoTotal();
	virtual ~Anuncio();
};

#endif

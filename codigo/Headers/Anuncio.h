#ifndef _ANUNCIO_H
#define _ANUNCIO_H

#include "Membro.h"
#include "Particular.h"
#include "Viagem.h"
#include "Preco.h"

using namespace std;

class Anuncio
{
protected:
	string titulo;
	string descricao;
	Viagem* viagem;
	Membro* anunciante;
	Membro* condutor;
public:
	Anuncio(const string &titulo, const string &descricao, Membro* anunciante, Viagem* viagem);
	string getTitulo() const;
	string getDescricao() const;
	Coordenadas getOrigem() const;
	Coordenadas getDestino() const;
	Membro* getAnunciante() const;
	void setTitulo(const string &titulo);
	void setDescricao(const string &descricao);
	void setOrigem(Coordenadas &o) const;
	void setDestino(Coordenadas &d) const;
	void setAnunciante() const;
	void calcularPrecoTotal();
	virtual void show() const;
	virtual void criar(Membro* utilizadorAtual);
};

#endif

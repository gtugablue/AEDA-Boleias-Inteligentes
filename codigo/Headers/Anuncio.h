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
	Coordenadas origem;
	Coordenadas destino;
	vector<Particular*> passageiros; // Número total de pessoas no veículo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; // se for igual ao inicio é um evento
	Membro* anunciante;
	Membro* condutor;
public:
	Anuncio();
	Anuncio(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim);
	string getTitulo() const;
	string getDescricao() const;
	Membro* getAnunciante() const;
	void setTitulo(const string &titulo);
	Coordenadas getOrigem();
	Coordenadas getDestino();
	void setDescricao(const string &descricao);
	void setAnunciante(Membro* membro);
	void calcularPrecoTotal();
	virtual void show() const;
	virtual void criar() = 0;
	virtual void editar() = 0;

	friend ostream& operator<<(ostream &os, Anuncio* anuncio);
};

#endif

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
	vector<Particular*> passageiros; // N�mero total de pessoas no ve�culo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; // se for igual ao inicio � um evento
	Membro* anunciante;
	Membro* condutor;
public:
	Anuncio();
	Anuncio(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim);
	string getTitulo() const;
	string getDescricao() const;
	Membro* getAnunciante() const;
	void setTitulo(const string &titulo);
	void setDescricao(const string &descricao);
	void setAnunciante() const;
	void calcularPrecoTotal();
	virtual void show() const;
	virtual void criar();
	
	friend ostream& operator<<(ostream &os, Anuncio* anuncio);
};

#endif

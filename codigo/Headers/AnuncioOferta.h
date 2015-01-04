#ifndef _ANUNCIO_OFERTA_H
#define _ANUNCIO_OFERTA_H

#include "Anuncio.h"
#include <vector>

using namespace std;

class AnuncioOferta: public Anuncio   ///Classe derivada da classe m�e anuncio.
{
private:
public:
	AnuncioOferta();///Construtor por defeito.
	AnuncioOferta(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim, Preco preco);///Construtor da classe com par�metros.
	void setAnunciante(Membro* anunciante);///M�todo para alterar a informa��o de um anunciante
	Membro* getAnunciante() const;///M�todo para retornar o anunciante da Boleia.
	void criar(Membro *utilizadorAtual);///Fun��o para criar um anuncio com a informa��o desta classe derivada.
	friend ostream& operator<<(ostream &os, const AnuncioOferta &anuncio);///Overload do operador de impress�o de anuncios.
	void editar();///Fun��o para alterar a informa��o de um anuncio.
	void show()const;///Fun��o para mostrar na consola a informa��o de um anuncio de oferta.
};

#endif

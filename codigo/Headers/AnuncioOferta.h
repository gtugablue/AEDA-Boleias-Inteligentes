#ifndef _ANUNCIO_OFERTA_H
#define _ANUNCIO_OFERTA_H

#include "Anuncio.h"
#include <vector>

using namespace std;

class AnuncioOferta: public Anuncio   ///Classe derivada da classe mãe anuncio.
{
private:
public:
	AnuncioOferta();///Construtor por defeito.
	AnuncioOferta(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim, Preco preco);///Construtor da classe com parâmetros.
	void setAnunciante(Membro* anunciante);///Método para alterar a informação de um anunciante
	Membro* getAnunciante() const;///Método para retornar o anunciante da Boleia.
	void criar(Membro *utilizadorAtual);///Função para criar um anuncio com a informação desta classe derivada.
	friend ostream& operator<<(ostream &os, const AnuncioOferta &anuncio);///Overload do operador de impressão de anuncios.
	void editar();///Função para alterar a informação de um anuncio.
	void show()const;///Função para mostrar na consola a informação de um anuncio de oferta.
};

#endif

#include "../headers/AnuncioOferta.h"

AnuncioOferta::AnuncioOferta(const string &titulo, const string &descricao, Preco* preco, Viagem* viagem, Membro* anunciante):
Anuncio(titulo, descricao, anunciante, viagem)
{
	this->preco = preco;
}
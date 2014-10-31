#include "../headers/AnuncioOferta.h"

AnuncioOferta::AnuncioOferta(const string &titulo, const string &descricao, Preco* precoTotal, Viagem* viagem, Membro* anunciante):
Anuncio(titulo, descricao, precoTotal, viagem)
{
	this->anunciante = anunciante;
}
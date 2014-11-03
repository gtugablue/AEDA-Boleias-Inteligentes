#include "../headers/AnuncioOferta.h"

AnuncioOferta::AnuncioOferta()
{
	 
}

AnuncioOferta::AnuncioOferta(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim, Preco* preco):
Anuncio(titulo, descricao, origem, destino, dataInicio, dataFim)
{
	this->preco = preco;
}

void AnuncioOferta::criar()
{
	Anuncio::criar();
	preco->criar();
}
#include "../headers/AnuncioProcura.h"

AnuncioProcura::AnuncioProcura()
{

}

void AnuncioProcura::criar()
{
	Anuncio::criar();
}

void AnuncioProcura::editar()
{
	return editar();
}

ostream& operator<<(ostream &os, const AnuncioProcura &anuncio)
{
	return os << anuncio.getTitulo();
}
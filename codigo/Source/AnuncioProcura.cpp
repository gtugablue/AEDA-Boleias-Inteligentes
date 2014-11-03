#include "../headers/AnuncioProcura.h"

AnuncioProcura::AnuncioProcura()
{

}

void AnuncioProcura::criar()
{
	Anuncio::criar();
}

ostream& operator<<(ostream &os, const AnuncioProcura &anuncio)
{
	return os << anuncio.getTitulo();
}
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
	Anuncio::editar();
}

void AnuncioProcura::save(ofstream &file, vector<Membro *> *membros)
{
	// Guardar condutores candidatos
	file << condutoresCandidatos.size() << endl;
	for (size_t i = 0; i < condutoresCandidatos.size(); ++i)
	{
		for (size_t j = 0; j < membros->size(); ++j)
		{
			if (condutoresCandidatos[i] == (*membros)[j])
			{
				file << j;
				break;	// Next condutor candidato
			}
		}
	}
}

ostream& operator<<(ostream &os, const AnuncioProcura &anuncio)
{
	return os << anuncio.getTitulo();
}
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
	Anuncio::save(file, membros);
	// Guardar condutores candidatos
	file << condutoresCandidatos.size() << endl;
	for (size_t i = 0; i < condutoresCandidatos.size(); ++i)
	{
		for (size_t j = 0; j < membros->size(); ++j)
		{
			if (condutoresCandidatos[i] == (*membros)[j])
			{
				file << j << endl;
				break;	// Next condutor candidato
			}
		}
	}
}

void AnuncioProcura::load(ifstream &file, vector<Membro *> *membros)
{
	Anuncio::load(file, membros);
	// Carregar condutores candidatos
	unsigned numCondutores, ID;
	file >> numCondutores;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < numCondutores; ++i)
	{
		file >> ID;
		file.ignore(1000, '\n');
		condutoresCandidatos.push_back((*membros)[ID]);
	}
}

ostream& operator<<(ostream &os, const AnuncioProcura &anuncio)
{
	return os << anuncio.getTitulo();
}

void AnuncioProcura::show()const
{
	Anuncio::show();
	for (size_t i = 0; i < condutoresCandidatos.size(); i++)
	{
		cout << condutoresCandidatos.at(i)->getNome() << endl;
	}
}
#include "../headers/AnuncioProcura.h"

AnuncioProcura::AnuncioProcura()
{

}

void AnuncioProcura::adicionarCondutorCandidato(pair<Membro *, Preco> &condutorCandidato)
{
	condutoresCandidatos.push_back(condutorCandidato);
}

void AnuncioProcura::criar(vector<Combustivel> *combustiveis)
{
	Anuncio::criar(combustiveis);
}

void AnuncioProcura::editar()
{
	Anuncio::editar();
}

vector<pair<Membro *, Preco>> AnuncioProcura::getCondutoresCandidatos()
{
	return condutoresCandidatos;
}

void AnuncioProcura::cleanCondutoresCandidatos()
{
	condutoresCandidatos.clear();
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
			if (condutoresCandidatos[i].first == (*membros)[j])
			{
				file << j << endl;
				condutoresCandidatos[i].second.save(file);
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
		Preco preco;
		preco.load(file);
		condutoresCandidatos.push_back(make_pair((*membros)[ID], preco));
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
		cout << condutoresCandidatos[i].first->getNome() << endl;
	}
}

ostream& operator<<(ostream &os, pair < Membro *, Preco > condutorCandidato)
{
	return os << condutorCandidato.first->getNome() << " - " << condutorCandidato.second;
}
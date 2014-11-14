#include "../headers/AnuncioProcura.h"

AnuncioProcura::AnuncioProcura()
{

}

void AnuncioProcura::adicionarCondutorCandidato(CondutorCandidato *condutorCandidato)
{
	condutoresCandidatos.push_back(condutorCandidato);
}

bool AnuncioProcura::podeSerPassageiro(Membro* membro) const
{
	if (Anuncio::podeSerPassageiro(membro))
	{
		for (size_t i = 0; i < condutoresCandidatos.size(); ++i)
		{
			if (condutoresCandidatos[i]->condutor == membro)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool AnuncioProcura::podeSerCondutor(Membro* membro) const
{
	if (Anuncio::podeSerCondutor(membro))
	{
		for (size_t i = 0; i < condutoresCandidatos.size(); ++i)
		{
			if (condutoresCandidatos[i]->condutor == membro)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

void AnuncioProcura::criar(Membro *utilizadorAtual)
{
	Anuncio::criar(utilizadorAtual);
	passageiros.push_back((Particular *)utilizadorAtual);
}

void AnuncioProcura::editar()
{
	Anuncio::editar();
}

vector<CondutorCandidato *> AnuncioProcura::getCondutoresCandidatos()
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
			if (condutoresCandidatos[i]->condutor == (*membros)[j])
			{
				file << j << endl;
				condutoresCandidatos[i]->preco.save(file);
				for (size_t k = 0; k < condutoresCandidatos[i]->condutor->getVeiculos().size(); ++k)
				{
					if (condutoresCandidatos[i]->condutor->getVeiculos()[i] == condutoresCandidatos[i]->veiculo)
					{
						file << k << endl;
						break;
					}
				}
				break;	// Next condutor candidato
			}
		}
	}
}

void AnuncioProcura::load(ifstream &file, vector<Membro *> *membros)
{
	Anuncio::load(file, membros);
	// Carregar condutores candidatos
	unsigned numCondutores, ID, ID2;
	file >> numCondutores;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < numCondutores; ++i)
	{
		file >> ID;
		file.ignore(1000, '\n');
		Preco preco;
		preco.load(file);
		CondutorCandidato *condutorCandidato = new CondutorCandidato();
		condutorCandidato->condutor = (*membros)[ID];
		condutorCandidato->preco = preco;
		file >> ID2;
		file.ignore(1000, '\n');
		condutorCandidato->veiculo = (*membros)[ID]->getVeiculos()[ID2];
		condutoresCandidatos.push_back(condutorCandidato);
	}
}

ostream& operator<<(ostream &os, const AnuncioProcura &anuncio)
{
	return os << anuncio.getTitulo();
}

void AnuncioProcura::show()const
{
	Anuncio::show();

	// Não há necessidade de mostrar os condutores candidatos no show do Anuncio
	/*cout << endl << "Condutores candidatos: ";
	if (condutoresCandidatos.size() == 0)
	{
		cout << "Nenhum" << endl << endl;
		return;
	}
	cout << endl;
	for (size_t i = 0; i < condutoresCandidatos.size(); i++)
	{
		cout << condutoresCandidatos[i].first->getNome() << endl;
	}*/
}

ostream& operator<<(ostream &os, CondutorCandidato *condutorCandidato)
{
	return os << condutorCandidato->condutor->getNome() << " - " << condutorCandidato->preco;
}
#include "../headers/Boleia.h"

Boleia::Boleia(Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim, const Hora &horaInicio, const Hora &horaFim) :
origem(localInicio), destino(localFim), dataInicio(dataInicio), dataFim(dataFim)
{
	this->condutor = NULL;
	this->veiculo = veiculo;
}

Boleia::Boleia(Membro* condutor, Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim, const Hora &horaInicio, const Hora &horaFim) :
origem(localInicio), destino(localFim), dataInicio(dataInicio), dataFim(dataFim)
{ 
	this->condutor = condutor;
	this->veiculo = veiculo;
}

Membro* Boleia::getCondutor() const
{
	return condutor;
}

Veiculo* Boleia::getVeiculo()const
{
	return veiculo;

}

void Boleia::setCondutor(Membro* condutor)
{
	this->condutor = condutor;
}

void Boleia::setVeiculo(Veiculo* veiculo)
{
	this->veiculo = veiculo;
}

void Boleia::removerPassageiro(Particular* passageiro)
{
	for (size_t i = 0; i < passageiros.size(); ++i)
	{
		if (passageiros[i] == passageiro)
		{
			passageiros.erase(passageiros.begin() + i);
			return;
		}
	}
}

vector<Particular*>Boleia::getPassageiros() const
{
	return  passageiros;
}

bool Boleia::isMembroInBoleia(Membro* membro) const
{
	if (condutor == membro)
	{
		return true;
	}
	for (size_t i = 0; i < passageiros.size(); ++i)
	{
		if (passageiros[i] == membro)
		{
			return true;
		}
	}
	return false;
}

void Boleia::show()
{
	cout << "Boleia" << endl;
	cout << endl;
	cout << "Condutor" << endl;
	condutor->show();
	cout << "Coordenadas de Inicio" <<endl;
	origem.showcoord();
	cout << "Coordenadas de Fim" << endl;
	destino.showcoord();
	cout << endl;
	for (size_t i = 0; i < passageiros.size(); i++)
	{
		passageiros.at(i)->show();
	}
	cout << "Data de Inicio: " << dataInicio << endl;
	cout << "Data de Fim: " << dataFim << endl;

}

void Boleia::load(ifstream &file, vector<Membro *> *membros)
{
	int ID;
	getline(file, titulo);
	getline(file, descricao);
	origem.load(file);
	destino.load(file);
	preco.load(file);
	unsigned numPassageiros;
	file >> numPassageiros;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < numPassageiros; ++i)
	{
		file >> ID;
		file.ignore(1000, '\n');
		passageiros[i] = (Particular *)((*membros)[ID]);
	}

	dataInicio.load(file);
	dataFim.load(file);

	file >> ID;
	file.ignore(1000, '\n');
	if (ID < 0)
	{
		condutor = NULL;
	}
	else
	{
		condutor = (*membros)[ID];
	}

	file >> ID;
	file.ignore(1000, '\n');
	if (ID < 0)
	{
		veiculo = NULL;
	}
	else
	{
		veiculo = condutor->getVeiculos()[ID];
	}

	horaInicio.load(file);
	horaFim.load(file);
	file >> diaDaSemana;
	file.ignore(1000, '\n');
}

void Boleia::save(ofstream &file, vector<Membro *> *membros)
{
	file << titulo << endl;
	file << descricao << endl;
	origem.save(file);
	destino.save(file);
	preco.save(file);

	// Guardar passageiros
	file << passageiros.size() << endl;
	for (size_t i = 0; i < passageiros.size(); ++i)
	{
		for (size_t j = 0; j < membros->size(); ++j)
		{
			if (passageiros[i] == (*membros)[j])
			{
				file << j << endl;
				break;	// Next passageiro
			}
		}
	}

	dataInicio.save(file);
	dataFim.save(file);

	// Guardar condutor
	if (condutor == NULL)
	{
		file << -1 << endl;
	}
	else
	{
		for (size_t i = 0; i < membros->size(); ++i)
		{
			if ((*membros)[i] == condutor)
			{
				file << i << endl;
				break;
			}
		}
	}

	// Guardar veiculo
	if (veiculo == NULL)
	{
		file << -1 << endl;
	}
	else
	{
		for (size_t i = 0; i < condutor->getVeiculos().size(); ++i)
		{
			if (condutor->getVeiculos()[i] == veiculo)
			{
				file << i << endl;
				break;
			}
		}
	}

	horaInicio.save(file);
	horaFim.save(file);
	file << diaDaSemana << endl;
}
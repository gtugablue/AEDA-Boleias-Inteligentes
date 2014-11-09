#include "../headers/Anuncio.h"

Anuncio::Anuncio()
{

}

Anuncio::Anuncio(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim) :
titulo(titulo), descricao(descricao), origem(origem), destino(destino), dataInicio(dataInicio), dataFim(dataFim)
{
}

string Anuncio::getTitulo() const
{
	return titulo;
}

string Anuncio::getDescricao() const
{
	return descricao;
}

void Anuncio::setTitulo(const string &titulo)
{
	this->titulo = titulo;
}

void Anuncio::setVeiculo(Veiculo* veiculo)
{
	this->veiculo = veiculo;
}

Veiculo* Anuncio::getVeiculo()
{
	return veiculo;
}

Membro* Anuncio::getCondutor()
{
	return condutor;
}

Preco* Anuncio::getPreco()
{
	return &preco;
}

void Anuncio::setCondutor(Membro* membro)
{
	condutor = membro;
}

void Anuncio::setPreco(const Preco &preco)
{
	this->preco = preco;
}

Coordenadas Anuncio::getOrigem()
{
	return origem;
}

Coordenadas Anuncio::getDestino()
{
	return destino;
}

vector<Particular *> Anuncio::getPassageiros()
{
	return passageiros;
}

Hora Anuncio::getHora() const
{
	return hora;
}

Data Anuncio::getDataInicio() const
{
	return dataInicio;
}

Data Anuncio::getDataFim() const
{
	return dataFim;
}

void Anuncio::setDescricao(const string &descricao)
{
	this->descricao = descricao;
}

Membro* Anuncio::getAnunciante() const
{
	return anunciante;
}

void Anuncio::setAnunciante(Membro* membro)
{
	anunciante = membro;
}

void Anuncio::addPassageiro(Particular *membro)
{
	passageiros.push_back(membro);
}

void Anuncio::show() const
{
	cout << "Titulo: " << titulo << endl;
	cout << "Descricao: " << descricao << endl;
	cout << endl << "Origem:" << endl;
	origem.show();
	cout << endl << "Destino:" << endl;
	destino.show();
	cout << endl << "Distancia total: " << origem.calcDistancia(destino) << " m" << endl;
	if (dataInicio == dataFim)
	{
		cout << "Data: " << dataInicio << endl;
	}
	else
	{
		cout << "Data de inicio: " << dataInicio << endl;
		cout << "Data de fim: " << dataFim << endl;
	}
	cout << "Anunciante: " << anunciante->getNome() << endl;
	if (condutor != NULL)
	{
		cout << "Condutor: " << condutor->getNome() << endl;
	}
	if (veiculo != NULL)
	{
		cout << endl << "Veiculo: " << endl;
		veiculo->show();
		cout << endl;
	}
	cout << endl << "Preco:" << endl;
	preco.show();
	cout << endl << endl << "Hora: " << hora << endl;
}

void Anuncio::load(ifstream &file, vector<Membro *> *membros)
{
	int ID;
	getline(file, titulo);
	getline(file, descricao);
	origem.load(file);
	destino.load(file);
	unsigned numPassageiros;
	file >> numPassageiros;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < numPassageiros; ++i)
	{
		file >> ID;
		file.ignore(1000, '\n');
		passageiros.push_back((Particular *)(*membros)[ID]);
	}
	dataInicio.load(file);
	dataFim.load(file);
	file >> ID;
	file.ignore(1000, '\n');
	anunciante = (*membros)[ID];

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

	preco.load(file);
	hora.load(file);
}

void Anuncio::save(ofstream &file, vector<Membro *> *membros)
{
	file << titulo << endl;
	file << descricao << endl;
	origem.save(file);
	destino.save(file);

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

	// Guardar anunciante
	for (size_t i = 0; i < membros->size(); ++i)
	{
		if ((*membros)[i] == anunciante)
		{
			file << i << endl;
			break;
		}
	}

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

	preco.save(file);
	hora.save(file);
}

void Anuncio::criar(Membro* utilizadorAtual)
{
	cout << "Introduza um titulo: ";
	getline(cin, titulo);
	cout << "Introduza uma descricao: ";
	getline(cin, descricao);
	cout << "Introduza as coordenadas de origem:" << endl;
	origem.criar();
	cout << "Introduza as coordenadas de destino:" << endl;
	destino.criar();
	cout << "Introduza a data de inicio (apenas deve diferir da data de fim caso seja uma boleia a repetir-se semanalmente):" << endl;
	dataInicio.criar();
	cout << "Introduza a data de fim (apenas deve diferir da data de inicio caso seja uma boleia a repetir-se semanalmente):" << endl;
	dataFim.criar();
	cout << "Introduza a hora da boleia:" << endl;
	hora.criar();
	anunciante = utilizadorAtual;
}

void Anuncio::editar()
{
	cout << "Pretende editar o titulo (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		while (1)
		{
			try
			{
				cout << "Introduza o novo titulo: ";
				titulo = InputUtils::readLine();
				break;
			}
			catch (InvalidInputException<string> e)
			{
				cout << "Erro: " << e.info << endl << endl;
			}
		}
	}
	cout << "Pretende editar a descricao (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		while (1)
		{
			try
			{
				cout << "Introduza a nova descricao: ";
				descricao = InputUtils::readLine();
				break;
			}
			catch (InvalidInputException<string> e)
			{
				cout << "Erro: " << e.info << endl << endl;
			}
		}
	}
	cout << "Pretende editar a origem (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		origem.editar();
	}
	cout << "Pretende editar o destino (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		destino.editar();
	}
	cout << "Pretende editar a data de inicio (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		dataInicio.editar();
	}
	cout << "Pretende editar a data de fim (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		dataFim.editar();
	}
	cout << "Pretende editar a hora (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza a nova hora: ";
		hora.editar();
	}
}

bool Anuncio::isPronto() const
{
	if (condutor == NULL || veiculo == NULL)
	{
		return false;
	}
	return true;
}

bool Anuncio::podeSerPassageiro(Membro* membro) const
{
	if (dynamic_cast<Particular *>(membro) == NULL)
	{
		// Empresa
		return false;
	}
	else if (veiculo == NULL)
	{
		return false;
	}
	else if (condutor == membro)
	{
		return false;
	}
	else if (find(passageiros.begin(), passageiros.end(), membro) != passageiros.end())
	{
		return false;
	}
	else
	{
		return passageiros.size() < veiculo->getLotacao();
	}
}

bool Anuncio::podeSerCondutor(Membro* membro) const
{
	if (find(passageiros.begin(), passageiros.end(), membro) != passageiros.end())
	{
		return false;
	}
	return condutor == NULL;
}

void Anuncio::updateConhecidos()
{
	vector<Membro *> passageirosMaisCondutor;
	for (size_t i = 0; i < passageiros.size(); ++i)
	{
		passageirosMaisCondutor.push_back(passageiros[i]);
	}
	passageirosMaisCondutor.push_back(condutor);
	for (size_t i = 0; i < passageiros.size(); ++i)
	{
		passageiros[i]->updateConhecidos(passageirosMaisCondutor);
	}
}

ostream& operator<<(ostream &os, Anuncio* anuncio)
{
	return os << anuncio->getTitulo();
}

double Anuncio::calcularFriendPoints(const Particular* utilizadorAtual) const
{
	double friendPoints = 0;
	if (condutor != NULL)
	{
		for (size_t i = 0; i < utilizadorAtual->getConhecidos().size(); ++i)
		{
			if (condutor == utilizadorAtual->getConhecidos()[i].first)
			{
				friendPoints += sqrt(utilizadorAtual->getConhecidos()[i].second);	/// sqrt() to make sure the number doesn't grow too fast
				break;
			}
		}
	}
	for (size_t i = 0; i < passageiros.size(); ++i)
	{
		for (size_t j = 0; j < utilizadorAtual->getConhecidos().size(); ++j)
		{
			if (passageiros[i] == utilizadorAtual->getConhecidos()[j].first)
			{
				friendPoints += sqrt(utilizadorAtual->getConhecidos()[j].second);	// sqrt() to make sure the number doesn't grow too fast
				break; // Próximo passageiro
			}
		}
	}
	return friendPoints;
}

double Anuncio::calcularDistanciaPoints(const Coordenadas &origem, const Coordenadas &destino) const
{
	return ((this->origem.calcDistancia(this->destino) + origem.calcDistancia(destino)) / 2) / (this->origem.calcDistancia(origem) + this->destino.calcDistancia(destino));
}

double Anuncio::calcularAnuncioPoints(const Particular* utilizadorAtual, const Coordenadas &origem, const Coordenadas &destino) const
{
	return calcularFriendPoints(utilizadorAtual) * calcularDistanciaPoints(origem, destino);
}
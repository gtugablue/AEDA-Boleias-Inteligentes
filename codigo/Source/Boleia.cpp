#include "../headers/Boleia.h"

Boleia::Boleia(Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim) :
origem(localInicio), destino(localFim), dataInicio(dataInicio), dataFim(dataFim)
{
	this->condutor = NULL;
	this->veiculo = veiculo;
}

Boleia::Boleia(Membro* condutor, Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim):
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
	condutor->showmembros();
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

void Boleia::cria()
{
	if (condutor != NULL)
	{
		condutor->criaMembro();
	}
	veiculo->criar();
	origem.criar();
	destino.criar();
	dataInicio.criar();
	dataFim.criar();
}



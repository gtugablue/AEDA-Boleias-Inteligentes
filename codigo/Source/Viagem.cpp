#include "../headers/Viagem.h"

Viagem::Viagem(Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim) :
localInicio(localInicio), localFim(localFim), dataInicio(dataInicio), dataFim(dataFim)
{
	this->condutor = NULL;
	this->veiculo = veiculo;
}

Viagem::Viagem(Membro* condutor, Veiculo* veiculo, const Coordenadas &localInicio, const Coordenadas &localFim, const Data &dataInicio, const Data &dataFim):
localInicio(localInicio), localFim(localFim), dataInicio(dataInicio), dataFim(dataFim)
{ 
	this->condutor = condutor;
	this->veiculo = veiculo;
}

Membro* Viagem::getCondutor() const
{
	return condutor;
}

Veiculo* Viagem::getVeiculo()const
{
	return veiculo;

}

Coordenadas Viagem::getLocalInicio()const
{
	return localInicio;
}

Coordenadas Viagem::getLocalFim()const
{
	return localFim;
}

void Viagem::setCondutor(Membro* condutor)
{
	this->condutor = condutor;
}

void Viagem::setLocalFim(const Coordenadas &localFim)
{
	this->localFim = localFim;
}
void Viagem::setLocalInicio(const Coordenadas &localInicio)
{
	this->localInicio = localInicio;
}

void Viagem::setVeiculo(Veiculo* veiculo)
{
	this->veiculo = veiculo;
}

vector<Particular*>Viagem::getPassageiros() const
{
	return  passageiros;
}

void Viagem::showViagem()
{
	cout << "Viagem" << endl;
	cout << endl;
	cout << "Condutor" << endl;
	condutor->showmembros();
	cout << "Coordenadas de Inicio" <<endl;
	localInicio.showcoord();
	cout << "Coordenadas de Fim" << endl;
	localFim.showcoord();
	cout << endl;
	for (size_t i = 0; i < passageiros.size(); i++)
	{
		passageiros.at(i)->showparticulares();
	}
	cout << "Data de Inicio" << endl;
	dataInicio.showdata();
	cout << "Data de Fim" << endl;
	dataFim.showdata();

}

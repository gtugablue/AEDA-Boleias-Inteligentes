#include "../headers/Motorista.h"

using namespace std;

#define	MOTORISTA_ORDENACAO_DIST_MIN		0.005

bool Motorista::orderByNome(const Motorista &motorista)
{
	return nome < motorista.nome;
}

Motorista::Motorista()
{

}

Motorista::Motorista(const string &nome, const Coordenadas &morada, const Coordenadas &garagem) :
nome(nome), morada(morada), distancia(morada.calcDistancia(garagem))
{

}

void Motorista::setNome(const string &nome)
{
	this->nome = nome;
}

void Motorista::setMorada(const Coordenadas &morada, const Coordenadas &garagem)
{
	this->morada = morada;
	updateDistancia(garagem);
}

string Motorista::getNome() const
{
	return nome;
}

Coordenadas Motorista::getMorada() const
{
	return morada;
}

double Motorista::getDistancia() const
{
	return distancia;
}

void Motorista::criar(const Coordenadas &garagem)
{
	cout << "Introduza o nome: ";
	getline(cin, nome);
	cout << "Morada: " << endl;
	morada.criar();
	updateDistancia(garagem);
}

void Motorista::editar(const Coordenadas &garagem)
{
	
}

void Motorista::updateDistancia(const Coordenadas &garagem)
{
	distancia = morada.calcDistancia(garagem);
}

void Motorista::save(ofstream &file) const
{
	file << nome << endl;
	morada.save(file);
}

void Motorista::load(std::ifstream &file, const Coordenadas &garagem)
{
	file >> nome;
	file.ignore(1000, '\n');
	morada.load(file);
	updateDistancia(garagem);
}

bool Motorista::operator<(const Motorista &motorista) const
{
	if (fabs(distancia - motorista.distancia) < MOTORISTA_ORDENACAO_DIST_MIN)
	{
		return nome < motorista.nome;
	}
	else
	{
		return distancia < motorista.distancia;
	}
}

bool Motorista::operator==(const Motorista &motorista) const
{
	return nome == motorista.nome;
}

ostream &operator<<(ostream &os, const Motorista &motorista)
{
	return os << motorista.nome << endl;
}
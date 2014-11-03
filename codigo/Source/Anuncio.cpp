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
Coordenadas Anuncio::getOrigem()
{
	return origem;
}

Coordenadas Anuncio::getDestino()
{
	return destino;
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

/*void Anuncio::adicionarCandidato(Particular* candidato)
{
candidatos.push_back(candidato);
}

void Anuncio::removerCandidato(Particular* candidato)
{
for(size_t i=0; i < candidatos.size();i++)
{
if(candidatos[i]->getUtilizador()==candidato->getUtilizador())
{
candidatos.erase(candidatos.begin()+i);
}
}
}

void Anuncio::aceitarCandidato(Particular* candidato)
{
for(size_t i=0; i < candidatos.size();i++)
{
if(candidatos[i]->getUtilizador()==candidato[i].getUtilizador())
{
//boleia->adicionarPassageiro(candidatos[i]);
}
}
}*/

void Anuncio::show() const
{
	cout << "Titulo: " << titulo << endl;
	cout << "Descricao: " << descricao << endl;
	cout << "Anunciante: " << anunciante->getNome() << endl;
}

void Anuncio::criar()
{
	cout << "Introduza o titulo: ";
	getline(cin, titulo);
	cout << "Introduza uma descricao: ";
	getline(cin, descricao);
	cout << endl << "Origem:" << endl;
	origem.criar();
	cout << endl << "Destino: " << endl;
	destino.criar();
	cout << endl << "Data de inicio: " << endl;
	dataInicio.criar();
	cout << endl << "Data de fim: " << endl;
	dataFim.criar();
}

void Anuncio::editar()
{
	cout << "Pretende editar o titulo (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza o novo titulo: ";
		getline(cin, titulo);
	}
	cout << "Pretende editar a descricao (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza a nova descricao: ";
		getline(cin, descricao);
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
	if(InputUtils::readYesOrNo('y', 'n'))
	{
		dataInicio.editar();
	}
	cout << "Pretende editar a data de fim (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		dataFim.editar();
	}
}

bool Anuncio::isPronto() const
{
	return true;
}

ostream& operator<<(ostream &os, Anuncio* anuncio)
{
	return os << anuncio->getTitulo();
}


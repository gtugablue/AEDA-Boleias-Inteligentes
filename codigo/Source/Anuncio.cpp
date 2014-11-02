#include "../headers/Anuncio.h"

Anuncio::Anuncio(const string &titulo, const string &descricao, Preco* precoTotal, Viagem* viagem):
precoTotal(*precoTotal)
{
	this->titulo = titulo;
	this->descricao = descricao;
	this->viagem = viagem;
}

string Anuncio::getTitulo() const
{
	return titulo;
}

string Anuncio::getDescricao() const
{
	return descricao;
}

Coordenadas Anuncio::getOrigem() const
{
	return viagem->getLocalInicio();
}

Coordenadas Anuncio::getDestino() const
{
	return viagem->getLocalFim();
}

void Anuncio::setTitulo(const string &titulo)
{
	this->titulo = titulo;
}

void Anuncio::setDescricao(const string &descricao)
{
	this->descricao=descricao;
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
			//viagem->adicionarPassageiro(candidatos[i]);
		}
	}
}*/

void Anuncio::setOrigem(Coordenadas &o) const
{
	viagem->setLocalInicio(o);
}

void Anuncio::setDestino(Coordenadas &d) const
{
	viagem->setLocalFim(d);
}


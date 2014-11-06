#include "../headers/AnuncioOferta.h"

AnuncioOferta::AnuncioOferta()
{
	 
}

AnuncioOferta::AnuncioOferta(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim, Preco preco):
Anuncio(titulo, descricao, origem, destino, dataInicio, dataFim)
{
	this->preco = preco;
}

void AnuncioOferta::criar(Membro* utilizadorAtual)
{
	Anuncio::criar(utilizadorAtual);
	// Escolher veiculo
	cout << "Escolha um veiculo da lista que se segue..." << endl;
	InputUtils::pause();
	int input;
	do
	{
		input = OutputUtils::showList(utilizadorAtual->getVeiculos());
	} while (input == -1);
	veiculo = utilizadorAtual->getVeiculos()[input];
	preco.criar();
	preco.updatePrecoCombustivel(veiculo->getConsumo(), veiculo->getCombustivel()->getPreco(), origem.calcDistancia(destino));
}

void AnuncioOferta::editar()
{
	Anuncio::editar();
	
}

ostream& operator<<(ostream &os, const AnuncioOferta &anuncio)
{
	return os << anuncio.getTitulo();
}

void AnuncioOferta::show()const
{
	Anuncio::show();
}
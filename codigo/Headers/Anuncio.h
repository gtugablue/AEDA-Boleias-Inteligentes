#ifndef _ANUNCIO_H
#define _ANUNCIO_H

#include "Membro.h"
#include "Particular.h"
#include "Boleia.h"
#include "Preco.h"
#include "Veiculo.h"
#include "Data.h"
#include <fstream>
#include <vector>
#include <string>
#include "Hora.h"
#include "Coordenadas.h"

#include <queue>

using namespace std;

class Anuncio
{
protected:
	string titulo;
	string descricao;
	Coordenadas origem;
	Coordenadas destino;
	vector<Particular *> passageiros; /// Número total de pessoas no veículo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; /// se for igual ao inicio é um evento
	Membro* anunciante;
	Membro* condutor;
	Veiculo* veiculo;
	Preco preco;
	Hora hora;
	priority_queue<Particular> candidatos; // Candidatos ao anúncio

public:
	Anuncio();///Construtor sem parâmetros
	Anuncio(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim);///Construtor com parâmetros
	string getTitulo() const;///Método para obter o titulo do anuncio
	string getDescricao() const;///Método para obter a descrição do anuncio
	Membro* getAnunciante() const;///Método para obter o membro responsavel pelo Anuncio
	void setTitulo(const string &titulo);///Método para alterar o titulo
	void setVeiculo(Veiculo* veiculo);///Método para alteras as informações do veículo
	Veiculo* getVeiculo();///Método para obter o veiculo do Anuncio
	Membro* getCondutor();///Método para obter o condutor do veiculo
	Preco* getPreco();///Método para obter o preço discriminado do Anuncio de Boleia
	Hora getHora() const;///Método para obter a hora de inicio da Boleia
	Data getDataInicio() const;///Método para obter a data de inicio do anuncio
	Data getDataFim() const;///Método para obter a data de fim do anuncio
	vector<Particular *> getPassageiros();///Método para obter os passageiros ja instalados no veiculo
	void setCondutor(Membro *membro);///Método para alterar o condutor
	void setPreco(const Preco &preco);///Método para alterar o preço do anuncio
	Coordenadas getOrigem();///Método que retorna as coordenadas do local de inicio da Boleia
	Coordenadas getDestino();///Método que retorna as coordenadas do local onde termina a Boleia
	void setDescricao(const string &descricao);///Método para alterar a descrição do anuncio
	void setAnunciante(Membro *membro);///Método para alterar o anunciante
	void addPassageiro(Particular *membro);///Função para adicionar um passageiro á viagem
	void calcularPrecoTotal();///Função para calcular o preço final com todos os custos ja associados
	virtual void show() const;///Função que mostra no ecrã da consola toda a informação de um determinado anuncio.
	virtual void load(ifstream &file, vector<Membro *> *membros);///Função virtual que carrega de um ficheiro para o vector toda a informação do anuncio.
	virtual void save(ofstream &file, vector<Membro *> *membros);///Função virtual que grava a informação do anuncio no ficheiro de anuncios.
	virtual void criar(Membro* utilizadorAtual);///Função virtual responsavel por criar um anuncio
	virtual void editar() = 0;///Função responsavel por editar as componentes de um anuncio.
	bool isPronto() const;///Funçao que confirma se o anuncio já tem condutor e veiculo,ou seja, se já está pronto para começar a viagem.
	virtual bool podeSerPassageiro(Membro* membro) const;///Função responsavel por determinar se um determinado membro é passageiro.Se o for retorna true.
	virtual bool podeSerCondutor(Membro* membro) const;///Funçao responsavel por determinar se um determinado membro é condutor.Se o for retorna true.
	virtual void updateConhecidos();///Função que da update aos conhecidos.
	double calcularFriendPoints(const Particular* utilizadorAtual) const;///Função que calcula os pontos obtidos por um membro de acordo com os conhecidos que posssui e com o numero de vezes que ja viajou com cada conhecido
	double calcularDistanciaPoints(const Coordenadas &origem, const Coordenadas &destino) const;///Função chave para organizar os anuncios por distância pois organiza os pontos atribuidos de acordo com a distancia a que esta do utilizador
	double calcularAnuncioPoints(const Particular* utilizadorAtual, const Coordenadas &origem, const Coordenadas &destino) const;///Calcula o rsultado final entre os friend points e a distancia para ordenar os anuncios
	friend ostream& operator<<(ostream &os, Anuncio* anuncio);///Overload do operador de impressão na classe Anuncio.
	void novoCandidato(Membro* candidato_novo);
	void organizarCandidatos();
	void removerCandidato(Membro* candidato);
	void alterarMorada(Membro* candidato, const Coordenadas &morada);
};

template<class T>///Tratamento da excepção para quando um anuncio esta incompleto.
class AnuncioIncompletoException
{
public:
	T info;
	AnuncioIncompletoException(T info)
	{
		this->info = info;
	}
};

#endif

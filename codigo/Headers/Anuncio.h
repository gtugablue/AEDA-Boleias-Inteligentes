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
	vector<Particular *> passageiros; /// N�mero total de pessoas no ve�culo = passageiros + 1 (condutor)
	Data dataInicio;
	Data dataFim; /// se for igual ao inicio � um evento
	Membro* anunciante;
	Membro* condutor;
	Veiculo* veiculo;
	Preco preco;
	Hora hora;
	priority_queue<Particular> candidatos; // Candidatos ao an�ncio

public:
	Anuncio();///Construtor sem par�metros
	Anuncio(const string &titulo, const string &descricao, const Coordenadas &origem, const Coordenadas &destino, const Data &dataInicio, const Data &dataFim);///Construtor com par�metros
	string getTitulo() const;///M�todo para obter o titulo do anuncio
	string getDescricao() const;///M�todo para obter a descri��o do anuncio
	Membro* getAnunciante() const;///M�todo para obter o membro responsavel pelo Anuncio
	void setTitulo(const string &titulo);///M�todo para alterar o titulo
	void setVeiculo(Veiculo* veiculo);///M�todo para alteras as informa��es do ve�culo
	Veiculo* getVeiculo();///M�todo para obter o veiculo do Anuncio
	Membro* getCondutor();///M�todo para obter o condutor do veiculo
	Preco* getPreco();///M�todo para obter o pre�o discriminado do Anuncio de Boleia
	Hora getHora() const;///M�todo para obter a hora de inicio da Boleia
	Data getDataInicio() const;///M�todo para obter a data de inicio do anuncio
	Data getDataFim() const;///M�todo para obter a data de fim do anuncio
	vector<Particular *> getPassageiros();///M�todo para obter os passageiros ja instalados no veiculo
	void setCondutor(Membro *membro);///M�todo para alterar o condutor
	void setPreco(const Preco &preco);///M�todo para alterar o pre�o do anuncio
	Coordenadas getOrigem();///M�todo que retorna as coordenadas do local de inicio da Boleia
	Coordenadas getDestino();///M�todo que retorna as coordenadas do local onde termina a Boleia
	void setDescricao(const string &descricao);///M�todo para alterar a descri��o do anuncio
	void setAnunciante(Membro *membro);///M�todo para alterar o anunciante
	void addPassageiro(Particular *membro);///Fun��o para adicionar um passageiro � viagem
	void calcularPrecoTotal();///Fun��o para calcular o pre�o final com todos os custos ja associados
	virtual void show() const;///Fun��o que mostra no ecr� da consola toda a informa��o de um determinado anuncio.
	virtual void load(ifstream &file, vector<Membro *> *membros);///Fun��o virtual que carrega de um ficheiro para o vector toda a informa��o do anuncio.
	virtual void save(ofstream &file, vector<Membro *> *membros);///Fun��o virtual que grava a informa��o do anuncio no ficheiro de anuncios.
	virtual void criar(Membro* utilizadorAtual);///Fun��o virtual responsavel por criar um anuncio
	virtual void editar() = 0;///Fun��o responsavel por editar as componentes de um anuncio.
	bool isPronto() const;///Fun�ao que confirma se o anuncio j� tem condutor e veiculo,ou seja, se j� est� pronto para come�ar a viagem.
	virtual bool podeSerPassageiro(Membro* membro) const;///Fun��o responsavel por determinar se um determinado membro � passageiro.Se o for retorna true.
	virtual bool podeSerCondutor(Membro* membro) const;///Fun�ao responsavel por determinar se um determinado membro � condutor.Se o for retorna true.
	virtual void updateConhecidos();///Fun��o que da update aos conhecidos.
	double calcularFriendPoints(const Particular* utilizadorAtual) const;///Fun��o que calcula os pontos obtidos por um membro de acordo com os conhecidos que posssui e com o numero de vezes que ja viajou com cada conhecido
	double calcularDistanciaPoints(const Coordenadas &origem, const Coordenadas &destino) const;///Fun��o chave para organizar os anuncios por dist�ncia pois organiza os pontos atribuidos de acordo com a distancia a que esta do utilizador
	double calcularAnuncioPoints(const Particular* utilizadorAtual, const Coordenadas &origem, const Coordenadas &destino) const;///Calcula o rsultado final entre os friend points e a distancia para ordenar os anuncios
	friend ostream& operator<<(ostream &os, Anuncio* anuncio);///Overload do operador de impress�o na classe Anuncio.
	void novoCandidato(Membro* candidato_novo);
	void organizarCandidatos();
	void removerCandidato(Membro* candidato);
	void alterarMorada(Membro* candidato, const Coordenadas &morada);
};

template<class T>///Tratamento da excep��o para quando um anuncio esta incompleto.
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

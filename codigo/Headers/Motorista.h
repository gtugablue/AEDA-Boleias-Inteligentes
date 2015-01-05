#ifndef _MOTORISTA_H
#define _MOTORISTA_H

#include <string>
#include <iostream>
#include "Coordenadas.h"

struct compareMotoristasByNome;

class Motorista
{
private:
	friend struct compareMotoristasByNome;
	std::string nome;
	Coordenadas morada;
	double distancia;
public:
	Motorista(); /// Construtor sem argumentos
	Motorista(const std::string &nome, const Coordenadas &morada, const Coordenadas &garagem); /// Construtor completo
	void setNome(const std::string &nome); /// Altera o nome do motorista

	/** @brief altera a morada de um motorista
	* 
	* @param morada nova morada do motorista
	* @param garagem localização da garagem da empresa
	*/
	void setMorada(const Coordenadas &morada, const Coordenadas &garagem);

	std::string getNome() const; /// Devolve o nome do motorista
	Coordenadas getMorada() const; /// Devolve a morada do motorista
	double getDistancia() const; /// Devolve a distância da morada do motorista à localização da garagem da empresa
	void criar(const Coordenadas &garagem); /// Cria um novo motorista perguntando os dados ao utilzador
	void editar(const Coordenadas &garagem); /// Pergunta ao utilizador quais atributos do motorista quer alterar e modifica-os de acordo
	void updateDistancia(const Coordenadas &garagem); /// Atualiza a distância da morada do motorista à localização da garagem da empresa
	void save(std::ofstream &file) const; /// Guarda a informação do motorista
	void load(std::ifstream &file, const Coordenadas &garagem); /// Lê a informação do motorista
	bool operator<(const Motorista &motorista) const; /// Compara motoristas pela distância à garagem da empresa e pelo nome
	bool operator==(const Motorista &motorista) const; /// Verifica se dois motoristas têm o mesmo nome
	friend std::ostream &operator<<(std::ostream &os, const Motorista &motorista); /// Imprime o nome de um motorista
};

struct compareMotoristasByNome
{
	bool operator()(const Motorista &motorista1, const Motorista &motorista2)
	{
		return motorista1.nome < motorista2.nome;
	}
};

std::ostream &operator<<(std::ostream &os, const Motorista &motorista);

#endif
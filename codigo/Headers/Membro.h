#ifndef _MEMBRO_H
#define _MEMBRO_H

#include <string>
#include <vector>
#include "Veiculo.h"
#include <iostream>
#include <fstream>
#include "InputUtils.h"
#include "Coordenadas.h"

using namespace std;

class Membro
{
protected:
	string nome;
	string utilizador;
	string password;
	vector<Veiculo *> veiculos;
public:
	Membro();///Construtor por defeito da classe
	Membro(string nome, string utilizador, string password);///Construtor com parametros da classe
	string getNome() const;///Método para retornar o nome do membro
	string getUtilizador() const;///Método para retornar o utilizador do membro
	string getPassword() const;///Método para retornar a password do membro
	virtual Coordenadas getMorada() const = 0;///Método para retornar a morada do membro
	vector<Veiculo *> getVeiculos();///Método para retornar os veiculos associados a um membro
	void setNome(string &nome);///Método para alterar o nome de um membro
	void setUtilizador(string &utilizador);///Método para alterar o utilizador de um membro
	void setPassword(string &password);///Método para alterar a password e um membro
	virtual void setMorada(const Coordenadas &morada) = 0;///Método para alterar a morada de um membro
	void setVeiculos(const vector<Veiculo> &veiculo);///Método para alterar os veiculos associados a um membro
	void addVeiculo(Veiculo *veiculo);///Função para adicionar um veiculo ao vector de veiculos
	void removeVeiculo(Veiculo* veiculo);///Função para remover um veiculo
	virtual void load(ifstream &file, vector<Combustivel> *combustiveis);///Função para carregar a informação de um membro
	virtual void save(ofstream &file, vector<Combustivel> *combustiveis);///Função para gravar a informação de um membro no ficheiro de membros
	virtual void signup() = 0;///Função abstrata para criar um novo utilizador da API
	virtual void edit();///Função virtual para editar a informação relativa a um membro
	virtual void updateConhecidos(vector<Membro *> passageiros);
	virtual void show() const;///Função para imprimir no ecrã toda a informação relativa a um membro
	bool temVeiculo() const;///Função para confirmar se um membro tem veiculos(retorna true caso se confirme)
	bool operator==(const Membro &membro1) const;///Overload do operador == para comparar membros e verificar se os mesmos são iguais.
};

///Tratamento da excepção de quando se verifica o caso de o utilizador ser repetido
template<class T>
class UtilizadorRepetidoException
{
public:
	T info;
	UtilizadorRepetidoException(T info)
	{
		this->info = info;
	}
};

///Excepção lançada quando se pesquisa por um utilizador inexistente
template<class T>
class UtilizadorInexistenteException
{
public:
	T info;
	UtilizadorInexistenteException(T info)
	{
		this->info = info;
	}
};

#endif

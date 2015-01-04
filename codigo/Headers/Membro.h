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
	string getNome() const;///M�todo para retornar o nome do membro
	string getUtilizador() const;///M�todo para retornar o utilizador do membro
	string getPassword() const;///M�todo para retornar a password do membro
	virtual Coordenadas getMorada() const = 0;///M�todo para retornar a morada do membro
	vector<Veiculo *> getVeiculos();///M�todo para retornar os veiculos associados a um membro
	void setNome(string &nome);///M�todo para alterar o nome de um membro
	void setUtilizador(string &utilizador);///M�todo para alterar o utilizador de um membro
	void setPassword(string &password);///M�todo para alterar a password e um membro
	virtual void setMorada(const Coordenadas &morada) = 0;///M�todo para alterar a morada de um membro
	void setVeiculos(const vector<Veiculo> &veiculo);///M�todo para alterar os veiculos associados a um membro
	void addVeiculo(Veiculo *veiculo);///Fun��o para adicionar um veiculo ao vector de veiculos
	void removeVeiculo(Veiculo* veiculo);///Fun��o para remover um veiculo
	virtual void load(ifstream &file, vector<Combustivel> *combustiveis);///Fun��o para carregar a informa��o de um membro
	virtual void save(ofstream &file, vector<Combustivel> *combustiveis);///Fun��o para gravar a informa��o de um membro no ficheiro de membros
	virtual void signup() = 0;///Fun��o abstrata para criar um novo utilizador da API
	virtual void edit();///Fun��o virtual para editar a informa��o relativa a um membro
	virtual void updateConhecidos(vector<Membro *> passageiros);
	virtual void show() const;///Fun��o para imprimir no ecr� toda a informa��o relativa a um membro
	bool temVeiculo() const;///Fun��o para confirmar se um membro tem veiculos(retorna true caso se confirme)
	bool operator==(const Membro &membro1) const;///Overload do operador == para comparar membros e verificar se os mesmos s�o iguais.
};

///Tratamento da excep��o de quando se verifica o caso de o utilizador ser repetido
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

///Excep��o lan�ada quando se pesquisa por um utilizador inexistente
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

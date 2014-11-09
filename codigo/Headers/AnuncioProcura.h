#ifndef _ANUNCIO_PROCURA_H
#define _ANUNCIO_PROCURA_H

#include "Anuncio.h"
#include "Boleia.h"
#include <vector>

struct CondutorCandidato
{
	Membro* condutor;
	Preco preco;
	Veiculo* veiculo;
};

class AnuncioProcura: public Anuncio      ///Classe derivada da classe mãe anuncio
{
private:
	vector<CondutorCandidato> condutoresCandidatos;
public:
	AnuncioProcura();///Construtor por defeito
	AnuncioProcura(Particular* anunciante);///Construtor com parâmetros
	void adicionarCondutorCandidato(CondutorCandidato &condutorCandidato);///Função para adicionar um condutor aos candidatos a condutor da boleia anunciada
	bool podeSerPassageiro(Membro* membro) const;///Função que verifica se um membro pode ser passageiro e retorna true caso tal situacai se verifique
	bool podeSerCondutor(Membro* membro) const;///Método para alterar as informações do anunciante
	vector<CondutorCandidato> getCondutoresCandidatos();///Método para retornar os condutores candidatos.
	void setAnunciante(Particular* anunciante);///Método para alterar um anunciante
	Particular* getAnunciante() const;///Metodo para retornar o anunciante
	void cleanCondutoresCandidatos();///Função para eliminar os condutores candidatos
	void criar(Membro* utilizadorAtual);///Função para criar um anuncio de procura
	void save(ofstream &file, vector<Membro *> *membros);///função para gravar a informação do anuncio no ficheiro respectivo.
	void load(ifstream &file, vector<Membro *> *membros);///função para preencher um anuncio com a informação do respectivo ficheiro txt.
	friend ostream& operator<<(ostream &os, const AnuncioProcura &anuncio);///Overload do operador de impressão.
	void editar();///Função que edita as informações de um anuncio.
	void show() const;///Função que imprime no ecra da consola toda a informação de um anuncio.
};

ostream& operator<<(ostream &os, CondutorCandidato condutorCandidato);///Overload do operador de impressao que permite imprimir um condutor candidato no ecra

#endif

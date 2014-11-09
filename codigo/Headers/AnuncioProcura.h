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

class AnuncioProcura: public Anuncio      ///Classe derivada da classe m�e anuncio
{
private:
	vector<CondutorCandidato> condutoresCandidatos;
public:
	AnuncioProcura();///Construtor por defeito
	AnuncioProcura(Particular* anunciante);///Construtor com par�metros
	void adicionarCondutorCandidato(CondutorCandidato &condutorCandidato);///Fun��o para adicionar um condutor aos candidatos a condutor da boleia anunciada
	bool podeSerPassageiro(Membro* membro) const;///Fun��o que verifica se um membro pode ser passageiro e retorna true caso tal situacai se verifique
	bool podeSerCondutor(Membro* membro) const;///M�todo para alterar as informa��es do anunciante
	vector<CondutorCandidato> getCondutoresCandidatos();///M�todo para retornar os condutores candidatos.
	void setAnunciante(Particular* anunciante);///M�todo para alterar um anunciante
	Particular* getAnunciante() const;///Metodo para retornar o anunciante
	void cleanCondutoresCandidatos();///Fun��o para eliminar os condutores candidatos
	void criar(Membro* utilizadorAtual);///Fun��o para criar um anuncio de procura
	void save(ofstream &file, vector<Membro *> *membros);///fun��o para gravar a informa��o do anuncio no ficheiro respectivo.
	void load(ifstream &file, vector<Membro *> *membros);///fun��o para preencher um anuncio com a informa��o do respectivo ficheiro txt.
	friend ostream& operator<<(ostream &os, const AnuncioProcura &anuncio);///Overload do operador de impress�o.
	void editar();///Fun��o que edita as informa��es de um anuncio.
	void show() const;///Fun��o que imprime no ecra da consola toda a informa��o de um anuncio.
};

ostream& operator<<(ostream &os, CondutorCandidato condutorCandidato);///Overload do operador de impressao que permite imprimir um condutor candidato no ecra

#endif

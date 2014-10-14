#include "Anuncio.h"
#include "Veiculo.h"
#include "Particular.h"
#include <vector>
#include "Viagem.h"
#include "Membro.h"

using namespace std;

class AnuncioOferta: public Anuncio
{
private:
	string titulo;
	string descricao;
	Membro* condutor;
	Veiculo* veiculo;
	Viagem* viagem;
	vector<Particular *> candidatos;
	float precoTotal;
public:
	AnuncioOferta(const string &titulo, const string &descricao, const Membro* condutor, const Veiculo* veiculo, Viagem* viagem);
	Veiculo* getVeiculo() const;
	void setVeiculo(Veiculo* veiculo);
	void setPrecoTotal(float precoTotal);
	float getPrecoTotal() const;
	void addCandidato(Particular* candidato);
	void aceitarCandidato(Particular* candidato);
	void recusarCandidato(Particular* candidato);
};

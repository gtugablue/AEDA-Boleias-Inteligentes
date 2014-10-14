#include "Coordenadas.h"
#include "Veiculo.h"
#include "Particular.h"

using namespace std;

class Viagem
{
private:
	Veiculo* veiculo;
	Coordenadas inicio;
	Coordenadas fim;
	vector<Particular*> passageiros;
public:
	Viagem();
	Viagem(Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim);
	Veiculo getVeiculo() const;
	Coordenadas getInicio() const;
	Coordenadas getFim() const;
	void setVeiculo(Veiculo* veiculo);
	void setInicio(const Coordenadas &inicio);
	void setFim(const Coordenadas &fim);
};

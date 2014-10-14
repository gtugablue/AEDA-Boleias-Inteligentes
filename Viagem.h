#include "Coordenadas.h"
#include "Veiculo.h"

using namespace std;

class Viagem
{
private:
	Veiculo veiculo;
	Coordenadas inicio;
	Coordenadas fim;
public:
	Viagem();
	Viagem(Veiculo veiculo, Coordenadas inicio, Coordenadas fim);
	Veiculo getVeiculo() const;
	Coordenadas getInicio() const;
	Coordenadas getFim() const;
	void setVeiculo(const Veiculo &veiculo);
	void setInicio(const Coordenadas &inicio);
	void setFim(const Coordenadas &fim);
};
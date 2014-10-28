#include "Viagem.h"
#include <string>

using namespace std;

class ViagemPeriodica: public Viagem
{
private:
	static const string diasDaSemana[];
	char diaDaSemana;
public:
	ViagemPeriodica(char diaDaSemana, Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim);
	ViagemPeriodica(char diaDaSemana, Membro* condutor, Veiculo* veiculo, const Coordenadas &inicio, const Coordenadas &fim);
	char getDiaDaSemana() const;
	void setDiaDaSemana(char diaDaSemana);
};

static const string diasDaSemana[] =
	{
			"Segunda-feira",
			"Terca-feira",
			"Quarta-feira",
			"Quinta-feira",
			"Sexta-feira",
			"Sabado",
			"Domingo"
	};

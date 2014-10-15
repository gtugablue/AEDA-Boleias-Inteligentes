#include "Viagem.h"
#include <string>

class ViagemPeriodica: public Viagem
{
private:
	static const string diasDaSemana[];
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

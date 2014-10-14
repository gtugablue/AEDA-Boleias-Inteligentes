#include "Evento.h"
#include "Data.h"
#include <string>

using namespace std;

class EventoPeriodico: public Evento
{
private:
	static const string diasDaSemana[];
	unsigned diaDaSemana; // 0 a 6
	Data inicio;
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

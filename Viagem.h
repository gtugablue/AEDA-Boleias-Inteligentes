#include "Coordenadas.h"

using namespace std;

class Viagem
{
private:
	Coordenadas inicio;
	Coordenadas fim;
public:
	Viagem();
	Viagem(Coordenadas inicio, Coordenadas fim);
	Coordenadas getInicio() const;
	Coordenadas getFim() const;
	void setInicio(const Coordenadas &inicio);
	void setFim(const Coordenadas &fim);
};
#include "Coordenadas.h"
#include "Membro.h"

using namespace std;

class Anuncio
{
private:
	Coordenadas origem;
	Coordenadas destino;
	Membro* anunciante;
public:
	Anuncio(const Coordenadas &origem, const Coordenadas &destino);
	Coordenadas getOrigem() const;
	Coordenadas getDestino() const;
	Membro getAnunciante() const;
	void setOrigem() const;
	void setDestino() const;
	void setAnunciante() const;
};

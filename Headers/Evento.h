#include "Data.h"
#include <string>
#include "Coordenadas.h"
#include "Horas.h"

using namespace std;

class Evento
{
private:
	string nome;
	Data data;
	Horas horas;
	Coordenadas local;
public:
	Evento();
	Evento(const string &nome, const Data &data, const Horas &horas, const Coordenadas &local);
	string getNome() const;
	Data getData() const;
	Horas getHoras() const;
	Coordenadas getLocal() const;
	void setNome(const string &nome) const;
	void setData(const Data &data) const;
	void setHoras(const Horas &horas) const;
	void setLocal(const Coordenadas &local) const;
};
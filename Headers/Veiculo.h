#include <string>
#include "Combustivel.h"

using namespace std;

class Veiculo
{
protected:
	string marca;
	unsigned mes;
	unsigned ano;
	unsigned cilindrada;
	Combustivel combustivel;
public:
	Veiculo();
	Veiculo(string marca, unsigned mes, unsigned ano);
	string getMarca() const;
	unsigned getMes() const;
	unsigned getAno() const;
	string getCilindrada() const;
	void setMarca(string &marca);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
	void setCilindrada(const Combustivel &combustivel);
};

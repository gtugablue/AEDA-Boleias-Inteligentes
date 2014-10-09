#include <string>

using namespace std;

class Veiculo
{
protected:
	string marca;
	unsigned mes;
	unsigned ano;
public:
	Veiculo();
	Veiculo(string marca, unsigned mes, unsigned ano);
	string getMarca() const;
	unsigned getMes() const;
	unsigned getAno() const;
	void setMarca(string &marca);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
};
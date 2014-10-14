#include "Membro.h"
#include "Data.h"
#include "Veiculo.h"
#include <vector>;

using namespace std;

class Particular : public Membro
{
private:
	Data dataNascimento;
	vector<Veiculo> veiculos;
public:
	Particular();
	Particular(Data dataNascimento);
	vector<Veiculo> getVeiculos() const;
	Data getDataNascimento() const;
	void setVeiculos(const vector<Veiculo> &veiculo);
	Data setDataNascimento(const Data &data);
};
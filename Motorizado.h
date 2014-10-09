#include "Veiculo.h"
#include "Combustivel.h"
#include <vector>

using namespace std;

class Motorizado : public Veiculo
{
private:
	static vector<Combustivel> combustiveis;
	Combustivel combustivel;
	unsigned lotacao;
public:
	Motorizado();
	Motorizado(Combustivel combustivel, unsigned lotacao);
	Combustivel getCombustivel() const;
	unsigned getLotacao() const;
	void setCombustivel(const Combustivel &combustivel);
	void setLotacao(unsigned lotacao);
};
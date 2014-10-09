#include "Membro.h"
#include "Viagem.h"
#include <vector>

using namespace std;

class Empresa : public Membro
{
	vector<Viagem> viagens;
	string website;
};
#ifndef _PARTICULAR_H
#define _PARTICULAR_H

#include "Membro.h"
#include "Data.h"
#include "Veiculo.h"
#include <vector>

using namespace std;

class Particular : public Membro
{
private:
	//Data dataNascimento;
public:
	Particular(string nome, string utilizador, string password);
	//Particular(Data dataNascimento);
	//Data getDataNascimento() const;
	//Data setDataNascimento(const Data &data);
};

#endif

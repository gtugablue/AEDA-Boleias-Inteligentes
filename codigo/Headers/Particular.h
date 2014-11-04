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
	Data dataNascimento;
public:
	Particular();
	Particular(string nome, string utilizador, string password);
	void show();
	void signup();
	void save(ofstream &file);
};

#endif

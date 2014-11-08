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
	vector<pair<Membro *, unsigned>> conhecidos;
public:
	Particular();
	Particular(string nome, string utilizador, string password);
	vector<pair<Membro*, unsigned>> getConhecidos() const;
	void show();
	void signup();
	void save(ofstream &file, vector<Combustivel> *combustiveis);
	void load(ofstream &file, vector<Combustivel> *combustiveis);	// TODO
	void updateConhecidos(vector<Membro *> passageiros);
};

#endif

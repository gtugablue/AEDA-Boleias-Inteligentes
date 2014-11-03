#ifndef _EMPRESA_H
#define _EMPRESA_H

#include "Membro.h"
#include "Boleia.h"
#include <vector>

using namespace std;

class Empresa : public Membro
{
	string website;
public:
	Empresa();
	Empresa(const string &nome, const string &utilizador, const string &password, const string &website);
	void signup();
	void edit();
};

#endif
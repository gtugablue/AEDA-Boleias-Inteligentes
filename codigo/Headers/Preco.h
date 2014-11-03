#ifndef _PRECO_H
#define _PRECO_H

#include <vector>
#include <string>
#include <iostream>
#include<fstream>
#include "InputUtils.h"

using namespace std;

class Preco
{
private:
	float combustivel;
	float desgaste;
	vector<pair<string, float>> outrasDespesas;
public:
	Preco();
	Preco(float combustivel, float desgaste, const vector<pair<string, float>> &outrasDespesas);
	void showDespesas() const;
	float getCombustivel() const;
	float getDesgaste() const;
	vector<pair<string, float>> getOutrasDespesas() const;
	void setCombustivel(float combustivel);
	void setDesgaste(float desgaste);
	friend ostream& operator<<(ostream &os, const Preco &preco);
	void show() const;
	float calcularTotal() const;
	void criar();
	void load(ifstream &file);
};

#endif
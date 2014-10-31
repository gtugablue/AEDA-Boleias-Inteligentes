#ifndef _PRECO_H
#define _PRECO_H

#include <vector>
using namespace std;

class Preco
{
private:
	float combustivel;
	float desgaste;
	vector<float> outrasDespesas;
public:
	Preco(float combustivel, float desgaste);
	void showDespesas()const;
	string getCombustivel()const;
	float getDesgaste()const;
	void setCombustivel(float combustivel);
	void setDesgaste(float desgaste);
	ostream& operator<< (Preco precinho)const;

};

#endif
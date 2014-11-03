#include "../headers/Preco.h"

Preco::Preco(float combustivel, float desgaste, const vector<pair<string, float>> &outrasDespesas)
{
	this->combustivel = combustivel;
	this->desgaste = desgaste;
}

float Preco::getCombustivel() const
{
	return combustivel;
}

float Preco::getDesgaste() const
{
	return desgaste;
}

vector<pair<string, float>> Preco::getOutrasDespesas() const
{
	return outrasDespesas;
}

ostream& operator<<(ostream &os, const Preco &preco)
{
	os << "Combustivel: " << preco.getCombustivel() << endl;
	os << "Desgaste: " << preco.getDesgaste() << endl;
	vector<pair<string, float>> outrasDespesas = preco.getOutrasDespesas();
	for (size_t i = 0; i < outrasDespesas.size(); ++i)
	{
		os << outrasDespesas[i].first << ": " << outrasDespesas[i].second << endl;
	}
	return os;
}

void Preco::show() const
{
	cout << "Combustivel: " << combustivel << endl;
	cout << "Desgaste: " << desgaste << endl;
	for (size_t i = 0; i < outrasDespesas.size(); ++i)
	{
		cout << outrasDespesas[i].first << ": " << outrasDespesas[i].second << endl;
	}
}

float Preco::calcularTotal() const
{
	float total = combustivel + desgaste;
	for (size_t i = 0; i < outrasDespesas.size(); ++i)
	{
		total += outrasDespesas[i].second;
	}
	return total;
}

void Preco::criar()
{
	// TODO
	cout << "Preco goes here" << endl;
}

void Preco::load()
{
	pair<string, float>a;
	fstream file;
	string cenas;
	float comb, desg,prc;
	file.open("precos.txt");
	int N,S;
	file >> N;
	cin.ignore(1000, '\n');
	for (size_t i = 0; i < N; i++)
	{
		file >> comb;
		cin.ignore(1000, '\n');
		file >> desg;
		cin.ignore(1000, '\n');
		file >> S;
		cin.ignore(1000, '\n');
		for (size_t j = 0; j < S; j++)
		{
			getline(file, cenas);
			file >> prc;
			a.first = cenas;
			a.second = prc;
			outrasDespesas.push_back(a);
		}
	}
}
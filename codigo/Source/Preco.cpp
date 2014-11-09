#include "../headers/Preco.h"

Preco::Preco()
{

}

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

void Preco::show() const
{
	cout << fixed << setprecision(2) <<  "Combustivel: " << combustivel << endl;
	cout << fixed << setprecision(2) << "Desgaste: " << desgaste << endl;
	for (size_t i = 0; i < outrasDespesas.size(); ++i)
	{
		cout << fixed << setprecision(2) << outrasDespesas[i].first << ": " << outrasDespesas[i].second << endl;
	}
	cout << "Preco total: " << calcularTotal() << endl;
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

void Preco::updatePrecoCombustivel(float consumo, float precoCombustivel, double distancia)
{
	combustivel = (float)(100.0 * distancia * precoCombustivel / consumo);
}

void Preco::criar()
{
	string nome;
	float preco;
	pair<string, float> despesas;
	while (1)
	{
		try
		{
			cout << "Introduza o preco do desgaste:" << endl;
			desgaste = InputUtils::readFloat();
			break;
		}
		catch (InvalidInputException<string>e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
	}
	while (1)
	{
		cout << "Deseja introduzir mais despesas (y/n)?" << endl;
		if (InputUtils::readYesOrNo('y', 'n'))
		{
			cout << "Introduza o nome da despesa: " << endl;
			getline(cin, nome);
			despesas.first = nome;
			while (1)
			{
				try
				{
					cout << "Insira o preco da despesa:" << endl;
					preco = InputUtils::readFloat();
					break;
				}
				catch (InvalidInputException<string>e)
				{
					cout << "Erro: " << e.info << endl << endl;
				}
			}
			despesas.second = preco;
			outrasDespesas.push_back(despesas);
		}
		else break;
	}
}

void Preco::save(ofstream &file)
{
	file << fixed << endl;
	file << desgaste << endl;
	file << outrasDespesas.size() << endl;
	for (size_t i = 0; i < outrasDespesas.size(); ++i)
	{
		file << outrasDespesas[i].first << endl;
		file << outrasDespesas[i].second << endl;
	}
}

void Preco::load(ifstream &file)
{
	file >> combustivel;
	file.ignore(1000, '\n');
	file >> desgaste;
	file.ignore(1000, '\n');
	unsigned n;
	file >> n;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < n; i++)
	{
		pair<string, float> despesa;
		getline(file, despesa.first);
		file >> despesa.second;
		file.ignore(1000, '\n');
		outrasDespesas.push_back(despesa);
	}
}

ostream& operator<<(ostream &os, const Preco &preco)
{
	return os << fixed << setprecision(2) << preco.calcularTotal() << " euros" << endl;
}
#include "../headers/Veiculo.h"

Veiculo::Veiculo()
{

}

string Veiculo::getMarca() const
{
	return marca;
}

string Veiculo::getModelo() const
{
	return modelo;
}

unsigned Veiculo::getMes()const
{
	return mes;
}

unsigned Veiculo::getAno()const
{
	return ano;
}

unsigned Veiculo::getCilindrada()const
{
	return cilindrada;
}

unsigned Veiculo::getLotacao() const
{
	return lotacao;
}

void Veiculo::setMarca(string &marca)
{
	this->marca = marca;
	return;

}

void Veiculo::setAno(unsigned ano)
{
	this->ano = ano;
	return;
}

void Veiculo::setMes(unsigned mes)
{
	this->mes = mes;
	return;
}

void Veiculo::setCilindrada(unsigned cilindrada)
{
	this->cilindrada = cilindrada;
	return;
}

void Veiculo::setCombustivel(Combustivel *combustivel)
{
	this->combustivel = combustivel;
	return;
}

Combustivel* Veiculo::escolherCombustivel(vector<Combustivel> *combustiveis)
{
	int input = OutputUtils::showList(*combustiveis);
	if (input == -1)
	{
		return escolherCombustivel(combustiveis);
	}
	else
	{
		return &(*combustiveis)[input];
	}
}

void Veiculo::load(ifstream &file, vector<Combustivel> *combustiveis)
{
	getline(file, marca);
	getline(file, modelo);
	file >> mes;
	file >> ano;
	file >> cilindrada;
	unsigned combustivelID;
	file >> combustivelID;
	combustivel = &(*combustiveis)[combustivelID];
	file >> lotacao;
	file.ignore(1000, '\n');
}

void Veiculo::save(ofstream &file, vector<Combustivel> *combustiveis)
{
	file << marca << endl;
	file << modelo << endl;
	file << mes << endl;
	file << ano << endl;
	file << cilindrada << endl;
	for (size_t i = 0; i < combustiveis->size(); ++i)
	{
		if (&(*combustiveis)[i] == combustivel)
		{
			file << i << endl;
			break;
		}
	}
	file << lotacao << endl;
}

void Veiculo::show() const
{
	cout << "Marca: " << marca << endl;
	cout << "Modelo: " << modelo << endl;
	cout << "Mes: " << mes << endl;
	cout << "Ano: " << ano << endl;
	cout << "Cilindrada: " << cilindrada << endl;
	combustivel->show();
}

void Veiculo::criar(vector<Combustivel> *combustiveis)
{
	cout << "Introduza a marca: ";
	getline(cin, marca);
	cout << "Introduza o modelo: ";
	getline(cin, modelo);
	while (1)
	{
		try
		{
			cout << "Introduza o ano: ";
			if (!(cin >> ano))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw InvalidInputException<string>("Insira um inteiro");
			}
			cin.ignore();
			break;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
	}

	while (1)
	{
		try
		{
			cout << "Insira o mes: ";
			if (!(cin >> mes))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw InvalidInputException<string>("Insira um inteiro");
			}
			else if (mes < 0 || mes > 12)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw DataInvalidaException<string>("Insira um valor igual ou inferior a 12");
			}
			cin.ignore(1000, '\n');
			break;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
		catch (DataInvalidaException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
	}
	while (1)
	{
		try
		{
			cout << "Introduza a cilindrada: ";
			if (!(cin >> cilindrada))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw InvalidInputException<string>("Insira um inteiro");
			}
			cin.ignore();
			break;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
	}
	while (1)
	{
		try
		{
			cout << "Introduza a lotacao maxima: ";
			if (!(cin >> lotacao))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw InvalidInputException<string>("Insira um inteiro");
			}
			cin.ignore();
			break;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
	}
	cout << "Escolha um combustivel da lista que se segue..." << endl;
	InputUtils::pause();
	combustivel = escolherCombustivel(combustiveis);
}

void Veiculo::editar()
{
	// TODO
}

ostream& operator<<(ostream &os, const Veiculo &veiculo)
{
	return os << veiculo.getMarca() << " " << veiculo.getModelo() << endl;
}
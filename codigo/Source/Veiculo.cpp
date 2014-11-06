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
	file.ignore(1000, '\n');
	file >> ano;
	file.ignore(1000, '\n');
	file >> cilindrada;
	file.ignore(1000, '\n');
	unsigned combustivelID;
	file >> combustivelID;
	file.ignore(1000, '\n');
	combustivel = &(*combustiveis)[combustivelID];
	file >> lotacao;
	file.ignore(1000, '\n');
	file >> consumo;
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
	file << consumo << endl;
}

void Veiculo::show() const
{
	cout << "Marca: " << marca << endl;
	cout << "Modelo: " << modelo << endl;
	cout << "Mes: " << mes << endl;
	cout << "Ano: " << ano << endl;
	cout << "Cilindrada: " << cilindrada << endl;
	combustivel->show();
	cout << "Consumo: " << consumo << " l/100km" << endl;
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
			ano = InputUtils::readInt();
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
			mes = InputUtils::readInt();
			if (mes < 0 || mes > 12)
			{
				throw DataInvalidaException<string>("Insira um valor igual ou inferior a 12");
			}
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
			cilindrada = InputUtils::readInt();
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
			lotacao = InputUtils::readInt();
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
			cout << "Introduza o consumo medio do veiculo (l/100km): ";
			lotacao = InputUtils::readDouble();
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

ostream& operator<<(ostream &os, Veiculo *veiculo)
{
	return os << veiculo->getMarca() << " " << veiculo->getModelo() << endl;
}
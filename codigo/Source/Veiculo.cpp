#include "../headers/Veiculo.h"

Veiculo::Veiculo()
{

}

Veiculo::Veiculo(string marca, unsigned mes, unsigned ano,unsigned cilindrada, Combustivel* combustivel)
{
	this->marca = marca;
	this->mes = mes;
	this->ano = ano;
	this->cilindrada = cilindrada;
	this->combustivel = combustivel;
}

string Veiculo::getMarca() const
{
	return marca;
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

Combustivel* Veiculo::getCombustivel() const
{
	return combustivel;
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

void Veiculo::setCombustivel(Combustivel* combustivel)
{
	this->combustivel = combustivel;
	return;
}

void Veiculo::load(ifstream &file)
{
	getline(file, marca);
	getline(file, modelo);
	file >> mes;
	file >> ano;
	file >> cilindrada;
	file.ignore(1000, '\n');
	combustivel->load(file);
	file >> lotacao;
	file.ignore(1000, '\n');
}

void Veiculo::save(ofstream &file)
{
	file << marca;
	file << modelo;
	file << mes;
	file << ano;
	file << cilindrada;
	combustivel->save(file);
	file << lotacao;
}

void Veiculo::show() const
{
	cout << "Veiculo" << endl;
	cout << endl;
	cout << "Marca: " << marca << endl;
	cout << "Mes: " << mes << endl;
	cout << "Ano: " << ano << endl;
	cout << "Cilindrada: " << cilindrada << endl;
	combustivel->show();
}

void Veiculo::criar()
{
	string marca;
	unsigned mes, ano, cilindrada;
	cout << "Introduza a marca: " << endl;
	getline(cin, marca);
	cout << "Introduza o modelo: " << endl;
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
				throw VeiculoInvalidaException<string>("Insira um valor igual ou inferior a 12");
			}
			cin.ignore(1000, '\n');
			break;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
		catch (VeiculoInvalidaException<string> e)
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
	


}

void Veiculo::editar()
{
	// TODO
}

ostream& operator<<(ostream &os, const Veiculo &veiculo)
{
	return os << veiculo.marca << " " << veiculo.modelo << endl;
}
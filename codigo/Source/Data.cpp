#include "../headers/Data.h"

Data::Data()
{
	
}

Data::Data(unsigned dia, unsigned mes, unsigned ano)
{
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

unsigned Data::getDia() const
{
	return dia;
}

unsigned Data::getMes() const
{
	return mes;
}

unsigned Data::getAno() const
{
	return ano;
}

void Data::setDia(unsigned dia)
{
	this->dia = dia;
	return;
}

void Data::setMes(unsigned mes)
{
	this->mes = mes;
	return;
}

void Data::setAno(unsigned ano)
{
	this->ano = ano;
	return;
}

bool Data::operator< (const Data &data)const
{
	if (this->getAno() < data.getAno())
	{
		return true;
	}
	else
	if (this->getAno() == data.getAno())
	{
		if (this->getMes() < data.getMes())
		{
			return true;
		}
		else
		if (this->getMes() == data.getMes())
		{
			if (this->getDia() < data.getDia())
			{
				return true;
			}
			else return false;
		}
		else
			return false;

	}
	else
		return false;
}

void Data::show()
{
	cout << "Data: " << endl;
	cout << endl;
	cout << dia << "/" << mes << "/" << ano;
}

void Data::criar()
{
	while (1)
	{
		try
		{
			cout << "Insira o ano: ";
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
			else if (mes > 12)
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
			cout << "Insira o dia: ";
			if (!(cin >> dia))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw InvalidInputException<string>("Insira um inteiro");
			}
			else if ((mes == 1 && dia > (isBissexto() ? 29 : 28)) || ((mes == 3 || mes == 5 || mes == 8 || mes == 10) && dia > 30) || dia > 31)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw DataInvalidaException<string>("Insira um dia existente");
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
}

bool Data::isBissexto() const
{
	if (ano % 400 == 0 || (ano % 4 == 0) && (ano % 100 != 0)) {
		return true;
	}
	else {
		return false;
	}
}
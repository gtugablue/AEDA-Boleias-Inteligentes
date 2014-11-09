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

void Data::save(ofstream &file)
{
	file << dia << endl;
	file << mes << endl;
	file << ano << endl;
}

void Data::load(ifstream &file)
{
	file >> dia;
	file.ignore(1000, '\n');
	file >> mes;
	file.ignore(1000, '\n');
	file >> ano;
	file.ignore(1000, '\n');
}

void Data::criar()
{
	while (1)
	{
		try
		{
			cout << "Insira o ano: ";
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
		catch (DataInvalidaException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
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
			cout << "Insira o dia: ";
			dia = InputUtils::readInt();
			if ((mes == 2 && dia > (unsigned)(isBissexto() ? 29 : 28)) || ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) || dia > 31)
			{
				throw DataInvalidaException<string>("Insira um dia existente");
			}
			break;
		}
		catch (DataInvalidaException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info << endl << endl;
		}
	}
}

void Data::editar()
{
	return criar();
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

bool Data::operator==(const Data &data) const
{
	return dia == data.dia && mes == data.mes && ano == data.ano;
}

ostream& operator<<(ostream &os, const Data &data)
{
	return os << data.getDia() << "/" << data.getMes() << "/" << data.getAno();
}
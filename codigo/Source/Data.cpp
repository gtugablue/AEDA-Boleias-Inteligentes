#include "../headers/Data.h"

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

void Data::showdata()
{
	cout << "Data :  " << endl;
	cout << endl;
	cout << dia << "/" << mes << "/" << ano;
}



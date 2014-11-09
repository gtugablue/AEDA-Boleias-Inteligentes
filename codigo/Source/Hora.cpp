#include "../headers/Hora.h"

Hora::Hora()
{
	
}

Hora::Hora(unsigned hora, unsigned minuto)
{
	this->hora=hora;
	this->minuto=minuto;
}

unsigned Hora::getHora()const
{
	return hora;
}

unsigned Hora::getMinuto()const
{
	return minuto;
}

void Hora::setHora(unsigned hora)
{
	this->hora=hora;
}

void Hora::setMinuto(unsigned minuto)
{
	this->minuto=minuto;
}

bool Hora::operator<(const Hora &horas)
{
	if(this->getHora() < horas.getHora())
	{
		return true;
	}
	else
	 if(this->getHora()==horas.getHora())
	 {
		 if(this->getMinuto()==horas.getMinuto())
		 {
			 return true;
		 }
		 else
			 return false;
	 }
	 else
		 return false;
}

void Hora::save(ofstream &file)
{
	file << hora << endl;
	file << minuto << endl;
}

void Hora::load(ifstream &file)
{
	file >> hora;
	file.ignore(1000, '\n');
	file >> minuto;
	file.ignore(1000, '\n');
}

void Hora::show()const
{
	cout << "Hora: " << hora << minuto << endl;
}

void Hora::criar()
{
	while (1)
	{
		try
		{
			cout << "Introduza uma hora: ";
			hora = InputUtils::readInt();
			break;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info;
		}
	}
	while (1)
	{
		try
		{
			cout << "Introduza os minutos: ";
			minuto = InputUtils::readInt();
			break;
		}
		catch (InvalidInputException<string> e)
		{
			cout << "Erro: " << e.info;
		}
	}

}

void Hora::editar()
{
	return criar();
}

ostream& operator<<(ostream &os, const Hora &hora)
{
	return os << hora.hora << ":" << hora.minuto << endl;
}
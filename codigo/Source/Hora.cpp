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

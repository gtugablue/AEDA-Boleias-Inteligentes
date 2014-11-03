#include "../headers/Coordenadas.h"

Coordenadas::Coordenadas()
{

}

Coordenadas::Coordenadas(const Coordenadas &coordenadas)
{
	this->latitude = coordenadas.latitude;
	this->longitude = coordenadas.longitude;
}
Coordenadas::Coordenadas(double latitude, double longitude)
{
	this->latitude = latitude;
	this->longitude = longitude;
}

double Coordenadas::getLatitude() const
{
	return latitude;
}

double Coordenadas::getLongitude() const
{
	return longitude;
}

void Coordenadas::setLatitude(double latitude)
{
	this->latitude = latitude;
	return;
}

void Coordenadas::setLongitude(double longitude)
{
	this->longitude = longitude;
	return;
}

void Coordenadas::showcoord()
{
	cout << "Coordenadas" << endl;
	cout << endl;
	cout << "Latitude : " << latitude << endl;
	cout << "Longitude:  " << longitude << endl;
}

void Coordenadas::criar()
{
	while (1)
	{
		try
		{
			cout << "Insira a latitude (formato XX.XXXXX...): ";
			if (!(cin >> latitude))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw InvalidInputException<string>("Utilize o formato XX.XXXXX...");
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
			cout << "Insira a longitude (formato XX.XXXXX...): ";
			if (!(cin >> longitude))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw InvalidInputException<string>("Utilize o formato XX.XXXXX...");
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

void Coordenadas::editar()
{
	return criar();
}

float Coordenadas::calcDistancia(const Coordenadas &coordenadas1, const Coordenadas &coordenadas2)
{
	double dist;
	double a = coordenadas2.getLatitude() - coordenadas1.getLatitude();
	double b = coordenadas2.getLongitude() - coordenadas1.getLongitude();
	dist = sqrt(pow(a, 2) + pow(b, 2));
	return dist;
}


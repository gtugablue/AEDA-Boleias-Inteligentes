#include "../headers/Coordenadas.h"

#define PI 3.14159265

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

void Coordenadas::show() const
{
	cout << setprecision(10);
	cout << "Latitude: " << latitude << endl;
	cout << "Longitude:  " << longitude << endl;
}

void Coordenadas::criar()
{
	while (1)
	{
		try
		{
			cout << "Insira a latitude (formato XX.XXXXX...): ";
			latitude = InputUtils::readDouble();
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
			longitude = InputUtils::readDouble();
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

double Coordenadas::toRad(double degrees) const
{
	//double radians = (degrees * (atan(1.0) * 4)) / 180;
	double radians = (degrees * PI) / 180;
	return radians;
}

double Coordenadas::calcDistancia(const Coordenadas &coordenadas) const
{
	// Haversine formula
	double earthRadius = 3958.75;
	double dLat = toRad(coordenadas.latitude - latitude);
	double dLng = toRad(coordenadas.longitude - longitude);
	double a = sin(dLat / 2) * sin(dLat / 2) +
		cos(toRad(latitude)) * cos(toRad(coordenadas.latitude)) *
		sin(dLng / 2) 
		* 
		sin(dLng / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double dist = earthRadius * c;
	double meterConversion = 1609.00;
	return dist * meterConversion;	// metros
}

void Coordenadas::load(ifstream &file)
{
	file >> latitude;
	file.ignore(1000, '\n');
	file >> longitude;
	file.ignore(1000, '\n');
}

void Coordenadas::save(ofstream &file)
{
	file << setprecision(10);
	file << latitude << endl;
	file << longitude << endl;
}
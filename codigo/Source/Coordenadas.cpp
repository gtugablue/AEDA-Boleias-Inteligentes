#include "../headers/Coordenadas.h"

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

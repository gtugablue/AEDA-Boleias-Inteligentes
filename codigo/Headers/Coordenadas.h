#ifndef _COORDENADAS_H
#define _COORDENADAS_H

using namespace std;

class Coordenadas
{
private:
	double latitude;
	double longitude;
public:
	Coordenadas();
	Coordenadas(const Coordenadas &coordenadas);
	Coordenadas(double latitude, double longitude);
	double getLatitude() const;
	double getLongitude() const;
	void setLatitude(double latitude);
	void setLongitude(double longitude);
};

#endif

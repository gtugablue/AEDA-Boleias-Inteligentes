using namespace std;

class Coordenadas
{
private:
	double latitude;
	double longitude;
public:
	Coordenadas();
	Coordenadas(double latitude, double longitude);
	double getLatitude() const;
	double getLongitude() const;
	void setLatitude(double latitude);
	void setLongitude(double longitude);
};

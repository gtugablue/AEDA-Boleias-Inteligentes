using namespace std;

class Horas
{
private:
	unsigned hora;
	unsigned minuto;
public:
	Horas();
	Horas(unsigned hora, unsigned minuto);
	unsigned getHora() const;
	unsigned getMinuto() const;
	void setHora(unsigned hora);
	void setMinuto(unsigned minuto);
	bool operator<(const Horas &horas);
};
class Data
{
protected:
	unsigned dia;
	unsigned mes;
	unsigned ano;
public:
	Data();
	Data(unsigned dia, unsigned mes, unsigned ano);
	unsigned getDia() const;
	unsigned getMes() const;
	unsigned getAno() const;
	void setDia(unsigned dia);
	void setMes(unsigned mes);
	void setAno(unsigned ano);
};
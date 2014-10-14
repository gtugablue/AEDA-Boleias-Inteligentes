#include <string>

using namespace std;

class Combustivel
{
private:
	string nome;
	float preco;
public:
	Combustivel();
	Combustivel(string nome, float preco);
	string getNome() const;
	float getPreco() const;
	void setNome(string &nome);
	void setPreco(float preco);
};

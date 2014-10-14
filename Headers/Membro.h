#include <string>

using namespace std;

class Membro
{
protected:
	string nome;
	string utilizador;
	string password;
public:
	Membro(string nome, string utilizador, string password);
	string getNome() const;
	string getUtilizador() const;
	string getPassword() const;
	void setNome(string &nome);
	void setUtilizador(string &utilizador);
	void setPassword(string &password);
};

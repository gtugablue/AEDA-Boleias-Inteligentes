#include "Membro.h"
#include "Data.h"

using namespace std;

class Particular : public Membro
{
private:
	Data dataNascimento;
public:
	Particular();
	Particular(Data dataNascimento);
	Data getDataNascimento() const;
	Data setDataNascimento(const Data &data);
};
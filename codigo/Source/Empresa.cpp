#include "../Headers/empresa.h"
#include <queue>

Empresa::Empresa() :
motoristas(Motorista("", Coordenadas(0, 0), Coordenadas(0, 0)))
{

}

Empresa::Empresa(const string &nome, const string &utilizador, const string &password, const string &website) :
Membro(nome, utilizador, password), motoristas(Motorista("", Coordenadas(0, 0), Coordenadas(0, 0)))
{
	this->website = website;
}

void Empresa::setMorada(const Coordenadas &morada)
{
	this->garagem = morada;

	queue<Motorista> aux;
	for (BSTItrLevel<Motorista> it(motoristas); !it.isAtEnd(); it.advance())
	{
		aux.push(it.retrieve());
	}
	
	BST<Motorista> novosMotoristas(Motorista("", Coordenadas(0, 0), Coordenadas(0, 0)));
	while (!aux.empty())
	{
		novosMotoristas.insert(aux.front());
		aux.pop();
	}
}

Coordenadas Empresa::getMorada() const
{
	return garagem;
}

const BST<Motorista> &Empresa::getMotoristas() const
{
	return motoristas;
}

void Empresa::addMotorista(const Motorista &motorista)
{
	motoristas.insert(motorista);
}

void Empresa::editMotorista(const string &nome)
{
	Motorista motoristaAEncontrar(nome, Coordenadas(), garagem);
	for (BSTItrLevel<Motorista> it(motoristas); !it.isAtEnd(); it.advance())
	{
		if (it.retrieve() == motoristaAEncontrar)
		{
			// Motorista encontrado
			Motorista motoristaEncontrado = it.retrieve();

			// Retirar motorista da BST
			motoristas.remove(motoristaEncontrado);
			cout << "Morada: " << endl;
			motoristaEncontrado.getMorada().show();
			cout << "Pretende alterar o nome (y/n)?" << endl;
			if (InputUtils::readYesOrNo('y', 'n'))
			{
				cout << "Introduza o novo nome: ";
				motoristaEncontrado.setNome(InputUtils::readLine());
			}
			cout << "Pretende alterar a morada (y/n)?" << endl;
			if (InputUtils::readYesOrNo('y', 'n'))
			{
				cout << "Nova morada: " << endl;
				Coordenadas morada;
				morada.editar();
				motoristaEncontrado.setMorada(morada, garagem);
			}
			cout << "Morada: " << endl;
			motoristaEncontrado.getMorada().show();

			// Voltar a colocar motorista na BST
			motoristas.insert(motoristaEncontrado);

			OutputUtils::clearScreen();
			cout << "Motorista editado com sucesso." << endl;
			InputUtils::pause();

			return;
		}
	}

	// Motorista não encontrado
	cout << "Erro: Nao existe nenhum motorista com esse nome." << endl;
	InputUtils::pause();
}

void Empresa::removeMotorista(const string &nome)
{
	Motorista motoristaAEncontrar(nome, Coordenadas(), garagem);
	for (BSTItrLevel<Motorista> it(motoristas); !it.isAtEnd(); it.advance())
	{
		if (it.retrieve() == motoristaAEncontrar)
		{
			// Motorista encontrado

			// Retirar motorista da BST
			motoristas.remove(it.retrieve());

			OutputUtils::clearScreen();
			cout << "Motorista removido com sucesso." << endl;
			InputUtils::pause();

			return;
		}
	}
	// Motorista não encontrado
	cout << "Erro: Nao existe nenhum motorista com esse nome." << endl;
	InputUtils::pause();
}

void Empresa::signup()
{
	cout << "Website (deixe em branco se nao existir): ";
	website = InputUtils::readLine();
}

void Empresa::edit()
{
	Membro::edit();
	cout << "Pretende alterar o website (y/n)?" << endl;
	if (InputUtils::readYesOrNo('y', 'n'))
	{
		cout << "Introduza o novo website: ";
		getline(cin, website);
	}
}

void Empresa::save(ofstream &file, vector<Combustivel> *combustiveis)
{
	file << 1 << endl;
	Membro::save(file, combustiveis);
	file << website << endl;
	garagem.save(file);
}

void Empresa::load(ifstream &file, vector<Combustivel> *combustiveis)
{
	Membro::load(file, combustiveis);
	garagem.load(file);
}

void Empresa::show() const
{
	Membro::show();
	cout << "Website: " << website << endl;
	cout << "Garagem: " << endl;
	garagem.show();

}

void Empresa::insertOld(ClientesAntigos &c1)
{
	clientes.insert(c1);

}


void Empresa::removeOld(string nome)
{
	ClientesAntigos x;
	unordered_set<ClientesAntigos, hstr, eqstr>set = clientes;
	unordered_set<ClientesAntigos, hstr, eqstr>::iterator it = set.find(x);
	x.setutilizador(nome);
	if (it == set.end())
	{
		cout << "Utilizador nao encontrado";
	}
	else clientes.erase(it);

}

void Empresa::showOld()
{
	unordered_set<ClientesAntigos, hstr, eqstr>::iterator it;

	for (it = clientes.begin(); it != clientes.end(); it++)
	{
		it->show();
	}
}



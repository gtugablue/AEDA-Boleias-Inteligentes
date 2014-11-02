#include "../headers/BoleiasInteligentes.h"

const string BoleiasInteligentes::ficheiroCombustiveis = "combustiveis.txt";
const string BoleiasInteligentes::ficheiroMembros = "membros.txt";
const string BoleiasInteligentes::ficheiroAnuncios = "anuncios.txt";

BoleiasInteligentes::BoleiasInteligentes(const string &dataFolder) :
dataFolder(dataFolder), utilizadorAtual(NULL)
{

}

void BoleiasInteligentes::start()
{
	load();
	showLoginMenu();
}

void BoleiasInteligentes::load()
{
	loadCombustiveis();
	//loadMembros();
	// APAGAR A PROXIMA LINHA
	membros.push_back(new Membro("Gustavo", "gtugablue", "123"));
}

void BoleiasInteligentes::loadCombustiveis()
{
	/*string nome;
	float n;
	string filename;
	fstream file;
	file.open(filename);

	while (!file.eof())
	{
	getline(file, nome);
	file >> n;

	}*/
}

/*void BoleiasInteligentes::loadMembros()
{

int N;
int i = 0;
fstream file;
float preco;
string filename, nome, utilizador, password,marca,name;
unsigned mes, ano, cilindrada;
file.open(filename);
while (!file.eof())
{
getline(file, nome);
getline(file, utilizador);
getline(file, password);
membros.push_back(new Particular(nome, utilizador, password));

file >> N;
while (i < N)
{
getline(file,marca);
i++;
file >> mes;
i++;
file >> ano;
i++;
file >> cilindrada;
i++;
getline(file, name);
file >> preco;
p.addveiculo(Veiculo(marca, mes, ano, cilindrada, new Combustivel(name, preco)));
i++;

}

}

}*/

void BoleiasInteligentes::save()
{
	saveCombustiveis();
	saveMembros();
}

void BoleiasInteligentes::saveCombustiveis()
{
	/*fstream file;
	string name;
	float preco;
	string filename;
	file.open(filename);
	while (!file.eof())
	{
	file << name << endl;
	file << preco;
	}*/
}

void BoleiasInteligentes::saveMembros()
{
	/*fstream file;
	string filename, nome, utilizador, password, marca, name;
	unsigned mes, ano, cilindrada;
	float preco;
	int N;

	file.open(filename);
	while (!file.eof())
	{
	file << nome << endl;
	file << utilizador << endl;
	file << password << endl;
	file << N << endl;
	file << marca << endl;
	file << mes << endl;
	file << ano << endl;
	file << cilindrada << endl;
	file << name << endl;
	file << preco << endl;
	}*/


}

Coordenadas BoleiasInteligentes::criarCoordenadas()
{
	double lat;
	double lng;
	cout << "Introduza a latitude " << endl;
	cin >> lat;
	cout << "Introduza a longitude" << endl;
	cin >> lng;
	return Coordenadas(lat, lng);
}

Combustivel BoleiasInteligentes::criarCombustivel()
{
	string nome;
	float preco;
	cout << "Introduza o nome do combustivel" << endl;
	getline(cin, nome);
	cout << "Introduza o seu preco" << endl;
	cin >> preco;
	return Combustivel(nome, preco);
}

Veiculo BoleiasInteligentes::criarVeiculo()
{
	string marca;
	unsigned mes, ano, cilindrada;
	cout << "Introduza a marca do seu veiculo" << endl;
	getline(cin, marca);
	cout << "Introduza o ano do seu veiculo" << endl;
	cin >> ano;
	cout << "Introduza o mes do seu veiculo" << endl;
	cin >> mes;
	cout << "Introduza a cilindrada do seu veiculo" << endl;
	cin >> cilindrada;


	return Veiculo(marca, mes, ano, cilindrada, NULL); // TODO --- TIRAR ESTE NULL DAQUI!

}

/*Anuncio BoleiasInteligentes::criarAnuncio()
{
string nome;
string descricao;

cout << "Introduza o nome do seu anuncio" << endl;
getline(cin, nome);
cout << "Introduza a descricao do seu anuncio" << endl;
getline(cin, descricao);

vector<pair<string, float>> outrasDespesas;
//return AnuncioOferta(nome, descricao, new Preco(0.0, 0.0, outrasDespesas), new Viagem(, new Membro("Arcanjo", "arcanjo45", "fagote"));	// TODO
}*/

void BoleiasInteligentes::addEmpresa(const Empresa &empresa)
{
	membros.push_back(new Empresa(empresa));
}

void BoleiasInteligentes::addParticular(const Particular &particular)
{
	membros.push_back(new Particular(particular));
}

Membro* BoleiasInteligentes::login(const string &username, const string &password)
{
	for (size_t i = 0; i < membros.size(); ++i)
	{
		if (membros[i]->getUtilizador() == username)
		{
			if (membros[i]->getPassword() == password)
			{
				return membros[i];
			}
			throw LoginException<string>("Password errada.");
		}
	}
	throw LoginException<string>("Username inexistente.");
}

void BoleiasInteligentes::showMenu(vector<string> itens)
{
	for (size_t i = 0; i < itens.size(); ++i)
	{
		cout << i << ". " << itens[i] << endl;
	}
	return;
}

void BoleiasInteligentes::showLoginMenu()
{
	vector<string> items =
	{
		"Login",
		"Sign up",
		"Sair"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);

	switch (n)
	{
	case 0:	// Login
	{
		clearScreen();
		cout << "Username: ";
		string username = InputUtils::readString();
		cout << "Password: ";
		string password = InputUtils::readPassword();
		cout << endl;
		try
		{
			login(username, password);
			clearScreen();
			showMainMenu();
		}
		catch (LoginException<string> e)
		{
			cout << e.info << endl;
			pause();
			clearScreen();
			return showLoginMenu();
		}
		return;
	}
	case 1:	// Sign up
	{
		cout << "Empresa? (y/n)";
		Membro* membro;
		if (InputUtils::readYesOrNo())
		{
			cout << endl;
			membro = new Empresa();
		}
		else
		{
			cout << endl;
			membro = new Particular();
		}
		membro->signup();
		membros.push_back(membro);
		clearScreen();
		cout << "Conta criada com sucesso!" << endl;
		pause();
		clearScreen();
		showLoginMenu();
		return;

	}
	case 2: // Sair
	{
		clearScreen();
		cout << "Tem a certeza que pretende sair (y/n)?";
		if (InputUtils::readYesOrNo())
		{
			cout << endl;
			return;
		}
		else
		{
			clearScreen();
			showLoginMenu();
		}
	}
	}
}

void BoleiasInteligentes::showMainMenu()
{
	vector<string> items =
	{
		"Editar conta",
		"Anuncios",
		"Veiculos",
		"Logout"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);
	switch (n)
	{
	case 0:
	{
		// TODO
	}
	case 1:
	{
		// TODO
	}
	case 2:
	{
		// TODO
	}
	case 3:
	{
		clearScreen();
		cout << "Tem a certeza que pretende fazer logout (y/n)?";
		if (InputUtils::readYesOrNo())
		{
			utilizadorAtual == NULL;
			clearScreen();
			return showLoginMenu();
		}
		else
		{
			clearScreen();
			return showMainMenu();
		}
	}
	}
	return;
}

void BoleiasInteligentes::clearScreen() const
{
	system("CLS");
}

void BoleiasInteligentes::pause() const
{
	system("pause");
}
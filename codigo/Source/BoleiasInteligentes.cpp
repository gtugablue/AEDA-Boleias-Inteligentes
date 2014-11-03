#include "../headers/BoleiasInteligentes.h"

const string BoleiasInteligentes::ficheiroCombustiveis = "combustiveis.txt";
const string BoleiasInteligentes::ficheiroMembros = "membros.txt";
const string BoleiasInteligentes::ficheiroAnuncios = "anuncios.txt";
const string BoleiasInteligentes::ficheiroPrecos = "precos.txt";

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
	membros.push_back(new Particular("Gustavo", "gtugablue", "123"));
}

void BoleiasInteligentes::loadCombustiveis()
{
	string nome;
	float n;
	fstream file;
	file.open(ficheiroCombustiveis);

	while (!file.eof())
	{
		getline(file, nome);
		file >> n;
		Combustivel p = Combustivel(nome, n);
		combustiveis.push_back(p);
	}
}

void BoleiasInteligentes::loadMembros()
{

	int N;
	int i = 0;
	fstream file;
	float preco;
	string filename, nome, utilizador, password, marca, name;
	unsigned mes, ano, cilindrada;
	file.open(ficheiroMembros);
	bool empresa;

	file >> N;

	for (size_t i = 0; i < N; ++i)
	{
		cin >> empresa;
		cin.ignore(1000, '\n');
		Membro* membro;
		if (empresa)
		{
			membro = new Empresa();
		}
		else
		{
			membro = new Particular();
		}
		membro->load();
		membros.push_back(membro);
	}



}

void BoleiasInteligentes::save()
{
	saveCombustiveis();
	saveMembros();
}

void BoleiasInteligentes::saveCombustiveis()
{
	ofstream file;
	file.open(ficheiroCombustiveis);
	for (size_t i = 0; i < combustiveis.size(); i++)
	{
		file << combustiveis.at(i).getNome() << endl;
		file << combustiveis.at(i).getPreco() << endl;
	}
}

void BoleiasInteligentes::saveMembros()
{
	ofstream file;
	file.open(ficheiroMembros);
	file << membros.size();
	for (size_t i = 0; i < membros.size(); ++i)
	{
		membros[i]->save(dataFolder + ficheiroMembros);
	}
	file.close();

}

void BoleiasInteligentes::addEmpresa(const Empresa &empresa)
{
	membros.push_back(new Empresa(empresa));
}

void BoleiasInteligentes::addParticular(const Particular &particular)
{
	membros.push_back(new Particular(particular));
}

vector<AnuncioOferta*> BoleiasInteligentes::getAnunciosOferta() const
{
	vector<AnuncioOferta*> anunciosOferta;
	for (size_t i = 0; i < anuncios.size(); ++i)
	{
		if (dynamic_cast<AnuncioOferta*>(anuncios[i]) != NULL)
		{
			anunciosOferta.push_back((AnuncioOferta*)anuncios[i]);
		}
	}
	return anunciosOferta;
}

vector<AnuncioProcura*> BoleiasInteligentes::getAnunciosProcura() const
{
	vector<AnuncioProcura*> anunciosProcura;
	for (size_t i = 0; i < anuncios.size(); ++i)
	{
		if (dynamic_cast<AnuncioProcura*>(anuncios[i]) != NULL)
		{
			anunciosProcura.push_back((AnuncioProcura*)anuncios[i]);
		}
	}
	return anunciosProcura;
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
	clearScreen();
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
			utilizadorAtual = login(username, password);
			showMainMenu();
		}
		catch (LoginException<string> e)
		{
			cout << e.info << endl;
			pause();
			return showLoginMenu();
		}
		return;
	}
	case 1:	// Sign up
	{
		clearScreen();
		cout << "Empresa? (y/n)";
		Membro* membro;
		if (InputUtils::readYesOrNo('y', 'n'))
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
		showLoginMenu();
		return;

	}
	case 2: // Sair
	{
		clearScreen();
		cout << "Tem a certeza que pretende sair (y/n)?";
		if (InputUtils::readYesOrNo('y', 'n'))
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
	clearScreen();
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
	case 0: // Editar conta
	{
		utilizadorAtual->edit();
		return showMainMenu();
	}
	case 1: // Anuncios
	{
		return showAnunciosMenu();
	}
	case 2: // Veiculos
	{
		// TODO
	}
	case 3:
	{
		clearScreen();
		cout << "Tem a certeza que pretende fazer logout (y/n)?";
		if (InputUtils::readYesOrNo('y', 'n'))
		{
			utilizadorAtual = NULL;
		}
		return showLoginMenu();
	}
	}
	return;
}

void BoleiasInteligentes::showAnunciosMenu()
{
	clearScreen();
	vector<string> items =
	{
		"Criar anuncio",
		"Ver anuncios",
		"Editar anuncio",
		"Voltar"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);
	switch (n)
	{
	case 0: // Criar anuncio
	{
		Anuncio* anuncio;
		if (dynamic_cast<Particular*>(utilizadorAtual) == NULL)
		{
			// Empresa
			anuncio = new AnuncioOferta();
		}
		else
		{
			// Particular
			cout << "Que tipo de anuncio pretende criar ('o' para oferta e 'p' para procura)?" << endl;
			if (InputUtils::readYesOrNo('o', 'p'))
			{
				anuncio = new AnuncioOferta();
			}
			else
			{
				anuncio = new AnuncioProcura();
			}
		}
		anuncio->criar();
		anuncio->setAnunciante(utilizadorAtual);
		anuncios.push_back(anuncio);
		clearScreen();
		cout << "Anuncio criado com sucesso." << endl;
		pause();
		return showAnunciosMenu();
	}
	case 1: // Ver anuncios
	{
		int input;
		clearScreen();
		cout << "Que tipo de anuncios pretende ver ('o' para oferta e 'p' para procura)?" << endl;
		if (InputUtils::readYesOrNo('o', 'p'))
		{
			try
			{
				input = showList(getAnunciosOferta(), 0);
			}
			catch (EmptyException<string> e)
			{
				clearScreen();
				cout << "Erro: " << e.info << endl;
				pause();
				return showAnunciosMenu();
			}
		}
		else
		{
			try
			{
				input = showList(getAnunciosProcura(), 0);
			}
			catch (EmptyException<string> e)
			{
				clearScreen();
				cout << "Erro: " << e.info << endl;
				pause();
				return showAnunciosMenu();
			}
		}
		if (input == -1)
		{
			return showAnunciosMenu();
		}
		else
		{
			clearScreen();
			anuncios[input]->show();
			pause();
			return showAnunciosMenu();
		}
	}
	case 2: // Editar anuncio
	{
		vector<Anuncio*> meusAnuncios;
		for (size_t i = 0; i < anuncios.size(); ++i)
		{
			if (anuncios[i]->getAnunciante() == utilizadorAtual)
			{
				meusAnuncios.push_back(anuncios[i]);
			}
		}
		try
		{
			int input = showList(meusAnuncios, 0);
			if (input == -1)
			{
				return showAnunciosMenu();
			}
			else
			{
				clearScreen();
				meusAnuncios[input]->show();
				pause();
				clearScreen();
				cout << "Pretende apagar este anuncio (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					anuncios.erase(find(anuncios.begin(), anuncios.end(), meusAnuncios[input])); // Não falha, porque está garantido que o anúncio existe
					cout << "Anuncio apagado com sucesso." << endl;
					pause();
					return showAnunciosMenu();
				}
				cout << "Pretende editar este anuncio (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					meusAnuncios[input]->editar();
					clearScreen();
					cout << "Anuncio editado com sucesso." << endl;
					pause();
					return showAnunciosMenu();
				}
				pause();
				return showAnunciosMenu();
			}
		}
		catch (EmptyException<string> e)
		{
			clearScreen();
			cout << "Erro: " << e.info << endl;
			pause();
			return showAnunciosMenu();
		}
	}
	case 3: // Voltar
	{
		clearScreen();
		return showMainMenu();
	}
	}
	return;
}

void BoleiasInteligentes::showVeiculosMenu()
{
	clearScreen();
	vector<string> items =
	{
		"Criar veiculo",
		"Ver veiculos",
		"Editar veiculo",
		"Voltar"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);
}

template<class T>
int BoleiasInteligentes::showList(const vector<T> &v, int page) const
{
	clearScreen();
	if (v.size() == 0)
	{
		throw EmptyException<string>("Nenhum elemento a listar.");
	}
	for (size_t i = page * BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE; page * BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE + i % BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE < v.size() && i < (page + 1) * BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE; ++i)
	{
		cout << i % BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE << ". " << v[i] << endl;
	}
	cout << endl;
	cout << "7. Anterior" << endl;
	cout << "8. Seguinte" << endl;
	cout << "9. Sair" << endl;
	unsigned input;
	try
	{
		do
		{
			input = InputUtils::readDigit(0, 9);
		} while (input > v.size() - page * BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE && input < 7);
		switch (input)
		{
		case 7:
		{
			if (page == 0)
			{
				throw PaginaInexistenteException<string>("Pagina inexistente.");
			}
			return showList(v, page - 1);
		}
		case 8:
		{
			if (page == v.size() / BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE)
			{
				throw PaginaInexistenteException<string>("Pagina inexistente");
			}
			return showList(v, page + 1);
		}
		case 9:
		{
			return -1;
		}
		default:	// Option selected
		{
			return page * BOLEIAS_INTELIGENTES_LIST_ITEMS_PER_PAGE + input;
		}
		}
	}
	catch (PaginaInexistenteException<string> e)
	{
		return showList(v, page);
	}
}

void BoleiasInteligentes::clearScreen() const
{
	system("CLS");
}

void BoleiasInteligentes::pause() const
{
	system("pause");
}

void BoleiasInteligentes::loadAnuncios()
{
	bool oferta;
	string titulo;
	string descricao;
	int N,S,ID;
	ifstream file;
	file.open(ficheiroAnuncios);
	file >> N;
	for (size_t i = 0; i < N; i++)
	{
		Anuncio *anuncio;
		Membro * condutor, *anunciante;
		vector<Particular *> passageiros;
		Coordenadas origem;
		Coordenadas destino;
		Data inicio;
		Data fim;
		Preco *preco;
		file >> oferta;
		if (oferta)
		{
			getline(file, titulo);
			getline(file, descricao);
			origem.load(file);
			destino.load(file);
			file >> S;
			cin.ignore(1000, '\n');
			for (size_t j = 0; j < S; j++)
			{
				file >> ID;
				cin.ignore(1000, '\n');
				passageiros.push_back((Particular *)membros[ID]);

			}
			inicio.load(file);
			fim.load(file);
			anunciante->load();
			condutor->load();
			preco->load(file);
			anuncios.push_back(new AnuncioOferta(titulo, descricao, origem, destino, inicio, fim, preco));

		}
		else
		int G, T;

        getline(file, titulo);
		getline(file, descricao);
		origem.load(file);
		destino.load(file);
		file >> S;
		cin.ignore(1000, '\n');
		for (size_t j = 0; j < S; j++)
		{
			file >> ID;
			cin.ignore(1000, '\n');
			passageiros.push_back((Particular *)membros[ID]);

		}
		inicio.load(file);
		fim.load(file);
		anunciante->load();
		condutor->load();
		file >> G;
		for (size_t i = 0; i < G; i++)
		{

		}
		
	
		
		


		
	}
}
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
	loadMembros();
}

void BoleiasInteligentes::loadCombustiveis()
{
	string nome;
	float n;
	fstream file;
	file.open(dataFolder + ficheiroCombustiveis);

	while (getline(file, nome))
	{
		file >> n;
		file.ignore(1000, '\n');
		Combustivel p = Combustivel(nome, n);
		combustiveis.push_back(p);
	}
}

void BoleiasInteligentes::loadMembros()
{
	unsigned numMembros;
	ifstream file(dataFolder + ficheiroMembros);
	float preco;
	bool empresa;
	file >> numMembros;
	for (size_t i = 0; i < numMembros; ++i)
	{
		file >> empresa;
		file.ignore(1000, '\n');
		Membro* membro;
		if (empresa)
		{
			membro = new Empresa();
		}
		else
		{
			membro = new Particular();
		}
		membro->load(file, &combustiveis);
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
	ofstream file(dataFolder + ficheiroCombustiveis);
	for (size_t i = 0; i < combustiveis.size(); i++)
	{
		combustiveis[i].save(file);
	}
}

void BoleiasInteligentes::saveMembros()
{
	ofstream file(dataFolder + ficheiroMembros);
	file << membros.size() << endl;
	for (size_t i = 0; i < membros.size(); ++i)
	{
		membros[i]->save(file, &combustiveis);
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

vector<AnuncioOferta *> BoleiasInteligentes::getAnunciosOferta() const
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

vector<AnuncioProcura *> BoleiasInteligentes::getAnunciosProcura() const
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

vector<Anuncio *> BoleiasInteligentes::getAnunciosByMembro(Membro* membro) const
{
	vector<Anuncio *> anunciosMembro;
	for (size_t i = 0; i < anuncios.size(); ++i)
	{
		if (anuncios[i]->getAnunciante() == membro)
		{
			anunciosMembro.push_back(anuncios[i]);
		}
	}
	return anunciosMembro;
}

vector<Boleia *> BoleiasInteligentes::getBoleiasWhereMembroExists(Membro* membro)
{
	vector<Boleia *> boleiasMembro;
	for (size_t i = 0; i < boleias.size(); ++i)
	{
		if (boleias[i].isMembroInBoleia(membro))
		{
			boleiasMembro.push_back(&boleias[i]);
		}
	}
	return boleiasMembro;
}

vector<Combustivel> BoleiasInteligentes::getCombustiveis()
{
	return combustiveis;
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

bool BoleiasInteligentes::existsUtilizador(const string &username) const
{
	for (size_t i = 0; i < membros.size(); ++i)
	{
		if (membros[i]->getUtilizador() == username)
		{
			return true;
		}
	}
	return false;
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
	OutputUtils::clearScreen();
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
		OutputUtils::clearScreen();
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
		OutputUtils::clearScreen();
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
		cout << "Nome: ";
		membro->setNome(InputUtils::readString());
		try
		{
			cout << "Username: ";
			membro->setUtilizador(InputUtils::readString());
			if (existsUtilizador(membro->getUtilizador()))
			{
				throw UtilizadorRepetidoException<string>("Utilizador ja existente");
			}
		}
		catch (UtilizadorRepetidoException<string> e)
		{
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			pause();
			delete membro;
			return showLoginMenu();
		}
		cout << "Password: ";
		membro->setPassword(InputUtils::readPassword());
		cout << endl;
		membro->signup();
		membros.push_back(membro);
		OutputUtils::clearScreen();
		cout << "Conta criada com sucesso!" << endl;
		pause();
		showLoginMenu();
		return;

	}
	case 2: // Sair
	{
		OutputUtils::clearScreen();
		cout << "Tem a certeza que pretende sair (y/n)?";
		if (InputUtils::readYesOrNo('y', 'n'))
		{
			save();
			cout << endl;
			return;
		}
		else
		{
			OutputUtils::clearScreen();
			showLoginMenu();
		}
	}
	}
}

void BoleiasInteligentes::showMainMenu()
{
	OutputUtils::clearScreen();
	vector<string> items =
	{
		"Editar conta",
		"Anuncios",
		"Veiculos",
		"Boleias",
		"Logout"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);
	switch (n)
	{
	case 0: // Editar conta
	{
		OutputUtils::clearScreen();
		utilizadorAtual->edit();
		cout << "Conta editada com sucesso." << endl;
		pause();
		return showMainMenu();
	}
	case 1: // Anuncios
	{
		return showAnunciosMenu();
	}
	case 2: // Veiculos
	{
		return showVeiculosMenu();
	}
	case 3: // Boleias
	{
		return showBoleiasMenu();
	}
	case 4: // Logout
	{
		OutputUtils::clearScreen();
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
	OutputUtils::clearScreen();
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
		OutputUtils::clearScreen();
		cout << "Anuncio criado com sucesso." << endl;
		pause();
		return showAnunciosMenu();
	}
	case 1: // Ver anuncios
	{
		int input;
		OutputUtils::clearScreen();
		cout << "Que tipo de anuncios pretende ver ('o' para oferta e 'p' para procura)?" << endl;
		if (InputUtils::readYesOrNo('o', 'p'))
		{
			try
			{
				input = OutputUtils::showList(getAnunciosOferta(), 0);
			}
			catch (EmptyException<string> e)
			{
				OutputUtils::clearScreen();
				cout << "Erro: " << e.info << endl;
				pause();
				return showAnunciosMenu();
			}
		}
		else
		{
			try
			{
				input = OutputUtils::showList(getAnunciosProcura(), 0);
			}
			catch (EmptyException<string> e)
			{
				OutputUtils::clearScreen();
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
			OutputUtils::clearScreen();
			anuncios[input]->show();
			pause();
			return showAnunciosMenu();
		}
	}
	case 2: // Editar anuncio
	{
		try
		{
			vector<Anuncio*> meusAnuncios = getAnunciosByMembro(utilizadorAtual);
			int input = OutputUtils::showList(meusAnuncios, 0);
			if (input == -1)
			{
				return showAnunciosMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				meusAnuncios[input]->show();
				pause();
				OutputUtils::clearScreen();
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
					cout << "Bambora";
					meusAnuncios[input]->editar();
					OutputUtils::clearScreen();
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
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			pause();
			return showAnunciosMenu();
		}
	}
	case 3: // Voltar
	{
		OutputUtils::clearScreen();
		return showMainMenu();
	}
	}
	return;
}

void BoleiasInteligentes::showVeiculosMenu()
{
	OutputUtils::clearScreen();
	vector<string> items =
	{
		"Criar veiculo",
		"Ver veiculos",
		"Editar veiculo",
		"Voltar"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);
	switch (n)
	{
	case 0: // Criar veiculo
	{
		Veiculo veiculo;
		OutputUtils::clearScreen();
		veiculo.criar(&combustiveis);
		utilizadorAtual->addVeiculo(veiculo);
		cout << "Veiculo criado com sucesso." << endl;
		pause();
		return showVeiculosMenu();
	}
	case 1: // Ver veiculos
	{
		try
		{
			OutputUtils::clearScreen();
			int input = OutputUtils::showList(utilizadorAtual->getVeiculos(), 0);
			if (input == -1)
			{
				return showVeiculosMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				utilizadorAtual->getVeiculos()[input].show();
				pause();
				return showVeiculosMenu();
			}
		}
		catch (EmptyException<string> e)
		{
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			pause();
			return showVeiculosMenu();
		}
	}
	case 2: // Editar veiculo
	{
		try
		{
			int input = OutputUtils::showList(utilizadorAtual->getVeiculos(), 0);
			if (input == -1)
			{
				return showVeiculosMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				utilizadorAtual->getVeiculos()[input].show();
				pause();
				OutputUtils::clearScreen();
				cout << "Pretende apagar este veiculo (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					utilizadorAtual->removeVeiculo(&utilizadorAtual->getVeiculos()[input]); // Não falha, porque está garantido que o veículo existe
					cout << "Veiculo apagado com sucesso." << endl;
					pause();
					return showVeiculosMenu();
				}
				cout << "Pretende editar este veiculo (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					utilizadorAtual->getVeiculos()[input].editar();
					OutputUtils::clearScreen();
					cout << "Veiculo editado com sucesso." << endl;
					pause();
					return showVeiculosMenu();
				}
				pause();
				return showAnunciosMenu();
			}
		}
		catch (EmptyException<string> e)
		{
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			pause();
			return showAnunciosMenu();
		}
	}
	case 3: // Voltar
	{
		OutputUtils::clearScreen();
		return showMainMenu();
	}
	}
}

void BoleiasInteligentes::showBoleiasMenu()
{
	OutputUtils::clearScreen();
	vector<string> items =
	{
		"Converter anuncio em boleia",
		"Ver minhas boleias",
		"Remover-me de uma boleia",
		"Voltar"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);
	switch (n)
	{
	case 0: // Converter anuncio em boleia
	{
		try
		{
			vector<Anuncio *> meusAnuncios;
			int input = OutputUtils::showList(getAnunciosByMembro(utilizadorAtual));
			if (input == -1)
			{
				return showBoleiasMenu();
			}
			else
			{
				if (!meusAnuncios[input]->isPronto())
				{
					throw AnuncioIncompletoException<string>("Impossivel converter um anuncio incompleto numa boleia.");
				}
				OutputUtils::clearScreen();
				meusAnuncios[input]->show();
				pause();
				OutputUtils::clearScreen();
				if (meusAnuncios[input]->getAnunciante() != utilizadorAtual)
				{
					throw ProibidoException<string>("Apenas o criador do anuncio pode converte-lo numa boleia.");
				}
			}
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			pause();
			return showBoleiasMenu();
		}
		catch (ProibidoException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			pause();
			return showBoleiasMenu();
		}
		catch (AnuncioIncompletoException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			pause();
			return showBoleiasMenu();
		}
	}
	case 1: // Ver minhas boleias
	{
		try
		{
			vector<Boleia *> minhasBoleias;
			int input = OutputUtils::showList(getBoleiasWhereMembroExists(utilizadorAtual));
			if (input == -1)
			{
				return showBoleiasMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				minhasBoleias[input]->show();
				pause();
				OutputUtils::clearScreen();
			}
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			pause();
			return showBoleiasMenu();
		}
	}
	case 2: // Remover-me de uma boleia
	{
		try
		{
			vector<Boleia *> minhasBoleias;
			int input = OutputUtils::showList(getBoleiasWhereMembroExists(utilizadorAtual));
			if (input == -1)
			{
				return showBoleiasMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				if (minhasBoleias[input]->getCondutor() == utilizadorAtual)
				{
					// Apagar boleia
					for (size_t i = 0; i < boleias.size(); ++i)
					{
						if (&boleias[i] == minhasBoleias[input])
						{
							boleias.erase(boleias.begin() + i);
							break; // Não é necessário continuar o loop
						}
					}
					cout << "Boleia apagada com sucesso." << endl;
				}
				else
				{
					minhasBoleias[input]->removerPassageiro((Particular *)utilizadorAtual);
					cout << "Removido da boleia com sucesso." << endl;
				}
				pause();
				OutputUtils::clearScreen();
			}
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			pause();
			return showBoleiasMenu();
		}
	}
	case 3: // Voltar
	{
		OutputUtils::clearScreen();
		return showMainMenu();
	}
	}
}

void BoleiasInteligentes::clearScreen()
{
	system("CLS");
}

void BoleiasInteligentes::pause()
{
	system("pause");
}

void BoleiasInteligentes::loadAnuncios()
{
	bool oferta;
	string titulo;
	string descricao;
	unsigned numAnuncios, ID;
	ifstream file;
	file.open(ficheiroAnuncios);
	file >> numAnuncios;
	for (size_t i = 0; i < numAnuncios; i++)
	{
		Anuncio* anuncio;
		Membro *condutor, *anunciante;
		vector<Particular *> passageiros;
		Coordenadas origem;
		Coordenadas destino;
		Data dataInicio;
		Data dataFim;
		Preco* preco;
		file >> oferta;
		getline(file, titulo);
		getline(file, descricao);
		origem.load(file);
		destino.load(file);
		dataInicio.load(file);
		dataFim.load(file);
		cin >> ID;
		cin.ignore(1000, '\n');
		if (ID == -1)
		{
			anunciante = NULL;
		}
		else
		{
			anunciante = membros[ID];
		}
		cin >> ID;
		cin.ignore(1000, '\n');
		if (ID == -1)
		{
			condutor = NULL;
		}
		else
		{
			condutor = membros[ID];
		}

		// TODO DAQUI PARA BAIXO
		if (oferta)
		{
			Preco preco;
			preco.criar();
			anuncios.push_back(new AnuncioOferta(titulo, descricao, origem, destino, dataInicio, dataFim, preco));
		}
	}
}
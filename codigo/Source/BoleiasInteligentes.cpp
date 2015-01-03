#include "../headers/BoleiasInteligentes.h"

const string BoleiasInteligentes::ficheiroCombustiveis = "combustiveis.txt";
const string BoleiasInteligentes::ficheiroMembros = "membros.txt";
const string BoleiasInteligentes::ficheiroAnuncios = "anuncios.txt";
const string BoleiasInteligentes::ficheiroBoleias = "boleias.txt";

#define	BOLEIASINTELIGENTES_DESTINO_DISTANCIA_ACEITAVEL		0.005

BoleiasInteligentes::BoleiasInteligentes(const string &dataFolder) :
dataFolder(dataFolder), utilizadorAtual(NULL)
{

}

void BoleiasInteligentes::start()
{
	try
	{
		load();
		showLoginMenu();
	}
	catch (FileException<string>e)
	{
		cout << "Erro: " << e.info << endl << endl;
	}
}

void BoleiasInteligentes::load()
{
	loadCombustiveis();
	loadMembros();
	loadAnuncios();
	loadBoleias();
}

void BoleiasInteligentes::loadCombustiveis()
{
	string nome;
	float n;
	fstream file;
	file.open(dataFolder + ficheiroCombustiveis);
	if (!file.is_open())
	{
		throw FileException<string>("Erro ao abrir o ficheiro membros");
	}

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
	if (!file.is_open())
	{
		throw FileException<string>("Erro ao abrir o ficheiro membros");
	}

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
	file.close();
}

void BoleiasInteligentes::loadAnuncios()
{
	ifstream file(dataFolder + ficheiroAnuncios);
	unsigned numAnuncios;
	if (!file.is_open())
	{
		throw FileException<string>("Erro ao abrir o ficheiro anuncios");
	}
	file >> numAnuncios;
	file.ignore(1000, '\n');
	bool oferta;
	Anuncio *anuncio;
	for (size_t i = 0; i < numAnuncios; ++i)
	{
		file >> oferta;
		file.ignore(1000, '\n');
		if (oferta)
		{
			anuncio = new AnuncioOferta();
		}
		else
		{
			anuncio = new AnuncioProcura();
		}
		anuncio->load(file, &membros);
		anuncios.push_back(anuncio);
	}
	file.close();
}

void BoleiasInteligentes::loadBoleias()
{
	ifstream file(dataFolder + ficheiroBoleias);
	unsigned numBoleias;
	if (!file.is_open())
	{
		throw FileException<string>("Erro ao abrir o ficheiro boleias");
	}
	file >> numBoleias;
	file.ignore(1000, '\n');
	for (size_t i = 0; i < numBoleias; ++i)
	{
		Boleia boleia;
		boleia.load(file, &membros);
		boleias.push_back(boleia);
	}
	file.close();
}

void BoleiasInteligentes::save()
{
	saveCombustiveis();
	saveMembros();
	saveAnuncios();
	saveBoleias();
}

void BoleiasInteligentes::saveCombustiveis()
{
	ofstream file(dataFolder + ficheiroCombustiveis);
	for (size_t i = 0; i < combustiveis.size(); i++)
	{
		combustiveis[i].save(file);
	}
	file.close();
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

void BoleiasInteligentes::saveAnuncios()
{
	ofstream file(dataFolder + ficheiroAnuncios);
	file << anuncios.size() << endl;
	for (size_t i = 0; i < anuncios.size(); ++i)
	{
		if (dynamic_cast<AnuncioOferta *>(anuncios[i]) == NULL)
		{
			// Procura
			file << false << endl;
		}
		else
		{
			// Oferta
			file << true << endl;
		}
		anuncios[i]->save(file, &membros);
		delete anuncios[i];
	}
	file.close();
}

void BoleiasInteligentes::saveBoleias()
{
	ofstream file(dataFolder + ficheiroBoleias);
	file << boleias.size() << endl;
	for (size_t i = 0; i < boleias.size(); ++i)
	{
		boleias[i].save(file, &membros);
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

vector<Anuncio *> BoleiasInteligentes::getAnunciosByDestino(const Coordenadas &destino) const
{
	vector<Anuncio *> anunciosDestino;
	for (size_t i = 0; i < anuncios.size(); ++i)
	{
		if (abs(anuncios[i]->getDestino().getLatitude() - destino.getLatitude()) < BOLEIASINTELIGENTES_DESTINO_DISTANCIA_ACEITAVEL && abs(anuncios[i]->getDestino().getLongitude() - destino.getLongitude()) < BOLEIASINTELIGENTES_DESTINO_DISTANCIA_ACEITAVEL)
		{
			anunciosDestino.push_back(anuncios[i]);
		}
	}
	return anunciosDestino;
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
		string username = InputUtils::readLine();
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
			InputUtils::pause();
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
		membro->setNome(InputUtils::readLine());
		try
		{
			cout << "Username: ";
			membro->setUtilizador(InputUtils::readLine());
			if (existsUtilizador(membro->getUtilizador()))
			{
				throw UtilizadorRepetidoException<string>("Utilizador ja existente");
			}
		}
		catch (UtilizadorRepetidoException<string> e)
		{
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
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
		InputUtils::pause();
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
	if (dynamic_cast<Particular*>(utilizadorAtual) != NULL)
	{
		// Particular
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
			InputUtils::pause();
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
			else
			{
				return showMainMenu();
			}
			return showLoginMenu();
		}
		}
	}
	else
	{
		// Empresa
		vector<string> items =
		{
			"Editar conta",
			"Anuncios",
			"Veiculos",
			"Boleias",
			"Motoristas",
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
			InputUtils::pause();
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
		case 4: // Motoristas
		{
			return showMotoristasMenu();
		}
		case 5: // Logout
		{
			OutputUtils::clearScreen();
			cout << "Tem a certeza que pretende fazer logout (y/n)?";
			if (InputUtils::readYesOrNo('y', 'n'))
			{
				utilizadorAtual = NULL;
			}
			else
			{
				return showMainMenu();
			}
			return showLoginMenu();
		}
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
		"Pesquisar anuncios",
		"Pesquisar anuncios por destino",
		"Pesquisar anuncios por anunciante",
		"Editar anuncio",
		"Voltar"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);
	switch (n)
	{
	case 0: // Criar anuncio
	{
		bool oferta;
		Anuncio* anuncio;
		OutputUtils::clearScreen();
		if (dynamic_cast<Particular*>(utilizadorAtual) == NULL)
		{
			// Empresa
			oferta = true;
			anuncio = new AnuncioOferta();
		}
		else
		{
			// Particular
			cout << "Que tipo de anuncio pretende criar ('o' para oferta e 'p' para procura)?" << endl;
			if (InputUtils::readYesOrNo('o', 'p'))
			{
				oferta = true;
				anuncio = new AnuncioOferta();
			}
			else
			{
				oferta = false;
				anuncio = new AnuncioProcura();
			}
		}
		try
		{
			anuncio->criar(utilizadorAtual);
			if (oferta)
			{
				anuncio->getPreco()->updatePrecoCombustivel(anuncio->getVeiculo()->getConsumo(), anuncio->getVeiculo()->getCombustivel()->getPreco(), anuncio->getOrigem().calcDistancia(anuncio->getDestino()));
				anuncio->setCondutor(utilizadorAtual);
			}
			anuncios.push_back(anuncio);
			OutputUtils::clearScreen();
			cout << "Anuncio criado com sucesso." << endl;
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			delete anuncio;
		}
		InputUtils::pause();
		return showAnunciosMenu();
	}
	case 1: // Pesquisar anuncios
	{
		int input;

		if (dynamic_cast<Empresa *>(utilizadorAtual) == NULL)
		{
			OutputUtils::clearScreen();
			Coordenadas origemPretendida, destinoPretendido;
			cout << "Indique as coordenadas do ponto de partida." << endl;
			origemPretendida.criar();
			cout << "Indique as coordenadas do destino." << endl;
			destinoPretendido.criar();
			if (anuncios.size() > 0)
			{
				sortAnuncios(origemPretendida, destinoPretendido, 0, anuncios.size() - 1);
			}
		}

		OutputUtils::clearScreen();
		cout << "Que tipo de anuncios pretende ver ('o' para oferta e 'p' para procura)?" << endl;
		bool oferta;
		if (oferta = InputUtils::readYesOrNo('o', 'p'))
		{
			try
			{
				input = OutputUtils::showList(getAnunciosOferta(), 0);
			}
			catch (EmptyException<string> e)
			{
				OutputUtils::clearScreen();
				cout << "Erro: " << e.info << endl;
				InputUtils::pause();
				return showAnunciosMenu();
			}
		}
		else
		{
			OutputUtils::clearScreen();
			try
			{
				OutputUtils::clearScreen();
				input = OutputUtils::showList(getAnunciosProcura(), 0);
			}
			catch (EmptyException<string> e)
			{
				cout << "Erro: " << e.info << endl;
				InputUtils::pause();
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
			InputUtils::pause();
			if (anuncios[input]->podeSerCondutor(utilizadorAtual))
			{
				cout << "Pretende-se candidatar a condutor (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					do
					{
						input = OutputUtils::showList(utilizadorAtual->getVeiculos());
					} while (input == -1);
					Veiculo* veiculo = utilizadorAtual->getVeiculos()[input];
					Preco preco;
					preco.criar();
					preco.updatePrecoCombustivel(veiculo->getConsumo(), veiculo->getCombustivel()->getPreco(), anuncios[input]->getOrigem().calcDistancia(anuncios[input]->getDestino()));
					CondutorCandidato *condutorCandidato = new CondutorCandidato();
					condutorCandidato->condutor = utilizadorAtual;
					condutorCandidato->preco = preco;
					condutorCandidato->veiculo = veiculo;
					((AnuncioProcura *)anuncios[input])->adicionarCondutorCandidato(condutorCandidato);
					cout << "Tornou-se num candidato a condutor desta viagem com sucesso." << endl;
					InputUtils::pause();
					return showAnunciosMenu();
				}
			}
			if (anuncios[input]->podeSerPassageiro(utilizadorAtual))
			{
				cout << "Pretende ser passageiro (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					anuncios[input]->addPassageiro((Particular *)utilizadorAtual);
					cout << "Tornou-se num passageiro desta viagem com sucesso." << endl;
					InputUtils::pause();
				}
			}
			return showAnunciosMenu();
		}
	}
	case 2: // Pesquisar anuncios por destino
	{
		int input;
		OutputUtils::clearScreen();
		Coordenadas destinoPretendido;
		cout << "Indique as coordenadas do destino." << endl;
		destinoPretendido.criar();
		vector<Anuncio *> anunciosDestino = getAnunciosByDestino(destinoPretendido);
		OutputUtils::clearScreen();
		try
		{
			OutputUtils::clearScreen();
			input = OutputUtils::showList(anunciosDestino, 0);
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
			return showAnunciosMenu();
		}
		if (input == -1)
		{
			return showAnunciosMenu();
		}
		else
		{
			OutputUtils::clearScreen();
			anunciosDestino[input]->show();
			InputUtils::pause();
			if (anunciosDestino[input]->podeSerCondutor(utilizadorAtual))
			{
				cout << "Pretende-se candidatar a condutor (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					do
					{
						input = OutputUtils::showList(utilizadorAtual->getVeiculos());
					} while (input == -1);
					Veiculo *veiculo = utilizadorAtual->getVeiculos()[input];
					Preco preco;
					preco.criar();
					preco.updatePrecoCombustivel(veiculo->getConsumo(), veiculo->getCombustivel()->getPreco(), anunciosDestino[input]->getOrigem().calcDistancia(anunciosDestino[input]->getDestino()));
					CondutorCandidato *condutorCandidato = new CondutorCandidato();
					condutorCandidato->condutor = utilizadorAtual;
					condutorCandidato->preco = preco;
					condutorCandidato->veiculo = veiculo;
					((AnuncioProcura *)anunciosDestino[input])->adicionarCondutorCandidato(condutorCandidato);
					cout << "Tornou-se num candidato a condutor desta viagem com sucesso." << endl;
					InputUtils::pause();
					return showAnunciosMenu();
				}
			}
			if (anunciosDestino[input]->podeSerPassageiro(utilizadorAtual))
			{
				cout << "Pretende ser passageiro (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					anunciosDestino[input]->addPassageiro((Particular *)utilizadorAtual);
					cout << "Tornou-se num passageiro desta viagem com sucesso." << endl;
					InputUtils::pause();
				}
			}
			return showAnunciosMenu();
		}
	}
	case 3: // Pesquisar anuncios por anunciante
	{
		int input;
		string username;
		Membro* anunciante = NULL;
		OutputUtils::clearScreen();
		while (1)
		{
			try
			{
				cout << "Insira o nome de utilizador do anunciante cujos anuncios pretende pesquisar: ";
				username = InputUtils::readLine();
				for (size_t i = 0; i < membros.size(); ++i)
				{
					if (username == membros[i]->getUtilizador())
					{
						anunciante = membros[i];
						break;
					}
				}
				if (anunciante == NULL)
				{
					throw UtilizadorInexistenteException<string>("Utilizador nao encontrado");
				}
				break;
				
			}
			catch (UtilizadorInexistenteException<string> e)
			{
				cout << "Erro: " << e.info << endl;
				continue;
			}
		}
		vector<Anuncio *> anunciosAnunciante = getAnunciosByMembro(anunciante);
		try
		{
			OutputUtils::clearScreen();
			input = OutputUtils::showList(anunciosAnunciante);
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
			return showAnunciosMenu();
		}
		if (input == -1)
		{
			return showAnunciosMenu();
		}
		else
		{
			OutputUtils::clearScreen();
			anunciosAnunciante[input]->show();
			InputUtils::pause();
			if (anunciosAnunciante[input]->podeSerCondutor(utilizadorAtual))
			{
				cout << "Pretende-se candidatar a condutor (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					do
					{
						input = OutputUtils::showList(utilizadorAtual->getVeiculos());
					} while (input == -1);
					Veiculo *veiculo = utilizadorAtual->getVeiculos()[input];
					Preco preco;
					preco.criar();
					preco.updatePrecoCombustivel(veiculo->getConsumo(), veiculo->getCombustivel()->getPreco(), anunciosAnunciante[input]->getOrigem().calcDistancia(anunciosAnunciante[input]->getDestino()));
					CondutorCandidato *condutorCandidato = new CondutorCandidato();
					condutorCandidato->condutor = utilizadorAtual;
					condutorCandidato->preco = preco;
					condutorCandidato->veiculo = veiculo;
					((AnuncioProcura *)anunciosAnunciante[input])->adicionarCondutorCandidato(condutorCandidato);
					cout << "Tornou-se num candidato a condutor desta viagem com sucesso." << endl;
					InputUtils::pause();
					return showAnunciosMenu();
				}
			}
			if (anunciosAnunciante[input]->podeSerPassageiro(utilizadorAtual))
			{
				cout << "Pretende ser passageiro (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					anunciosAnunciante[input]->addPassageiro((Particular *)utilizadorAtual);
					cout << "Tornou-se num passageiro desta viagem com sucesso." << endl;
					InputUtils::pause();
				}
			}
			return showAnunciosMenu();
		}
	}
	case 4: // Editar anuncio
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
				InputUtils::pause();
				OutputUtils::clearScreen();

				// Aceitar candidatos
				if (meusAnuncios[input]->getCondutor() == NULL)
				{
					cout << "Pretende aceitar candidatos a condutor (y/n)?" << endl;
					if (InputUtils::readYesOrNo('y', 'n'))
					{
						OutputUtils::clearScreen();
						int input2 = OutputUtils::showList(((AnuncioProcura *)meusAnuncios[input])->getCondutoresCandidatos());
						if (input2 == -1)
						{
							return showAnunciosMenu();
						}
						else
						{
							OutputUtils::clearScreen();
							cout << "Pretende aceitar o condutor " << ((AnuncioProcura *)meusAnuncios[input])->getCondutoresCandidatos()[input2]->condutor->getNome() << "?" << endl;
							if (InputUtils::readYesOrNo('y', 'n'))
							{
								meusAnuncios[input]->setCondutor(((AnuncioProcura *)meusAnuncios[input])->getCondutoresCandidatos()[input2]->condutor);
								meusAnuncios[input]->setPreco(((AnuncioProcura *)meusAnuncios[input])->getCondutoresCandidatos()[input2]->preco);
								cout << "Condutor definido com sucesso." << endl;
								((AnuncioProcura *)meusAnuncios[input])->cleanCondutoresCandidatos();	// Não há necessidade de deixar ficar a lista de candidatos quando já existe um condutor
							}
						}
					}
				}

				cout << "Pretende apagar este anuncio (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					delete meusAnuncios[input];
					anuncios.erase(find(anuncios.begin(), anuncios.end(), meusAnuncios[input])); // Não falha, porque está garantido que o anúncio existe
					cout << "Anuncio apagado com sucesso." << endl;
					InputUtils::pause();
					return showAnunciosMenu();
				}
				cout << "Pretende editar este anuncio (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					meusAnuncios[input]->editar();
					OutputUtils::clearScreen();
					cout << "Anuncio editado com sucesso." << endl;
					InputUtils::pause();
					return showAnunciosMenu();
				}
				InputUtils::pause();
				return showAnunciosMenu();
			}
		}
		catch (EmptyException<string> e)
		{
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
			return showAnunciosMenu();
		}
	}
	case 5: // Voltar
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
		OutputUtils::clearScreen();
		Veiculo *veiculo = new Veiculo();
		veiculo->criar(&combustiveis);
		utilizadorAtual->addVeiculo(veiculo);
		cout << "Veiculo criado com sucesso." << endl;
		InputUtils::pause();
		return showVeiculosMenu();
	}
	case 1: // Ver veiculos
	{
		try
		{
			OutputUtils::clearScreen();
			int input = OutputUtils::showList(utilizadorAtual->getVeiculos());
			if (input == -1)
			{
				return showVeiculosMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				utilizadorAtual->getVeiculos()[input]->show();
				InputUtils::pause();
				return showVeiculosMenu();
			}
		}
		catch (EmptyException<string> e)
		{
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
			return showVeiculosMenu();
		}
	}
	case 2: // Editar veiculo
	{
		OutputUtils::clearScreen();
		try
		{
			int input = OutputUtils::showList(utilizadorAtual->getVeiculos());
			if (input == -1)
			{
				return showVeiculosMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				utilizadorAtual->getVeiculos()[input]->show();
				InputUtils::pause();
				OutputUtils::clearScreen();
				cout << "Pretende apagar este veiculo (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					utilizadorAtual->removeVeiculo(utilizadorAtual->getVeiculos()[input]); // Não falha, porque está garantido que o veículo existe
					cout << "Veiculo apagado com sucesso." << endl;
					InputUtils::pause();
					return showVeiculosMenu();
				}
				cout << "Pretende editar este veiculo (y/n)?" << endl;
				if (InputUtils::readYesOrNo('y', 'n'))
				{
					utilizadorAtual->getVeiculos()[input]->editar(&combustiveis);
					OutputUtils::clearScreen();
					cout << "Veiculo editado com sucesso." << endl;
					InputUtils::pause();
					return showVeiculosMenu();
				}
				InputUtils::pause();
				return showAnunciosMenu();
			}
		}
		catch (EmptyException<string> e)
		{
			OutputUtils::clearScreen();
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
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
			vector<Anuncio *> meusAnuncios = getAnunciosByMembro(utilizadorAtual);
			OutputUtils::clearScreen();
			int input = OutputUtils::showList(meusAnuncios);
			if (input == -1)
			{
				return showBoleiasMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				if (!meusAnuncios[input]->isPronto())
				{
					throw AnuncioIncompletoException<string>("Impossivel converter um anuncio incompleto numa boleia.");
				}
				if (meusAnuncios[input]->getAnunciante() != utilizadorAtual)
				{
					throw ProibidoException<string>("Apenas o criador do anuncio pode converte-lo numa boleia.");
				}

				OutputUtils::clearScreen();
				meusAnuncios[input]->updateConhecidos();
				boleias.push_back(Boleia(
					meusAnuncios[input]->getTitulo(),
					meusAnuncios[input]->getDescricao(),
					meusAnuncios[input]->getOrigem(),
					meusAnuncios[input]->getDestino(),
					*(meusAnuncios[input]->getPreco()),
					meusAnuncios[input]->getPassageiros(),
					meusAnuncios[input]->getDataInicio(),
					meusAnuncios[input]->getDataFim(),
					meusAnuncios[input]->getCondutor(),
					meusAnuncios[input]->getVeiculo(),
					meusAnuncios[input]->getHora()));

				for (size_t i = 0; i < anuncios.size(); ++i)
				{
					if (anuncios[i] == meusAnuncios[input])
					{
						delete anuncios[i];
						anuncios.erase(anuncios.begin() + i);
					}
				}
				OutputUtils::clearScreen();
				cout << "Conversao efetuada com sucesso." << endl;
				InputUtils::pause();
			}
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
			return showBoleiasMenu();
		}
		catch (ProibidoException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
			return showBoleiasMenu();
		}
		catch (AnuncioIncompletoException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
			return showBoleiasMenu();
		}
		return showAnunciosMenu();
	}
	case 1: // Ver minhas boleias
	{
		try
		{
			vector<Boleia *> minhasBoleias = getBoleiasWhereMembroExists(utilizadorAtual);
			OutputUtils::clearScreen();
			int input = OutputUtils::showList(minhasBoleias);
			if (input == -1)
			{
				return showBoleiasMenu();
			}
			else
			{
				OutputUtils::clearScreen();
				minhasBoleias[input]->show();
				InputUtils::pause();
				OutputUtils::clearScreen();
			}
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
		}
		return showBoleiasMenu();
	}
	case 2: // Remover-me de uma boleia
	{
		try
		{
			vector<Boleia *> minhasBoleias = getBoleiasWhereMembroExists(utilizadorAtual);
			OutputUtils::clearScreen();
			int input = OutputUtils::showList(minhasBoleias);
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
				InputUtils::pause();
			}
		}
		catch (EmptyException<string> e)
		{
			cout << "Erro: " << e.info << endl;
			InputUtils::pause();
		}
		return showBoleiasMenu();
	}
	case 3: // Voltar
	{
		OutputUtils::clearScreen();
		return showMainMenu();
	}
	}
}

void BoleiasInteligentes::showMotoristasMenu()
{
	OutputUtils::clearScreen();
	vector<string> items =
	{
		"Adicionar motorista",
		"Editar motorista",
		"Remover motorista",
		"Voltar"
	};
	showMenu(items);
	int n = InputUtils::readDigit(0, items.size() - 1);

	switch (n)
	{
	case 0:	// Adicionar motorista
	{

	}
	case 1:	// Editar motorista
	{

	}
	case 2: // Remover motorista
	{

	}
	case 3: // Voltar
	{
		return showMainMenu();
	}
	}
}

void BoleiasInteligentes::sortAnuncios(const Coordenadas &origem, const Coordenadas &destino, int left, int right)
{
	int i, j;
	Anuncio *x, *y;
	i = left;
	j = right;
	x = anuncios[(left + right) / 2];

	while (i <= j)
	{
		while (anuncios[i] < x && i < right)
		{
			i++;
		}
		while (anuncios[j] > x && j > left)
		{
			j--;
		}
		if (i <= j)
		{
			y = anuncios[i];
			anuncios[i] = anuncios[j];
			anuncios[j] = y;
			i++;
			j--;
		}
	}
	if (j > right)
	{
		sortAnuncios(origem, destino, left, j);
	}
	if (i < right)
	{
		sortAnuncios(origem, destino, i, right);
	}
}
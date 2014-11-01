#include "../headers/BoleiasInteligentes.h"

BoleiasInteligentes::BoleiasInteligentes(const string &dataFolder):
dataFolder(dataFolder), utilizador(NULL)
{

}

void BoleiasInteligentes::load()
{
	loadCombustiveis();
	loadParticulares();
	loadEmpresas();
}

void BoleiasInteligentes::loadCombustiveis()
{

}

void BoleiasInteligentes::loadParticulares()
{

}

void BoleiasInteligentes::loadEmpresas()
{

}

void BoleiasInteligentes::save()
{
	saveCombustiveis();
	saveParticulares();
	saveEmpresas();
}

void BoleiasInteligentes::saveCombustiveis()
{

}

void BoleiasInteligentes::saveParticulares()
{

}

void BoleiasInteligentes::saveEmpresas()
{

}

Coordenadas BoleiasInteligentes::criarCoordenadas()
{
	double lat;
	double lng;
	cout << "Introduza a latitude " << endl;
	cin >> lat ;
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

Anuncio BoleiasInteligentes::criarAnuncio()
{
	string nome;
	string descricao;

	cout << "Introduza o nome do seu anuncio" << endl;
	getline(cin, nome);
	cout << "Introduza a descricao do seu anuncio" << endl;
	getline(cin, descricao);

	vector<pair<string, float>> outrasDespesas;
	return AnuncioOferta(nome, descricao, new Preco(0.0, 0.0, outrasDespesas), new Viagem(), new Membro("Arcanjo", "arcanjo45", "fagote"));	// TODO
}

void BoleiasInteligentes::addEmpresa(const Empresa &empresa)
{
	Empresa novaEmpresa = empresa;
	empresas.push_back(empresa);
}

void BoleiasInteligentes::addParticular(const Particular &particular)
{
	Particular novoParticular = particular;
	particulares.push_back(particular);
}

Membro* BoleiasInteligentes::login(const string &username, const string &password)
{
	// TODO
	return new Membro("Gustavo Silva", "gtugablue", "123456");
}
#include "../headers/BoleiasInteligentes.h"

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


#include "../headers/BoleiasInteligentes.h"

Coordenadas BoleiasInteligentes::criaCoordenadas()
{
	double lat;
	double lng;
	cout << "Introduza a latitude " << endl;
	cin >> lat ;
	cout << "Introduza a longitude" << endl;
	cin >> lng;
	return Coordenadas(lat, lng);
}

Veiculo BoleiasInteligentes::criaVeiculo()
{
	string marca;
	unsigned mes, ano, dia;
	cout << "Introduza a marca do seu veiculo" << endl;
	getline(cin, marca);
	cout << "Introduza o ano do seu veiculo" << endl;
	cin >> ano;
	cout << "Introduza o mes do seu veiculo" << endl;
	cin >> mes;
	cout << "Introduza o dia do seu veiculo" << endl;
	cin >> dia;
	
}

bool BoleiasInteligentes::criaAnuncio()
{
	string nome;
	string descricao;

	cout << "Introduza o nome do seu anuncio" << endl;
	getline(cin, nome);
	cout << "Introduza a descricao do seu anuncio" << endl;
	getline(cin, descricao);

}


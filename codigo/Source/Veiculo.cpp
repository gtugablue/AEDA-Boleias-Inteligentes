#include "../headers/Veiculo.h"

Veiculo::Veiculo()
{

}

Veiculo::Veiculo(string marca, unsigned mes, unsigned ano,unsigned cilindrada, Combustivel* combustivel)
{
	this->marca = marca;
	this->mes = mes;
	this->ano = ano;
	this->cilindrada = cilindrada;
	this->combustivel = combustivel;
}

string Veiculo::getMarca() const
{
	return marca;
}

unsigned Veiculo::getMes()const
{
	return mes;
}

unsigned Veiculo::getAno()const
{
	return ano;
}

unsigned Veiculo::getCilindrada()const
{
	return cilindrada;
}

Combustivel* Veiculo::getCombustivel() const
{
	return combustivel;
}

void Veiculo::setMarca(string &marca)
{
	this->marca = marca;
	return;

}

void Veiculo::setAno(unsigned ano)
{
	this->ano = ano;
	return;
}

void Veiculo::setMes(unsigned mes)
{
	this->mes = mes;
	return;
}

void Veiculo::setCilindrada(unsigned cilindrada)
{
	this->cilindrada = cilindrada;
	return;
}

void Veiculo::setCombustivel(Combustivel* combustivel)
{
	this->combustivel = combustivel;
	return;
}

void Veiculo::load()
{
	fstream file;
	string marcas, name;
	float preco;
	unsigned m, a, cil;
	file.open("veiculos.txt");
	while (!file.eof())
	{
		getline(file, marcas);
		file >> m;
		file >> a;
		file >> cil;
		getline(file, name);
		file >> preco;
		Veiculo(marcas, m, a, cil, new Combustivel(name, preco));
	}
}

void Veiculo::show() const
{
	cout << "Veiculo" << endl;
	cout << endl;
	cout << "Marca: " << marca << endl;
	cout << "Mes: " << mes << endl;
	cout << "Ano: " << ano << endl;
	cout << "Cilindrada: " << cilindrada << endl;
	cout << endl;
	cout << "Gasolina: " << endl;
	cout << endl;
	cout << "Nome: " << combustivel->getNome() << endl;
	cout << "Preco: " << combustivel->getPreco() << endl;
}

void Veiculo::criar()
{
	string marca;
	unsigned mes, ano, cilindrada;
	cout << "Introduza a marca: " << endl;
	getline(cin, marca);
	cout << "Introduza o modelo: " << endl;
	getline(cin, modelo);
	cout << "Introduza o ano: " << endl;
	cin >> ano;
	cout << "Introduza o mes: " << endl;
	cin >> mes;
	cout << "Introduza a cilindrada: " << endl;
	cin >> cilindrada;
}

void Veiculo::editar()
{
	// TODO
}

ostream& operator<<(ostream &os, const Veiculo &veiculo)
{
	return os << veiculo.marca << " " << veiculo.modelo << endl;
}
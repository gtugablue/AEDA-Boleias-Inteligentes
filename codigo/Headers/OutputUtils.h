#ifndef _OUTPUT_UTILS_H
#define _OUTPUT_UTILS_H

#include <iostream>
#include <vector>

#define LIST_ITEMS_PER_PAGE	8

using namespace std;

class Veiculo;

class OutputUtils
{
public:
	template<class T>
	static int showList(const vector<T> &v);

	template<class T>
	static int showList(const vector<T> &v, int page);

	static void clearScreen();
};

template<class T>
class PaginaInexistenteException
{
public:
	T info;
	PaginaInexistenteException(T info)
	{
		this->info = info;
	}
};

template<class T>
class EmptyException
{
public:
	T info;
	EmptyException(T info)
	{
		this->info = info;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
static int OutputUtils::showList(const vector<T> &v)
{
	return showList(v, 0);
}

template<class T>
static int OutputUtils::showList(const vector<T> &v, int page)
{
	OutputUtils::clearScreen();
	if (v.size() == 0)
	{
		throw EmptyException<string>("Nenhum elemento a listar.");
	}
	for (size_t i = page * LIST_ITEMS_PER_PAGE; (unsigned)(page * LIST_ITEMS_PER_PAGE + i % LIST_ITEMS_PER_PAGE) < v.size() && i < (unsigned)((page + 1) * LIST_ITEMS_PER_PAGE); ++i)
	{
		cout << i % LIST_ITEMS_PER_PAGE << ". " << v[i] << endl;
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
		} while (input > v.size() - page * LIST_ITEMS_PER_PAGE && input < 7);
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
			if (page == v.size() / LIST_ITEMS_PER_PAGE)
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
			return page * LIST_ITEMS_PER_PAGE + input;
		}
		}
	}
	catch (PaginaInexistenteException<string> e)
	{
		return showList(v, page);
	}
}

#endif
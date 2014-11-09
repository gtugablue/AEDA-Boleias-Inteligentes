#ifndef _INPUT_UTILS_H
#define _INPUT_UTILS_H

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

///Classe que cont�m fun��es uteis para ler do teclado e para seleccionar op�oes de escolha

class InputUtils
{
public:
	static string readLine();///Fun��o que l� uma linha
	static int readInt();///Fun��o que l� um inteiro do teclado
	static float readFloat();///Fun��o que l� um float do teclado
	static double readDouble();///Fun��o que l� um double do teclado
	static string readPassword();///Fun��o que l� a password quando esta a ser introduzida no momento do login
	static int readDigit(unsigned from, unsigned to);///Fun��o que l� um digito do teclado
	static bool readYesOrNo(unsigned char yes, unsigned char no);///Fun��o que permite ao utilizador escolher a op��o sim(yes) ou n�o(no) quando esta a alterar informa��es do programa
	static void pause();///fun��o que pausa o ecr�
};

///Tratamento da excep��o quando � introduzido um input invalido
template<class T>
class InvalidInputException
{
public:
	T info;
	InvalidInputException(T info)
	{
		this->info = info;
	}
};

#endif
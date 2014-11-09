#ifndef _INPUT_UTILS_H
#define _INPUT_UTILS_H

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

///Classe que contém funções uteis para ler do teclado e para seleccionar opçoes de escolha

class InputUtils
{
public:
	static string readLine();///Função que lê uma linha
	static int readInt();///Função que lê um inteiro do teclado
	static float readFloat();///Função que lê um float do teclado
	static double readDouble();///Função que lê um double do teclado
	static string readPassword();///Função que lê a password quando esta a ser introduzida no momento do login
	static int readDigit(unsigned from, unsigned to);///Função que lê um digito do teclado
	static bool readYesOrNo(unsigned char yes, unsigned char no);///Função que permite ao utilizador escolher a opção sim(yes) ou não(no) quando esta a alterar informações do programa
	static void pause();///função que pausa o ecrã
};

///Tratamento da excepção quando é introduzido um input invalido
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
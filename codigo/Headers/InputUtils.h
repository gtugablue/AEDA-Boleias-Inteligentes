#ifndef _INPUT_UTILS_H
#define _INPUT_UTILS_H

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class InputUtils
{
public:
	static string readString();
	static string readPassword();
	static int readDigit(unsigned from, unsigned to);
	static bool readYesOrNo(unsigned char yes, unsigned char no);
	static void pause();
};

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
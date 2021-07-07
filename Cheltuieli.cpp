#include "Cheltuieli.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Cheltuieli::Cheltuieli() 
{
	this->zi = 0;
	this->suma_bani = 0;
	this->tip = NULL;
}

Cheltuieli::Cheltuieli(const Cheltuieli& c) 
{
	this->zi = c.zi;
	this->suma_bani = c.suma_bani;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}


Cheltuieli::~Cheltuieli() 
{
	this->zi = 0;
	this->suma_bani = 0;
	if (this->tip != NULL) 
	{
		delete[] this->tip;
		this->tip = NULL;
	}
}

Cheltuieli::Cheltuieli(int zi, int suma_bani, char* tip) 
{
	this->zi = zi;
	this->suma_bani = suma_bani;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}


bool Cheltuieli::operator==(const Cheltuieli& c) 
{
	return (this->zi == c.zi) && (this->suma_bani == c.suma_bani) && (strcmp(this->tip, c.tip) == 0);
}

int Cheltuieli::getZi() 
{
	return this->zi;
}

int Cheltuieli::getSumaBani() 
{
	return this->suma_bani;
}

char* Cheltuieli::getTip() 
{
	return this->tip;
}

void Cheltuieli::setZi(int zi) 
{
	this->zi = zi;
}

void Cheltuieli::setSumaBani(int suma_bani) 
{
	this->suma_bani = suma_bani;
}
void Cheltuieli::setTip(char* tip) 
{
	if (this->tip != NULL) {
		delete[] this->tip;
	}
	if (tip != NULL) {
		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	}
	else
		this->tip = NULL;
}

Cheltuieli& Cheltuieli::operator=(const Cheltuieli& c) 
{
	this->setZi(c.zi);
	this->setSumaBani(c.suma_bani);
	this->setTip(c.tip);
	return *this;
}


ostream& operator<<(ostream& os, const Cheltuieli& c) 
{
	os << " Cheltuiala: " << c.zi << "," << c.suma_bani << " , " << c.tip << "\n";
	return os;
}
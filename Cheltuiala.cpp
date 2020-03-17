#include "Cheltuiala.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Cheltuieli::Cheltuieli() 
{
	this->zi = 0;
	this->sumaBani = 0;
	this->tip = NULL;
}

Cheltuieli::Cheltuieli(const Cheltuieli& c) 
{
	this->zi = c.zi;
	this->sumaBani = c.sumaBani;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}

Cheltuieli::~Cheltuieli() 
{
	this->zi = 0;
	this->sumaBani = 0;
	if (this->tip != NULL) 
	{
		delete[] this->tip;
		this->tip = NULL;
	}
}

Cheltuieli::Cheltuieli(int zi, int sumaBani, char* tip) 
{
	this->zi = zi;
	this->sumaBani = sumaBani;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

bool Cheltuieli::operator==(const Cheltuieli& c) 
{
	return (this->zi == c.zi) && (this->sumaBani = c.sumaBani) && (strcmp(this->tip, c.tip) == 0);
}

int Cheltuieli::getZi()
{
	return this->zi;
}

int Cheltuieli::getSumaBani() 
{
	return this->sumaBani;
}

char* Cheltuieli::getTip() 
{
	return this->tip;
}

void Cheltuieli::setZi(int zi) 
{
	this->zi = zi;
}

void Cheltuieli::setSumaBani(int sumaBani) 
{
	this->sumaBani = sumaBani;
}

void Cheltuieli::setTip(char* tip) 
{
	if (this->tip != NULL) 
	{
		delete[] this->tip;
		this->tip = NULL;
	}
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

Cheltuieli& Cheltuieli::operator=(const Cheltuieli& c) 
{
	this->setZi(c.zi);
	this->setSumaBani(c.sumaBani);
	this->setTip(c.tip);
	return *this;
}

ostream& operator<<(ostream& os, const Cheltuieli& c) 
{
	os << "ziua: " << c.zi << " \n suma de bani: " << c.sumaBani << "\n tipul: " << c.tip;
	return os;
}
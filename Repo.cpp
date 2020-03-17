#include "Repo.h"
#include <cstddef>

Repo::Repo() 
{
	this->n = 0;
}

Repo::~Repo()
{
	this->n = 0;
}

int Repo::getSize()
{
	return this->n;
}

void Repo::addElem(Cheltuieli c) 
{
	this->cheltuieli[this->n++] = c;
}

Cheltuieli* Repo::getAll() 
{
	return this->cheltuieli;
}
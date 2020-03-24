#include "Repo.h"
#include <cstddef>

Repo::Repo() 
{
	this->n = 0;
	this->buget = 10000;
}

Repo::~Repo() 
{
	this->n = 0;
	this->buget = 0;
}

int Repo::getSize() 
{
	return this->n;
}

void Repo::adaugare(Cheltuieli c) 
{
	this->cheltuieli[this->n++] = c;
	this->buget -= c.getSumaBani();
}

Cheltuieli* Repo::getAll() 
{
	return this->cheltuieli;
}

int Repo::getBuget() 
{
	return this->buget;
}

void Repo::stergere(Cheltuieli c) 
{
	int poz = this->cautare(c);
	int lungime = this->getSize();
	if (poz != -1) 
	{
		for (int i = poz; i < lungime-1; i++) 
		{
			this->cheltuieli[i] = this->cheltuieli[i + 1];
		}
		this->setBuget(this->buget + cheltuieli[poz].getSumaBani());
		this->cheltuieli[lungime - 1] = Cheltuieli();
		this->setSize(lungime-1);
	}
}

void Repo::setSize(int n) 
{
	this->n = n;
}

int Repo::cautare(const Cheltuieli& c) 
{
	for (int i = 0; i < this->getSize(); i++) 
	{
		if (this->cheltuieli[i] == c) 
		{
			return i;
		}
	}
	return -1;
}

void Repo::setBuget(int n) 
{
	this->buget = n;
}

Repo::Repo(Cheltuieli cheltuieli[], int n,int buget)
{
	this->buget = buget;
	this->n = n;
	for (int i = 0; i < n; i++) 
	{
		this->cheltuieli[i] = cheltuieli[i];
	}
}

Repo& Repo::operator=( Repo & r) 
{
	this->n = 0;
	int i;
	for (i = 0; i < this->n; i++) 
	{
		this->adaugare(r.getAll()[i]);
	}
	return *this;
}
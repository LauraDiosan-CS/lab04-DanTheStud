#pragma once

#include "Cheltuiala.h"

class Repo 
{
private:

	Cheltuieli cheltuieli[100];
	int n;

public:

	Repo();
	~Repo();

	void addElem(Cheltuieli c);

	Cheltuieli* getAll();

	int getSize();
};
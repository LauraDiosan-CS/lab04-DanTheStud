#pragma once
#include "Cheltuieli.h"

class Repo 
{
private:
	Cheltuieli cheltuieli[100];
	int n;
	int buget;
public:
	Repo();
	~Repo();
	Repo(Cheltuieli cheltuieli[], int n,int buget);
	void adaugare(Cheltuieli c);
	Cheltuieli* getAll();
	int getSize();
	int getBuget();
	void stergere(Cheltuieli c);
	int cautare(const Cheltuieli& c);
	void setSize(int n);
	Repo& operator=( Repo& r);
	void setBuget(int n);
};

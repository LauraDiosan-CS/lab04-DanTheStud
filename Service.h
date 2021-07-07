#pragma once
#include "Repo.h"



class Service 
{
private:
	Repo repo_cheltuiala;
public:
	int getCurrentDay();
	void adaugare_cheltuiala_zi(int suma, char* tip);
	void adaugare_cheltuiala(int zi, int suma, char* tip);
	Cheltuieli* getAll();
	void stergere_cu_zi(int day);
	void stergere_interval(int day1, int day2);
	void stergere_tip(char* tip);
	void getElemByType(char* type, Cheltuieli cheltuieli[], int& resultlen);
	void getElemByCondAndType(int nr, char* tip, Cheltuieli cheltuieli[], int& resultlen);
	void getElemByCond2AndType(int nr, char* tip, Cheltuieli cheltuieli[], int& resultlen);
	int suma_elem_tip(char* tip);
	int max_zi_suma();
	void sortare_suma_desc(Cheltuieli cheltuieli[], int& resultlen);
	void sortare_suma_tip(char* tip,Cheltuieli cheltuieli[], int& resultlen);
	void filtrare_tip(char* tip);
	int getSizeRepo();
	void filtrare_tip_cond(int nr, char* tip);
	void filtrare_tip_cond2(int nr, char* tip);
	int getBuget();
};
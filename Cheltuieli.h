#pragma once
#include <ostream>
using namespace std;

class Cheltuieli 
{
private:
	int zi;
	int suma_bani;
	char* tip;
public:
	Cheltuieli();
	Cheltuieli(int zi, int suma_bani, char* tip);
	~Cheltuieli();
	Cheltuieli(const Cheltuieli& c);
	int getZi();
	int getSumaBani();
	char* getTip();
	Cheltuieli& operator=(const Cheltuieli& c);
	bool operator==(const Cheltuieli& c);
	void setZi(int zi);
	void setSumaBani(int suma_bani);
	void setTip(char* tip);
	friend ostream& operator<<(ostream &os, const Cheltuieli& c);
};
